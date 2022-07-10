
/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//17-04-21
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(NULL); cin.tie(nullptr);
#define endl "\n"
#define int long long
#define pb emplace_back
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define fr(i,n)                           for(int i=0;i<n;i++)
#define fr1(i,n)                          for(int i=1;i<=n;i++)
#define fro(i,a,b)                        for(int i=a;i<=b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)

using namespace std;

const int N   = 2e5 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j,a,b,c,d;
int kase = 1;
int dp[100][100];
int row,col;

void kkp()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}

int kadane(int *arr,int *start,int *finish,int n)
{
    int sum = 0,maxSum = INT_MIN,i;

    *finish = -1;
    int local_start = 0;

    for(i=0; i<n; ++i)
    {
        sum += arr[i];
        if(sum<0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if(sum>maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if(*finish!=-1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaximumSum()
{
    int maxSum = INT_MIN,finalLeft = 0,finalRight = 0,finalTop = 0,
        finalBottom = 0;

    int left,right,i;
    int temp[row],sum = 0,start = 0,finish = 0;

    for(left = 0; left<col; ++left)
    {
        memset(temp,0,sizeof(temp));
        for(right = left; right<col; ++right)
        {
            for(i=0; i<row; ++i)
                temp[i] += dp[i][right];

            sum = kadane(temp,&start,&finish,row);

            if(sum>maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    cout<< maxSum<<endl;

    cout<< finalTop<< " "<<finalBottom<< " "<<finalLeft<< " "<<finalRight<<endl;
}

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    cin>>row>>col;
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            cin>>dp[i][j];
    }

    findMaximumSum();
}

int32_t main()
{
    //kkp();
    //IOS;

    //TEST
    solve();

    return 0;
}



