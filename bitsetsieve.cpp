#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

const int NMAX = (int)1e8;
bitset<NMAX> bits;
void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif 
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    bits.set();
    bits[0] = bits[1] = 0;

    for (int i = 2; i*i <= NMAX; i++) {
        if (bits[i]) {
            for (int j = i * i; j <= NMAX; j += i) bits[j] = 0;
        }

}
    //iterate over primes
int64_t sum(0);
int cnt(0);
for (int p = bits._Find_first(); p < bits.size(); p = bits._Find_next(p)) {
    sum += p;
    cnt++;

   // cout<<p<< " ";    
}

assert(bits.count() == cnt);
std::cout << "sum = " << sum << std::endl;
std::cout << "cnt = " << cnt << std::endl;

time();
return 0;
}