#include<bits/stdc++.h>
using namespace std;

queue<int> q1,q2 ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    while(k--){int x ; scanf("%d",&x) ; q1.push(x) ;}
    scanf("%d",&k) ;
    while(k--){int x ; scanf("%d",&x) ; q2.push(x) ;}
    for(int cnt=0;cnt<100000000;cnt++)
    {
        if(q1.empty()){printf("%d 2\n",cnt) ; return 0 ;}
        if(q2.empty()){printf("%d 1\n",cnt) ; return 0 ;}
        int x=q1.front() ; q1.pop() ;
        int y=q2.front() ; q2.pop() ;
        if(x>y) q1.push(y) , q1.push(x) ;
        else q2.push(x) , q2.push(y) ;
    }
    printf("-1\n") ;
}
