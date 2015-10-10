#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=60 ;

LL a[maxn] ;
vector<int> ans ;
void getans(int n,LL k,int add)
{
    if(!n || k==1)
    {
        for(int i=1;i<=n;i++) ans.push_back(i+add) ;
        return ;
    }
    if(k>a[n-1])
    {
        ans.push_back(add+2) ;
        ans.push_back(add+1) ;
        getans(n-2,k-a[n-1],add+2) ;
    }
    else
    {
        ans.push_back(add+1) ;
        getans(n-1,k,add+1) ;
    }
}

main()
{
    a[0]=a[1]=1 ;
    for(int i=2;i<=50;i++) a[i]=a[i-1]+a[i-2] ;
    int n ; LL k ; scanf("%d%lld",&n,&k) ;
    getans(n,k,0) ;
    for(int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
