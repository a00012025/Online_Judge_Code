#include<stdio.h>
#include<algorithm>
#include<stack>
#include<math.h>
#define DB double
#define pw(x) (((DB)x)*((DB)x))
using namespace std;
typedef struct{double st,ed ; int id ;} P;
bool comp(P x,P y)
{
    return x.ed<y.ed ;
}
int db_cmp(double a,double b)
{
    double e=0.00001 ;
    if(a-b > e) return 1 ;
    if(b-a > e) return -1 ;
    return 0 ;
}
stack<P> st ;
P p[10001] , newp[10001] ;
main()
{
    int n,l,w ;
    while(scanf("%d %d %d",&n,&l,&w)!=EOF){
    int num1=0 ;
    for(int i=1;i<=n;i++)
    {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        if(2*b<=w) continue ;
        double d1=max( (DB)0 , ((DB)a)-sqrt( pw(b) - pw(w)/4 ) ) ;
        double d2=min( (DB)l , ((DB)a)+sqrt( pw(b) - pw(w)/4 ) ) ;
        num1++ ;
        p[num1].st=d1 ; p[num1].ed=d2 ; p[num1].id=num1 ;
    }
    sort(p+1,p+num1+1,comp) ;
    int num2=0 ; while(!st.empty()) st.pop() ;
    for(int i=1;i<=num1;i++)
    {
        while(!st.empty() && db_cmp(st.top().st,p[i].st)!=-1)
            {st.pop() ; num2-- ;}
        st.push(p[i]) ; num2++ ;
    }
    for(int i=num2;i>=1;i--)
    {
        newp[i]=st.top() ;
        st.pop() ;
    }
    //for(int i=1;i<=num1;i++)printf("%lf,%lf\n",p[i].st,p[i].ed);
    double left=(DB)0 ; int nowid=1,ans=0 ;
    while(left<(DB)l)
    {
        if( db_cmp(newp[nowid].st,left)==1 ) break ;
        int i ;
        for(i=nowid;i<=num2 && db_cmp(newp[i].st,left)!=1;i++);
        left=newp[i-1].ed ;
        nowid=i ; ans++ ;
        if(i==num2+1) break ;
    }
    if(left<(DB)l) printf("-1\n") ;
    else printf("%d\n",ans);
    }
}
