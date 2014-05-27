
#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int C[SQ][SQ],n;

int kruskal();

int main()
{
	int i,j,ans;
	
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&C[i][j]);

	ans=kruskal();

	printf("The minimum computed cost is:%d\n",ans);

	return 0;

}

int kruskal()
{
	int a,b,u,v,parent[SQ],ne;
	int i,j;
	int min,mincost;

	ne=0,mincost=0;

	for(i=1;i<=n;i++)
	parent[i]=0;

	while(ne!=n-1)
	{
		min=99;

		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(C[i][j]<min)
			{
				min=C[i][j];
				a=u=i;
				b=v=j;
			}
		}

			while(parent[u]!=0)
			u=parent[u];
			
			while(parent[v]!=0)
			v=parent[v];

			if(u!=v)
			{
				printf("%d-->%d:%d\n",a,b,min);
				parent[v]=u;
				mincost=mincost+min;
				ne++;
			}

			C[a][b]=C[b][a]=99;
	}

return mincost;
}
