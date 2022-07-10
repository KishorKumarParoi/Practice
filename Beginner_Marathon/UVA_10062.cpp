//26-7-20
#pragma GCC optimize ("-O2")
#define _CRT_SECURE_NO_WARNINGS 1

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define scu(n)                            scanf("%u",&n)
#define scl(n)                            scanf("%d",&n)
#define scll(n)                           scanf("%lld",&n)
#define sz(a)                             (int)a.size()
#define maxN                              10000005
#define uu                                first
#define vv                                second
#define ll                                long long
#define U                                 unsigned
#define pb                                emplace_back
#define pf                                emplace_front
#define mp                                make_pair
#define pii                               pair<int,int>
#define vi                                vector<int>
#define mii                               map<int,int>
#define Pi                                acos(-1.0)
#define endl                              "\n"
#define isOn(S, j)                        (S & (1 << j))
#define setBit(S, j)                      (S |= (1 << j))
#define clearBit(S, j)                    (S &= ~(1 << j))
#define toggleBit(S, j)                   (S ^= (1 << j))
#define lowBit(S)                         (S & (-S))
#define setAll(S, n)                      (S = (1 << n) - 1)
#define isPowerOfTwo(S)                   (!(S & (S - 1)))
#define nearestPowerOfTwo(S)              ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)                 ((S) & (S - 1))
#define turnOnLastZero(S)                 ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S)     ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S)    ((S) | (S - 1))
#define _fastio                              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod                               1000000007
#define inf                               1e18
#define EPS                               1e-9
#define ps(x,y)                           fixed<<setprecision(y)<<x
#define mk(arr,n,type)                    type *arr=new type[n];
#define TEST                              int tc;cin>>tc; while(tc--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//Vector Macros
#define ALL(v)                            v.begin(),v.end()
#define UNIQUE(v)                         v.erase(unique(ALL(v)),v.end())
#define MIN(c)                            *min_element(ALL(c))
#define MAX(c)                            *max_element(ALL(c))
#define SUM(c)                            accumulate(ALL(c),0)

//Loop Macros
#define For(i,a,b)                        for(ll i=a;i<=b;i++)
#define rep(i,a,b)                        for(int i=a;i<=b;i++)
#define fr(i,n)                           for(int i=0;i<n;i++)

//Debug Macros
#define open                              freopen("input.txt","r",stdin);
#define close                             freopen("output.txt","w",stdout);
#define deb(a)                            cout << #a << " : " << a << " ";
#define debln(a)                          cout<< #a <<" : " << a << endl;
//Print Macros
#define print(v)  for(auto x : v)         {  cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         { cout<<x.uu<<" "<<x.vv<<endl;}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

struct node
{
    int ascii;
    int freq;
} arr[128];

bool com(node a,node b)
{
    if(a.freq==b.freq)
        return a.ascii > b.ascii;
    return a.freq < b.freq;
}


int main()
{
    //_fastio

    char c[10010];
    int id = 0;
    while(gets(c))
    {
        if(id!=0)
            cout<<endl;

        for(int i=0; i<128; ++i)
        {
            arr[i].ascii = 0;
            arr[i].freq = 0;
        }

        for(int i=0; i<strlen(c); ++i)
        {
            int m = (int)c[i];
            arr[m].ascii = m;
            arr[m].freq++;
        }

        sort(arr,arr+128,com);

        for(int i = 32; i<128; ++i)
        {
            if(arr[i].freq>0)
            {
                cout<< arr[i].ascii<< " " << arr[i].freq<<endl;
            }
        }
        id = 1;
    }

    return 0;
}

