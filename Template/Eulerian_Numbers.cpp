#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

long Eulerian_Number(int n,int k)
{
    int i,j;
    long en[MAXN][MAXN];

    for(i=0; i<=n; i++)
        en[i][0] = 1;
    for(j=0; j<=n; j++)
        en[0][j] = 0;
    for(i=1; i<=n; i++)
        for(j=1; j<i; j++)
            en[i][j] = k*en[i-1][j] + (i-j+1)*en[i-1][j-1];

    return en[n][k];
}

int main()
{
    cout<<Eulerian_Number(3,2)<<endl;
    return 0;
}
