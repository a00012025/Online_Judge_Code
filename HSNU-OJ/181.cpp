#include<stdio.h>
#include<algorithm>
#include<stack>
#define LL long long
#define INF 100000000
using namespace std;
const int maxn=1000000+100 ;
struct P{int x,y,val;}a[maxn];
struct Q{LL y ; int val ; }b[maxn];
int len(const P &p)
{
    return p.x*p.x+p.y*p.y ;
}
bool cmp(P p,P q)
{
    if(len(p) != len(q)) return len(p)<len(q) ;
    else return p.x<q.x ;
}

LL sum[maxn] ;
int right[maxn] ;
bool vis[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val) ;
    sort(a+1,a+n+1,cmp) ;
    int cnt=0 , mval=INF ; LL S=0LL ;
    for(int i=1;i<=n;i++)
    {
        if(i>1 && len(a[i])!=len(a[i-1]))
        {
            b[++cnt]=(Q){S,mval} ;
            mval=a[i].val ;
            S=a[i].y ;
        }
        else mval=min(a[i].val,mval) , S+=a[i].y ;
    }
    b[++cnt]=(Q){S,mval} ;

    sum[0]=0LL ;
    for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+b[i].y ;

    for(int i=1;i<=cnt;i++) right[i]=cnt+1 ;
    stack<int> st ;
    for(int i=cnt;i>=1;i--)
    {
        while(!st.empty() && b[st.top()].val >= b[i].val) st.pop() ;
        if(!st.empty()) right[i]=st.top() ;
        st.push(i) ;
    }

    //for(int i=1;i<=cnt;i++) printf("(%I64d,%d),",b[i].y,b[i].val) ; printf("\n") ;
    //for(int i=1;i<=cnt;i++) printf("%d,",right[i]) ; printf("\n") ;

    LL ans=0LL ;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i;j<=cnt && !vis[j];j=right[j])
            ans=max(ans,((LL)b[j].val)*(sum[right[j]-1]-sum[i-1])) , vis[j]=1 ;
    }
    printf("%lld\n",ans) ;
}
