#include <bits/stdc++.h>
using namespace std;
struct job{
	int no;
	int profit;
	int dead;
};
bool comp(job a,job b){
	return (a.profit>b.profit);
}
void jobseq(struct job J[],int n){
	int final[n],ref[n];
	for (int i = 0; i < n; i += 1)
	{
		ref[i]=0;
	}
	for (int i = 0; i < n; i += 1)
	{
		for (int j = J[i].dead-1; j >= 0; j -= 1)
		{
			if (ref[j]==0)
			{
				final[j]=i;
				ref[j]=1;
				break;
			}
		}
	}
	int sum=0;
	for (int i = 0; i < n; i += 1)
	{
		if(ref[i])
		{
			cout<<J[final[i]].no<<"\t";
		 	sum = sum + J[final[i]].profit;	
		}
	}
	cout<<"\nTotal max. profit is :"<<sum;
	
}
int main (int argc, char const* argv[])
{
	int n;
	cout<<"Enter no. of jobs :";
	cin>>n;
	job J[n];
	
	for (int i = 0; i < n; i += 1)
	{
        J[i].no=i+1;
		cout<<"Enter profit, deadline of job "<<i+1<<" :";
		cin>>J[i].profit>>J[i].dead;
	}
	sort(J,J+n,comp);
	jobseq(J,n);
	return 0;
}

