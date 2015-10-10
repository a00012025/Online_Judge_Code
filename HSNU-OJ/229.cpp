#include<bits/stdc++.h>
using namespace std;
const int maxn=300001 ;
struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return id<rhs.id ;
    }
};

int L[maxn],R[maxn],val[maxn] ;
int a[maxn] ;
set<P> st ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , L[i]=i-1 , R[i]=i+1 ;
    R[0]=1 ;

    for(int i=1;i<n;i++) val[i]=a[i+1]-a[i] , st.insert((P){i,val[i]}) ;

    int now=n , ans=0 ;
    while(k--)
    {
        set<P>::iterator it=st.begin() ;
        P u=(*it) ; st.erase(it) ;
        ans+=u.val ;

        if(L[u.id]==0)
        {
            st.erase((P){R[u.id],val[R[u.id]]}) ;
            L[R[R[u.id]]]=0 ;
            R[0]=R[R[u.id]] ;
        }
        else if(R[u.id]==n)
        {
            st.erase((P){L[u.id],val[L[u.id]]}) ;
            R[L[L[u.id]]]=n ;
            L[n]=L[L[u.id]] ;
        }
        else
        {
            st.erase((P){L[u.id],val[L[u.id]]}) ;
            st.erase((P){R[u.id],val[R[u.id]]}) ;
            now++ ; val[now]=val[L[u.id]]+val[R[u.id]]-val[u.id] ;
            L[now]=L[L[u.id]] ; R[now]=R[R[u.id]] ;
            R[L[L[u.id]]]=now ;
            L[R[R[u.id]]]=now ;
            st.insert((P){now,val[now]}) ;
        }
    }
    printf("%d\n",ans) ;
}
