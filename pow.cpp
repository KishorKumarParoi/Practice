int pow(int a,int b,int m)
{
    a%=m;
    int ans = 1;

    while(b>0)
    {
        if(b&1)
            ans = (ans*a) % m;
        a = (a*a)%m;
        b>>=1;
    }
    return ans;
}

ll Pow(int base, int exp)
{
    if(exp == 0)
        return 1;
    if(exp == 1)
        return base;
    ll sub = Pow(base, exp/2);
    return (((sub*sub)%MOD)*(exp%2 ? base : 1))%MOD;
}