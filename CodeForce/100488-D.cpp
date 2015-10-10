#include<stdio.h>
#include<map>
using namespace std;
map<int,int> m ;
main()
{
    int n,color[100101],same=1;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ;
        scanf("%d",&x) ;
        color[i]=x ;
        if(m.count(x)==1) m[x]=m[x]+1 ;
        else m[x]=1 ;
        if(i>1 && color[i]!=color[i-1]) same=0 ;
    }
    int b,ans=-1;
    scanf("%d",&b) ;
    for(int i=1;i<=b;i++)
    {
        int p,q ;
        scanf("%d %d",&p,&q) ;
        m[color[p]]=m[color[p]]-1 ;
        if(m[color[p]]==0) m.erase(color[p]) ;
        if(m.count(q)==1) m[q]=m[q]+1 ;
        else m[q]=1 ;
        color[p]=q ;
        if(m[q]==n && ans==-1) ans=i ;
    }
    if(same==0) printf("%d\n",ans);
    else printf("0\n") ;
}
