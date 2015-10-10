#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1024+5 ;

int bit[maxn][maxn] ;
void add(int x,int y,int val)
{
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
        bit[i][j]+=val ;
}
int query(int x,int y)
{
    int ret=0 ;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
        ret+=bit[i][j] ;
    return ret ;
}

main()
{
    int n,op ; scanf("%d",&n) ;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==1)
        {
            int x,y,val ; scanf("%d%d%d",&x,&y,&val) ;
            add(x+1,y+1,val) ;
        }
        else
        {
            int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
            printf("%d\n",query(x2+1,y2+1)-query(x1,y2+1)
                   -query(x2+1,y1)+query(x1,y1)) ;
        }
    }
}
