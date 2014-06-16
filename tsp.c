#include<stdio.h>
#define MAX 50

void mincost(int);

int a[20][20],visit[20];
int n;
float cost;

float optimal();
int distance(int path[],int dist,int no,int s,int visited[]);

int solno;
int paths[MAX][MAX];
int path[MAX];
int source;
int visited[MAX];
int dis[MAX];

int least(int c);

void mincost(int city)
{
	int i,ncity;
	visit[city]=1;
	
	printf("%d-->",city);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=1;
		printf("%d",ncity);
		cost +=a[city][ncity];
		return;
	}
	mincost(ncity);
	
	return;
}

int least(int c)
{
	
	int nc=999,i;
	int min=999,kmin;
	for(i=1;i<=n;i++)
	{
		if((a[c][i]!=0)&&(visit[i]==0))
		if(a[c][i]<min)
		{	
//			printf("/*a[i][0]*/:%d  for i=%d\n",a[i][0],i);
			min=/*a[i][0]+*/a[c][i];
			kmin=a[c][i];
			nc=i;
		}
	}
	if(min!=999)
	cost+=kmin;


	return nc;
}


int distance(int path[MAX],int dist, int no,int s,int visited[MAX])
{
	int flag=0,i;
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			path[no]=i;
			visited[i]=1;
			flag=1;
			distance(path,dist+a[s][i],no+1,i,visited);
			visited[i]=0;
		}
	}
	if(flag==0)
	{
		printf("Solution %d\n",solno+1);
		for(i=1;i<=n;i++)
		{
			printf("%d-->",path[i]);
			paths[solno][i]=path[i];
		}
		printf("%d\t",source);
		printf("Distance: %d\n",dist+a[s][source]);
		dis[solno]=dist+a[s][source];
		solno++;
	}
	return 0;
}


float optimal()
{
	int i,min=dis[0],solno=0;
	for(i=1;i<=n;i++)
	{
		if(dis[i]<min)
		{
			min=dis[i];
			solno=i;
		}
	}
	printf("Min cost: %d\n",min);
	printf("Optimal Path:");
	for(i=1;i<=n;i++)
	{
		printf("%d->",paths[solno][i]);
	}
	printf("%d\n",source);
	return min;
}


int main()
{
	int dist=0,i,j,no;
	float accuracy, min;
	printf("Enter the number of cities:\n");
	scanf("%d",&n);
	printf("\nYou are to enter paths from respective cities, note that an input --\n-- of 999 is to be given for no path\n\n");
	for(i=1;i<=n;i++)
	{
		printf("ENter the paths from city %d:\n",i);
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
		visit[i]=0;
	}
	printf("\nENter the source\n");
	scanf("%d",&source);
	printf("Using approximate algrithm\n");
	printf("The path is\t\t");
	mincost(source);
	printf("\nmincost is %f\n",cost);
	printf("--------------------------------------\n");
	printf("\n\nUsing optimal method:\n");
	visited[source]=1;
	path[1]=source;
	
	distance(path,dist,2,source,visited);
	min=optimal();
	printf("\nApproximate algorithm cost: %f,\nOptimal algoritm minimum cost: %f\n",cost,min);
	accuracy=(float)(cost/min);
	printf("Accuracy= %f\n\n",accuracy);

	return 0;
}
