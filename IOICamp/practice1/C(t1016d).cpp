#include <bits/stdc++.h>
using namespace std;

int dp[210][210][110];
int a[300],b[300],N;

int f(int l,int r,int c)
{
	if(l>r)
		return 0;
	if(dp[l][r][c]!=-1)
		return dp[l][r][c];
	if(b[r]==c || (c==0 && a[r]==b[r]) )
		return dp[l][r][c]=f(l,r-1,c);
	if(b[l]==c || (c==0 && a[l]==b[l]) )
		return dp[l][r][c]=f(l+1,r,c);
	int ans=f(l,r-1,c)+1;
	for(int i=l;i<r;i++)
		if(b[i]==b[r])
			ans=min(ans, f(l,i-1,c)+f(i+1,r-1,b[r])+1 );
	return dp[l][r][c]=ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",a+i);
		for(int i=0;i<N;i++)
			scanf("%d",b+i);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",f(0,N-1,0));
	}
	return 0;
}
