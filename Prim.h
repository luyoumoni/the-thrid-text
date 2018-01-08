typedef struct
{
	VerT vertex;
	int weight;
}MinSpanTree;

void Prim(AdjMGraph G,MinSpanTree closeVertex[])
{
	VerT x;
	int n = G.Vertices.size,minCost;
	int *lowCost = (int *)malloc(sizeof(int)*n);
	int i,j,k;


	for(i = 1;i < n ;i++)
		lowCost[i] = G.edge[0][i];
	//ListGet (SeqList *L, int i, DataType *x)
	ListGet(G.Vertices,0,&x);
	closeVertex[0].vertex = x;
	lowCost[0] = -1;
	

	for(i = 1;i < n;i++)
	{
		minCost = MaxWeight;
		for(j = 0;j < n;j++)
		{
			if(lowCost[j] < minCost && lowCost[j] > 0)
			{
				minCost = lowCost[j];
				k = j;
			}
		}


		ListGet(G.Vertices,k,&x);
		closeVertex[i].vertex = x;
		closeVertex[i].weight = minCost;
		lowCost[k] = -1;


		for(j = 1;j<n;j++)
		{
			if(G.edge[k][j] < lowCost[j])
				lowCost[j] = G.edge[k][j];
		}
	}
}