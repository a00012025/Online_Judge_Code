#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int n,k ;
int a[maxn],dp[maxn] ;
deque<int> dq ;

main()
{
     scanf("%d",&n) ;
     for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
     int Q ; scanf("%d",&Q) ;
     while(Q--)
     {
          scanf("%d",&k) ;
          dq.clear() ;
          dp[1]=0 ; dq.push_front(1) ;
          for(int i=2;i<=n;i++)
          {
               while(dq.back()+k < i) dq.pop_back() ;
               dp[i]= a[dq.back()]>a[i] ? dp[dq.back()] : dp[dq.back()]+1 ;
               while(!dq.empty() && dp[dq.front()]>dp[i]) dq.pop_front() ;
               while(!dq.empty() && dp[dq.front()]==dp[i] && a[i]>a[dq.front()])
                    dq.pop_front() ;
               dq.push_front(i) ;
          }
          printf("%d\n",dp[n]) ;
     }
}
