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
	printf("%4d%6d\n",i+1,a[i].key);
}
void bubble(record a[],int n)
{
	int k;
	for (int i=0;i<n-1;i++)
	{
	for (int j=n-1;j>=i+1;j--)
		{
			if (a[j].key<a[j-1].key)
			Swap(a[j],a[j-1]);
		}
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
	printf("\t BUBBLE SORT \n");
	printf("Du lieu truoc khi sap xep \n");
	in(a,n);
	printf("Du lieu sau khi sap xep \n");
	bubble(a,n);
	printf("\n");
	in(a,n);
	return 0;
}


