#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    while(Q--)
    {
        char s[30] ; scanf("%s",s) ;
        if(s[0]=='M')
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            fa[getfa(b)]=getfa(a) ;
        }
        else
        {
            int x ; scanf("%d",&x) ;
            printf("%d\n",getfa(x)) ;
        }
    }
}
