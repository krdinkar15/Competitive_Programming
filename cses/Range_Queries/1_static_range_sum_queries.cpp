#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
}
int main()
{
	file_i_o();
	int n,q;
	cin>>n>>q;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)	
		cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--,r--;
		if(l==0)
			cout<<arr[r]<<endl;
		else 
			cout<<arr[r]-arr[l-1]<<endl;
	}
 
}