#include<bits/stdc++.h>
using namespace std;
const int maxn=20000001 ;
char s[maxn] ;
int Z[maxn],len ;

int match(int l,int r)
{
    int ret=0 ;
    for(; l-ret>=0 && r+ret<len && s[l-ret]==s[r+ret] ; ret++) ;
    return ret ;
}

main()
{
    gets(s) ;
    len=strlen(s) ; if(s[len-1]=='\n') len-- ;
    for(int i=len-1;i>=0;i--) s[2*i+2]='.' , s[2*i+1]=s[i] ; s[0]='.' ;
    len=2*len+1 ;

    Z[0]=1 ; int L=0,R=0,ans=1 ;
    for(int i=1;i<len;i++)
    {
        int i2=2*L-i ;
        if(R<i)
        {
            Z[i]=match(i,i) ;
            L=i ; R=i+Z[i]-1 ;
        }
        else if(Z[i2]==R-i+1)
        {
            Z[i]=Z[i2]+match(i-Z[i2],i+Z[i2]) ;
            L=i ; R=i+Z[i]-1 ;
        }
        else Z[i]=min(Z[i2],R-i+1) ;
        ans=max(ans,Z[i]-1) ;
    }
    printf("%d\n",ans) ;
}
