#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int sum,tag ;
    node(int _s=0){l=r=NULL ; tag=-1 ; sum=_s ;}
};

void push(int L,int R,node *u)
{
    if(u->tag==0)
    {
        u->l->tag=0 ; u->l->sum=0 ;
        u->r->tag=0 ; u->r->sum=0 ;
        u->tag=-1 ;
    }
    else if(u->tag==1)
    {
        int mid=(L+R)/2 ;
        u->l->tag=1 ; u->l->sum=mid-L+1 ;
        u->r->tag=1 ; u->r->sum=R-mid ;
        u->tag=-1 ;
    }
}
void pull(node *u){u->sum=u->l->sum+u->r->sum;}

char s[maxn] ;
node *build(int l,int r,char c)
{
    if(l==r) return new node(s[l]==c) ;
    node *u=new node ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid,c) ;
    u->r=build(mid+1,r,c) ;
    pull(u) ; return u ;
}

void modify(int l,int r,int L,int R,node *u,int val)
{
    if(l==L && r==R)
    {
        if(val==0) u->tag=u->sum=0 ;
        else u->tag=1 , u->sum=r-l+1 ;
        return ;
    }
    int mid=(L+R)/2 ;
    push(L,R,u) ;
    if(r<=mid) modify(l,r,L,mid,u->l,val) ;
    else if(l>mid) modify(l,r,mid+1,R,u->r,val) ;
    else modify(l,mid,L,mid,u->l,val) ,
        modify(mid+1,r,mid+1,R,u->r,val) ;
    pull(u) ;
}
int query(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return u->sum ;
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return query(l,mid,L,mid,u->l)+query(mid+1,r,mid+1,R,u->r) ;
}

node *root[26] ;
int num[26] ;
main()
{
    int n,Q ; scanf("%d%d%s",&n,&Q,s+1) ;
    for(int i=0;i<26;i++) root[i]=build(1,n,(char)'a'+i) ;
    while(Q--)
    {
        int L,R,k ; scanf("%d%d%d",&L,&R,&k) ;
        for(int i=0;i<26;i++)
            num[i]=query(L,R,1,n,root[i]) ,
            modify(L,R,1,n,root[i],0) ;
        if(k)
        {
            for(int i=0,now=L;i<26;now+=num[i],i++) if(num[i])
                modify(now,now+num[i]-1,1,n,root[i],1) ;
        }
        else
        {
            for(int i=25,now=L;i>=0;now+=num[i],i--) if(num[i])
                modify(now,now+num[i]-1,1,n,root[i],1) ;
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<26;j++)
        if(query(i,i,1,n,root[j])){printf("%c",j+'a') ; break ;}
    printf("\n") ;
}
