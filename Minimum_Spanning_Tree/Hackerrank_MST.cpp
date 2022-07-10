#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int> ;   // dest & cost


struct node
{
    int u;
    int cost;
};

bool operator < (node a, node b)
{
    return a.cost > b.cost;
}

priority_queue<node> pq;

#define MX 4000
#define deb(a)                        cout << #a << " : " << a << " ";
#define debln(a)                      cout<< #a <<" : " << a << endl;


int cost[MX];
bool taken[MX];
int vertex,edge,source;
vector<pii>v[MX];

int prim(int source)
{
    for(int i=0; i<vertex; ++i)
    {
        cost[i] = INT_MAX;
        taken[i] = false;
    }

    cost[source] = 0;
    node temp;
    temp.u = source;
    temp.cost = 0;

    pq.push(temp);
    int ans = 0;

    while(!pq.empty())
    {
        node current = pq.top();
        pq.pop();

        if(taken[current.u])
            continue;

        taken[current.u] = true;
        ans+=current.cost;

        //deb(current.u) deb(current.cost)  debln(ans)

        for(int i=0; i<v[current.u].size(); i++)
        {
            if(taken[v[current.u][i].first])
                continue;

            node temp2;
            temp2.u = v[current.u][i].first;
            temp2.cost = v[current.u][i].second;

            pq.push(temp2);
            cost[v[current.u][i].first] = v[current.u][i].second;

            //deb(v[current.u][i].first) debln(cost[v[current.u][i].first])
        }
    }

    return ans;
}

void printGraph()
{
    for(int i=0; i<vertex; ++i)
    {
        cout<< i<< "-----";
        for(int j=0; j<v[i].size(); ++j)
        {
            cout<<v[i][j].first<< "----"<<v[i][j].second<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    cin>>vertex>>edge;

    for(int i=0; i<edge; ++i)
    {
        int source;
        pii p;

        cin>>source>>p.first>>p.second;

        v[source].push_back(p);
        int source2 = p.first;

        p.first = source;
        v[source2].push_back(p);
    }

    //printGraph();

    int src;
    cin>>src;

    cout<< prim(src)<<endl;
    return 0;
}
