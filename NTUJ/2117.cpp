#include<bits/stdc++.h>
#define DB double
using namespace std;

DB cal(DB x,DB y,int t)
{
    if(t==1) return x+y ;
    if(t==2) return x-y ;
    if(t==3) return x*y ;
    return fabs(y)<1e-7 ? 1e7 : x/y ;
}

bool check(const vector<DB> &v)
{
    if(v.size()==1)
    {
        return fabs(v[0]-24)<1e-7 ;
    }
    int sz=v.size() ;
    vector<DB> v2 ;
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) if(i!=j)
    {
        v2.clear() ;
        for(int k=0;k<sz;k++) if(k!=i && k!=j)
            v2.push_back(v[k]) ;
        for(int k=1;k<=4;k++)
        {
            v2.push_back(cal(v[i],v[j],k)) ;
            if(check(v2)) return 1 ;
            v2.pop_back() ;
        }
    }
    return 0 ;
}
bool check(const vector<int> &v)
{
    vector<DB> v2 ;
    for(auto i : v) v2.push_back(i) ;
    return check(v2) ;
}

int pw[]={1,14,196,2744,38416,537824,7529536,105413504} ;
int encode(const vector<int> &t)
{
    int ret=0 ;
    for(int i=(int)t.size()-1;i>=0;i--) ret=ret*14+t[i] ;
    return ret ;
}

bool b[100000] ;
void dfs1(int x,vector<int> &v)
{
    if(v.size()==4){b[encode(v)]=check(v) ; return ;}
    for(int i=x;i<=13;i++)
        v.push_back(i) ,
        dfs1(i,v) ,
        v.pop_back() ;
}

unordered_map<int,int> mp ;
int s1,s2 ;
void dfs2(int x,int val,int val1,int val2)
{
    if(s1+s2==8)
    {
        if(b[val1] && b[val2]) mp[val]++ ;
        return ;
    }
    for(int i=x;i<=13;i++)
    {
        if(s1<4)
        {
            s1++ ;
            dfs2(i,val+i*pw[s1+s2-1],val1+i*pw[s1-1],val2) ;
            s1-- ;
        }
        if(s2<4 && s1)
        {
            s2++ ;
            dfs2(i,val+i*pw[s1+s2-1],val1,val2+i*pw[s2-1]) ;
            s2-- ;
        }
    }
}

void pre_cal()
{
    vector<int> now ;
    dfs1(1,now) ;
    dfs2(1,0,0,0) ;
}

int a[16] ;
void dfs(int x,int val1,int val2,int &ans)
{
    if(x==16){ans+=mp[val1]*mp[val2] ; return ;}
    if(s1<8)
    {
        s1++ ;
        dfs(x+1,val1+a[x]*pw[s1-1],val2,ans) ;
        s1-- ;
    }
    if(x!=1 && s2<8)
    {
        s2++ ;
        dfs(x+1,val1,val2+a[x]*pw[s2-1],ans) ;
        s2-- ;
    }
}

main()
{
//    freopen("in","r",stdin) ;
//    freopen("out","w",stdout) ;
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<16;i++) scanf("%d",&a[i]) ;
        sort(a,a+16) ;
        int ans=0 ;
        dfs(0,0,0,ans) ;
        printf("%d\n",ans/3) ;
    }
}
