#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
const int maxn=200000+100 ;
int L[maxn],R[maxn] ;
int rmax[maxn],r[maxn],dis[maxn] ;
int cost[20][maxn],newr[20][maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]) , R[i]=L[i]+R[i] ;
    stack<int> st ;
    for(int i=n;i>=1;i--)
    {
        rmax[i]=R[i] ;
        if(i==n || L[st.top()] > R[i]) { st.push(i) ; continue ; }

        while(!st.empty() && L[st.top()]<=rmax[i])
            rmax[i]=max(rmax[i],rmax[st.top()]) , st.pop() ;

        while(!st.empty() && rmax[i]>=rmax[st.top()]) st.pop() ;
        st.push(i) ;
    }
    for(int i=1;i<=n;i++) debugf("%d,",rmax[i]) ; debugf("\n") ;
    for(int i=1;i<=n;i++) r[i]= lower_bound(L+1,L+n+1,rmax[i]) - L ;
    for(int i=1;i<=n;i++) debugf("%d,",r[i]) ; debugf("\n") ;
    for(int i=1;i<=n;i++) dis[i]= r[i]==n+1 ? INF : L[r[i]]-rmax[i] ;
    for(int i=1;i<=n;i++) debugf("%d,",dis[i]) ; debugf("\n") ;

    for(int i=0;i<20;i++) for(int j=1;j<=n;j++) newr[i][j]=n+1 ;
    for(int i=1;i<=n;i++) if(r[i]!=n+1)
        cost[0][i]=dis[i] , newr[0][i]=r[r[i]] , debugf("newr[%d][%d]=%d\n",0,i,r[r[i]]) ;
    for(int i=1;i<20;i++) for(int j=1;j<=n;j++) if(newr[i-1][j]!=n+1)
    {
        newr[i][j]= newr[i-1][newr[i-1][j]-1] ;
        cost[i][j]= cost[i-1][j]+cost[i-1][newr[i-1][j]-1] ;
        debugf("newr[%d][%d]=%d\n",i,j,newr[i][j]) ;
        debugf("cost[%d][%d]=%d\n",i,j,cost[i][j]) ;
    }

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(y<r[x]) { printf("0\n") ; continue ; }
        int ans=0 ;
        while(1)
        {
            int i ;
            for(i=19;i>=0 && (newr[i][x]==n+1 || newr[i][x]>y);i--) ;
            if(i==-1) { ans+=cost[0][x] ; break ; }
            debugf("i=%d , x=%d\n",i,x) ;
            ans+=cost[i][x] ; x=newr[i][x]-1 ;
        }
        printf("%d\n",ans) ;
    }
}
