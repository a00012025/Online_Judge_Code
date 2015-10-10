#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P{int x,y;}p[maxn];
int pcnt=0 ;

int a[maxn] ;
char c[maxn] ;
int le[maxn],ri[maxn] ;
stack<int> st ;
vector<int> v[maxn] ;
set<int> st2 ;
main()
{
    int n ; scanf("%d",&n) ;
    gets(c+1) ; gets(c+1) ;
    for(int i=1;i<=n;i++) a[i]=a[i-1]+ (c[i]=='p'?1:-1) ;
    for(int i=0;i<=n;i++)
    {
        le[i]=1 ;
        while(!st.empty() && a[st.top()]<=a[i]) st.pop() ;
        if(!st.empty()) le[i]=st.top()+2 ;
        st.push(i) ;
    }
    while(!st.empty()) st.pop() ;
    for(int i=n;i>=0;i--)
    {
        ri[i+1]=n ;
        while(!st.empty() && a[st.top()]>=a[i]) st.pop() ;
        if(!st.empty()) ri[i+1]=st.top()-1 ;
        st.push(i) ;
    }
    for(int i=1;i<=n;i++) if(c[i]=='p') v[le[i]].push_back(i) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        while(!st2.empty() && *st2.begin()<i) st2.erase(st2.begin()) ;
        for(int j=0;j<v[i].size();j++) st2.insert(v[i][j]) ;
        if(c[i]!='p') continue ;
        set<int>::iterator it=st2.upper_bound(ri[i]) ;
        if(it!=st2.begin())
        {
            it-- ;
            ans=max(ans,*it-i+1) ;
        }
    }
    printf("%d\n",ans) ;
}
