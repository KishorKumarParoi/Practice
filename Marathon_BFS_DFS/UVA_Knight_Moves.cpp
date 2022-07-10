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
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

//output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

*/
int fx[]= { 2, 1, -1, -2, -2, -1, 1, 2 };                         //Direction Array
int fy[]= { 1, 2, 2, 1, -1, -2, -2, -1 };

int cell[10][10];
int vis[10][10];
int dis[10][10];
string src,dest;

int bfs(int sx,int sy,int dx,int dy)
{
    memset(vis,0,sizeof(vis));
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;

    queue<pii>q;                               //A queue containing STL pairs
    q.push(pii(sx,sy));

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        for(int k=0; k<8; k++)
        {
            int tx = top.uu + fx[k];
            int ty = top.vv + fy[k];             //Neighbor cell [tx][ty]

            if(tx>0 && tx<9 && ty>0 && ty<9 && cell[tx][ty]!=-1 && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                dis[tx][ty] = dis[top.uu][top.vv]+1;

                //Pushing a new pair in the queue
                q.push(pii(tx,ty));

                //deb(tx) deb(ty) deb(vis[tx][ty]) debln(dis[tx][ty])
            }
        }
    }

    return dis[dx][dy];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    while(cin>>src>>dest)
    {
        int sx,sy,dx,dy;
        sx = src[0] - 'a' + 1;
        sy = src[1] - '0';

        dx = dest[0] - 'a' + 1;
        dy = dest[1] - '0';

        //deb(sx) deb(sy) deb(dx) debln(dy)

        memset(cell,0,sizeof(cell));
        int ans = bfs(sx,sy,dx,dy);

        printf("To get from ");
        cout<<src;
        cout<< " to ";
        cout<<dest;
        printf(" takes %d knight moves.\n",ans);
    }

    return 0;
}

