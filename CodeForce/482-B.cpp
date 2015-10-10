#include<bits/stdc++.h>
using namespace std;
bool data[35][1000000] ;

void modify(int l,int r,int L,int R,int id,int col)
{
    if(l==L && r==R) {data[col][id]=1 ; return ; }
    if(data[col][id]) return ;
    int mid=(L+R)/2 ;
    if(mid>=r) modify(l,r,L,mid,2*id,col) ;
    else if(mid<l) modify(l,r,mid+1,R,2*id+1,col) ;
    else {modify(l,mid,L,mid,2*id,col) ; modify(mid+1,r,mid+1,R,2*id+1,col) ;}
}

bool have_zero(int l,int r,int L,int R,int id,int col)
{
    if(data[col][id]) return 0 ;
    if(l==L && r==R) return data[col][id]==0 ;
    int mid=(L+R)/2 ;
    if(mid>=r) return have_zero(l,r,L,mid,2*id,col) ;
    else if(mid<l) have_zero(l,r,mid+1,R,2*id+1,col) ;
    else return have_zero(l,mid,L,mid,2*id,col) || have_zero(mid+1,r,mid+1,R,2*id+1,col) ;
}

int n ;
vector<pair<int,int> >v[31] ;
bool ok()
{
    for(int i=0;i<30;i++) for(int j=0;j<v[i].size();j++)
    {
        int l=v[i][j].first , r=v[i][j].second ;
        if(!have_zero(l,r,1,n,1,i)) return 0 ;
    }
    return 1 ;
}

bool query(int L,int R,int x,int id,int col)
{
    if(data[col][id]) return 1 ;
    if(L==R) return data[col][id] ;
    int mid=(L+R)/2 ;
    if(x<=mid) return query(L,mid,x,2*id,col) ;
    else return query(mid+1,R,x,2*id+1,col) ;
}

bool ans[101001][40] ;
main()
{
    int q ;
    scanf("%d%d",&n,&q) ;
    memset(data,0,sizeof(data)) ;
    for(int i=0;i<30;i++) v[i].clear() ;
    while(q--)
    {
        int l,r,val ; scanf("%d%d%d",&l,&r,&val) ;
        for(int i=0;i<30;i++)
        {
            if((1<<i)&val) modify(l,r,1,n,1,i) ;
            else v[i].push_back(make_pair(l,r)) ;
        }
    }
    if(!ok()) {printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
    for(int j=1;j<=n;j++) for(int i=0;i<30;i++)
        ans[j][i]=query(1,n,j,1,i) ;
    for(int j=1;j<=n;j++)
    {
        int val=0 ;
        for(int i=29;i>=0;i--) {val*=2 ; val+=ans[j][i] ;}
        printf("%d%c",val,j==n?'\n':' ') ;
    }
}
