#include<bits/stdc++.h>
using namespace std;
#ifndef REFERENCE_POINTER
#define REFERENCE_POINTER
template<typename T>
struct _RefCounter{
	T data;
	int ref;
	_RefCounter(const T&d=0):data(d),ref(0){}
};
template<typename T>
struct reference_pointer{
	_RefCounter<T> *p;
	T *operator->(){
		return &(*p).data;
	}
	T &operator*(){
		return p->data;
	}
	operator int(){return(int)(long long)p;}
	reference_pointer&operator=(const reference_pointer &t){
		if(p&&--(*p).ref==0)delete p;
		p=t.p;
		p&&(*p).ref++;
		return*this;
	}
	reference_pointer(_RefCounter<T> *t=0):p(t){
		p&&(*p).ref++;
	}
	reference_pointer(const reference_pointer &t):p(t.p){
		p&&(*p).ref++;
	}
	~reference_pointer(){
		if(p&&--(*p).ref==0)delete p;
	}
};
template<typename T,typename... _Args>
inline reference_pointer<T>
new_reference(_Args... __args){
	return reference_pointer<T>
	(new _RefCounter<T>(T(__args)...));
}
#endif
struct node;
typedef reference_pointer<node> pt;
struct node{
	char data;
	int size;
	pt l,r;
	node(const node&t):data(t.data),size(t.size),l(t.l),r(t.r){}
	node(const char &d){
		size=1;
		data=d;
	}
	inline void up(){
		size=1;
		if(l)size+=l->size;
		if(r)size+=r->size;
	}
};
inline int size(pt &o){return o?o->size:0;}
void split(pt o,pt &a,pt &b,const int &k){
	if(!o)a=b=NULL;
	else{
		o=new_reference<node>(*o);
		if(k<=size(o->l)){
			b=o;
			split(o->l,a,b->l,k);
		}else{
			a=o;
			split(o->r,a->r,b,k-size(o->l)-1);
		}
		o->up();
	}
}
pt merge(pt a,pt b){
	if(!a||!b)return a?a:b;
	static int x;
	if(x++%(a->size+b->size)<a->size){
		a->r=merge(a->r,b);
		a->up();
		return a;
	}else{
		b->l=merge(a,b->l);
		b->up();
		return b;
	}
}
pt build(char *s,int l,int r){
	int mid=(l+r)>>1;
	pt k=new_reference<node>(s[mid]);
	if(l<=mid-1)k->l=build(s,l,mid-1);
	if(mid+1<=r)k->r=build(s,mid+1,r);
	k->up();
	return k;
}
void dfs(pt&t){
	if(!t)return;
	dfs(t->l);
	putchar(t->data);
	dfs(t->r);
}
char s[1000005];
pt root;
pt a,b,c,d,e,f;
int n,m;
int main(){
	scanf("%i%s%i",&m,s,&n);
	root=build(s,0,strlen(s)-1);
	while(n--){
		int l,r,x;scanf("%i%i%i",&l,&r,&x);
		split(root,b,c,++r);
		split(b,a,b,l);
		split(root,d,e,x);
		root=merge(merge(d,b),e);
		split(root,root,f,m);
	}
	dfs(root);puts("");
	return 0;
}
