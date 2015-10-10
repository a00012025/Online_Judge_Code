#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;
struct node
{
    node *l,*r ;
    int val,fix,size,w ;
    node()
    {
        l=r=NULL ;
        fix=rand() ; size=w=1 ;
    }
};

struct Treap
{
    inline int lsize(node *u){ return u->l ? u->l->size : 0 ; }
    inline int rsize(node *u){ return u->r ? u->r->size : 0 ; }
    void maintain(node *u) { if(u) u->size = lsize(u)+rsize(u)+u->w ; }

    void left_rotate(node *&u)
    {
        node *v=u->r ;
        u->r=v->l ;
        v->l=u ;
        u=v ; v=u->l ;
        maintain(v) ; maintain(u) ;
    }

    void right_rotate(node *&u)
    {
        node *v=u->l ;
        u->l=v->r ;
        v->r=u ;
        u=v ; v=u->r ;
        maintain(v) ; maintain(u) ;
    }

    void insert(node *&u,int value)
    {
        if(!u) { u=new node ; u->val=value ; return ; }
        if(value<u->val)
        {
            insert(u->l,value) ; maintain(u) ;
            if(u->l->fix < u->fix) right_rotate(u) ;
        }
        else if(value>u->val)
        {
            insert(u->r,value) ; maintain(u) ;
            if(u->r->fix < u->fix) left_rotate(u) ;
        }
        else { u->w++ ; maintain(u) ; }
    }

    void erase(node *&u,int value)
    {
        if(!u) return ;
        if(u->val==value)
        {
            if(u->l==NULL) { u->w-- ; if(!u->w) u=u->r ;  }
            else if(u->r==NULL) { u->w-- ; if(!u->w) u=u->l ;  }
            else
            {
                if(u->l->fix < u->r->fix)
                {
                    right_rotate(u) ;
                    erase(u->r,value) ;
                }
                else
                {
                    left_rotate(u) ;
                    erase(u->l,value) ;
                }
            }
            maintain(u) ;
        }
        else if(u->val > value) { erase(u->l,value) ; maintain(u) ; }
        else { erase(u->r,value) ; maintain(u) ; }
    }

    int less_equal_than(node *u,int value)
    {
        if(!u) return 0 ;
        if(u->val==value) return u->w + lsize(u) ;
        else if(u->val < value)
            return u->w + lsize(u) + less_equal_than(u->r,value) ;
        else return less_equal_than(u->l,value) ;
    }

    bool in_range(node *u,int lo,int hi)
    {
        if(!u) return 0 ;
        if(hi>=u->val && lo<=u->val) return 1 ;
        if(hi<u->val) return in_range(u->l,lo,hi) ;
        else return in_range(u->r,lo,hi) ;
    }
}trp ;

node* ST[10*maxn] ;

void modify(int L,int R,int id,int pos,int value)
{
    trp.insert(ST[id],value) ;
    if(L==R) return ;
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,value) ;
    else modify(mid+1,R,2*id+1,pos,value) ;
}

void st_erase(int L,int R,int id,int pos,int value)
{
    trp.erase(ST[id],value) ;
    if(L==R) return ;
    int mid=(L+R)/2 ;
    if(pos<=mid) st_erase(L,mid,2*id,pos,value) ;
    else st_erase(mid+1,R,2*id+1,pos,value) ;
}

int query(int l,int r,int L,int R,int id,int value)
{
    if(l==L && r==R) return trp.less_equal_than(ST[id],value) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id,value) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1,value) ;
    else return
        query(l,mid,L,mid,2*id,value)+query(mid+1,r,mid+1,R,2*id+1,value) ;
}

bool st_in_range(int l,int r,int L,int R,int id,int lo,int hi)
{
    if(l==L&&r==R) return trp.in_range(ST[id],lo,hi) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return st_in_range(l,r,L,mid,2*id,lo,hi) ;
    else if(l>mid) return st_in_range(l,r,mid+1,R,2*id+1,lo,hi) ;
    else return st_in_range(l,mid,L,mid,2*id,lo,hi)
            || st_in_range(mid+1,r,mid+1,R,2*id+1,lo,hi) ;
}

int a[maxn] ;
main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    memset(ST,0,sizeof(ST)) ;
    int num=0 ;
    while(T--)
    {
        int type ; scanf("%d",&type) ;
        if(type==0)
        {
            int x ; scanf("%d",&x) ;
            modify(1,maxn,1,num+1,x) ;
            a[++num]=x ;
        }
        else if(type==1)
        {
            int l,r,x ; scanf("%d%d%d",&l,&r,&x) ;
            int ans=0 ;
            for(int i=19;i>=0;i--)
            {
                if(!(x&(1<<i)))
                {
                    if(st_in_range(l,r,1,maxn,1,ans+(1<<i),ans+(1<<(i+1))-1 ))
                        ans+=(1<<i) ;
                }
                else
                {
                    if(!st_in_range(l,r,1,maxn,1,ans,ans+(1<<i)-1 ))
                        ans+=(1<<i) ;
                }
            }
            printf("%d\n",ans) ;
        }
        else if(type==2)
        {
            int k ; scanf("%d",&k) ;
            for(int i=num-k+1;i<=num;i++) st_erase(1,maxn,1,i,a[i]) ;
            num-=k ;
        }
        else if(type==3)
        {
            int l,r,value ; scanf("%d%d%d",&l,&r,&value) ;
            printf("%d\n",query(l,r,1,maxn,1,value)) ;
        }
        else if(type==4)
        {
            int l,r,k ; scanf("%d%d%d",&l,&r,&k) ;
            int lo=0 , hi=500100 ;
            while(hi-lo>1)
            {
                int mid=(hi+lo)/2 ;
                if(query(l,r,1,maxn,1,mid)>=k) hi=mid ;
                else lo=mid ;
            }
            printf("%d\n",hi) ;
        }
    }
}
