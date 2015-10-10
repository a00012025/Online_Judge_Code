#include<bits/stdc++.h>
#define LL long long
#define SQ(x) ((LL)(x)*(x))
#define DIS(a,b) SQ(a.x-b.x)+SQ(a.y-b.y)+SQ(a.z-b.z)
using namespace std;

struct P{int x,y,z ;}a[8];
set<LL> st ;
bool check()
{
    st.clear() ;
    for(int i=0;i<8;i++) for(int j=i+1;j<8;j++)
    {
        st.insert(DIS(a[i],a[j])) ;
        if(st.size()>3) return 0 ;
    }
    if(st.size()!=3) return 0 ;
    auto it=st.begin() ; LL val=*it ;
    return *(++it)==2*val && *(++it)==3*val ;
}

void dfs(int now)
{
    if(now==8 && check())
    {
        printf("YES\n") ;
        for(int i=0;i<8;i++)
            printf("%d %d %d\n",a[i].x,a[i].y,a[i].z) ;
        exit(0) ;
    }
    else if(now==8) return ;
    for(int i=0;i<3;i++)
    {
        dfs(now+1) ;
        swap(a[now].y,a[now].z) ;
        dfs(now+1) ;
        swap(a[now].x,a[now].y) ;
    }
}

main()
{
    for(int i=0;i<8;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z) ;
    dfs(0) ;
    printf("NO\n") ;
}
