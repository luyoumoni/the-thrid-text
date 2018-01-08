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
	int	*n1 = (int *)malloc(sizeof(int));        //���ĸ���
	int	*n2 = (int *)malloc(sizeof(int));        //����Ӧ�ıߵ�������


void xianshi()
{
	printf("****************************************\n");
	printf("1)����·������������ͼ\n");
	printf("2)���·������������ͼ\n");
	printf("3)����·�����Ľ���Լ��ý���Ӧ�ı�\n");
	printf("4)ɾ��·��������������ӵı�\n");
	printf("5)����RIP�������������С����MST\n");
	printf("6)��ԭ·������һ���������OSPFѰ�����·��\n");
	printf("7)ɾ��·�ɽ��\n");
	printf("8)�˳�\n");
	printf("****************************************\n");
	printf("��������Ҫ��ɵĹ���\n");
}


int menu(int n3)
{
	switch(n3)
	{
	case 1:     //����·������������ͼ
        {
	    int i;
	
	    printf("�����������ڵ�ĸ�������󲻳���10��\n");
	    scanf("%d%*c",n1);
		//getchar();
	    printf("������ڵ�����ƣ���ĸ��\n");
	    DataType *a = (DataType *)malloc(sizeof(DataType)*(*n1));
	    for(i =0; i < *n1;i++)
		{
		    scanf("%c%*c",&a[i]);
			//getchar();
		}
	    printf("����������ڵ�Ĵ����Լ������ڵ�֮��Ĺ�ϵ����ǰ���Ӧ�Ľڵ���Ŵ�0��ʼ���ڵ�֮��ľ���Ϊ1,10,64���֣�\n");
	    printf("����������һ�Խڵ�֮��Ĺ�ϵ����\n");
	    printf("��������������ͼ��Ӧ�ıߵ�������\n");
	    scanf("%d%*c",&(*n2));
	    printf("���������֮��Ĺ�ϵ\n");
	    RowColWeight *rcw = (RowColWeight *)malloc(sizeof(RowColWeight)*(*n2));
	    for(i = 0;i < *n2;i++)
		{
			fflush( stdin );
			scanf("%d%d%d%*c",&rcw[i].row,&rcw[i].col,&rcw[i].weight);
		}
		//getchar();
	    CreatGraph(g1,a,*n1,rcw,*n2);
	    printf("���Ѿ���������·��������������ͼ����ѡ����Ҫ��ɵĹ��ܣ�\n");
		return n3;
		break;
		}
	case 2:    //���·������������ͼ
        {
			printf("���㼯��Ϊ��\n");
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
	case 3:    //����·�����Ľ���Լ��ý���Ӧ�ı�
        {
		    DataType vertex,m;
			int weight,v1,v2,n4;
		    printf("��������Ҫ�������½��\n");
			fflush( stdin );
			scanf("%c%*c",&vertex);
			m=vertex;
			//getchar();
			//getchar();
			InsertVertex(g1,vertex);
     		printf("�������½����ıߵ�����\n");
			scanf("%d%*c",&n4);
			//getchar();
  			for(int i = 0;i < n4;i++)
			{
			    printf("���������½�������Ľڵ��±�\n");
			    scanf("%d%*c",&v2);
				//getchar();
			    printf("�������Ӧ���Ȩֵ\n");
			    scanf("%d%*c",&weight);
				//getchar();
			    v1 = g1->Vertices.size-1 ;
			    InsertEdge(g1,v1,v2,weight);
			    InsertEdge(g1,v2,v1,weight);
			}
			printf("�½��ͱ��Ѿ��������\n");
			return n3;
			break;
		}
	case 4:   //ɾ����㼰�����ڵı�
        {
		    int v1,v2;
			printf("��������Ҫɾ���Ľ����±�v1,v2\n");
			scanf("%d%d%*c",&v1,&v2);
			DeleteEdge(g1,v1,v2);
			DeleteEdge(g1,v2,v1);
			return n3;
			break;
		}
	case 5:  //����RIP�������������С����MST
        {
           int i;
		   MinSpanTree *colseVertex = (MinSpanTree *)malloc(sizeof(MinSpanTree)*(*n1));
		   Prim(*g1,colseVertex);
		   printf("��ʼ���� = %c\n",colseVertex[0].vertex);
		   for(i = 1;i < *n1; i++)
			   printf("���� =%c  �ߵ�Ȩֵ = %d\n",colseVertex[i].vertex, colseVertex[i].weight);
           return n3;
		   break;
		}
	case 6:  //��ԭ·������һ���������OSPFѰ�����·��
		{
			int *distance = (int *)malloc(sizeof(int)*(*n1));
			int *path = (int *)malloc(sizeof(int)*(*n1));
			printf("��������ʼ�����Ӧ���±�\n");
			int qi,i;
			scanf("%d%*c",&qi);
			Dijkstra(*g1,qi,distance,path);
			printf("�Ӷ���%c�ĵ������������̾��룺\n",g1->Vertices.list[0]);
			for(i = 0;i < *n1;i++)
				printf("������%c����̾���Ϊ%d\n",g1->Vertices.list[i],distance[i]);
			printf("�Ӷ���%c�������������·����ǰһ����Ϊ��\n",g1->Vertices.list[0]);
			for(i = 0;i < *n1;i++)
				if(path[i] != -1)
					printf("������%c��ǰһ����Ϊ%c\n",g1->Vertices.list[i],g1->Vertices.list[path[i]]);
			return n3;
			break;
		}
	case 7:  //ɾ��·�ɽ��
		{
			int v1;
			printf("������Ҫɾ�������±�\n");
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



	
	






