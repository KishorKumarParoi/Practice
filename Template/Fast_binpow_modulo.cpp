#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll bipow(ll a,ll b,ll m)
{
    a%=m;
    ll res = 1;

    while(b>0)
    {
        if(b&1)
            res = (res *a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return res;
}

ll FastMultiply(ll a,ll b,ll m)
{
    ll res = 0;
    a%=m;

    while(b>0)
    {
        if(b&1)
            res = (res+a)%m;
        a = (a<<1)%m;
        b>>=1;
    }

    return res;
}

int main()
{
    ll a,b,m;

    while(cin>>a>>b>>m)
    {
        cout<<bipow(a,b,m)<<endl;
        cout<<FastMultiply(a,b,m)<<endl;
    }

    return 0;
}
