#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

long Catalan_Numbers(int n)
{
    int i,j;
    long bc[MAXN][MAXN];

    for(i=0; i<=2*n; i++)
        bc[i][0] = 1;
    for(j=0; j<=2*n; j++)
        bc[j][j] = 1;
    for(i=1; i<=2*n; i++)
        for(j=1; j<i; j++)
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];

    return bc[2*n][n]/(n+1);
}

int main()
{
    cout<<Catalan_Numbers(5)<<endl;
    return 0;
}

