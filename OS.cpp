#include<iostream>
using namespace std;
int main()
{
	
	
	label:int p,q,resource,max_need=0,count=0;
	cout<<"Enter Number of Resources available : \n";
	cin>>p;
	cout<<"Enter Number of Processes available : \n";
	cin>>q;
	resource=p;
	int process[q],End[q],allot[q];
	system("COLOR 0B");
	for(int i=0;i<q;i++)
	{
		cout<<"Enter number of resources required by Process"<<i+1<<"\n";
		cin>>process[i];
		End[i]=0;
		allot[i]=0;
	}
	cout<<"\tYOU HAVE\n\n";
	cout<<"\tProcess \tResources\n";
	for(int i=0;i<q;i++)
	{
		cout<<"\tP"<<i+1<<"\t\t"<<process[i]<<"\n";
		max_need=max_need+process[i];
		if(process[i]<1||process[i]>p)
		{
			count++;
		}
	}
	if(max_need<p+q&&count==0)
	{		
		cout<<"\n\n";
		
		cout<<"#####*****####";
		cout<<"\n\n";
		cout<<"  Both Condition given are satisfied"<<"\n";
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
					cout<<"Process"<<i+1<<"\n";
					}
					if(allot[i]==process[i])
					{
						cout<<"Process completed it execution"<<i+1<<"\n";
						End[i]=1;
						resource=resource+process[i];
						cout<<"Process"<<i+1-process[i]<<"\n";
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
		cout<<"\n\n";
		cout<<"\tAS LOOKING ABOVE\t";
		cout<<"\n\n";
		cout<<"No Dead Lock\n";
		cout<<"DO YOU WANT TO CONTINUE YES or NO:\n";
		char c;
		cin>>c;
		if(c=='Y' || c=='y')
		{
			goto label;
		}
		else
		{
			exit;
		}	
						
			
					
					
}

