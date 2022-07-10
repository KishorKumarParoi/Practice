//18-06-20

#include<bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define vpi vector<pii>
#define ff first
#define ss second
#define mp make_pair

vpi V[3005];                             //graph is stored here as adjacency list
int vis[3005]= {0};
int vertex,edge,src;

int prim(int src)
{
    priority_queue<pii> p;               //stored as <cost,node> pair
    int cost = 0;
    p.push(mp(0,src));     //source is 0, and cost of source to source is 0

    while(!p.empty())
    {
        pii tem = p.top();
        p.pop();
        int v = tem.ss;
        if(!vis[v])
        {
            vis[v] = 1;
            cost += -tem.ff;
            for(int i=0; i<V[v].size(); i++)
                if(!vis[V[v][i].ff])
                    p.push(mp(-(V[v][i].ss),V[v][i].ff));
        }
    }
    return cost;
}

int main()
{
    cin>>vertex>>edge;

    for(int i=0; i<edge; ++i)
    {
        int source;
        pii p;

        cin>>source>>p.second>>p.first;

        V[source].push_back(p);
        int source2 = p.second;

        p.second = source;
        V[source2].push_back(p);
    }

    //printGraph();
    int x;
    cin>>x;

    cout<< "MST is "<< prim(src)<<endl;
}
