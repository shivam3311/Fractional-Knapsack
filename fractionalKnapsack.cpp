#include<iostream>
using namespace std;
void order(int n, int *prof, int *ratio, int *weight)
{
	int i,temp,temp1;
	for(i=0;i<n-1;i++)
	{
		if(ratio[i]<ratio[i+1])
		{
			temp = prof[i];   temp1=weight[i];
			prof[i] = prof[i+1]; weight[i]=weight[i+1];
			prof[i+1] = temp; weight[i+1] = temp1;
		} 
	}
}
int main()
{
	int n,cap,i;
	cout<<"Enter number of objects: ";
	cin>>n;
	int prof[n], weight[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter profit and weight: ";
		cin>>prof[i];
		cin>>weight[i];
	}
	cout<<"Enter maximum capacity: ";
	cin>>cap;	
	int ratio[n];
	for(i=0;i<n;i++)
	{
		ratio[i] = (int)prof[i]/weight[i];
	}
	order(n, prof, ratio, weight);
	int k = 0;
	int max_prof = 0;
	while(k<n && cap != 0)
	{
		if(weight[k] < cap)
		{
		   max_prof += prof[k];
		   cap -= weight[k]; 	
		} 
		else
		{ 
		   max_prof += prof[k] * ((double) cap / weight[k]);			
		}
		k++;
	}	
	cout<<"Maximum profit is: "<<max_prof;	
}
