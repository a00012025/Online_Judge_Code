#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int size,val,sum,fix ;
    node(int _v)
    {
        l=r=NULL ;
        val=sum=_v ;
        size=1 ;
        fix=rand() ;
    }
};

inline int size(node *u){return u ? u->size : 0 ;}
inline void pull(node *u)
{
    if(u)
        u->sum=u->val+(u->l?u->l->sum:0)+(u->r?u->r->sum:0) ,
        u->size=1+size(u->l)+size(u->r);
}

node *merge(node *a,node *b)
{
    if(!a||!b) return a ? a : b ;
    if(a->fix<b->fix)
    {
        a->r=merge(a->r,b) ;
        pull(a) ;
        return a ;
    }
    else
    {
        b->l=merge(a,b->l) ;
        pull(b) ;
        return b ;
    }
}

void split1(node *u,node *&a,node *&b,int k)
{
    if(!u){a=b=NULL ; return ;}
    if(u->val<=k)
    {
        a=u ;
        split1(u->r,a->r,b,k) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split1(u->l,a,b->l,k) ;
        pull(b) ;
    }
}

void split2(node *u,node *&a,node *&b,int k)
{
    if(!u){a=b=NULL ; return ;}
    if(k>=size(u->l)+1)
    {
        a=u ;
        split2(u->r,a->r,b,k-size(u->l)-1) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split2(u->l,a,b->l,k) ;
        pull(b) ;
    }
}

node *root ;
void insert(int x)
{
    node *a,*b ;
    split1(root,a,b,x) ;
    root=merge(merge(a,new node(x)),b) ;
}

int query(int k)
{
    node *a,*b ;
    split2(root,a,b,k) ;
    int ret=a ? a->sum : 0 ;
    root=merge(a,b) ;
    return ret ;
}

vector<int> v[maxn],now ;
main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
    }
    for(int i=0;i<maxn;i++)
        sort(v[i].begin(),v[i].end(),greater<int>()) ;

    int nownum=0,nowsum=0 ;
    for(int i=1;i<maxn;i++) if(!v[i].empty())
    {
        if(v[i].size()>=v[0].size())
        {
            nownum+=v[i].size()-v[0].size()+1 ;
            if(v[0].empty()) nownum-- ;

            int st=v[0].empty() ? 0 : v[0].size()-1 ;
            for(int j=st;j<v[i].size();j++)
                nowsum+=v[i][j] ;
            now.push_back(i) ;
        }
        for(int j=0;j<v[i].size() && j+1<v[0].size();j++)
            insert(v[i][j]) ;
    }

    int ans=2147483647 ;
    for(int i=v[0].size();i<=n;i++)
    {
        int num2=v[0].size()+nownum ;
        if(num2<=i)
            ans=min(ans,nowsum+query(i-num2)) ;

        if(i==0) continue ;
        for(int j=0;j<now.size();j++)
        {
            insert(v[now[j]][i-1]) ;
            nownum-- ; nowsum-=v[now[j]][i-1] ;
            if(v[now[j]].size()==i)
                swap(now[j],now.back()) ,
                now.pop_back() , j-- ;
        }
    }
    printf("%d\n",ans) ;
}
