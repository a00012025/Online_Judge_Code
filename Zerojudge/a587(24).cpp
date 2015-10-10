#include<stdio.h>
int main()
{
	int a,b,f,g,h;
	while(scanf("%d",&a)==1)
	{
		int c[200]={0};
		int d[200]={0};
		int e[20000]={0};
		for(b=1;b<=a;b++)
		{
			scanf("%d %d",&c[b],&d[b]);
		}
		scanf("%d",&b);
		for(f=1;f<=a;f++)
		{
			for(g=b;g>=c[f];g--)
			{
				if(e[g-c[f]]!=0||g==c[f])
				{
					e[g]=e[g-c[f]]+d[f]>e[g]?e[g-c[f]]+d[f]:e[g];
				}
			}
		}
		h=-1;
		for(f=0;f<=b;f++)
		{
			if(e[f]>h)
			{
				h=e[f];
			}
		}
		printf("%d\n",h);
	}
	return 0;	 
}
