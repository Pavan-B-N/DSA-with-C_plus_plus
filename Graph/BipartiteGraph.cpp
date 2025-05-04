// https://www.geeksforgeeks.org/problems/bipartite-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// isBipartite is a graph where no two adjacent nodes have same color
// its two colored graaph like 0,1
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adjList(V);
        // insteaad of visited array we can use color vector
        vector<int> color(V,-1);// default = -1 (not colored), colors = 0,1
        
        // constructing the adjList
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(bfs(adjList,color,i)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool bfs(vector<vector<int>> &adjList,vector<int> &color,int start){
        queue<int> q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto neighbor:adjList[node]){
                // unvisited and not colored
                if(color[neighbor]==-1){
                    color[neighbor]=!color[node];
                    q.push(neighbor);
                }
                // colored by someone
                // no two adjacent nodes have the same color
                else if(color[neighbor]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};