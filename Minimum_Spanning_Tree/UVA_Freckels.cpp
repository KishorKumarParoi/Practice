//20-7-20
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

struct node
{
    ll N;
    double cost;
};

bool operator<(node a,node b)
{
    return a.cost>b.cost;
}

const ll maxn = 10005;
vector<vector<node>>graph(maxn);
map<double,bool>taken;

void prim()
{
    set<ll>st;

    ll n;

    cin>>n;
    vector<pair<double,double>>V(n+1);

    for(ll i=1; i<=n; ++i)
    {
        cin>>V[i].first>>V[i].second;
    }

    for(ll i=0; i<maxn; ++i)
    {
        graph[i].clear();
    }
    taken.clear();


    for(ll i=1; i<=n; i++)
    {
        for(ll j=i+1; j<=n; j++)
        {
            double diffx = abs(V[j].first - V[i].first) * abs(V[j].first - V[i].first);
            double diffy = abs(V[j].second - V[i].second) * abs(V[j].second - V[i].second);

            double diff = diffx + diffy;
            diff = sqrt(diff);

            //deb(i) deb(j) debln(diff)

            graph[i].pb({j,diff});
            graph[j].pb({i,diff});

            st.insert(i);
            st.insert(j);
        }
    }

    /*cout<<"graph1_size : "<<graph[1].size()<<endl;

    for(int i=1; i<=st.size(); ++i)
    {
        cout<< i<< " : "<<endl;
        for(auto x : graph[i])
            cout<<x.N<< " "<<x.cost<<endl;
        cout<<endl;
    }
    */
    priority_queue<node>pq;

    for(auto X : graph[1])
        pq.push(X);

    //cout<<"#1: "<<pq.size()<<endl;
    taken[1] = true;

    double ans = 0;

    while(!pq.empty())
    {
        auto T = pq.top();
        pq.pop();

        //cout<<"#2: "<<pq.size()<<endl;

        if(taken[T.N])
            continue;

        taken[T.N] = true;
        ans+=T.cost;

        //deb(T.N) deb(T.cost)  debln(ans)

        for(auto X : graph[T.N])
        {
            if(!taken[X.N])
                pq.push(X);
        }
    }

    printf("%.2lf\n",ans);
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    //open
    //close

    ll t;
    cin>>t;

    while(t--)
    {
        prim();

        if(t)
            cout<<endl;
    }

    return 0;
}

