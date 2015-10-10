#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

queue<int> q,q2 ;
main()
{
    int n,m,x ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&x) , q.push(x) , q2.push(i) ;
    int last=-1 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int id=q2.front() ; q2.pop() ;
        x-=m ;
        if(x>0) q.push(x) , q2.push(id) ;
        last=id ;
    }
    printf("%d\n",last) ;
}
