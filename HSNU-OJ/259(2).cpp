#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

pii a[maxn];
int now[maxn] ;
set<int> st ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    sort(a+1,a+n+1) ;

    memset(now,0,sizeof(now)) ;
    int nowsum=0 ;
    now[1]=1 ; now[a[1].S+1]=-1 ;
    st.insert(1) ; st.insert(a[1].S+1) ; st.insert(a[1].F+1) ;
    if(a[1].S==a[1].F) nowsum=1 ;
    for(int i=2;i<=n;i++)
    {
        if(a[i].F>a[i-1].F)
        {
            if(!nowsum) st.erase(a[i-1].F+1) ;
            now[a[i-1].F+1]=-nowsum ; nowsum=0 ;
            st.insert(a[i].F+1) ;
        }
        int pos=a[i].F-a[i].S+1 ;
        if(now[pos])
        {
            now[pos]++ ; nowsum++ ;
            if(!now[pos]) st.erase(pos) ;
        }
        else
        {
            set<int>::iterator it=st.lower_bound(pos) ;
            int L,R ;
            R=*it ; it-- ; L=*it ;

            now[L]++ ; if(!now[L]) st.erase(L) ;
            now[L+R-pos]=-1 ; st.insert(L+R-pos) ;

            if(R<=a[i].F)
            {
                now[R]++ ; nowsum++ ;
                if(!now[R]) st.erase(R) ;
            }
        }
    }
    LL ans=0LL , sum=0LL ;
    for(int i=1;i<=a[n].F;i++)
    {
        sum+=now[i] ;
        ans+=sum*(sum-1)/2 ;
    }
    printf("%I64d\n",ans) ;
}
