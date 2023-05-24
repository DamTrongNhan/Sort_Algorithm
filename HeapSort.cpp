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
	int i;
	for (i=0;i<n;i++)
	{
		printf(" %3d%5d\n",i+1,a[i].key);
	}
}
void PushDown(record a[ ], int first,int last)
{ 
	int r= first;
	while (r <= (last-1)/2)
		if (last == 2*r+1) 
		{
		if (a[r].key > a[last].key) Swap(a[r],a[last]);
				r = last;
		} 
		else
		if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key))
			{
				Swap(a[r],a[2*r+1]);
				r = 2*r+1 ;
			} 
		else
		if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key))
			{
				Swap(a[r],a[2*r+2]);
				r = 2*r+2 ;
			}
		else
				r = last;
}
void HeapSort(record a[], int n)
{ 
   int i;
   for (i = (n-2)/2; i>=0; i--)
   PushDown(a, i, n-1);
    for (i = n-1; i>=2; i--) 
      {
        Swap(a[0],a[i]);
        PushDown(a, 0, i-1);
      }
    Swap(a[0],a[1]);
}
int main ()
{
	record a[100];
	int n;
	doc(a,&n);
	printf("\t HEAP SORT \n");
	printf("Du lieu truoc khi sap xep \n");
	in(a,n);
	printf("Du lieu sau khi sap xep \n");
	HeapSort(a,n);
	in(a,n);
	return 0;
}


