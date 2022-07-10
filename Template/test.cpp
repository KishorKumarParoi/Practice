#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, t_case;

ll bigmod(ll b, ll p, ll m)
{
    if(p==0)
        return 1;
    ll xx=bigmod(b, p/2, 1000);
    xx=(xx*xx)%1000;
    if(p%2==1)
        xx=(xx*b)%1000;
    return xx;
}

int main()
{

    cin>>t_case;
    while(t_case)
    {
        cin>>n>>k;

        /* executing first 3 digits */
        double x=k*(log10(n));
        x=x-(int)x;              // taking fraction value only
        double ans=pow(10, x);
        ans=ans*100;
        cout<<(int)ans<<"...";

        /* executing last 3 digits */
        printf("%03d\n", bigmod(n, k, 1000));
        t_case--;
    }
    return 0;
}
