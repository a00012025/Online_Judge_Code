#include<bits/stdc++.h>
using namespace std;

char s[101],t[101] ;
int a[200] ;

void split(int x)
{
    a[x]-=2 ;
    if(x==1) a[x+1]++ ;
    else if(x==2) a[x-1]++ , a[x+1]++ ;
    else a[x-2]++ , a[x+1]++ ;
}

main()
{
    while(scanf("%s%s",s+1,t+1)!=EOF)
    {
        memset(a,0,sizeof(a)) ;
        int n=strlen(s+1) , m=strlen(t+1) ;
        for(int i=1;i<=max(m,n);i++)
        {
            if(i>n) a[i]=t[m+1-i]-'0' ;
            else if(i>m) a[i]=s[n+1-i]-'0' ;
            else a[i]=t[m+1-i]+s[n+1-i]-2*('0') ;
        }
        n=max(n,m)+10 ;

        for(int i=1;i<=n;i++) if(a[i]&&a[i+1]&&(!a[i+2]))
                a[i]-- , a[i+1]-- , a[i+2]++ ;

        for(int i=1;i<=n;i++) if(a[i]==2)
        {
            if(i<=2 || a[i-2]==0) { split(i) ; continue ; }
            int j ;
            for(j=i-2;j>=1 && a[j]+a[j+1]==1;j--) ;
            if(j>=1 && a[j]+a[j+1]==2)
            {
                for(int k=j;k<i-1;k++) a[k]=0 ;
                a[i-1]=1 ;
                split(i) ; continue ;
            }
            if(j>=1 && a[j]+a[j+1]==0)
            {
                a[j]=1 ; j++ ;
                int ri=i+1 ; a[ri]=1 ;
                while(1)
                {
                    while(a[ri]+a[ri+1]==1) ri++ ;
                    if(!(a[ri]==0 && a[ri+1]==2)) break ;
                    ri++ ;
                    a[j]=1 ; j++ ;
                    ri++ ; a[ri]=1 ;
                }
                a[j]=0 ; a[j+1]=0 ;
                for(int z=j+2;z<=ri;z++) a[z]=1-a[z-1] ;
                continue ;
            }

            a[1]=1-a[1] ; a[i+1]=1 ;
            int ri=i+1 ;
            while(1)
            {
                while(a[ri]+a[ri+1]==1) ri++ ;
                if(!(a[ri]==0 && a[ri+1]==2)) break ;
                ri++ ; a[ri+1]=1 ; ri++ ; a[1]=1-a[1] ;
            }
            for(int j=2;j<=ri;j++) a[j]=1-a[j-1] ;
        }

        for(int i=n+2;i>=1;i--) if(a[i]&&a[i+1])
        {
            for(int j=i;a[j]&&a[j+1];j+=2) a[j]-- , a[j+1]-- , a[j+2]++ ;
        }

        int M ; for(M=n+2;!a[M];M--) ;
        for(int i=M;i>=1;i--) printf("%d",a[i]) ;
        printf("\n\n") ;
    }
}
