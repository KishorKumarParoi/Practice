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
Sample Input

1
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

Sample Output

spice stock 4
may pod 3
*/

vector<string>arr;
map<string,int>vis;
map<string,int>dis;

void bfs(string src,string dest)
{
    vis[src] = 1;
    dis[src] = 0;

    queue<string>q;
    q.push(src);

    while(!q.empty())
    {
        string u = q.front();
        q.pop();

        for(int i=0; i<arr.size(); ++i)
        {
            string v = arr[i];

            if(v.size()==u.size() && vis[v]==0)
            {
                int cnt = 0;

                for(int j=0; j<v.size(); ++j)
                {
                    if(v[j]!=u[j])
                        cnt++;
                }

                if(cnt==1)
                {
                    vis[v] = 1;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int t,k=0;
    cin>>t;

    while(t--)
    {
        if(k++>0)
            cout<<endl;

        arr.clear();

        string s;
        while(1)
        {
            cin>>s;
            if(s=="*")
                break;
            arr.pb(s);
        }

        cin.ignore();
        while(getline(cin,s))
        {
            if(s.size()==0)
                break;

            stringstream str(s) ;
            string src,dest;

            str>>src>>dest;

            dis.clear();
            vis.clear();

            bfs(src,dest);

            cout<<src<< " "<<dest<<" "<< dis[dest]<<endl;
        }
    }

    return 0;
}
