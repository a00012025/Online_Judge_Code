#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int box[51],w[1001],n,m,sum ;

bool cmp(int x,int y)
{
    return x>y ;
}

bool iddfs(int num,int prev_box)
{
        //printf("%d,%d\n",len,num) ;
    if(num==m) return true ;
    int sum2=0 ; for(int i=num+1;i<=m;i++) sum2+=w[i] ;
    if(sum2>sum) return false ;

    int start=1 ;
    if(prev_box!=-1 && w[num]==w[num+1]) start=prev_box ;
    for(int i=start;i<=n;i++)
    {
        if(w[num+1]>box[i]) continue ;
        int x=box[i] , y=box[i]-w[num+1] ;
        box[i]-=w[num+1] ; sum-=w[num+1] ;
        if(iddfs(num+1,i))
        {
            sum+=w[num+1] ;
            box[i]+=w[num+1] ;
            return true ;
        }
        sum+=w[num+1] ;
        box[i]+=w[num+1] ;
    }
    return false ;
}

main()
{
    scanf("%d %d",&n,&m) ;
    sum=0 ;
    for(int i=1;i<=n;i++) {scanf("%d",&box[i]) ; sum+=box[i] ;}
    for(int i=1;i<=m;i++) scanf("%d",&w[i]) ;
    sort(w+1,w+m+1,cmp) ;
    int l=0 , r=m+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(iddfs(m-mid,-1)) l=mid ;
        else r=mid ;
    }
    printf("%d\n",l) ;
}
