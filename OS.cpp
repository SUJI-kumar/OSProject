#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	
	int i,p,q,resource,max_need=0,count=0;
	cout<<"Enter Number of Resources available : \n";
	cin>>p;
	cout<<"Enter Number of Processes available : \n";
	cin>>q;
	resource=p;
	int process[q],End[q],allot[q];
	for(int i=0;i<q;i++)
	{
		cout<<"Enter number of resources required by Process";
		cout<<i+1<<"\n";
		cin>>process[i];
		End[i]=0;
		allot[i]=0;
	}
	
	cout<<"Process \tResources\n";
	for(int i=0;i<q;i++)
	{
		cout<<i+1;
		cout<<"\t"<<process[i];
		max_need=max_need+process[i];
		if(process[i]<1||process[i]>p)
		{
			count++;
		}
	}
	if(max_need<p+q&&count==0)
	{		
		cout<<"\n\n";
		cout<<"#####";
		cout<<"\n\n";
		cout<<"  Both Condition satisfied: \n";
	}
	else
	{
		cout<<"Conditions are not satisfied so system is in unsafe state,there are chances of dead lock\n\n";
	}
		while(1)
		{
			count=0;
			for(int i=0;i<q;i++)
			{
				if(End[i]==0)
				{
					if(resource>0)
					{
					allot[i]=allot[i]+1;
					resource=resource-1;
					cout<<"Process %d + 1\n",i+1;
					}
					if(allot[i]==process[i])
					{
						cout<<"Process completed it execution\n"<<i+1;
						End[i]=1;
						resource=resource+process[i];
						cout<<"Process\n";
						cout<<i+1-process[i];
					}
				}
			}
			for(int i=0;i<q;i++)
			{
				if(End[i]==1)
				count++;
			}
			if(count==q)
			break;
		}
			cout<<"\n";;
			cout<<"###";
			cout<<"\n";
			cout<<"No Dead Lock";

}
