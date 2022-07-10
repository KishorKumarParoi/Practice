/*
Please Chant The Holy Name Of Lord Krisna(The Supreme Personality Of Godhead)

      "Hare Krisna Hare Krisna Krisna Krisna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself to the Lotus Feet of Krisna, serve devotees and Srila Prabhupada
*/
//14-9-20
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

const int N = 1e6 + 5;
bitset<N>isPrime;
int prime[N];
int kase = 1;
int p = 0;

void Sieve()
{
    for(int i=2; i<=N; ++i)
    {
        if(isPrime[i]==0)
        {
            for(int j = i+i; j<=N; j+=i)
                isPrime[j] = 1;
        }
    }

    for(int i=2; i<=N; ++i)
    {
        if(isPrime[i]==0)
            prime[p++] = i;
    }

    // for(int i=0; i<p; ++i)
    // cout<<prime[i] << " ";
    //cout<<endl;
}




const int N = 1e6 + 5;
int largest_prime_factor[N+5];  // = {0}
int distinct_prime_factor[N+5] = {0} ;
vector<int>primes;
vector<pair<int,int> > prime_factors[N+5];

// prime_factors[45] = vector({3,2}, {5,1}) = 3^2 * 5^1

void Sieve()
{
    for(int i=2; i<=N; ++i)
    {
        if(largest_prime_factor[i]!=0)
            continue;
        largest_prime_factor[i] = i;

        primes.push_back(i);
        for(int j = i+i; j<=N; j+=i)
            largest_prime_factor[j] = i;
    }


    for(int i=2; i<=N; ++i)
    {
        int x = i;
        map<int,int>M;

        while(x!=1)
        {
            M[largest_prime_factor[x]]++;
            x/=largest_prime_factor[x];
        }

        distinct_prime_factor[i] = M.size();
        for(auto v : M)
            prime_factors[i].push_back(v);
    }
}

int32_t main()
{
    //IOS;

    Sieve();

    return 0;
}

