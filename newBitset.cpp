#include <bits/stdc++.h>
using namespace std;

const int NMAX = (int)1e6;
bitset<NMAX / 2> bits;

void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;

        bits.set();
        auto sum = 2LL;
        int cnt = 1;

        if(n<2)
            continue;

        cout<<2<<endl;

        for (int i = 3; i / 2 < bits.size(); i = 2 * bits._Find_next(i / 2) + 1)
        {
            //sum += i;
            if(i>n)
                break;
            cout<<i<<endl;

            for (auto j = (int64_t) i * i / 2; j < bits.size(); j += i)
            {
                bits[j] = 0;
                if(j>n)
                    break;
            }
        }

        //cout << "sum = " << sum << endl;
        //cout << "cnt = " << cnt << endl;
        //time();
    }
    return 0;
}
