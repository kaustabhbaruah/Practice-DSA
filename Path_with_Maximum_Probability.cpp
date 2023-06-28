class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n + 1,0.0);//probability array of all the vertices - initially 0
        vector<pair<int,double>> adj[n + 1]; // adjacency list

        // creation of adjacency list
        for(int i = 0;i < edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        

        priority_queue<pair<double,int>>pq;

        // pushing the starting node and prob of going from start node to start node is obviously 1
        pq.push({1.0,start});
        
        //prob of going from start node to start node is obviously 1
        prob[start] = 1.0;

        while(!pq.empty()){
            int node = pq.top().second; // node 
            double node_prob = pq.top().first;// probabilty of that node

            pq.pop();

            // travelling the neighboring nodes
            for(auto it : adj[node]){
                int neigh_node = it.first; //neighboring node
                double neigh_prob = it.second;// probability of going from node to neighboring node

                double new_prob = neigh_prob * node_prob; // new probability - multiplication of the all the other paths to reach this neighboring node
                
                // checking if it's larger than the already present then we update it and we travel further 
                if(prob[neigh_node] < new_prob) {
                    prob[neigh_node] = new_prob;
                    pq.push({prob[neigh_node],neigh_node});
                }

            }
        } 

        // return the probability of going to the end node'
        return prob[end];    
    }
};
