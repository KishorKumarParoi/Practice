/*
One Day You will become RED Coder Kishore;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//09-02-22
#include <bits/stdc++.h>

#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define pb emplace_back
#define err 1e-8
#define sz(s) (int)s.size()
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) !!(x & (1LL << k))
#define all(v)                            v.begin(),v.end()
#define fr(i,a,b)                         for(int i=a;i<b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)
#define printArr(a,b,arr)                 for(int i=a;i<b;++i) { cout<<arr[i]<< " ";} cout<<endl;
#define yes                               cout<< "Yes"<<endl
#define no                                cout<< "No"<<endl
using namespace std;

void kkp()
{
//#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//#endif
}

void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}

const int N   = 1e6 + 5;
const int MOD = 1e9 + 7;
//int ar[N],br[N];

string convert_base(int n,int base)
{
    if(n==0)
        return "0";

    int power = 1;
    while(power*base<=n) power*=base;
    string result;

    while(n>0)
    {
        int k = n/power;
        result += k + '0';

        n-= power*k;
        power/=base;
        d(power) d(k) dl(result)
    }

    return result;
}

int convert_to_decimal(string s,int base)
{
    int n = 0,power = 1;

    for(int i=sz(s)-1; i>=0; i--)
        n += power*(s[i]-'0'), power*=base;

    return n;
}

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    cout<<convert_base(10,2)<<endl;
}

int32_t main()
{
    //kkp();
    ios_base::sync_with_stdio(!cin.tie(0));

    //TEST
    solve();

    return 0;
}



