#include<bits/stdc++.h>
using namespace std;
const int maxn=6000+10 ;

int num[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++){int x ; scanf("%d",&x) ; num[x]++ ;}
    int ans=0 ;
    for(int i=1;i<maxn;i++) if(num[i]>1) ans+=num[i]-1 , num[i+1]+=num[i]-1 ;
    printf("%d\n",ans) ;
}
