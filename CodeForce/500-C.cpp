#include<bits/stdc++.h>
using namespace std;
const int maxn=600 ;

int w[maxn] ;
bool inst[maxn] ;
int st[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    memset(inst,0,sizeof(inst)) ;
    int sum=0,ans=0,num=0 ;
    for(int i=1;i<=m;i++)
    {
        int x ; scanf("%d",&x) ;
        if(!inst[x])
        {
            ans+=sum ; sum+=w[x] ;
            st[num++]=x ; inst[x]=1 ; continue ;
        }
        int j ;
        for(j=0;st[j]!=x;j++) ;
        for(int k=j+1;k<num;k++) ans+=w[st[k]] ;
        for(int k=j;k<num-1;k++) st[k]=st[k+1] ;
        st[num-1]=x ;
    }
    printf("%d\n",ans) ;
}
