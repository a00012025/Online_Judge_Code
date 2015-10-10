#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
#define LL long long
using namespace std;
typedef pair<int,LL> pil ;
const int maxn=2000000+10 ;
pil operator + (const pil &a,const pil &b){ return (pil){a.F+b.F,a.S+b.S} ; }
pil ST[maxn*7] ;

int L[maxn],R[maxn] ;
vector<int> tmp ;

int find_in_v(int x)
{
    int l=0 , r=tmp.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(tmp[mid]>x) r=mid ;
        else l=mid ;
    }
    return l ;
}

void add(int l,int r,int L,int R,int id,int x,LL y)
{
    if(l>r || l<L || r>R) return ;
    if(l==L && r==R) {ST[id].F+=x ; ST[id].S+=y ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) add(l,r,L,mid,2*id,x,y) ;
    else if(l>mid) add(l,r,mid+1,R,2*id+1,x,y) ;
    else
    {
        add(l,mid,L,mid,2*id,x,y) ;
        add(mid+1,r,mid+1,R,2*id+1,x,y) ;
    }
}

pil query(int l,int r,int id,int pos)
{
    if(l==r) return ST[id] ;
    int mid=(l+r)/2 ;
    if(pos<=mid) return ST[id]+query(l,mid,2*id,pos) ;
    else return ST[id]+query(mid+1,r,2*id+1,pos) ;
}

int n2 ;
LL get_val(int pos)
{
    LL x=(LL)tmp[pos] ;
    pil p=query(0,n2,1,pos) ;
    return x*p.F + p.S ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&L[i],&R[i]) , tmp.push_back(L[i]) , tmp.push_back(R[i]) ;
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    n2=tmp.size()-1 ; /// 0 ~ n2
    for(int i=1;i<=n;i++) L[i]=find_in_v(L[i]) , R[i]=find_in_v(R[i]) , debugf("%d,%d\n",L[i],R[i]) ;

    for(int i=1;i<=n;i++)
    {
        add(R[i]+1,n2,0,n2,1,1,(LL)-tmp[R[i]] ) ;
        add(0,L[i]-1,0,n2,1,-1,(LL)tmp[L[i]] ) ;
        int l=0 , r=n2 ; LL last1=get_val(0),last2=get_val(n2) ;
        while(r-l>2)
        {
            int mid1=(2*l+r)/3 , mid2=(l+2*r)/3 ;
            LL val1=last1 , val2=get_val(mid1) ;
            LL val3=get_val(mid2) , val4=last2 ;
            //if(i==1) printf("%d : %I64d\n%d : %I64d\n",)
            if(val1>=val2 && val2>=val3 && val3>=val4) l=mid2 , last1=val3 ;
            else if(val1>=val2 && val2>=val3 && val3<=val4) l=mid1 , last1=val2 ;
            else if(val1>=val2 && val2<=val3 && val3<=val4) r=mid2 , last2=val3 ;
            else if(val1<=val2 && val2<=val3 && val3<=val4) r=mid1 , last2=val2 ;
        }
        LL ans=min(last1,last2) ;
        if(r==l+2) ans=min(ans,get_val((r+l)/2)) ;
        printf("%lld\n",ans) ;
    }
}
