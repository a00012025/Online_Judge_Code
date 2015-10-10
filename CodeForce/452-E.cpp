#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=300000+10 ;

struct node
{
    node *p ;
    int l,sz=0 ; /// l : Max
    node *trans[27] ;
    bool vis=0 ;
    node(node *u)
    {
        p=u->p ; l=u->l ;
        for(int i=0;i<27;i++) trans[i]=u->trans[i] ;
    }
    node(int _l,node *_p)
    {
        l = _l ; p = _p ;
        memset(trans,0,sizeof(trans)) ;
    }
};

vector<node*> vn[maxn] ;
void build_SAM(char *A,node *&root)
{
    for(int i=0;i<maxn;i++) vn[i].clear() ;
    node *curnode ;
    root=curnode=new node(0,NULL);//最开始的后缀自动机只有一个节点，长度是0，父亲是空
    for(int i=0;A[i];i++)
    {
        int x=A[i]-'a';//增加一个字符
        node *p=curnode;
        curnode=new node(i+1,NULL);//建立一个Lth为i+1的节点
        vn[i+1].push_back(curnode) ;
        for(;p && p->trans[x]==NULL ; p=p->p) p->trans[x]=curnode;//沿祖先向上，寻找插入位置。同时更新Trans
        if(!p)curnode->p=root;//插入到根的下面
        else
        {
            node *q=p->trans[x];
            if (q->l==p->l+1)curnode->p=q;//成为q的孩子
            else
            {
                node *r=new node(q);r->l=p->l+1;//新建一个节点，表示curnode和q的公共前缀
                vn[r->l].push_back(r) ;
                q->p=r;curnode->p=r;//兄弟
                for (;p && p->trans[x]==q;p=p->p)p->trans[x]=r;//更新第二部分的Trans
            }
        }
    }
    node *u=root ;
    for(int i=0;A[i];i++) u=u->trans[A[i]-'a'] , u->sz++ ;
    for(int i=maxn-1;i>=0;i--) for(auto j : vn[i])
        j->p->sz+=j->sz ;
}

LL ans[maxn] ;
void dfs(node *u1,node *u2,node *u3,node *u)
{
    if(u->vis) return ;
    u->vis=1 ;
    if(u->p)
    {
        LL add=((LL)u1->sz*u2->sz)*u3->sz%MOD ;
        ans[u->p->l+1]+=add ;
        ans[u->l+1]-=add ;
    }
    for(int i=0;i<26;i++)
        if(u1->trans[i] && u2->trans[i] && u3->trans[i])
        dfs(u1->trans[i],u2->trans[i],u3->trans[i],u->trans[i]) ;
}

char s[4][maxn] ;
int len[4] ;
node *root[4] ;
main()
{
    scanf("%s%s%s",s[0],s[1],s[2]) ;
    for(int i=0;i<3;i++)
        len[i]=strlen(s[i]) ,
        build_SAM(s[i],root[i]) ;
    for(int i=0;i<len[1];i++) s[0][len[0]+1+i]=s[1][i] ;
    for(int i=0;i<len[2];i++) s[0][len[0]+len[1]+2+i]=s[2][i] ;
    s[0][len[0]]=s[0][len[0]+len[1]+1]='z'+1 ;
    build_SAM(s[0],root[3]) ;

    dfs(root[0],root[1],root[2],root[3]) ;
    int n=min(len[0],min(len[1],len[2])) ;
    for(int i=0;i<n;i++)
        ans[i+1]=(ans[i+1]+ans[i])%MOD+MOD ,
        printf("%lld\n",ans[i+1]%MOD) ;
}
