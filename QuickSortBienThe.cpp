#include <stdio.h>
typedef struct 
{
	int key;
}record;
void Swap(record &a, record &b)
{
	record temp;
	temp = a;
	a = b;
	b = temp;
}
void doc(record a[], int *n)
{
	FILE *f;
    f=fopen("t.txt","r"); 
	int i=0;
	while (!feof(f))
	{
		fscanf(f,"%d",&a[i].key);
		i++;
	}
	fclose(f);
	*n=i;
}
void in(record a[],int n)
{
	for (int i=0;i<n;i++)
		{
		printf("%3d%5d",i+1,a[i].key);
		printf("\n");
		}
}
int FindPivot(record a[ ], int i,int j) 
{
	int firstkey;
	int k ;
 	k = i+1;
 	firstkey = a[i].key;
 		while ( (k <= j) && (a[k].key == firstkey) ) 
		 k++;
 			if (k > j) 
			 return -1;
			else
			 if (a[k].key>firstkey) 
			 return i;
			  else
			   return k;
		}
		
int Partition(record a[], int i, int j, int pivot)
{ 
	int L,R;
 	L = i;
 	R = j;
 	while (L <= R)
 	{ 
 		while (a[L].key <= pivot) 
		     L++;
 			while (a[R].key > pivot) 
			 R--;
 			if (L<R) Swap(a[L],a[R]);
	}
 	return L; 
}
void QuickSort(record a[], int i,int j)
{ 
	int pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a,i,j);
	if (pivotindex != -1) 
	{
	pivot = a[pivotindex].key;
	k = Partition(a,i,j,pivot);
	QuickSort(a,i,k-1);
	QuickSort(a,k,j);
	}
}
int main ()
{
	record a[100];
	int n;
	doc(a,&n);
	printf("\t QUICK SORT BIEN THE \n");
	printf("Du lieu truoc khi sap xep \n");
	in(a,n);
	printf("Du lieu sau khi sap xep \n");
	QuickSort(a,0,n-1);
	in(a,n);
	return 0;
}


