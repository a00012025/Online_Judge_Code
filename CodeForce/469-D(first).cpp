#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,A,B,a[110000],l,r,flagA[110000],flagB[110000],f[110000],fa[110000];
int i,b[110000],ans[110000];
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	x=getfa(x);y=getfa(y);
	fa[x]=y;
}
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=i;
		fa[i]=i;
	}
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1);
	for(l=1,r=n;l<=r;l++)
	{
		while(r>l&&a[l]+a[r]>A)r--;
		if(a[l]+a[r]==A){
			merge(l,r);
			flagA[l]=1;
			flagA[r]=1;
		}
	}
	for(l=1,r=n;l<=r;l++)
	{
		while(r>l&&a[l]+a[r]>B)r--;
		if(a[l]+a[r]==B){
			merge(l,r);
			flagB[l]=1;
			flagB[r]=1;
		}
	}
	for(i=1;i<=n;i++)getfa(i);
	for(i=1;i<=n;i++)
	{
		if(flagA[i]+flagB[i]==0)break;
		if(flagA[i]==0)
		{
			if(f[fa[i]]&&f[fa[i]]!=2)break;
			f[fa[i]]=2;
		}
		if(flagB[i]==0)
		{
			if(f[fa[i]]&&f[fa[i]]!=1)break;
			f[fa[i]]=1;
		}
	}

	if(i<=n)puts("NO");
	else
	{
		puts("YES");
		for(i=1;i<=n;i++)if(f[i]==0)f[i]=1;
		for(i=1;i<=n;i++)
			ans[b[i]]=f[fa[i]]-1;
		for(i=1;i<n;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
}
