#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define INF 18446744073709551615ULL
using namespace std;
const int maxn=100000 ;

struct node
{
    node *p ;
    int l,dp[4] ;
    node *trans[4] ;
    node(){l=0 ; p=NULL ;}
    node(node *u)
    {
        p=u->p ; l=u->l ;
        for(int i=0;i<4;i++) trans[i]=u->trans[i] ;
        fill(dp,dp+4,maxn) ;
    }
    node(int _l,node *_p)
    {
        l = _l ; p = _p ;
        memset(trans,0,sizeof(trans)) ;
        fill(dp,dp+4,maxn) ;
    }
};

node *root ;
void build_SAM(char *A)
{
    node *curnode ;
    root=curnode=new node(0,NULL);//最开始的后缀自动机只有一个节点，长度是0，父亲是空
    for(int i=0;A[i];i++)
    {
        int x=A[i]-'A';//增加一个字符
        node *p=curnode;
        curnode=new node(i+1,NULL);//建立一个Lth为i+1的节点
        for(;p && p->trans[x]==NULL ; p=p->p) p->trans[x]=curnode;//沿祖先向上，寻找插入位置。同时更新Trans
        if(!p)curnode->p=root;//插入到根的下面
        else
        {
            node *q=p->trans[x];
            if (q->l==p->l+1)curnode->p=q;//成为q的孩子
            else
            {
                node *r=new node(q);r->l=p->l+1;//新建一个节点，表示curnode和q的公共前缀
                q->p=r;curnode->p=r;//兄弟
                for (;p && p->trans[x]==q;p=p->p)p->trans[x]=r;//更新第二部分的Trans
            }
        }
    }
}

char s[maxn] ;
void DP(node *u)
{
    if(u->dp[0]!=maxn) return ;
    for(int i=0;i<4;i++)
    {
        if(!u->trans[i]) u->dp[i]=1 ;
        else DP(u->trans[i]) ;
    }
    for(int i=0;i<4;i++) if(u->trans[i])
        for(int j=0;j<4;j++)
        u->dp[j]=min(u->dp[j],u->trans[i]->dp[j]+1) ;
}

struct P{ULL a[4][4];};
P operator + (const P &x,const P &y)
{
    P z ;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++)
    {
        z.a[i][j]=INF ;
        for(int k=0;k<4;k++)
            z.a[i][j]=min(z.a[i][j],x.a[i][k]+y.a[k][j]) ;
    }
    return z ;
}

P len[63] ;
ULL getlen(ULL x)
{
    P p ; memset(p.a,0,sizeof(p.a)) ;
    for(int i=0;i<63 && x;i++) if(x&(1LL<<i))
        p=p+len[i] , x^=(1LL<<i) ;
    ULL ret=INF ;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++)
        ret=min(ret,p.a[i][j]) ;
    return ret ;
}

main()
{
    ULL n ; scanf("%I64u%s",&n,s) ;
    if(n==1){printf("1\n") ; return 0 ;}
    build_SAM(s) ;
    DP(root) ;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++)
        len[0].a[i][j]=root->trans[i]->dp[j] ;
    for(int i=1;i<64;i++) len[i]=len[i-1]+len[i-1] ;

    ULL l=0 , r=n ;
    while(r-l>1)
    {
        ULL mid=(r+l)/2 ;
        if(getlen(mid)>=n) r=mid ;
        else l=mid ;
    }
    printf("%I64u\n",r) ;
}
