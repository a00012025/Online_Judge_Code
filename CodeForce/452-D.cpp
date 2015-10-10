#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq1,pq2,pq3 ;
main()
{
    int k,n1,n2,n3,t1,t2,t3 ;
    scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3) ;
    while(n1--) pq1.push(0) ;
    while(n2--) pq2.push(t1) ;
    while(n3--) pq3.push(t1+t2) ;
    while(k--)
    {
        int x=pq1.top() ; pq1.pop() ;
        int y=pq2.top() ; pq2.pop() ;
        int z=pq3.top() ; pq3.pop() ;
        int t=max(max(x,y-t1),z-t1-t2) ;
        pq1.push(t+t1) ;
        pq2.push(t+t1+t2) ;
        pq3.push(t+t1+t2+t3) ;
        if(!k) printf("%d\n",t+t1+t2+t3) ;
    }
}
