#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10,LOG=19 ;
int dep[maxn],anc[maxn][LOG] ;
int getfa(int x,int d)
{
    for(int i=0;i<LOG && d;i++) if(d&(1<<i))
        x=anc[x][i] , d^=(1<<i) ;
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]!=dep[y]) return dep[x]>dep[y] ?
        LCA(getfa(x,dep[x]-dep[y]),y) :
        LCA(x,getfa(y,dep[y]-dep[x])) ;
    if(x==y) return x ;
    for(int i=LOG-1;i>=0;i--) if(anc[x][i]!=anc[y][i])
        x=anc[x][i] , y=anc[y][i] ;
    return anc[x][0] ;
}

main()
{
    for(int i=0;i<LOG;i++) anc[1][i]=1 ;
    int Q,last=0,now=1,cnt=1 ; scanf("%d",&Q) ;
    while(Q--)
    {
        char s[3] ; scanf("%s",s) ;
        if(s[0]=='a')
        {
            int x ; scanf("%d",&x) ; x-=last ;
            dep[++cnt]=dep[x]+1 ;
            anc[cnt][0]=x ;
            for(int i=1;i<LOG;i++)
                anc[cnt][i]=anc[anc[cnt][i-1]][i-1] ;
        }
        else if(s[0]=='r')
        {
            int x ; scanf("%d",&x) ;
            now=x-last ;
        }
        else
        {
            int x,y=now,k,lca,len ; scanf("%d%d",&x,&k) ;
            x-=last ; k-=last ;
            if(x==y){printf("%d\n",last=x) ; continue ;}
            lca=LCA(x,y) ; len=dep[x]+dep[y]-2*dep[lca] ;
            k%=(2*len) ;
            if(k>=len) k-=len , swap(x,y) ;
            if(k<=dep[x]-dep[lca]) last=getfa(x,k) ;
            else last=getfa(y,len-k) ;
            printf("%d\n",last) ;
        }
    }
}
