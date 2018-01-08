#include"SeqList.h"


typedef struct
{
	SeqList Vertices;
	int edge[MaxVertices][MaxVertices];
	int numOfEdges;
}AdjMGraph;



void Initiate(AdjMGraph *G,int n)   //邻接表的初始化
{
	int i,j;
	for(i = 0;i<n;i++)
		for(j = 0;j<n;j++)
		{
			if(i == j)G->edge[i][j] = 0;
			else G->edge[i][j] = MaxWeight;
		}

		G->numOfEdges = 0;
		ListInitiate(&G->Vertices);
}



void InsertVertex(AdjMGraph *G,DataType vertex) //插入顶点
{
	ListInsert(&G->Vertices,G->Vertices.size,vertex);
}

void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)//插入边
{
	if(v1 < 0||v1>=G->Vertices.size||v2 < 0||v2 >=G->Vertices.size)
	{
		printf("出界！\n");
		return;
	}
	int j,i = 0;
	for(;i < G->Vertices.size;i++)
		for(j =0;j < G->Vertices.size;j++)
		{
			if(i == v1&&j == v2)
	            G->edge[v1][v2] = weight;
			if(i == v2&&j ==v1)
	            G->edge[v2][v1] = weight;
		    if(G->edge[i][j] < 0||G->edge[i][j] > MaxWeight)
				G->edge[i][j] = MaxWeight;
		}
	G->numOfEdges++;
}




void DeleteEdge(AdjMGraph *G,int v1,int v2)// 删除边
{
	if(v1 < 0||v1>=G->Vertices.size||v2 < 0||v2 >=G->Vertices.size)
	{
		printf("出界！\n");
		return;
	}
	if(G->edge[v1][v2] == MaxWeight||v1 == v2)
	{
		printf("该边不存在！\n");
		return;
	}
	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}


void DeleteNode(AdjMGraph *G,int v1)
{
	int i;
	DataType x;
	for( i = 0;i <G->Vertices.size;i++)
		if(G->edge[v1][i] > 0&&G->edge[v1][i] < MaxWeight && i != v1)
			G->edge[v1][i] = MaxWeight;
	for(i = 0;i <G->Vertices.size;i++)
		if(G->edge[i][v1] > 0 && G->edge[i][v1] < MaxWeight && i !=v1)
			G->edge[i][v1] = MaxWeight;
	ListDelete(&(G->Vertices),v1,&x);
}








