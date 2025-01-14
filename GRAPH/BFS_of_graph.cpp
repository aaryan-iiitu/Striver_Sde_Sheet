//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<int>vis(n,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        ans.push_back(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};
