#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val==rhs.val ? id>rhs.id : val>rhs.val ;
    }
};

int nex[maxn],las[maxn] ;
int a[maxn] ;
int now[maxn] ;
set<P> st ;

main()
{
    int num,k,n ; scanf("%d%d%d",&num,&k,&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    fill(las,las+maxn,n+1) ;
    for(int i=n;i>=1;i--)
    {
        nex[i]=las[a[i]] ;
        las[a[i]]=i ;
    }

    memset(now,-1,sizeof(now)) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        if(now[a[i]]!=-1)
        {
            st.erase((P){a[i],now[a[i]]}) ;
            now[a[i]]=nex[i] ;
            st.insert((P){a[i],nex[i]}) ;
            continue ;
        }

        ans++ ;
        if(st.size()<k)
        {
            now[a[i]]=nex[i] ;
            st.insert((P){a[i],nex[i]}) ;
            continue ;
        }
        P tmp=*st.begin() ; st.erase(tmp) ;
        now[tmp.id]=-1 ;
        now[a[i]]=nex[i] ;
        st.insert((P){a[i],nex[i]}) ;
    }
    printf("%d\n",ans) ;
}
