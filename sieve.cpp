
/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//25-02-20
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(NULL); cin.tie(nullptr);
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

const int N   = 2e5 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j;
int kase = 1;

int prime[300000],nPrime;
int mark[1000002];

void sieve(int n)
{
    int i,j, limit = sqrt(n*1.0) + 2;
    mark[1] = 1;

    for(i=4; i<=n; i+=2)
        mark[i] = 1;

    prime[nPrime++] = 2;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nPrime++] = i;
            if(i<=limit)
            {
                for(j= i*i; j<=n; j+=i*2)
                    mark[j] = 1;
            }
        }
    }
}

vector<int>primes;
bool marked[90000007];
void ssieve(int n)
{
    int i,j, limit = sqrt(n*1.0) + 2;
    mark[1] = 1;

    for(i=4; i<=n; i+=2)
        mark[i] = 1;

    primes.pb(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            primes.pb(i);
            if(i<=limit)
            {
                for(j= i*i; j<=n; j+=i*2)
                    mark[j] = 1;
            }
        }
    }

    //print(primes);
}

void vsieve(int n)
{
    int i,j,limit = sqrt(1.0*n) + 2;
    vector<bool>mark(limit+1,false);

    vector<int>primes;
    for(int i=2; i<=limit; ++i)
    {
        if(!mark[i])
        {
            primes.pb(i);
            for(int j = i*i; j<=limit; j+=i)
                mark[j] = 1;
        }
    }

    print(primes)
}

void segSieve(int L,int R)
{
    int i,j,limit = sqrt(1.0*R) + 2;
    vector<bool>mark(limit+1,false);

    vector<int>primes;
    for(int i=2; i<=limit; ++i)
    {
        if(!mark[i])
        {
            primes.pb(i);
            for(int j = i*i; j<=limit; j+=i)
                mark[j] = 1;
        }
    }

    print(primes)

    vector<bool>isPrime(R-L+1,true);
    for(int i : primes)
    {
        for(int j = max(i*i,(L+i-1)/i*i); j<=R; j+=i)
            isPrime[j-L] = false;
    }

    if(L==1)
        isPrime[0] = false;

    for(int i=L; i<=R; ++i)
        if(isPrime[i])
        {
            cout<<i<< " "<<isPrime[i-L]<<endl;
        }

}

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    //segSieve(10,100);
    vsieve(1e4);
}

int32_t main()
{
    //kkp();
    //IOS;

    //TEST
    solve();
    //time();

    return 0;
}


