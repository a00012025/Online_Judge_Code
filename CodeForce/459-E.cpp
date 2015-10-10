#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10 ;

struct P
{
    int x,y,dis ;
    void get(){scanf("%d%d%d",&x,&y,&dis);}
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

P v[maxn] ;
int ans[maxn],tmp[maxn],val[maxn] ;
int id[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++) v[i].get() ;
    sort(v,v+m) ;
    for(int i=0;i<m;)
    {
        int j=i , cnt=0 ;
        while(j<m && v[j].dis==v[i].dis) j++ ;
        for(int z=i;z<j;z++) tmp[cnt++]=v[z].x ;
        sort(tmp,tmp+cnt) ;
        cnt=unique(tmp,tmp+cnt)-tmp ;
        for(int z=0;z<cnt;z++) id[tmp[z]]=z , val[z]=ans[tmp[z]] ;
        for(int z=i;z<j;z++)
            ans[v[z].y]=max(ans[v[z].y],val[id[v[z].x]]+1) ;
        i=j ;
    }
    printf("%d\n",*max_element(ans+1,ans+n+1)) ;
}
