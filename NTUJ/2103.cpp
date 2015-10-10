#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

char s[maxn] ;
int Z[maxn] ;
void getz(int n)
{
    Z[0]=-1 ;
    for(int i=1,L=-1,R=-1;i<n;i++)
    {
        int i2=i-L , R2 ;
        if(R<i)
        {
            for(R2=i;R2<n && s[R2]==s[R2-i];R2++) ; R2-- ;
            L=i ; R=R2 ; Z[i]=R-L+1 ;
        }
        else if(Z[i2]<R-i+1) Z[i]=Z[i2] ;
        else
        {
            for(R2=R+1;R2<n && s[R2]==s[R2-i];R2++) ; R2-- ;
            L=i ; R=R2 ; Z[i]=R-L+1 ;
        }
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) ;
        getz(n) ;
        int ans=0 ;
        for(int i=1;i<n;i++) if(Z[i]==n-i)
            ans++ ;
        printf("%d\n",ans) ;
    }
}
