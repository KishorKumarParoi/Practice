#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll bigmod(ll a,ll b,ll c)
{
    if(b==0)
        return 1;
    else if(b%2==0)
    {
        ll value = bigmod(a,b/2,c);
        return (value*value)%c;
    }
    else
    {
        ll x,y;
        x=a%c;
        y=bigmod(a,b-1,c);
        return (x*y)%c;
    }
}

int main()
{

    return 0;
}
