#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

char s[maxn] ;
int Z[maxn] ;
main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        int n=strlen(s+1) ;
        for(int i=1;i<n+1-i;i++) swap(s[i],s[n+1-i]) ;
        Z[1]=0 ;
        int L=1 , R=1 , ans=0 ;
        for(int i=2;i<=n;i++)
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
            if(Z[i]>=i-1) ans=i-1 ;
        }
        printf("%d\n",ans) ;
    }
}
