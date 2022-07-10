#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void wait(){
	for(ll i=1;i<=1e9;i++);
}

int main()
{
	freopen("output.txt","a",stdout);
	freopen("input.txt","r",stdin);

	ll n;
	cin>>n;

	ll x_plus_y,y_plus_z,z_plus_x,x,y,z;

	cout<<"? "<<1<<" "<<2<<endl;
	wait();
	cin>>x_plus_y;

	cout<<"? "<<2<<" "<<3<<endl;
	wait();
	cin>>y_plus_z;

	cout<<"? "<<3<<" "<<1<<endl;
	wait();
	cin>>z_plus_x;

	x=(x_plus_y-y_plus_z+z_plus_x)/2;
	y=x_plus_y-x;
	z=y_plus_z-y;

	vector<ll> ans;
	ans.pb(x);
	ans.pb(y);
	ans.pb(z);

	for(ll i=4;i<=n;i++){
		ll sum;
		cout<<"? "<<3<<" "<<i<<endl;
		wait();
		cin>>sum;
		ans.pb(sum-z);
	}

	cout<<"!";
	for(ll i=0;i<n;i++) cout<<" "<<ans[i];cout<<endl;
	wait();

	string s;
	cin>>s;

	return 0;
}