#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int n,m ;
int x[maxn],y[maxn],g[2*maxn] ;
int nex[maxn] ;
vector<int> v ;

int search_in_v(int val)
{
    int l=0 , r=v.size() ;
    if(v[0]==val) return 0 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid]==val) return mid ;
        if(v[mid]>val) r=mid ;
        else l=mid ;
    }
}

int num[2*maxn] ;
bool vis[2*maxn] ;
main()
{
    scanf("%d%d",&n,&m) ;
    v.push_back(0) ; v.push_back(2000001) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]) ;
        v.push_back(x[i]) ;
        v.push_back(y[i]) ;
    }
    sort(v.begin(),v.end()) ;
    for(int i=1;i<=n;i++)
    {
        x[i]=search_in_v(x[i]) ;
        y[i]=search_in_v(y[i]) ;
        g[x[i]]=y[i] ;
        g[y[i]]=x[i] ;
    }
    for(int i=1;i<=2*n;i++) nex[i]= g[i]+1 ;

    int ans=0 ;
    for(int i=1;i!=2*n+1;i=nex[i]) ans++ , vis[i]=1 ;

    int cnt=0 ;
    for(int i=1;i<=2*n;i++) if(!vis[i])
    {
        int x=1 ; vis[i]=1 ;
        for(int j=nex[i];j!=i;j=nex[j]) x++ , vis[j]=1 ;
        num[++cnt]=x ;
    }

    sort(num+1,num+cnt+1,greater<int>()) ;
    for(int i=1;i<=m;i++) ans+= num[i]+2 ;
    if(m>cnt && ((m-cnt)%2)) ans-- ;

    printf("%d\n",ans) ;
}
