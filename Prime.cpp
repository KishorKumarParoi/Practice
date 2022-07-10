/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//11-01-22
#include <bits/stdc++.h>

#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define vi vector<int>
#define int long long
#define pb emplace_back
#define err 1e-8
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define fr(i,a,b)                         for(int i=a;i<b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)
#define printArr(a,b,arr)                 for(int i=a;i<b;++i) { cout<<arr[i]<< " ";} cout<<endl;
using namespace std;

const int N   = 2e6 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j,a,b,c,d;
int kase = 1;

void kkp()
{
//#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//#endif
}
void time()
{
//#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
//#endif
}

map<int,bool>primes;

void generate_prime()
{
    int n = 1e6+7;
    vector<bool>is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i=4; i<=n; i+=2)
        is_prime[i] = false;

    primes[2] = true;

    for(int i=3; i<=n; i+=2)
    {
        if(is_prime[i])
        {
            primes[i] = true;
            for(int j = i*i; j<=n; j+=2*i)
                is_prime[j] = false;
        }
    }

    //print(st)
    //PRINT(primes);
    //dl(sz(primes))
}
//
//void divisors(int val)
//{
//    int k = 0,divCnt = 1,ssize = sz(primes);
//
//    for(int j = primes[k]; j*j<=val && k<ssize; j = primes[++k])
//    {
//        int kkp = 1;
//        while(val%j==0)
//        {
//            val/=j;
//            kkp++;
//        }
//
//        divCnt*=kkp;
//    }
//
//    if(val!=1)
//        divCnt*=2;
//
//}


void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    generate_prime();

    int n;
    cin>>n;

    if(!primes[n])
        cout<< "NO" <<endl;
    else
        cout<< "YES" <<endl;
}

int32_t main()
{
    //kkp();
    ios_base::sync_with_stdio(!cin.tie(0));

    //TEST
    solve();

    return 0;
}



