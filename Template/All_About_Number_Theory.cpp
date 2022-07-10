//20/12/19

#include<bits/stdc++.h>
#define MX 1000009    //sqrt(10^12)=10^6   n can be maximum MX or 10^6 :D
#define pb push_back
#define ll long long
#define U unsigned int

using namespace std;

// Sieve Of Eratosthenes

const U mx = 1000009;
vector<U>primes;
U pr[mx];
bool prime[mx];

void sieve()
{
    U i,j;
    memset(prime,true,sizeof(prime));

    prime[0]=prime[1]=false;

    for( i=4; i<=mx; i+=2)
        prime[i]=false;

    for( i=3; i*i<=mx; i+=2)
    {
        if(prime[i]==true)
        {
            for(j=i*i ; j<=mx ; j+=(i<<1) )
            {
                prime[j]=false;
            }
        }
    }


    for(i=2; i<=mx; i++)
    {

        if(prime[i])
            primes.pb(i);
    }
    /*
     pr[2]=1;

     for(i=3; i<=mx; i+=2)
     {
         if(prime[i])
         {
             pr[i+1]=pr[i]=pr[i-1]+1;
         }
         else
         {
             pr[i+1]=pr[i]=pr[i-1];
         }
     }

    */

   // print(primes);

}
// Memory Efficient Sieve Aka BITSIEVE

#define mx 100000000
int marked[mx/64+2];

#define on(x)         (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)      marked[x/64]!= (1<<((x%64)/2))

void BITSIEVE(int n)
{

    {
        for (int i = 3; i * i < n; i += 2)
        {
            if (!on(i))
            {
                for (int j = i * i; j <= n; j += i + i)
                {
                    mark(j);
                }
            }
        }
    }

}

bool isPrime(int num)
{
    return (num>1) && (num==2   || ((num & 1)  && !on(num)) );
}


/*--------------Bitwise Sieve------------*/

#define M (U) 1009
bool Check(U N,U pos)
{
    return (bool)(N & (1<<pos));
}
U Set(U N,U pos)
{
    return N= N|(1<<pos);
}

vector<U>PRIMES;
U status[(M/32)+2];

void BITSieve()
{
    U i, j;

    for( i = 3; i * i <= M; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= M; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }

    PRIMES.push_back(2);
    for(i=3; i<=M; i+=2)
        if( Check(status[i>>5],i&31)==0)
        {
            PRIMES.push_back(i);
        }

}

U optimizedDivisor(U n )
{
    U divisor = 1;
    U  x = PRIMES.size(),k=0;

    for (U i = PRIMES[k]; i*i <= n && k<x ; i=PRIMES[++k])
    {
            U cnt = 1;
            while (n % PRIMES[i] == 0)
            {
                n /= PRIMES[i];
                cnt++;
            }
            divisor *= cnt;
    }

	if(n!=1)
	divisor*=2;

    return divisor;
}

void primeFactorization(U n)
{
    U x= PRIMES.size();

    for(U i=0; i<x; i++)
    {
        while(n%PRIMES[i]==0)
        {
            n/=PRIMES[i];
            cout<<PRIMES[i]<<endl;
        }
        if(n==1)
            break;
    }
    if(n!=1)
        cout<<endl;

}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

/*
int phi (int n)
{
    int ret = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ret -= ret / i;
        }
    }
    // this case wiint happen if n is a prime number
    // in that case we won't find any prime that divides n
    // that's less or equal to sqrt(n)
    if (n > 1)
        ret -= ret / n;
    return ret;
}

*/

#define MM 1000005
int phi[MM];

void calculatePhi()
{
    for (int i = 1; i < MM; i++)
    {
        phi[i] = i;
    }
    for (int p = 2; p < MM; p++)
    {
        if (phi[p] == p)   // p is a prime
        {
            for (int k = p; k < MM; k += p)
            {
                phi[k] -= phi[k] / p;
            }
        }
    }
}


int bigmod(int a,int b,int c)
{
    if(b==0)
        return 1;
    else if(b%2==0)
    {
        int value = bigmod(a,b/2,c);
        return (value*value)%c;
    }
    else
    {
        int x,y;
        x=a%c;
        y=bigmod(a,b-1,c);
        return (x*y)%c;
    }
}


typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclid(int a, int b)   // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

int modularInverse(int a, int n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

main()
{

    // sieve(M);
    // print(primes);

    BITSieve();

    // BITSIEVE(100000);
    // cout<<isPrime(10007)<<endl;

    // primeFactorization(138);

    cout<< optimizedDivisor(12)<<endl;

    return 0;
}
