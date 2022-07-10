//25-09-19 2.10pm
#include<bits/stdc++.h>
using namespace std;

vector<int>arr;
//int arr[1000009];

int lowerBound(int Q,int n)
{
    int lo=0,hi=n-1,mid;
    int ans=-1;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]>=Q)
        {
            if(arr[mid]==Q)
                ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    return ans;
}


int upperBound(int Q,int n)
{
    int lo=0,hi=n-1,mid;
    int ans=-1;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]<=Q)
        {
            if(arr[mid]==Q)
                ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    return ans;
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    arr.clear();
    //memset(arr,0,sizeof(arr));
    for(int i=0; i<n; i++)
    {
        int x;
        //scanf("%d",&arr[i]);
        scanf("%d",&x);
        arr.push_back(x);
    }
    while(q--)
    {
        int Q;
        scanf("%d",&Q);
        //cin>>Q;
        printf("%d\n",lowerBound(Q,n));
        printf("%d\n",upperBound(Q,n));
        //cout<<upperBound(Q,n)<<endl;
    }
}
