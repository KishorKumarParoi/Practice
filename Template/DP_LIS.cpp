#include<bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_Value -1

int mem[MAX_N];
int f(int i,vector<int>&A)
{
    if(mem[i]!=EMPTY_Value)
        return mem[i];

    int ans = 0;
    for(int j= i+1 ;j<A.size();++j)
    {
        if(A[j]>A[i])
            ans = max(ans,f(j,A));
    }

    mem[i] = ans + 1;
    return mem[i];
}

int findLIS(vector<int>&A)
{
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        mem[i] = EMPTY_Value;
    }

    for (int i = 0; i < A.size(); ++i)
    {
        ans = max(ans,f(i,A));
    }

    return ans;
}

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    vector<int>A(n);

    for (int i = 0; i < n; ++i)
        cin>>A[i];

    cout<<findLIS(A)<<endl;
}