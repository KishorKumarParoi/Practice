//15-02-20
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define scl(n) scanf("%d",&n)

int node,edge,u,v,sum,i,j,p;
vector<int>graph[2222];
vector<int>cost[2222];
bool vis[2222];
int dis[2222];

struct data
{
    int nod,weight;
    bool operator < (data kishor) const
    {
        return weight > kishor.weight;
    }
};

int Prims(int src,int n)
{
    priority_queue<data> pq;
    sum = 0;
    for(i=0; i<n-1; i++)
    {
        u = src;
        vis[src] = true;

        for(j=0; j<graph[u].size(); j++)
        {
            v = graph[u][i];

            if(vis[v]==0)
            {
                data D;
                D.nod = v;
                D.weight = cost[u][i];

                pq.push(D);
            }
        }

        while(vis[src])
        {
            data T = pq.top();
            pq.pop();

            src = T.nod;
            p = T.weight;
        }

        sum+= p;
    }
    return sum;
}

int main()
{
    scl(node);
    scl(edge);

    for(int i=0; i<edge; i++)
    {
        int x,y,w;
        scl(x);
        scl(y);
        scl(w);

        graph[x].pb(y);
        graph[y].pb(x);

        cost[x].pb(w);
        cost[y].pb(w);
    }

    printf("%d\n",Prims(1,node));
    return 0;
}
