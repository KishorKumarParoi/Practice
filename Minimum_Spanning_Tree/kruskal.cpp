#include<bits/stdc++.h>
using namespace std;

#define MX 100

struct node
{
    int u;
    int v;
    int w;
};

bool operator < (node a,node b)
{
    return a.w < b.w;
}

int parent[MX];
int rankParent[MX];

vector<node>graph;

void initializeSet(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] = i;
        rankParent[i] = 0;
    }
}


int findParent(int x)
{
    if(x != parent[x])
        return parent[x] = findParent(parent[x]);
    else
        return x;
}


void unionSet(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);
    if(px == py) return;

    ///cout << px << " " << py << endl;
    if(rankParent[px] < rankParent[py])
        parent[px] = py;
    else if(rankParent[px] > rankParent[py])
        parent[py] = px;
    else
    {
        parent[py] = px;
        rankParent[px]++;
    }

}

int kruskal(int n)
{
    initializeSet(n);

    sort(graph.begin(),graph.end());
    int sz = graph.size();

    int ans = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(findParent(graph[i].u) != findParent(graph[i].v))
        {
            //union
            unionSet(parent[graph[i].u], parent[graph[i].v]);

            //cout << graph[i].u << " " << graph[i].v << endl;

            ans+=graph[i].w;
        }
    }

    // cout<<endl;
    return ans;
}

int main()
{

    int vertex, edge;
    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        node e;
        cin >> e.u >> e.v >> e.w;
        graph.push_back(e);
    }
    //cout << "MST" << endl;
    cout << "MST Cost " << kruskal(vertex) << endl;
    return 0;
}
