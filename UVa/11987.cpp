#include<stdio.h>
int fa[301000],nowid[101000] ;
int sum[101000],num[101000] ;

int getfa(int x)
{
    return x==fa[x] ? x : fa[x]=getfa(fa[x]) ;
}

main()
{
    int n,m ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=1;i<=3*n;i++) fa[i]=i ;
        for(int i=1;i<=n;i++) {nowid[i]=i ; sum[i]=i ; num[i]=1 ;}
        int pt_num=n ;
        for(int i=1;i<=m;i++)
        {
            int type ;
            scanf("%d",&type) ;
            if(type==1)
            {
                int a,b ;
                scanf("%d%d",&a,&b) ;
                int i=getfa(nowid[a]) , j=getfa(nowid[b]) ;
                if(i==j) continue ;
                fa[i]=j ; num[j]+=num[i] ; sum[j]+=sum[i] ;
            }
            else if(type==2)
            {
                int a,b ;
                scanf("%d%d",&a,&b) ;
                int i=getfa(nowid[a]) , j=getfa(nowid[b]) ;
                if(i==j) continue ;
                sum[i]-=a ; num[i]-=1 ;
                sum[j]+=a ; num[j]+=1 ;
                nowid[a]=++pt_num ;
                fa[nowid[a]]=j ;
            }
            else if(type==3)
            {
                int a;
                scanf("%d",&a) ;
                printf("%d %d\n",num[getfa(nowid[a])],sum[getfa(nowid[a])]);
            }
        }
    }
}
