#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

char s[maxn] ;
int a[maxn],b[maxn] ;
main()
{
    int n,x,y ; scanf("%s%d%d",s+1,&x,&y) ;
    n=strlen(s+1) ;
    for(int i=1;i<=n;i++) a[i]=((a[i-1]*10%x)+s[i]-'0')%x ;
    for(int i=n,j=1;i>=1;i--,j=j*10%y) b[i]=(b[i+1]+j*(s[i]-'0'))%y ;
    for(int i=1;i<n;i++) if(!a[i]&&!b[i+1]&&s[i+1]!='0')
    {
        printf("YES\n") ;
        for(int j=1;j<=i;j++) printf("%c",s[j]) ; printf("\n") ;
        for(int j=i+1;j<=n;j++) printf("%c",s[j]) ; printf("\n") ;
        return 0 ;
    }
    printf("NO\n") ;
}
