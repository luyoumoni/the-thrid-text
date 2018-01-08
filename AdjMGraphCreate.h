
typedef struct
{
	int row;
	int col;
	int weight;
}RowColWeight;


void CreatGraph(AdjMGraph *G,DataType V[],int n,RowColWeight E[],int e)
{
	int i,k;
	Initiate(G,n);
	for(i = 0; i < n;i++)
		InsertVertex(G,V[i]);
	for(k = 0;k < e;k++)
	{
		InsertEdge(G,E[k].row,E[k].col,E[k].weight);
	}
}