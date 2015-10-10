#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000000+10 ;

struct manacher
{
    char *s ;
    int n , *Z ;
    int extl(int l,int r)
    {
        int i=1 ;
        for(;l-i+1>=0 && r+i-1<=2*n-2 && s[l-i+1]==s[r+i-1];i++) ;
        return i-1 ;
    }
    void init(char *t)
    {
        n=strlen(t) ;
        s=new char[2*n+2] ;
        Z=new int[2*n+2] ;
        for(int i=0;i<2*n-1;i++) s[i]=(i%2 ? '$' : t[i/2]) ;
        for(int i=0,L=-1,R=-1;s[i];i++)
        {
            int i2=L+R-i ;
            if(R<i) Z[i]=extl(i,i) ;
            else if(Z[i2]!=R-i+1) Z[i]=min(Z[i2],R-i+1) ;
            else Z[i]=extl(2*i-R,R)+(R-i) ;
            if(i+Z[i]-1>=R) L=i-Z[i]+1 , R=i+Z[i]-1 ;
        }
    }
    bool check(int l,int r)
    {
        return Z[r+l]>=r-l+1 ;
    }
}man[maxn];

struct node
{
    node *l,*r ;
    int c ; int val,fix ;
    node(int _c,int _val){c=_c ; val=_val ; fix=rand() ;}
};

node *merge(node *a,node *b)
{
    if(!a || !b) return a ? a : b ;
    if(a->fix<b->fix)
    {
        node *u=a ;
        u->r=merge(a->r,b) ;
        return u ;
    }
    else
    {
        node *u=b ;
        u->l=merge(a,b->l) ;
        return u ;
    }
}
void split(node *u,node *&a,node *&b,int k)
{
    if(!u){a=b=NULL ; return ;}
    if(u->c <= k)
    {
        a=u ;
        split(u->r,a->r,b,k) ;
    }
    else
    {
        b=u ;
        split(u->l,a,b->l,k) ;
    }
}

int ccnt ;
node *root[maxn] ;
int find(node *&u,int c)
{
    if(!u){u=new node(c,++ccnt) ; return ccnt ; }
    if(u->c == c) return u->val ;
    else if(u->c < c) return find(u->l,c) ;
    else return find(u->r,c) ;
}

int val[maxn] ;
void insert(char *t)
{
    int now=0 ;
    for(int i=0;t[i];i++)
    {
        int c=t[i]-'a' ;
        now=find(root[now],c) ;
    }
    val[now]++ ;
}

char *s[maxn] ;
int len[maxn] ;
main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        int m ; scanf("%d",&m) ;
        s[i]=new char[m+5] ; scanf("%s",s[i]) ;
        man[i].init(s[i]) ;
        insert(s[i]) ;
        len[i]=man[i].n ;
    }
    LL ans=0 ;
    for(int i=0;i<n;i++) for(int j=0,now=0;j<len[i];j++)
    {
        now=find(root[now],s[i][j]-'a') ;
        int mul=(j==len[i]-1 ? 1 : man[i].check(0,len[i]-j-2)) ;
        ans+=2*mul*val[now] ;
    }
    ans-=n ;
    for(int i=1;i<=ccnt;i++) ans-=(LL)val[i]*(val[i]-1)/2 ;
    printf("%lld\n",ans) ;
}
