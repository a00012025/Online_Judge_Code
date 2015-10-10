#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<cassert>
#define DB double
using namespace std;
const int maxn=19870000 ;
int left[maxn],right[maxn],val[1000011],fix[1000011],size[maxn],cnt ;
char data[maxn] ;

int newnode(int value,char c)
{
    if(cnt==maxn-1) cnt=3254567 ;
    int u=++cnt ; left[u]=right[u]=0 ; size[u]=1 ;
    data[u]=c ; if(u<1000011) val[u]=value , fix[u]=rand() ;
    //assert(u<maxn) ;
    return u ;
}

struct Treap
{
    inline int lsize(int u) {return left[u] ? size[left[u]] : 0 ; }
    inline int rsize(int u) {return right[u] ? size[right[u]] : 0 ; }
    void maintain(int u) { size[u]=lsize(u)+rsize(u)+1 ; }

    void left_rotate(int &u)
    {
        int v=right[u] ;
        right[u]=left[v] ;
        left[v]=u ;
        u=v ; v=left[u] ;
        maintain(v) ; maintain(u) ;
    }

    void right_rotate(int &u)
    {
        int v=left[u] ;
        left[u]=right[v] ;
        right[v]=u ;
        u=v ; v=right[u] ;
        maintain(v) ; maintain(u) ;
    }

    void insert(int &u,int value,char c)
    {
        if(!u) u=newnode(value,c) ;
        else if(val[u]>value)
        {
            insert(left[u],value,c) ; maintain(u) ;
            if(fix[left[u]]<fix[u]) right_rotate(u) ;
        }
        else if(val[u]<value)
        {
            insert(right[u],value,c) ; maintain(u) ;
            if(fix[right[u]]<fix[u]) left_rotate(u) ;
        }
    }

    bool randchoice(DB p)
    {
        return ((DB)rand())/((DB)RAND_MAX) <= p ;
    }

    int merge(int a,int b)
    {
        if(!a) return b ;
        if(!b) return a ;
        int newp ;
        if(randchoice( ((DB)size[a])/((DB)size[a]+size[b]) ))
        {
            newp=newnode(-1,data[a]) ;
            left[newp]=left[a] ;
            right[newp]=merge(right[a],b) ;
            maintain(newp) ;
        }
        else
        {
            newp=newnode(-1,data[b]) ;
            right[newp]=right[b] ;
            left[newp]=merge(a,left[b]) ;
            maintain(newp) ;
        }
        return newp ;
    }

    void split(int u,int sz,int &a,int &b)
    {
        if(!u) {a=b=0 ; return ; }
        int newp=newnode(-1,data[u]) ;
        if(sz>=lsize(u)+1)
        {
            split(right[u],sz-lsize(u)-1,a,b) ;
            left[newp]=left[u] ;
            right[newp]=a ;
            a=newp ;
            maintain(newp) ;
        }
        else
        {
            split(left[u],sz,a,b) ;
            right[newp]=right[u] ;
            left[newp]=b ;
            b=newp ;
            maintain(newp) ;
        }
    }
};

void print_ans(int u)
{
    if(!u) return ;
    print_ans(left[u]) ;
    printf("%c",data[u]) ;
    print_ans(right[u]) ;
}

Treap trp ;
main()
{
    srand(time(NULL)) ;
    int m,Q ; scanf("%d",&m) ;
    cnt=0 ; int root ;
    char c ; scanf("%c",&c) ;
    for(int i=0;;i++)
    {
        scanf("%c",&c) ; if(c=='\n') break ;
        trp.insert(root,i,c) ;
    }
    scanf("%d",&Q) ;
    while(Q--)
    {
        int l,r,t ; scanf("%d%d%d",&l,&r,&t) ;
        int sz=size[root] ;
        int root1,root2,tmp,root3 ;
        trp.split(root,l,root1,root2) ;
        trp.split(root2,r-l+1,root2,root3) ;
            //printf("root2 : ") ; print_ans(root2) ; printf("\n") ;
        if(t==sz) root=trp.merge(root,root2) ;
        else if(t==0) root=trp.merge(root2,root) ;
        else
        {
            int root4,root5 ;
            trp.split(root,t,root4,root5) ;
            root=trp.merge(root4,root2) ;
            root=trp.merge(root,root5) ;
        }
        if(size[root]>m) trp.split(root,m,root,root3) ;
        //print_ans(root) ; printf(" , size=%d\n",size[root]) ;
    }
    print_ans(root) ; printf("\n") ;
}
