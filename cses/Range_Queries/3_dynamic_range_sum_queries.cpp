#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int B=500;
void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
}
int main()
{
	file_i_o();
	int n,q;
	cin>>n>>q;
	vector<int> arr(N,0);
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	vector<ll> SM(600,0);
	for(int i=1;i<=n;i++)
		SM[i/500]+=arr[i];
	ll sum=0;
	while(q--)
	{
		int p;
		cin>>p;
		if(p==1)
		{
			int k,u;
			cin>>k>>u;
			SM[k/500]=SM[k/500]-arr[k];
			arr[k]=u;
			SM[k/500]=SM[k/500]+arr[k];
		}
		else 
		{
			int l,r;
			cin>>l>>r;
			int b1=l/500;
			int b2=r/500;
			sum=0;
			for(int i=l;i<=r;i++)
			{
				if(i/500==b1 || i/500==b2)
				{
					// cout<<arr[i]<<endl;
					sum+=arr[i];
				}
				else 
				{
					sum+=SM[i/500];
					i=i+499;  // i=499+1  will be incremented in for loop.
				}
			}
			cout<<sum<<endl;
		}
		
	}
}