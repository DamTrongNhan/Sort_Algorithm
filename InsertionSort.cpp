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
void insertion(record a[], int n)
{
	int j,k;
	for (int i=1;i<n;i++)
	{
		j=i;
		while ((j>0)&&(a[j].key<a[j-1].key))
		{
			Swap(a[j],a[j-1]);
			j--;
		}
		printf("\n%d----%d\n",i,i);
		for (k=0;k<=i;k++)
		printf("%d ",a[k]);
		printf("\n");
	}
}
int main ()
{
	record a[100];
	int n;
	doc(a,&n);
	printf("\t INSERTION SORT \n");
	printf("Du lieu truoc khi sap xep \n");
	in(a,n);
	printf("Du lieu sau khi sap xep \n");
	insertion(a,n);
	in(a,n);
	return 0;
}


