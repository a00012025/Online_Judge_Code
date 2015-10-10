#include<bits/stdc++.h>
using namespace std;

bool win(int h1,int a1,int d1,int h2,int a2,int d2)
{
    if(a1<=d2) return 0 ;
    int k=h2/(a1-d2) ; if(h2-k*(a1-d2)>0) k++ ;
    return h1-k*(a2-d1) > 0 ;
}

int h1,a1,d1,h2,a2,d2 ;
int c1,c2,c3 ;

int check(int x)
{
    for(int i=0;i*c1<=x;i++) for(int j=0;i*c1+j*c2<=x;j++)
        if(win(h1+i,a1+j,d1+(x-i*c1-j*c2)/c3,h2,a2,d2)) return 1 ;
    return 0 ;
}

main()
{
    scanf("%d%d%d%d%d%d%d%d%d",&h1,&a1,&d1,&h2,&a2,&d2,&c1,&c2,&c3) ;
    if(win(h1,a1,d1,h2,a2,d2)) { printf("0\n") ; return 0 ; }
    int l=0 , r=1000000 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
