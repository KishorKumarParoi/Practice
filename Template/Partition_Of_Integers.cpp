#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

long int_coefficient(int n,int k)
{
    int i,j;
    long f[MAXN][MAXN];

    f[1][1] = 1;
    for(i=0; i<=n; i++)
        f[i][0] = 0;
    for(i=1; i<=n; i++)
        for(j=1; j<i; j++)
            if(i-j<=0)
                f[i][j] = f[i][k-1] ;
            else
                f[i][j] = f[i-j][k] + f[i][k-1];

    return f[n][k];

}
int main()
{

    cout<<int_coefficient(5,3)<<endl;
    return 0;
}
