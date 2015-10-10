#include<bits/stdc++.h>
#define LL long long
using namespace std;

int cal(LL x)
{
    return x ? x%10+cal(x/10) : 0 ;
}

LL pw(LL x,int n)
{
    return n ? pw(x,n-1)*x : 1LL ;
}

vector<int> v ;
main()
{
    int a,b,c ; scanf("%d%d%d",&a,&b,&c) ;
    for(int i=1;i<100;i++)
    {
        LL x=b*pw(i,a)+c ;
        if(x<=0) continue ;
        if(x>=1000000000) break ;
        if(cal(x)==i) v.push_back(x) ;
    }
    sort(v.begin(),v.end()) ;
    printf("%d\n",v.size()) ;
    for(int i=0;i<v.size();i++) printf("%d%c",v[i],i+1==v.size()?'\n':' ') ;
}
