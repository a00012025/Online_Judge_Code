#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
struct P {int l,r ;};
bool cmp(P x,P y)
{
    if(x.l != y.l) return x.l<y.l ;
    else return x.r<y.r ;
}
P a[5001] ;
stack<P> st ;
main()
{
    int n;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].r,&a[i].l) ;
    sort(a+1,a+n+1,cmp) ;
    for(int i=1;i<=n;i++)
    {
        if(st.empty()) {st.push(a[i]) ; continue ;}
        else if(st.top().l == a[i].l || st.top().r==a[i].r)
            {st.pop() ; st.push(a[i]) ; continue ;}
        else if(a[i].r <= st.top().l) continue ;
        else if(st.top().r==st.top().l && a[i].l<st.top().r)
        {
            st.pop() ;
            st.push((P){a[i].r,a[i].r}) ;
            continue ;
        }
        //int right=a[i].r ;
        int cnt=0,tmp[5001] ;
        if(st.top().r<a[i].r) st.push(a[i]) ;
        else
        {
            while(!st.empty() && st.top().r>a[i].r)
            {
                tmp[++cnt]=st.top().r ;
                st.pop() ;
            }
            st.push((P){tmp[1],tmp[1]}) ;
        }
    }
    printf("%d\n",st.top().l) ;
}
