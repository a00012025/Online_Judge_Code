#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int n ;
bool a[2*maxn] ;
set<int> st ;
int solve(int *p)
{
    memset(a,0,sizeof(a)) ;
    st.clear() ;
    for(int i=1;i<=n;i++)
    {
        if(p[i]>i) a[i-p[i]+n]=1 ;
        else a[i-p[i]]=1 ;
    }
    for(int i=0;i<n;i++) if(a[i])
        st.insert(i) , st.insert(i+n) ;

    int ret=n+1 ;
    for(int i=0;i<n;i++)
    {
        int val=0 ;
        set<int>::iterator it=st.lower_bound(i+(n+1)/2) ;
        if(it!=st.end() && *it<i+n) val=max(val,i+n-(*it)) ;
        if(it!=st.begin())
        {
            it-- ;
            if(*it >= i ) val=max(val,*it-i) ;
        }
        ret=min(ret,val) ;
    }
    return ret ;
}

int p1[maxn],p2[maxn] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&p1[i]) , p2[n+1-i]=p1[i] ;
    printf("%d\n",min(solve(p1),solve(p2))) ;
}
