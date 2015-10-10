#include <bits/stdc++.h>
#define pof pop_front
#define pub push_back
#define pob pop_back
using namespace std;
typedef long long ll;

struct Treap{
	char c;
	int size;
	bool rotate;
	Treap *l,*r;
	Treap() {}
	Treap(char c_): c(c_), size(1), rotate(0), l(0), r(0) {}
}space[20000000],*at;

bool choose(int a,int b)
{
	return rand() % ( a + b ) < a ;
	//return rand()<RAND_MAX*a/(a+b);
}

inline int size(Treap *p)
{
	return p?p->size:0;
}

Treap* copy(Treap *p)
{
	if(!p)
		return 0;
	Treap *r = new(at++) Treap(p->c);
	r->l = p->l;
	r->r = p->r;
	r->rotate = p->rotate;
	r->size = p->size;
	//r->pri = p->pri; ////
	return r;
}

void push(Treap *p)
{
	if(p->rotate)
	{
		swap(p->l,p->r);
		if(p->l)
		{
			p->l = copy(p->l);
			p->l->rotate ^= 1;
		}
		if(p->r)
		{
			p->r = copy(p->r);
			p->r->rotate ^= 1;
		}
		p->rotate=0;
	}
}
void pull(Treap *p)
{
	p->size = size(p->l) + size(p->r) + 1 ;
}

Treap* merge(Treap *a,Treap *b)
{
	if(!a || !b) return a?a:b;
	if(choose(size(a),size(b)))
	{
		a=copy(a);
		push(a);
		a->r = merge(a->r,b);
		pull(a);
		return a;
	}
	else
	{
		b=copy(b);
		push(b);
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(Treap *t,Treap* &a,Treap* &b,int k) // Size of a will be k
{
	if(!t)
	{
		a=b=0;
		return;
	}
	t=copy(t);
	push(t);
	if(size(t->l)+1 <= k)
	{
		a=t;
		split(t->r,a->r,b,k-size(t->l)-1);
		pull(a);
	}
	else
	{
		b=t;
		split(t->l,a,b->l,k);
		pull(b);
	}
}

void pre(Treap *p,bool ro)
{
	ro ^= p->rotate;
	if(ro)
	{
		if(p->r)
			pre(p->r,ro);
		putchar(p->c);
		if(p->l)
			pre(p->l,ro);
	}
	else
	{
		if(p->l)
			pre(p->l,ro);
		putchar(p->c);
		if(p->r)
			pre(p->r,ro);
	}
}

char ori[50100];

int main()
{
	int T,n,m,e,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",ori);
		at=space;
		Treap* root=0;
		for(int i=0;i<n;i++)
			root=merge(root,new(at++)Treap(ori[i]));
		while(m--)
		{
//printf("(%d,%d)\n",size(root->l),size(root->r));
			scanf("%d%d%d",&e,&l,&r);
			Treap *tl,*tm,*tr;
			split(root,tm,tr,r);
			split(tm,tl,tm,l-1);
			if(e==1)
			{
				pre(tm,0);
				puts("");
			}
			else if(e==2)
			{
				tm=merge(tm,tm);
			}
			else
			{
				tm=copy(tm);
				tm->rotate ^= 1;
			}
			root= merge( tl, merge(tm,tr) );
		}
	}
	return 0;
}

