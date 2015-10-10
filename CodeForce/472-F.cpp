#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=10000+10 ;

int gauss_elim(int *t,int n,vector<pii> &v)
{
    v.clear() ;
    int j=0 ;
    for(int i=0;i<31;i++)
    {
        int x=-1 ;
        for(int k=j;k<n;k++) if(t[k]&(1<<i))
            {x=k ; break ;}
        if(x==-1) continue ;
        if(x!=j)
        {
            swap(t[x],t[j]) ;
            v.push_back(pii(x,j)) ;
            v.push_back(pii(j,x)) ;
            v.push_back(pii(x,j)) ;
        }
        for(int k=j+1;k<n;k++) if(t[k]&(1<<i))
            v.push_back(pii(k,j)) ,
            t[k]^=t[j] ;
        j++ ;
    }
    return j ;
}

int tmp[50],tmp2[50] ;
bool decomp(int *t,int n,int val,int *res)
{
    memset(tmp2,0,sizeof(tmp2)) ;
    for(int i=0;i<n;i++) for(int j=0;j<30;j++)
        if(t[i]&(1<<j)) tmp2[j]|=(1<<i) ;
    for(int j=0;j<30;j++) if(val&(1<<j))
        tmp2[j]|=(1<<n) ;
    vector<pii> nouse ;
    gauss_elim(tmp2,30,nouse) ;

    fill(res,res+n,0) ;
    for(int i=29;i>=0;i--) if(tmp2[i])
    {
        if(tmp2[i]==(1<<n)) return 0 ;
        int j=0 ;
        while(!(tmp2[i]&(1<<j))) j++ ;
        res[j]=(tmp2[i]&(1<<n)) ? 1 : 0 ;
        for(int k=j+1;k<n;k++) if(tmp2[i]&(1<<k))
            res[j]^=res[k] ;
    }
    return 1 ;
}

int a[maxn],b[maxn] ;
vector<pii> v1,v2 ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=0;i<n;i++) scanf("%d",&b[i]) ;
    int x=gauss_elim(a,n,v1) ;
    int y=gauss_elim(b,n,v2) ;

    reverse(v2.begin(),v2.end()) ;
    for(int i=0;i<y;i++)
    {
        if(!decomp(a,x,b[i],tmp))
            {printf("-1\n") ; return 0 ;}
        if(!tmp[i]) for(int j=i+1;j<x;j++) if(tmp[j])
        {
            swap(tmp[i],tmp[j]) ;
            swap(a[i],a[j]) ;
            v1.push_back(pii(i,j)) ;
            v1.push_back(pii(j,i)) ;
            v1.push_back(pii(i,j)) ;
        }
        tmp[i]=0 ;
        for(int j=0;j<x;j++) if(tmp[j])
            v1.push_back(pii(i,j)) ,
            a[i]^=a[j] ;
    }
    for(int i=y;i<x;i++) v1.push_back(pii(i,i)) ;
    printf("%d\n",v1.size()+v2.size()) ;
    for(auto i : v1) printf("%d %d\n",i.first+1,i.second+1) ;
    for(auto i : v2) printf("%d %d\n",i.first+1,i.second+1) ;
}
