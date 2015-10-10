#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1500+10 ;

struct pt
{
    int x,y;
    bool operator < (const pt &rhs) const
    {
        if(x==rhs.x&&y==rhs.y) return 0 ;
        if(x==0&&y<0) return 1 ;
        if(rhs.x==0&&rhs.y<0) return 0 ;
        if(x>0 && rhs.x<=0) return 1 ;
        if(x<=0 && rhs.x>0) return 0 ;
        return ((LL)x)*((LL)rhs.y) - ((LL)y)*((LL)rhs.x) > 0LL ;
    }
}a[maxn],b[maxn];

bool operator == (const pt &a,const pt &b){ return a.x==b.x && a.y==b.y ; }
pt operator - (const pt &a,const pt &b){ return (pt){a.x-b.x,a.y-b.y} ; }
LL cross(const pt &a,const pt &b){ return ((LL)a.x)*((LL)b.y) - ((LL)a.y)*((LL)b.x) ; }
LL dot(const pt &a,const pt &b){ return ((LL)a.x)*((LL)b.x) + ((LL)a.y)*((LL)b.y) ; }

int type(const pt &a,const pt &b)
{
    return dot(a,b)>=0 && cross(a,b)>0 ;
}
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
        int ans=0 ;
        for(int z=1;z<=n;z++)
        {
            int cnt=-1 ;
            for(int j=1;j<=n;j++) if(j!=z)
            {
                b[++cnt]=a[j]-a[z] ;
                int g=__gcd(b[cnt].x,b[cnt].y) ;
                if(g<0) g=-g ;
                b[cnt].x/=g , b[cnt].y/=g ;
            }
            sort(b,b+n-1) ;
            for(int i=0,j=0 ; i<n-1 ;)
            {
                while(type(b[i],b[(j+1)%(n-1)])==1 ||
                      (b[i]==b[j] && b[i]==b[(j+1)%(n-1)]))
                {
                    j=(j+1)%(n-1) ;
                    if(b[j].x==-b[i].y && b[j].y==b[i].x)
                        break ;
                }
                if(b[j].x!=-b[i].y || b[j].y!=b[i].x)
                {
                    if(j==i) j++ ;
                    i++ ; continue ;
                }
                int i2,j2 ;
                for(i2=i ; i2<n-1 && b[i2].x==b[i].x && b[i2].y==b[i].y
                        ; i2++) ;
                for(j2=j ; b[j2].x==b[j].x && b[j2].y==b[j].y
                        ; j2=(j2+1)%(n-1)) ;
                ans+= (i2-i)*( j2>=j ? (j2-j) : (j2-j+n-1) ) ;
                i=i2 ; j=(j2-1+n-1)%(n-1) ;
            }
        }
        printf("%d\n",ans) ;
    }
}
