#include<bits/stdc++.h>
using namespace std;

main()
{
    int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
    if(x1<=x2 && y1<=y2) printf("Polycarp\n") ;
    else if(x1+y1 <= max(x2,y2)) printf("Polycarp\n") ;
    else printf("Vasiliy\n") ;
}
