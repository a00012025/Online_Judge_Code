#include<bits/stdc++.h>
#define MOD 987654361
#define INV8 864197566
#define LL long long
using namespace std;

LL power(int a,int b)
{
    if(b==0) return 1LL ;
    if(b==1) return (LL)a ;
    LL tmp=power(a,b/2) ;
    if(b%2) return (tmp*tmp%MOD)*a%MOD ;
    else return tmp*tmp%MOD ;
}

struct P
{
    int x,y,id ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

typedef vector<P> poly ;
bool operator == (const poly &p,const poly &q)
{
    for(int i=0;i<p.size();i++)
        if(p[i].x!=q[i].x || p[i].y!=q[i].y) return 0 ;
    return 1 ;
}

void normalize(poly &p)
{
    int mx=100,my=100 ;
    for(auto i : p) mx=min(mx,i.x) , my=min(my,i.y) ;
    for(auto &i : p) i.x-=mx , i.y-=my ;
}

poly rotate(const poly &p)
{
    poly q ;
    for(auto i : p) q.push_back((P){-i.y,i.x,i.id}) ;
    normalize(q) ;
    return q ;
}

poly flip(const poly &p)
{
    poly q ;
    for(auto i : p) q.push_back((P){-i.x,i.y,i.id}) ;
    normalize(q) ;
    return q ;
}

int per[500] ;
bool vis[500] ;
LL cal2(const poly &p,const poly &q,int c)
{
    if(!(p==q)) return 0LL ;
    int m=p.size() ;
    for(int i=0;i<m;i++) per[p[i].id]=q[i].id ;

//    printf("p :") ; for(auto i : p)printf("(%d,%d,%d)",i.x,i.y,i.id) ; printf("\n") ;
//    printf("q :") ; for(auto i : q)printf("(%d,%d,%d)",i.x,i.y,i.id) ; printf("\n") ;

    int num=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=m;i++) if(!vis[i])
    {
        num++ ; vis[i]=1 ;
        for(int j=per[i];j!=i;j=per[j]) vis[j]=1 ;
    }
//    printf("num = %d\n",num) ;
    return power(c,num) ;
}

LL cal(const poly &p,int c)
{
    LL ret=0LL ;
    poly tmp=p ;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            sort(tmp.begin(),tmp.end()) ;
            ret= (ret+cal2(p,tmp,c))%MOD ;
            tmp=rotate(tmp) ;
        }
        tmp=flip(tmp) ;
    }
    return ret ;
}

char s[30][30] ;
poly a[10] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m,c ; scanf("%d%d%d",&n,&m,&c) ;
        for(int i=0;i<n;i++) scanf("%s",s[i]) ;

        int cnt=0 ;
        poly tmp ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='#')
            tmp.push_back((P){i,j,++cnt}) ;
        normalize(tmp) ;

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<4;j++)
            {
                sort(tmp.begin(),tmp.end()) ;
                a[4*i+j]=tmp ;
                tmp=rotate(tmp) ;
            }
            tmp=flip(tmp) ;
        }

        int num=0 ;
        for(int i=0;i<8;i++)
        {
            bool keep=1 ;
            for(int j=0;j<i;j++) if(a[j]==a[i])
                {keep=0 ; break ;}
            if(keep) a[num++]=a[i] ;
        }
//        printf("num=%d\n",num) ;
        LL ans=0LL ;
        for(int i=0;i<num;i++) ans+=cal(a[i],c) ;
        ans = (ans*INV8)%MOD ;
        printf("%lld\n",ans) ;
    }
}
