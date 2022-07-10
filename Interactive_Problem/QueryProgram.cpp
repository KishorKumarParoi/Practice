#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[21];

ll query_sum(ll i,ll j){
	return arr[i]+arr[j];
}

void wait(){
	for(ll i=1;i<=1e9;i++);
}

int main()
{
	freopen("output.txt","r",stdin);
	freopen("input.txt","a",stdout);
	ll n;
	n=rand()%18+3;
	cout<<n<<endl;

	for(ll i=1;i<=n;i++) arr[i]=rand()%100+1;
	wait();

	for(ll i=1;i<=n;i++){
		char s;
		ll p,q;
		cin>>s;
		if(s=='!') goto read;
		cin>>p>>q;
		if(p==q || s!='?'){
			cout<<"Invalid Query"<<endl;
			return 0;
		}
		cout<<query_sum(p,q)<<endl;
		wait();
	}

	char s;
	cin>>s;
	if(s=='?'){
		cout<<"Query Limit Exceeded"<<endl;
		return 0;
	}
	if(s!='!'){
		cout<<"Invalid Input"<<endl;
		return 0;
	}
	read:
	ll ok=0;

	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;

		if(x!=arr[i]) ok=1;
	}

	if(ok) cout<<"Incorrect"<<endl;
	else cout<<"Correct"<<endl;

	return 0;
}