#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b) ;
}

int a[maxn],G1[maxn],G2[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,Q ; scanf("%d%d",&n,&Q) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) G1[i]= i==1?a[i]:gcd(G1[i-1],a[i]) ;
        for(int i=n;i>=1;i--) G2[i]= i==n?a[i]:gcd(G2[i+1],a[i]) ;
        while(Q--)
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            if(l==1 && r==n) printf("0\n") ;
            else if(l==1) printf("%d\n",G2[r+1]) ;
            else if(r==n) printf("%d\n",G1[l-1]) ;
            else printf("%d\n",gcd(G1[l-1],G2[r+1])) ;
        }
    }
}
