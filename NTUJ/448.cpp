#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+5 , maxl=200+5 ;

struct node
{
    node *p ;
    int l ;
    node *trans[26] ;
    node(){l=0 ; p=NULL ;}
    node(node *u)
    {
        p=u->p ; l=u->l ;
        for(int i=0;i<26;i++) trans[i]=u->trans[i] ;
    }
    node(int _l,node *_p)
    {
        l = _l ; p = _p ;
        memset(trans,0,sizeof(trans)) ;
    }
};

void build_SAM(char *A,node *&root)
{
    node *curnode ;
    root=curnode=new node(0,NULL);//最开始的后缀自动机只有一个节点，长度是0，父亲是空
    for(int i=0;A[i];i++)
    {
        int x=A[i]-'a';//增加一个字符
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

void up(string &x,const string &y)
{
    if(y.size()>x.size()) x=y ;
    else if(y.size()==x.size() && y<x) x=y ;
}

node *root[maxn],*now[maxn] ;
char s[maxn][maxl] ;
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",s[i]) ,
            build_SAM(s[i],root[i]) ;
        string ans="" ;
        for(int i=0;s[0][i];i++)
        {
            for(int k=1;k<n;k++) now[k]=root[k] ;
            int j=i ;
            for(;s[0][j];j++)
            {
                bool ok=1 ;
                for(int k=1;k<n;k++)
                    if(!now[k]->trans[s[0][j]-'a']){ok=0 ; break ;}
                    else now[k]=now[k]->trans[s[0][j]-'a'] ;
                if(!ok) break ;
            }
            up(ans,string(s[0]+i,s[0]+j)) ;
        }
        if(ans.empty()) ans="IDENTITY LOST" ;
        cout << ans << endl ;
    }
}
