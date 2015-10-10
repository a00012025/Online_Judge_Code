#include<stdio.h>
#include<algorithm>
using namespace std;
int ST[1660000] , a[110001] ;
void buildtree(int l,int r,int id)
{
    if(l==r) {ST[id]=a[l] ; return ;}
    int mid=(l+r)/2 ;
    buildtree(l,mid,2*id) ;
    buildtree(mid+1,r,2*id+1) ;
    ST[id]=min(ST[2*id],ST[2*id+1]) ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return min(query(l,mid,L,mid,2*id) , query(mid+1,r,mid+1,R,2*id+1)) ;
}

void modify(int L,int R,int id,int x,int y)
{
    if(L==R) {ST[id]=y ; return ;}
    int mid=(L+R)/2 ;
    if(x<=mid) modify(L,mid,2*id,x,y) ;
    else modify(mid+1,R,2*id+1,x,y) ;
    ST[id]=min(ST[2*id],ST[2*id+1]) ;
}

main()
{
    int n,m;
    scanf("%d %d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    buildtree(1,n,1) ;
    while(m--)
    {
        char s[10000] ;
        scanf("%s",s) ;
        if(s[0]=='q')
        {
            int a,b,i=0 ;
            while(s[i]>'9' || s[i]<'0') i++ ;
            sscanf(&s[i],"%d",&a) ;
            while(s[i]!=',') i++ ;
            i++ ; sscanf(&s[i],"%d",&b) ;
            printf("%d\n",query(a,b,1,n,1)) ;
        }
        else
        {
            int fir,x,y,i=0 ;
            while(s[i]>'9' || s[i]<'0') i++ ;
            sscanf(&s[i],"%d",&x) ;
            fir=a[x] ;
            while(1)
            {
                while(s[i]<='9' && s[i]>='0') i++ ;
                if(s[i]!=',') break ;
                i++ ; sscanf(&s[i],"%d",&y) ;
                modify(1,n,1,x,a[y]) ;
                a[x]=a[y] ;
                x=y ;
            }
            modify(1,n,1,x,fir) ; a[x]=fir ;
        }
        //for(int i=1;i<=n;i++)printf("%d,",query(i,i,1,n,1));
        //printf("\n");
    }
}
