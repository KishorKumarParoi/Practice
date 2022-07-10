//16-7-20
#pragma GCC optimize ("-O2")
#define _CRT_SECURE_NO_WARNINGS 1

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace std :: chrono;

#define scu(n)                        scanf("%u",&n)
#define scl(n)                        scanf("%d",&n)
#define scll(n)                       scanf("%lld",&n)
#define sz(a)                         (int)a.size()
#define maxN                          10000005
#define uu                            first
#define vv                            second
#define ll                            long long
#define U                             unsigned
#define pb                            push_back
#define mp                            make_pair
#define pii                           pair<int,int>
#define vi                            vector<int>
#define mii                           map<int,int>
#define Pi                            acos(-1.0)
#define endl                         "\n"
#define pqb                           priority_queue<int>
#define pqs                           priority_queue<int,vi,greater<int> >
#define setbits(x)                    __builtin_popcountll(x)
#define zrobits(x)                    __builtin_ctzll(x)
#define mod                           1000000007
#define inf                           1e18
#define EPS                           1e-9
#define ps(x,y)                       fixed<<setprecision(y)<<x
#define mk(arr,n,type)                type *arr=new type[n];
#define TEST                          int tc;cin>>tc; while(tc--)
mt19937                               rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//Vector Macros
#define pb                            push_back
#define eb                            emplace_back
#define ALL(v)                        v.begin(),v.end()
#define UNIQUE(v)                     v.erase(unique(ALL(v)),v.end())
#define MIN(c)                        *min_element(ALL(c))
#define MAX(c)                        *max_element(ALL(c))
#define SUM(c)                        accumulate(ALL(c),0)

//Loop Macros
#define For(i,a,b)                    for(ll i=a;i<=b;i++)
#define rep(i,a,b)                    for(int i=a;i<=b;i++)
#define fr(i,n)                       for(int i=0;i<n;i++)

//Debug Macros
#define open                          freopen("input.txt","r",stdin);
#define close                         freopen("output.txt","w",stdout);
#define deb(a)                        cout << #a << " : " << a << " ";
#define debln(a)                      cout<< #a <<" : " << a << endl;
//Print Macros
#define print(v)  for(auto x : v) {  cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v) { cout<<x.uu<<" "<<x.vv<<endl;}

/*
Time Calculation :
auto st = high_resolution_clock::now();
auto en = high_resolution_clock::now();
auto duration = duration_cast < milliseconds > (en-st);
cout<< "consumed time in ms " << duration.count() <<endl;
*/

// input
/*

*/

map<int,vector<int>> graph;
map<int,int>vis;

void bfs(int start,int ending)
{
    vis[start] = 0;
    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v : graph[u])
        {
            if(!vis.count(v))
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    if(start<10)
        printf("%2d",start);
    else
        printf("%d",start);

    printf(" to ");

    if(ending<10)
        printf("%2d",ending);
    else
        printf("%d",ending);

    printf(": %d\n",vis[ending]);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int kase=1,x,i,j,y;

    while(scanf("%d",&x)==1)
    {
        graph.clear();
        vis.clear();

        for(int j=0; j<x; ++j)
        {
            scanf("%d",&y);
            graph[1].pb(y);
            graph[y].pb(1);
        }

        for(int i=2; i<20; ++i)
        {
            int numOfNodes;
            scl(numOfNodes);

            for(int j=0; j<numOfNodes; ++j)
            {
                int node;
                scl(node);

                graph[i].pb(node);
                graph[node].pb(i);
            }
        }

        /*
        for(auto x : graph)
        {
            cout<<x.first<< "->";
            for(auto y : x.vv)
                cout<<y<< " ";
            cout<<endl;
        }
        cout<<endl;

        */

        int query;
        scl(query);

        printf("Test Set #%d\n",kase++);

        while(query--)
        {
            int starting_node,ending_node;
            cin>>starting_node>>ending_node;

            vis.clear();
            bfs(starting_node,ending_node);
        }
        cout<<endl;
    }

    return 0;
}

