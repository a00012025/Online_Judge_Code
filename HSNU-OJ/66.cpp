#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=5000000+10 ;
int n,m ;
int L[maxn],R[maxn] ;
map<int,int> mp1,mp2 ;
LL cal(int x,int y)
{
    mp1.clear() ; mp2.clear() ;
    LL ret=0LL ;
    for(int i=1;i<=n;i++)
    {
        if(i>x)
        {
            map<int,int>::iterator it=mp1.find(L[i-x]) ;
            if(it->S==1) mp1.erase(it) ;
            else it->S-- ;

            it=mp2.find(R[i-x]) ;
            if(it->S==1) mp2.erase(it) ;
            else it->S-- ;
        }
        mp1[L[i]]++ ; mp2[R[i]]++ ;
        if(i<x) continue ;
        map<int,int>::iterator it1=mp1.end() ; it1-- ;
        map<int,int>::iterator it2=mp2.begin() ;
        ret+= max(0,it2->F - it1->F + 1 - y + 1) ;
    }
    return ret ;
}

main()
{
    int x,y ; scanf("%d%d%d%d",&m,&n,&x,&y) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]) , R[i]=L[i]+R[i]-1 ;
    if(x!=y) printf("%lld\n",cal(x,y)+cal(y,x)) ;
    else printf("%lld\n",cal(x,y)) ;
}
