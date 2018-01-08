#include<stdio.h>
#include<malloc.h>
typedef char DataType;
typedef char VerT;
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Prim.h"
#include "Dijkstra.h"

AdjMGraph *g1 = (AdjMGraph *)malloc(sizeof(AdjMGraph));
	int	*n1 = (int *)malloc(sizeof(int));        //结点的个数
	int	*n2 = (int *)malloc(sizeof(int));        //结点对应的边的总条数


void xianshi()
{
	printf("****************************************\n");
	printf("1)建立路由器网络拓扑图\n");
	printf("2)输出路由器网络拓扑图\n");
	printf("3)增添路由器的结点以及该结点对应的边\n");
	printf("4)删除路由器两结点所连接的边\n");
	printf("5)利用RIP建立该网络的最小网络MST\n");
	printf("6)从原路由器的一个结点利用OSPF寻找最短路径\n");
	printf("7)删除路由结点\n");
	printf("8)退出\n");
	printf("****************************************\n");
	printf("请输入所要完成的功能\n");
}


int menu(int n3)
{
	switch(n3)
	{
	case 1:     //建立路由器网络拓扑图
        {
	    int i;
	
	    printf("请输入所建节点的个数（最大不超过10）\n");
	    scanf("%d%*c",n1);
		//getchar();
	    printf("请输入节点的名称（字母）\n");
	    DataType *a = (DataType *)malloc(sizeof(DataType)*(*n1));
	    for(i =0; i < *n1;i++)
		{
		    scanf("%c%*c",&a[i]);
			//getchar();
		}
	    printf("请输入各个节点的代号以及各个节点之间的关系（与前面对应的节点序号从0开始，节点之间的距离为1,10,64三种）\n");
	    printf("请在输入完一对节点之间的关系后换行\n");
	    printf("请输入所建立的图对应的边的总条数\n");
	    scanf("%d%*c",&(*n2));
	    printf("请输入各边之间的关系\n");
	    RowColWeight *rcw = (RowColWeight *)malloc(sizeof(RowColWeight)*(*n2));
	    for(i = 0;i < *n2;i++)
		{
			fflush( stdin );
			scanf("%d%d%d%*c",&rcw[i].row,&rcw[i].col,&rcw[i].weight);
		}
		//getchar();
	    CreatGraph(g1,a,*n1,rcw,*n2);
	    printf("您已经建立好了路由器的网络拓扑图，请选择所要完成的功能：\n");
		return n3;
		break;
		}
	case 2:    //输出路由器网络拓扑图
        {
			printf("顶点集合为：\n");
			for(int i1 = 0;i1 < g1->Vertices.size;i1++)
				printf("%c  ",g1->Vertices.list[i1]);
			printf("\n");
	        for( int i = 0;i < g1->Vertices.size;i++)
			{
		    for(int j = 0;j < g1->Vertices.size;j++)
			     printf("%5d  ",g1->edge[i][j]);
		         printf("\n");
			}
			return n3;
			break;
		}
	case 3:    //增添路由器的结点以及该结点对应的边
        {
		    DataType vertex,m;
			int weight,v1,v2,n4;
		    printf("请输入所要建立的新结点\n");
			fflush( stdin );
			scanf("%c%*c",&vertex);
			m=vertex;
			//getchar();
			//getchar();
			InsertVertex(g1,vertex);
     		printf("请输入新建立的边的条数\n");
			scanf("%d%*c",&n4);
			//getchar();
  			for(int i = 0;i < n4;i++)
			{
			    printf("请输入与新结点相连的节点下标\n");
			    scanf("%d%*c",&v2);
				//getchar();
			    printf("请输入对应变得权值\n");
			    scanf("%d%*c",&weight);
				//getchar();
			    v1 = g1->Vertices.size-1 ;
			    InsertEdge(g1,v1,v2,weight);
			    InsertEdge(g1,v2,v1,weight);
			}
			printf("新结点和边已经建立完成\n");
			return n3;
			break;
		}
	case 4:   //删除结点及其相邻的边
        {
		    int v1,v2;
			printf("请输入所要删除的结点的下标v1,v2\n");
			scanf("%d%d%*c",&v1,&v2);
			DeleteEdge(g1,v1,v2);
			DeleteEdge(g1,v2,v1);
			return n3;
			break;
		}
	case 5:  //利用RIP建立该网络的最小网络MST
        {
           int i;
		   MinSpanTree *colseVertex = (MinSpanTree *)malloc(sizeof(MinSpanTree)*(*n1));
		   Prim(*g1,colseVertex);
		   printf("初始顶点 = %c\n",colseVertex[0].vertex);
		   for(i = 1;i < *n1; i++)
			   printf("顶点 =%c  边的权值 = %d\n",colseVertex[i].vertex, colseVertex[i].weight);
           return n3;
		   break;
		}
	case 6:  //从原路由器的一个结点利用OSPF寻找最短路径
		{
			int *distance = (int *)malloc(sizeof(int)*(*n1));
			int *path = (int *)malloc(sizeof(int)*(*n1));
			printf("请输入起始顶点对应的下标\n");
			int qi,i;
			scanf("%d%*c",&qi);
			Dijkstra(*g1,qi,distance,path);
			printf("从顶点%c的到其他顶点的最短距离：\n",g1->Vertices.list[0]);
			for(i = 0;i < *n1;i++)
				printf("到顶点%c的最短距离为%d\n",g1->Vertices.list[i],distance[i]);
			printf("从顶点%c到其他顶点最短路径的前一顶点为：\n",g1->Vertices.list[0]);
			for(i = 0;i < *n1;i++)
				if(path[i] != -1)
					printf("到顶点%c的前一顶点为%c\n",g1->Vertices.list[i],g1->Vertices.list[path[i]]);
			return n3;
			break;
		}
	case 7:  //删除路由结点
		{
			int v1;
			printf("请输入要删除结点的下标\n");
			scanf("%d%*c",&v1);
			DeleteNode(g1,v1);
			return n3;
			break;
		}

	}
}
            


          




void main()
{

	xianshi();
	int n3;
	scanf("%d",&n3);
	while(menu(n3) != 8)
	{
		xianshi();
		scanf("%d",&n3);
	}
}



	
	






