#include<bits/stdc++.h>
using namespace std;

vector<int> a ;
priority_queue<int> pq ;

int solve()
{
    vector<int> tmp ;
    for(int i=0;i<a.size();i++)
    {
        tmp.clear() ;
        for(int j=1;j<=a[i];j++)
        {
            if(pq.empty()) return 0 ;
            int u=pq.top() ; pq.pop() ;
            if(!u) return 0 ;
            tmp.push_back(u-1) ;
        }
        for(int j=0;j<tmp.size();j++) pq.push(tmp[j]) ;
    }
    if(pq.top()) return 0 ;
    return 1 ;
}

main()
{
    int n,m ;
    scanf("%d",&n) ;
    while(n--)
    {
        int x,num ; scanf("%d%d",&x,&num) ;
        while(num--) a.push_back(x) ;
    }
    scanf("%d",&m) ;
    while(m--)
    {
        int x,num ; scanf("%d%d",&x,&num) ;
        while(num--) pq.push(x) ;
    }
    sort(a.begin(),a.end(),greater<int>()) ;
    printf("%d\n",solve()) ;
}
