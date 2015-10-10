#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int maxn=40000+10 ;
const ULL x=123456789ULL ;
char s[maxn] ;
ULL h[maxn],power[maxn] ;

void get_pow()
{
    power[0]=1ULL ;
    for(int i=1;i<maxn;i++) power[i]=power[i-1]*x ;
}

int n ;
void get_h()
{
    h[0]=0ULL ; h[1]=s[1]-'a' ;
    for(int i=2;i<=n;i++) h[i]=h[i-1]*x+(s[i]-'a') ;
}

ULL gethash(int l,int r)
{
    return h[r]-h[l-1]*power[r-l+1] ;
}

struct P{ULL val ; int id ;};
bool cmp(const P &a,const P &b)
{
    if(a.val==b.val) return a.id<b.id ;
    else return a.val<b.val ;
}

P tmp[maxn] ;
int m ;
int check(int len)
{
    for(int i=1;i+len-1<=n;i++)
    {
        tmp[i].val=gethash(i,i+len-1) ;
        tmp[i].id=i ;
    }

    sort(tmp+1,tmp+n-len+2,cmp) ;
    int cnt=0 , ret=-1 ;
    for(int i=1;i+len-1<=n;i++)
    {
        if(i==1 || tmp[i].val!=tmp[i-1].val) cnt=1 ;
        else cnt++ ;
        if(cnt>=m) ret=max(ret,tmp[i].id) ;
    }
    return ret ;
}

main()
{
    get_pow() ;
    while(scanf("%d",&m)==1 && m)
    {
        scanf("%s",s+1) ;
        n=strlen(s+1) ;
        get_h() ;

        int l=0 , r=n+1 ;
        while(r-l>1)
        {
            int mid=(l+r)/2 ;
            if(check(mid)==-1) r=mid ;
            else l=mid ;
        }
        if(l==0) printf("none\n") ;
        else printf("%d %d\n",l,check(l)-1) ;
    }
}
