
typedef struct
{
  DataType list[MaxSize];
  int size;
}SeqList ;

void ListInitiate(SeqList *L)
{//初始化顺序表L,即构造一个空顺序表
  L->size=0;
}

int ListLength(SeqList *L)
{//求顺序表L表长
  return L->size;
}

int ListGet (SeqList L, int i, DataType *x)
{//取顺序表L的第i个数据元素，由第三个参数返回
  if (i<0 || i>L.size-1)
  {
     printf("i is error!\n");
     return 0;
  }
  *x=L.list[i];
  return 1;
}

int  ListInsert(SeqList *L, int i, DataType x)
{//在顺序表L的第i个数据元素之前插入数据元素x
   int j;
   if ( L->size>=MaxSize)
   {
     printf("The table is full!\n");
     return 0;
   }
   if ( i<0 || i>L->size)
   {
      printf("i is error \n");
      return 0;
   }
   for ( j=L->size; j>i; j--)
	L->list[j]=L->list[j-1];
   L->list[i]=x;
   (L->size)++;
   return 1;
}

int ListDelete (SeqList *L, int i, DataType *x)
{  //删除顺序表L中第i个数据元素，并通过第三个参数返回
	int j;
   if (L->size<=0 )
   {
      printf("The table is empty! \n");
      return 0;
   }
   if (i<0 || i>L->size-1)
   {
      printf("i is error! \n");
      return 0;
   }
   *x=L->list[i];
   for (j=i+1; j<=L->size-1; j++)
       L->list[j-1]=L->list[j];
   (L->size)--;
   return 1;
}

void ListPrint(SeqList *L)
{
	int i;
	DataType x;
	for(i=0;i<ListLength(L);i++)
	{
		if(ListGet(*L, i, &x)==0)
		{
			printf("Error!\n");
		}
		else
			printf("%d   ",x);
	}
	printf("\n");
}
