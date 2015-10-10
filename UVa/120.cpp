#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,a[100],b[100] ;

void flip(int k)
{
    for(int i=1;i<=n+1-k;i++) b[i]=a[n+2-k-i] ;
    for(int i=1;i<=n+1-k;i++) a[i]=b[i] ;
    printf("%d ",k) ;
}

main()
{
    char s[300] ;
    while(gets(s))
    {
        n=0 ;
        for(int i=0;i<strlen(s);)
        {
            n++ ;
            sscanf(&s[i],"%d",&a[n]) ;
            while(i<strlen(s) && s[i]>='0' && s[i]<='9') i++ ;
            i++ ;
        }
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ') ;
        for(int i=n;i>=1;i--)
        {
            int M=0 ;
            for(int j=1;j<=i;j++) M=max(M,a[j]) ;
            if(a[i]==M) continue ;
            int id ;
            for(id=1;a[id]!=M;id++) ;
            if(id==1) flip(n+1-i) ;
            else
            {
                flip(n+1-id) ;
                flip(n+1-i) ;
            }
        }
        printf("0\n") ;
    }
}
