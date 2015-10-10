#include<stdio.h>
int box[51],item[1001],yes[1001],ans,ANS,M,N,mm;
void dfs(int a,int b)
    {
    int j;
    mm=0;
    for(j=1;j<=M;j++)
        {
        if((yes[j]==1)&&(item[j]<=b))
            {
            yes[j]=0;
            ans+=1;
            dfs(a,b-item[j]);
            yes[j]=1;
            ans=ans-1;
            mm=1;
            }
        }
        if((a==N)&&(mm==0))
            {
            if(ans>=ANS) ANS=ans;
            }
        else if(mm==0)
            {
            dfs(a+1,box[a+1]);
            }
    }
main()
{
 int i,z;
 while(scanf("%d %d",&N,&M)==2)
 {
 for(i=1;i<=1000;i++) yes[i]=1;
 for(i=1;i<=N;i++) scanf("%d",&box[i]);
 for(i=1;i<=M;i++) scanf("%d",&item[i]);
 ans=0;
 ANS=0;
 dfs(1,box[1]);
 printf("%d\n",ANS);
 }
}
