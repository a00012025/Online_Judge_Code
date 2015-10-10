#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

typedef int type;
struct node{
	node *l,*r;
	int fix,size;
	type data;
	node(){
		l=r=NULL;
		fix=rand();
		size=1;
	}
	int lsize(){return l?l->size:0;}
	int rsize(){return r?r->size:0;}
};
struct treap{
	node *root;
	treap(){
		root=NULL;
	}
	int size()
	{
	    return root ? root->size : 0 ;
	}
	inline void left_rotate(node *&a){
		node *b=a->r;
		a->r=b->l;
		b->l=a;
		a=b;
		b=a->l;
		b->size=b->lsize()+b->rsize()+1;
		a->size=a->lsize()+a->rsize()+1;
	}
	inline void right_rotate(node *&a){
		node *b=a->l;
		a->l=b->r;
		b->r=a;
		a=b;
		b=a->r;
		b->size=b->lsize()+b->rsize()+1;
		a->size=a->lsize()+a->rsize()+1;
	}
	void insert(node *&p,type data){
		if(!p){
			p=new node;
			p->data=data;
		}else{
			p->size++;
			if(data<p->data){
				insert(p->l,data);
				if(p->l->fix<p->fix)right_rotate(p);
			}else if(data>p->data){
				insert(p->r,data);
				if(p->r->fix<p->fix)left_rotate(p);
			}
		}
	}
	inline void insert(type data){
		insert(root,data);
	}
	int rank(node *p,type data,int cur){
	    if(!p) return cur ;
		if(data==p->data)return p->lsize()+cur+1;
		else if(data<p->data)return rank(p->l,data,cur);
		else return rank(p->r,data,cur+p->lsize()+1);
	}
	inline int rank(type data){
		return rank(root,data,0);
	}
};

struct RET{ int id ; LL val ; };
treap s[maxn] ;
int scnt=0 ;

int tmp[maxn],tcnt ;
void dfs(node *u)
{
    if(!u) return ;
    dfs(u->l) ;
    tmp[tcnt++]=u->data ;
    dfs(u->r) ;
}

RET solve()
{
    int z ; scanf("%d",&z) ;
    if(z) { s[scnt++].insert(z) ; return (RET){scnt-1,0} ; }
    RET r1=solve() ;
    RET r2=solve() ;
    int x=r1.id , y=r2.id ;
    RET ret ; ret.val=r1.val + r2.val ;

    if(s[x].size() < s[y].size()) swap(x,y) ;
    int i=0 ;
    LL cnt=0LL , tot=((LL)s[x].size())*((LL)s[y].size()) ;
    tcnt=0 ; dfs(s[y].root) ;
    for(int i=0;i<tcnt;i++) cnt+=s[x].rank(tmp[i]) ;
    ret.val+=min(cnt,tot-cnt) ;

    for(int i=0;i<tcnt;i++) s[x].insert(tmp[i]) ;
    ret.id=x ;
    return ret ;
}

main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    RET ans=solve() ;
    printf("%lld\n",ans.val) ;
}
