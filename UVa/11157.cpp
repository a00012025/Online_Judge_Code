#include<stdio.h>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;
set<int> big,small ;
int d,tmp[200],cnt ;

bool go1(int st,int ed,int dis)
{
    if(st==ed) return true ;
    set<int>::iterator id,id2 ;
    id=upper_bound(big.begin(),big.end(),st+dis) ; id-- ;
    if((*id) > st) return go1(*id,ed,dis) ;
    if(!small.size()) return false ;
    id2=upper_bound(small.begin(),small.end(),st+dis) ;
    if((id2--)==small.begin()) return false ;
    else if((*id2) > st)
    {
        tmp[++cnt]= (*id2) ;
        small.erase(*id2) ;
        return go1(*id2,ed,dis) ;
    }
    else return false ;
}

bool go2(int st,int ed,int dis)
{
    if(st==ed) return true ;
    set<int>::iterator id,id2 ;
    id=lower_bound(big.begin(),big.end(),st-dis) ;
    if( (*id)<st ) return go2(*id,ed,dis) ;
    if(!small.size()) return false ;
    id2=lower_bound(small.begin(),small.end(),st-dis) ;
    if(id2!=small.end() && (*id2)<st) return go2(*id2,ed,dis) ;
    else return false ;
}

bool ok(int dis)
{
    memset(tmp,0,sizeof(tmp)) ;
    cnt=0 ;
    if(!go1(0,d,dis))
    {
        for(int i=1;i<=cnt;i++) small.insert(tmp[i]) ;
        return false ;
    }
    bool res=go2(d,0,dis) ;
    for(int i=1;i<=cnt;i++) small.insert(tmp[i]) ;
    if(res) return true ;
    else return false ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        big.clear() ; small.clear() ;
        int n ;
        scanf("%d %d",&n,&d) ;
        big.insert(d) ; big.insert(0) ;
        while(n--)
        {
            char s[100] ;
            int a ;
            scanf("%s",s) ;
            sscanf(&s[2],"%d",&a) ;
            if(s[0]=='B') big.insert(a) ;
            else small.insert(a) ;
        }
        int l=0 , r=d ;
        while(r-l>1)
        {
            int mid=(l+r)/2 ;
            if(ok(mid)) r=mid ;
            else l=mid ;
        }
        printf("Case %d: %d\n",++tc,r) ;
    }
}
