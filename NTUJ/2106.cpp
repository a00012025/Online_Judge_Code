#include<bits/stdc++.h>
using namespace std;
const int maxn=3000+10 ;

int t[maxn] ;
inline int get(int id,int sz){return (id<0 || id>=sz) ? 0 : t[id] ;}
void fold(int *a,int &sz,int w,bool lef)
{
    for(int i=0;i<sz;i++) t[i]=a[i] ;
    if(lef) for(int i=min(0,2*w-sz);i<w;i++)
        a[i-min(0,2*w-sz)]=get(i,sz)+get(2*w-1-i,sz) ;
    else for(int i=0;i<max(w,sz-w);i++)
        a[i]=get(w-1-i,sz)+get(w+i,sz) ;
    sz=max(w,sz-w) ;
}

int a[maxn],b[maxn],sa,sb ;
void solve()
{
    int n,m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    sa=n ; sb=m ;
    for(int i=0;i<n;i++) a[i]=1 ;
    for(int i=0;i<m;i++) b[i]=1 ;
    while(Q--)
    {
        char s[3] ; scanf("%s",s) ;
        if(s[0]=='?')
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            printf("%d\n",a[x]*b[y]) ;
            continue ;
        }
        int w ; scanf("%d",&w) ;
        if(s[0]=='^') fold(a,sa,sa-w,1) ;
        else if(s[0]=='v') fold(a,sa,w,0) ;
        else if(s[0]=='<') fold(b,sb,sb-w,1) ;
        else if(s[0]=='>') fold(b,sb,w,0) ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
