
/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//13-03-21
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(NULL); cin.tie(nullptr);
#define endl "\n"
#define int long long
#define pb emplace_back
#define sz(s) (int)s.size()
#define pii                               pair<int,int>
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

const int N   = 2e5 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j,a,b,c,d;
int kase = 1;

void kkp()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif 
}

vector<pii>v;

bool cmp(pii A,pii B)
{
    return A.second*B.first > A.first*B.second;
}

void Frac_Knapsack()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    int n,w;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        int weight,price;
        cin>>weight>>price;

        v.pb(pii(weight,price));
    }

    sort(all(v),cmp);

    cin>>w;
    int ans = 0;

    for(int i=0;i<n;++i)
    {
        int z = min(w,v[i].first);
        w-=z;
        ans += z*v[i].first;
    }

    printf("Maximum Cost : %d\n",ans );
}

int32_t main()
{
    kkp();
    IOS;

    //TEST
    solve();

    return 0;
}


