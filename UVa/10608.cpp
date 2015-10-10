#include<stdio.h>
#include<vector>
using namespace std;
int fa[30001],rk[30001],num[30001] ;

int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]);
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) {fa[i]=i ; rk[i]=1 ; num[i]=0 ;}
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b) ;
            int p=getfa(a) , q=getfa(b) ;
            if(rk[p]>rk[q]) {fa[q]=p ; num[p]+=num[q] ;}
            else if(rk[q]>rk[p]) {fa[p]=q ; num[q]+=num[p] ;}
            else {fa[p]=q ; rk[q]++ ; num[q]+=num[p] ;}
        }
        for(int i=1;i<=n;i++) num[getfa(i)]++ ;
        int ans=0 ;
        for(int i=1;i<=n;i++) if(num[getfa(i)]>ans) ans=num[getfa(i)];
        printf("%d\n",ans) ;
    }
}
