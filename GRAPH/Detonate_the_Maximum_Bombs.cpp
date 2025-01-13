#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution {
public:
    bool f(ll x1,ll x2,ll y1,ll y2,ll r1,ll r2){
        long long  dist=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        return dist<=(r1*r1);
    }
    int bfs(int i,map<int,vector<int>>&adj,int n){
        vector<int>vis(n,0);
        int cnt=0;
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& a) {
        int n=a.size();
        map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int x1=a[i][0],x2=a[j][0];
                int y1=a[i][1],y2=a[j][1];
                int r1=a[i][2],r2=a[j][2];
                if(f(x1,x2,y1,y2,r1,r2))adj[i].push_back(j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt=max(cnt,bfs(i,adj,n));
        }
        return cnt;
    }
};