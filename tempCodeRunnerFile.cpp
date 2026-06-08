#include<bits/stdc++.h>
using namespace std;
void dfs(int start , vector<bool>& vis,vector<vector<pair<int,int>>>& adj, stack<int>& st)
{
    vis[start]=true;
    for(auto neighbor: adj[start])
    {
      if(!vis[neighbor.first])
      {
        dfs(neighbor.first,vis,adj,st);
      }
    }
    st.push(start);
}
int main()
{
   int  vertex,edges;
   cin>>vertex>>edges;
   vector<vector<pair<int,int>>>adj(vertex);
   for(int i=0;i<edges;i++)
   {
     int u,v,w;
     cin>>u>>v>>w;
     adj[u].push_back({v,w});
   }
   // topological sort
vector<bool>vis(vertex,false);
 stack<int>st;
 for(int i=0;i<vertex;i++)
 {
    if(!vis[i])
    {
    dfs(i,vis,adj,st);
    }
 }
 int src=1;
 vector<int>distance(vertex,INT_MAX);
 distance[src]=0;
 while(!st.empty())
 {
    int top=st.top();
    st.pop();
    if(distance[top]!=INT_MAX)
    {
    for(auto i : adj[top])
    {
        if(i.second+distance[top]<distance[i.first])
        {
            distance[i.first]=i.second+distance[top];
        }
    }
    }
 }
 for(int i = 0; i < vertex; i++)
{
    if(distance[i] == INT_MAX)
        cout << "INF ";
    else
        cout << distance[i] << " ";
}
cout << endl;
 return 0;
}