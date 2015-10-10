#include<bits/stdc++.h>
#include "interactive/363.h"
using namespace std;
/*
int Ramen()
{
    return 400 ;
}

int cnt=0 ;
int Compare(int x,int y)
{
    cnt++ ;
    return x<y ? -1 : 1 ;
}

void Answer(int x,int y)
{
    if(x==0 && y==399) printf("yes\n") ;
    //printf("small : %d , big : %d \n",x,y) ;
}
*/

bool vis[800] ;
int p[800] ;
main()
{
    srand(time(NULL)) ;
    int n=Ramen() ;
    if(n==1) Answer(0,0) ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            int x=(((rand())%n)+2*n)%n ;
            if(!vis[x]) {p[i]=x ; vis[x]=1 ; break ; }
        }
    }
    int M=p[0],m=p[1] ;
    if(Compare(m,M)==1) swap(M,m) ;
    int cnt=1 ;
    for(int i=n-1;i>=2;i--)
    {
        cnt++ ;
        if(Compare(p[i],M)==1) M=p[i] ;
        else {cnt++ ; if(Compare(p[i],m)==-1) m=p[i] ; }
        if(cnt>=598) break ;
    }
    //printf("cnt=%d\n",cnt) ;
    Answer(m,M) ;
}
