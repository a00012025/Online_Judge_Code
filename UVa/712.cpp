#include<stdio.h>
int n,id[1000],tree[50000],y[1000] ;

int query(int now,int depth)
{
    if(depth==n) return tree[now] ;
    if(y[depth]==1) return query(2*now+1,depth+1) ;
    else return query(2*now,depth+1) ;
}

main()
{
    int tc=0,fir=1 ;
    while(scanf("%d",&n)==1 && n)
    {
        //if(fir) fir=0 ;
        //else printf("\n") ;
        printf("S-Tree #%d:\n",++tc) ;
        char s[10000] ;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s) ;
            id[s[1]-'0']=i ;
        }
        scanf("%s",s) ;
        for(int i=(1<<n);i<(1<<(n+1));i++) tree[i]=s[i-(1<<n)]-'0' ;
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            scanf("%s",s) ;
            for(int i=0;i<n;i++) y[id[i+1]]=s[i]-'0' ;
            printf("%d",query(1,0)) ;
        }
        printf("\n\n") ;
    }
}
