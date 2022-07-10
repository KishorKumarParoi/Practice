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

/*
Sample input
3
JV PT
KA PT
KA HP
JV HP
2
JV PT
KA HP
JV HP
Sample output
JV PT
PT KA
KA HP
No route:

*/
map<string,vector<string>>graph;
map<string,int>dis;
map<string,string>p;


void bfs(string src,string dest)
{
    dis[src] = 0;
    p[src] = "-1";

    queue<string>q;
    q.push(src);

    while(!q.empty())
    {
        string u = q.front();
        q.pop();

        for(auto v : graph[u])
        {
            if(!dis.count(v))
            {
                dis[v] = dis[u] + 1;
                q.push(v);

                p[v] = u;
            }
        }
    }

    //PRINT(p)

    if(!dis.count(dest))
        cout<< "No route\n";
    else
    {
        vector<string> path;

        for(string x = dest; x!="-1"; x = p[x])
        {
            path.pb(x);
        }

        reverse(path.begin(),path.end());

        for(int i=0; i<path.size()-1; i++)
            cout<< path[i] << " "<<path[i+1]<<endl;
    }
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int t,k=0;

    while(cin>>t)
    {
        if(k++>0)
            cout<<endl;

        graph.clear();
        dis.clear();
        p.clear();

        while(t--)
        {
            string a,b;
            cin>>a>>b;

            graph[a].pb(b);
            graph[b].pb(a);
        }

        string src,dest;
        cin>>src>>dest;

        bfs(src,dest);
    }

    return 0;
}

