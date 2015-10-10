#include<bits/stdc++.h>
using namespace std;

char s[2000] ;
int sum[2000] ;
main()
{
    int tc=0 ;
    while(scanf("%s",s+1)!=EOF)
    {
        printf("AB Circle #%d:\n",++tc) ;
        int n=strlen(s+1) ;
        sum[0]=0 ;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+ (s[i]=='a'?1:0) ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        {
            int a1=sum[i]+sum[n]-sum[j] ;
            int a2=sum[j]-sum[i] ;
            int b1=n-j+i-a1 ;
            int b2=j-i-a2 ;
            if(a1==b2 || a2==b1) printf("%d,%d\n",i,j) ;
        }
        printf("\n") ;
    }
}
