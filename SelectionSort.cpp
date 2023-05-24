#include <stdio.h>
typedef struct 
{
	int key;
}record;
void Swap(record  &a, record &b)
{
	record temp;
	temp = a;
	a = b;
	b = temp;
}
void doc(record a[], int *n)
{
	FILE *f;
	int i=0;
    f=fopen("t.txt","r"); 
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
void selectionsort(record a[],int n)
{
	int lowkey,k;
	int lowindex;
	for (int i=0;i<n-1;i++)
	{
	lowkey=a[i].key;
	lowindex=i;
	for (int j=i+1;j<n;j++)
		if (a[j].key<lowkey)
		{
			lowkey=a[j].key;
			lowindex=j;
		}
		Swap(a[i],a[lowindex]);
			printf("\n%d----%d\n",i+1,i+1);
			for (k=i;k<n;k++)
			printf("%d ",a[k]);
			printf("\n");
	}	
		
}
int main ()
{
	record a[100];
	int n;
	doc(a,&n);
	printf("\t SELECTION SORT \n");
	printf("Du lieu truoc khi sap xep \n");
	in(a,n);
	printf("Du lieu sau khi sap xep \n");
	selectionsort(a,n);
	in(a,n);
	return 0;
}


