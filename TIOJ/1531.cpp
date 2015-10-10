#include<bits/stdc++.h>
using namespace std;
const int maxn=5000000+10 ;

char s[maxn] ;
int Z[maxn] ;
main()
{
    int k,n ; scanf("%d%s",&k,s+1) ;
    n=strlen(s+1) ;
    Z[1]=0 ;
    for(int i=2,L=1,R=1;i<=n;i++)
    {
        if(R<i)
        {
            for(R=i;R<=n && s[R]==s[R-i+1];R++) ; R-- ;
            L=i ; Z[i]=R-i+1 ;
        }
        else if(i+Z[i-L+1]<R) Z[i]=Z[i-L+1] ;
        else
        {
            int R2 ;
            for(R2=R;R2<=n && s[R2]==s[R2-i+1];R2++) ; R2-- ;
            Z[i]=R2-i+1 ;
            if(R2>R) R=R2 , L=i ;
        }
    }
    for(int i=n/k;i>=0;i--) if(Z[i+1]>=i*(k-1))
        { printf("%d\n",i) ; return 0 ; }
}
