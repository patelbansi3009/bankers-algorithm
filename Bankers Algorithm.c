//17BCP061D
#include<stdio.h>
int main()
{
	int p,res;
	printf("Enter Number of Process=");
	scanf("%d",&p);
	printf("Enter Number of Resources=");
	scanf("%d",&res);

	int allocated[p][res],need[p][res],status[p],seq[p],available[1][res],flag=0;
	printf("Enter Allocated Matrix=");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<res;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	printf("Enter Need Matrix=");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<res;j++)
		{
			scanf("%d",&need[i][j]);
		}
	}
	printf("Enter Resourse=");
	for(int i=0;i<res;i++)
	{
		scanf("%d",&available[0][i]);
	}
	for(int i=0;i<p;i++)
	{
		status[i]=0;
	}
	
	int counter=0;
	while(counter<p)
	{
		int st=0;
		int processid=9999;
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<res;j++)
			{ 
				if(available[0][j]>=need[i][j] && status[i]==0)
				{
					st=1;
					processid=i;
				}
				else	
				{
					st=0;
					break;
				}	
			}
			if(st==1){
				break;
			}
			else{
				continue;
			}
		}
		if(processid==9999){
			printf("This is Deadlock");
			flag=1;
			break;
		}
		seq[counter]=processid;	
		status[processid]=1;
		counter++;
		for(int j=0;j<res;j++)
		{
			available[0][j]=available[0][j]+allocated[processid][j];	
		}


	}
	if(flag==0)
	{
			printf("---Safe Execution Sequence---\n");
			for(int i=0;i<p;i++)
			{
				printf("P%d\n",seq[i]);
			}
	}
	return 0;
}
