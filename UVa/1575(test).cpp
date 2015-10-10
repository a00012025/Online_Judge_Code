#include<bits/stdc++.h>
using namespace std;
int p[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;
int cnt=25 ;

int fac(int x)
{
    int ret=1 ;
    for(int i=1;i<=x;i++) ret*=i ;
    return ret ;
}

main()
{
    for(int i=2;i<=100;i++)
    {
        int x=i ;
        vector<int> v ;
        for(int j=1;x!=1 && j<=cnt;j++) if(x%p[j]==0)
        {
            int t=0 ;
            while(x%p[j]==0) t++ , x/=p[j] ;
            v.push_back(t) ;
        }
        int ans=1 , s=0 ;
        for(int j=0;j<v.size();j++) s+=v[j] ;
        ans=fac(s) ;
        for(int j=0;j<v.size();j++) ans/=fac(v[j]) ;
        printf("%d : %d\n",i,ans) ;
    }
}
