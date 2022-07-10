
// Problem : Prime Generator
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/PRIME1/
// Memory Limit : 1536.000000MB 
// Time Limit : 6000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)


/*

Rationalizing everything, avoiding unpleasant things
That kind of life is empty, isn't it?

If we didn't meet here by chance back then
Without even knowing what it means to live

Whatever path you master, it doesn't happen in a single day
Hold that ideal image in your heart
Don't chatter, don't look aside...

But when you're about to cry, when you want to throw everything down
When you're about to lose to your weak self
Put that kind of you in a birdcage
And throw it into a ravine!

And then, for the sake of the guys who believe in you more than anyone
For the sake of your beliefs
You'll be able to get strong. Break through it.

Are you getting closer bit by bit to your ideals, your dreams?
If you can't see it with your eyes, you're uneasy

During your long life, it's okay to stumble, or to stop dead
Hold those words in your heart
And sometimes take a big look at the sky

If you don't understand, if you can't do anything
Sometimes it's okay to give yourself up
If you're at your wits' end like that
Don't shed any tears!

And once you've reached the bottom of your worries, when you're ready to give up
A new path will open up suddenly
You can become strong. You have the courage.

"I love it." "I don't want to give up."
You said even when you were completely worn out
Don't ever let go
Of that strong, wonderful heart!

But when you're about to cry, when you want to throw everything down
When you're about to lose to your weak self
Put that kind of you in a birdcage
And throw it into a ravine!

And then, for the sake of the guys who believe in you more than anyone
For the sake of your beliefs
You'll be able to get strong. Break through it.

*/

//21-12-19
#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ll long long
#define mx 1000009  //sqrt(10^12)=10^6
vector<ll>primes;
ll i,j,k;
void Sieve_Of_Eratosthenas()
{
    bool flag[mx+1];
    memset(flag,true,sizeof(flag));  //soba age true kore nilam
    flag[0]=flag[1]=false;       // 0,1 prime na so false kore dilam
    primes.eb(2);     //2 k push korlqm


    for(i=4; i<=mx; i+=2)
        flag[i]=false;                                   //sokkol even number k false kore dilam

    for(i=3; i<=mx; i+=2)
    {
        if(flag[i]==true)                             //checkinng a number is prime or not                //pushing the prime number
        {
            primes.eb(i);                            //pushing prime number
            for(j=i+i; j<=mx; j+=i)              //prime number er multiple gula k false kore diyechi
                flag[j]=false;
        }
    }
}

void SegmentedSieve(ll L,ll R)
{
    bool isPrime[R-L+1];
    memset(isPrime,true,sizeof(isPrime));                  //true kore dilam initialize

    if(L==1)
        isPrime[0]=false;                                      //j-l=1-1=0

    for(i=0; primes[i]*primes[i]<=R; i++)
    {
        ll currprime=primes[i];                                //2 theke kata shuru korlam
        ll base=currprime*currprime;                       //4,6,8 esb agei kata hoye geche Sieve calanor somoy

        if(base<L)
            base=((L-1+currprime)/currprime)*currprime;             //(21-1+3)/3=7*3=21

        for(j=base; j<=R; j+=currprime)
            isPrime[j-L]=false;                                                    //31-29=2 no. index
    }
    for(i=0; i<=R-L; i++)
    {
        if(isPrime[i]==true)
            cout<<L+i<<" ";                     //2+29=31
    }
    cout<<endl;
}

int main()
{
    Sieve_Of_Eratosthenas();
    ll t,L,R;
    cin>>t;
    while(t--)
    {
        cin>>L>>R;
        SegmentedSieve(L,R);
    }
    return 0;
}
n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve()
{
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    for(i=3, j=0; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
int segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2)
        return 0;
    if(a<3)
        a = 3;
    if(a%2==0)
        a++;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0)
            j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segment, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment, i))
            cnt++;
    return cnt;
}

using namespace std;

int main()
{
    //open
    //close
    //fastio

    int t;
    scl(t);

    while(t--)
    {

        int l,r;
        scl(l);
        scl(r);

        printf("%d\n",segmented_sieve(l,r));
    }

    return 0;
}





