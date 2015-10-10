#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int getint()
{
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar() ;
    int x=0 ;
    while(1)
    {
        x=x*10+c-'0' ;
        c=getchar() ;
        if(c<'0'||c>'9') return x ;
    }
}

struct node
{
	node *l,*r,*p ;
	int val,size ;
	int fix ;
	node()
	{
		l=r=p=NULL;
		size=1;
	}
	void update()
	{
		size=1;
		if(l) size+=l->size ;
		if(r) size+=r->size ;
	}
};

node s[maxn],*root ;

void rotate(node* u)
{
	node *fa=u->p,*gfa=fa->p;
	if(fa->l==u)
	{
		if(u->r)
			u->r->p=fa;
		fa->l=u->r;
		u->r=fa;
	}
	else
	{
		if(u->l)
			u->l->p=fa;
		fa->r=u->l;
		u->l=fa;
	}
	fa->p=u;
	if(gfa)
		(gfa->l==fa?gfa->l:gfa->r)=u;
	else
		root=u;
	u->p=gfa;
	fa->update() ;
}

LL ans=0LL , sum ;
void insert(node *u)
{
    node *now = root ;
    u->l = u->r = 0 ;
    u->size = 1 ;
    u->fix=rand() ;
    while(1)
    {
        now->size++ ;
        if(u->val > now->val)
        {
            sum++ ;
            if(now->l) sum+=now->l->size ;
            if(!now->r)
            {
                now->r=u ;
                u->p=now ;
                break ;
            }
            now=now->r ;
        }
        else
        {
            if(!now->l)
            {
                now->l=u ;
                u->p=now ;
                break ;
            }
            now=now->l ;
        }
    }

    while(u->p && u->fix > u->p->fix)
        rotate(u) ;
    u->update() ;
}

void dfsinsert(node *u)
{
    if(!u) return ;
    node *l=u->l , *r=u->r ;
    dfsinsert(l) ;
    insert(u) ;
    dfsinsert(r) ;
}

LL tot ;
node *solve()
{
    int z=getint() ;
    if(z) return s+z ;

    node *x=solve() ;
    node *y=solve() ;

    if(x->size < y->size) swap(x,y) ;

    root=x ;
    sum= -(LL)y->size*(y->size-1)/2;
    tot=(LL) x->size * y->size ;
    dfsinsert(y) ;
    ans+=min(sum,tot-sum) ;

    return root ;
}

main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;++i)
    {
        s[i].val=i ;
        s[i].fix=rand() ;
    }
    root=solve() ;
    printf("%lld\n",ans) ;
}
