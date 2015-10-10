#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

char s[1000],t[1000] ;
int res[100],ST[3000][3000],n,m ;

void modify2(int tree,int l,int r,int id,int pos,int val)
{
    if(l==r) {ST[tree][id]=max(val,ST[tree][id]) ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid) modify2(tree,l,mid,2*id,pos,val) ;
    else modify2(tree,mid+1,r,2*id+1,pos,val) ;
    ST[tree][id]=max(ST[tree][2*id],ST[tree][2*id+1]) ;
}

int query2(int tree,int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[tree][id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query2(tree,l,r,L,mid,2*id) ;
    else if(l>mid) return query2(tree,l,r,mid+1,R,2*id+1) ;
    else return max(query2(tree,l,mid,L,mid,2*id),query2(tree,mid+1,r,mid+1,R,2*id+1)) ;
}

int query(int x1,int x2,int y1,int y2,int l,int r,int id)
{
    if(x1==l && x2==r) return query2(id,y1,y2,0,m,1) ;
    int mid=(l+r)/2 ;
    if(x2<=mid) return query(x1,x2,y1,y2,l,mid,2*id) ;
    else if(x1>mid) return query(x1,x2,y1,y2,mid+1,r,2*id+1) ;
    else return max(query(x1,mid,y1,y2,l,mid,2*id),query(mid+1,x2,y1,y2,mid+1,r,2*id+1)) ;
}

void modify(int L,int R,int id,int posx,int posy,int val)
{
    modify2(id,0,m,1,posy,val) ;
    if(L==R) return ;
    int mid=(L+R)/2 ;
    if(posx<=mid) modify(L,mid,2*id,posx,posy,val) ;
    else modify(mid+1,R,2*id+1,posx,posy,val) ;
}

main()
{
    scanf("%s%s",s+1,t+1) ;
    n=strlen(s+1) , m=strlen(t+1) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        for(int i=1;i<=26;i++) res[i]=INF ;
        char c[3] ;
        while(1)
        {
            scanf("%s",c) ;
            if(c[0]=='$') break ;
            int d ; scanf("%d",&d) ; res[c[0]-'A'+1]=d ;
        }
        memset(ST,0,sizeof(ST)) ;
        int ans=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i]==t[j])
        {
            int r=res[s[i]-'A'+1] ;
            int x1=max(0,i-r-1),y1=max(0,j-r-1),x2=i-1,y2=j-1 ;
            int val=query(x1,x2,y1,y2,0,n,1) ;
            ans=max(ans,val+1) ;
            modify(0,n,1,i,j,val+1) ;
        }
        printf("%d%c",ans,Q?' ':'\n') ;
    }
}
