#include<stdio.h>
int fa[5000001] ;
int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]) ;
}
main()
{
    int n,T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        int ans1=0,ans2=0 ;
        for(int i=1;i<=n;i++) fa[i]=i ;
        char c[10] ; gets(c) ;
        while(1)
        {
            //if(scanf("%s",c)==EOF) break ;
            if(gets(c)==0) break ;
            if(c[0]!='c' && c[0]!='q') break ;
            int a,b ;
            sscanf(&c[1],"%d%d",&a,&b) ;
            //scanf("%d%d",&a,&b) ;
            if(c[0]=='c') fa[getfa(a)]=getfa(b) ;
            else if(getfa(a)==getfa(b)) ans1++ ;
            else ans2++ ;
        }
        printf("%d,%d\n",ans1,ans2) ;
        if(T)printf("\n");
    }
}
