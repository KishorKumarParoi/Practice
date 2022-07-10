
/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//06-04-21
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

// MillerRobin Primality tests starts from here

int multiply(int a,int b,int m)
{
    a%=m;
    int res = 0;

    while(b)
    {
        if(b&1)
        {
            res += a;
            res%=m;
        }

        a+=a;
        a%=m;
        b>>=1;
    }

    return res%m;
}

int binpow(int a,int b,int m)
{
    int res = 1;
    b%=m;

    while(b>0)
    {
        if(b&1)
            res = multiply(res,a,m);
        a = multiply(a,a,m);
        b>>=1;
    }

    return res%m;
}

bool testComposite(int a,int d,int n,int r)
{
    int val = binpow(a,d,n);

    if(val==1 || val==n-1)
        return false;

    for(int i=1; i<r; ++i)
    {
        val = multiply(val,val,n);
        if(val==n-1)
            return false;
    }

    return true;
}

bool MillerRobin(int p)
{
    int r = 0,n = p,d = 0;;

    if(p<2)
        return false;
    if(!(p&1) && p>2)
        return false;

    n--;

    while(!(n&1))
    {
        n = n>>1;
        r++;
    }

    d = n;
    int smalbase[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

    for(int i=0; i<12; ++i)
    {
        if(smalbase[i]==p)
            return true;
        if(testComposite(smalbase[i],d,p,r))
            return false;
    }

    return true;
}

vector<int>primes;
bool mark[90000007];
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

void totdiv(int x)
{
    int cnt = 1;
    int t = x;

    for(int i=0; i<primes[i]*primes[i]*primes[i]; ++i)
    {

        if((t)%primes[i]==0)
        {
            int kkp = 1;
            while((t)%primes[i]==0)
            {
                t/=primes[i];
                kkp++;
            }

            cnt*=kkp;
        }
        if(t==1)
            break;
    }

    if(t>1)
    {
        int rt = sqrt(t);
        if(rt*rt==t)
            cnt*=3;
        else if(MillerRobin(t))
            cnt*=2;
        else
            cnt*=4;
    }

    cout<<cnt<<endl;
}

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    int t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(MillerRobin(x))
            cout<< "YES"<<endl;
        else
            cout<< "NO"<<endl;
    }
}

int32_t main()
{
    //kkp();
    IOS;

    ssieve(1e7);
    //TEST
    solve();

    return 0;
}



