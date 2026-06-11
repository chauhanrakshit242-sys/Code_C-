#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

void makeSet(vector<int>& parent, vector<int>& rank, int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int node)
{
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v,
              vector<int>& parent,
              vector<int>& rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    int mstWeight = 0;

    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(findParent(parent, u) != findParent(parent, v))
        {
            mstWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    cout << "MST Weight = " << mstWeight << endl;

    return 0;
}