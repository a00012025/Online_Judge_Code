#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<functional>
using namespace std;
int box[51],w[2001],n,m ;
int yes=0 ;
bool iddfs(int num,int prev_box)
{
    if(num==0) return true ;
    int start=1 ;
    if(prev_box>0 && w[num]==w[num+1]) start=prev_box ;
    for(int i=start;i<=n;i++)
    {
        if(w[num]>box[i]) continue ;
        box[i]-=w[num] ;
        bool result=iddfs(num-1,i) ;
        box[i]+=w[num] ;
        if(result) return true ;
    }
    return false ;
}

main()
{
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    scanf("%d %d",&n,&m) ;
    int boxsum=0 ;
    for(int i=1;i<=n;i++) {scanf("%d",&box[i]) ; boxsum+=box[i] ;}
    for(int i=1;i<=m;i++) scanf("%d",&w[i]) ;
    sort(w+1,w+m+1) ;
    sort(box+1,box+n+1,greater<int>()) ;
    int depth,sum2=0  ;
    for(depth=1;depth<=m;depth++)
    {
        sum2+=w[depth] ;
        if(sum2>boxsum) break ;
        if(!iddfs(depth,-1)) break ;
    }
    printf("%d\n",depth-1) ;
}
