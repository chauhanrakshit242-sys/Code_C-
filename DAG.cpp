#include<bits/stdc++.h>
using namespace std;

void dfs(int node,
         vector<bool>& vis,
         vector<vector<pair<int,int>>>& adj,
         stack<int>& st)
{
    vis[node] = true;

    for(auto neighbour : adj[node])
    {
        if(!vis[neighbour.first])
        {
            dfs(neighbour.first, vis, adj, st);
        }
    }

    st.push(node);
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<pair<int,int>>> adj(vertex);

    for(int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    // Topological Sort
    vector<bool> vis(vertex, false);
    stack<int> st;

    for(int i = 0; i < vertex; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // Store topo order in vector
    vector<int> topo;

    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }

    // Shortest path from every source
    for(int src = 0; src < vertex; src++)
    {
        vector<int> distance(vertex, INT_MAX);
        distance[src] = 0;

        for(auto node : topo)
        {
            if(distance[node] != INT_MAX)
            {
                for(auto edge : adj[node])
                {
                    int v = edge.first;
                    int wt = edge.second;

                    if(distance[node] + wt < distance[v])
                    {
                        distance[v] = distance[node] + wt;
                    }
                }
            }
        }

        cout << "Source " << src << " : ";

        for(int i = 0; i < vertex; i++)
        {
            if(distance[i] == INT_MAX)
                cout << "INF ";
            else
                cout << distance[i] << " ";
        }

        cout << endl;
    }

    return 0;
}