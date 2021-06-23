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
	vector<int> arr(N);
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	vector<int> MNM(600);
	int minm=arr[1];
	int j=1;
	for(int i=0;j<200005;i++)
	{
		minm=arr[j];
		int times=500;
		while(times--)
		{
			minm=min(minm,arr[j++]);
		}
		MNM[i]=minm;	
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int b1=l/500;
		int b2=r/500;
		minm=INT_MAX;
		for(int i=l;i<=r;i++)
		{
			if(i/500==b1 || i/500==b2)
			{
				minm=min(minm,arr[i]);
			}
			else 
			{
				minm=min(minm,MNM[i/500]);
				i=i+499;  // +1 will be incremented in for loop.
			}
		}
		cout<<minm<<endl;
	}
}