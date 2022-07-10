/*
Please Chant The Holy Name Of Lord Krisna(The Supreme Personality Of Godhead)

      "Hare Krisna Hare Krisna Krisna Krisna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself to the Lotus Feet of Krisna, serve devotees and Srila Prabhupada
*/

//29-8-20
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define pb emplace_back
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define fr(i,n)                           for(int i=0;i<n;i++)
#define fr1(i,n)                          for(int i=1;i<=n;i++)
#define fro(i,a,b)                        for(int i=a;i<=b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)

using namespace std;

const int N   = 2e3 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j;

vector<int>graph[N];
int node,edge;
int src;
bool vis[N];
vector<int>dis(N),color(N),parent(N);

void bfs(int src)
{
    queue<int>q;
    vis[src] = true;

    q.push(src);
    parent[src] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : graph[v])
        {
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);

                dis[v] = dis[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (!vis[u])
    {
        cout << "No path!";
    }
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}

void solve()
{

}

int32_t main()
{
    //IOS;

    //TEST
    solve();

    return 0;
}


