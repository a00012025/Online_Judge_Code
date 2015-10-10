#include<stdio.h>
#include<string.h>
double p[1000],last ;

double f(int n)
{
    if(n<500) return p[n] ;
    else return last ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,s ;
        scanf("%d%d%d",&n,&m,&s) ;
        memset(p,0,sizeof(p)) ;
        p[0]=1.0 ;
        for(int i=1;i<n && i<500;i++) for(int j=i-m;j<i;j++)
            {
                if(j<0) continue ;
                p[i]+=p[j]/m ;
                last=p[i] ;
            }
        double ans=0 ;
        int cnt=0 ;
        for(int i=s-m;i<n;i++)
        {
            if(i<0) continue ;
            ans+=f(i)*(i-s+m+1) ;
            cnt+=i-s+m+1 ;
        }
        ans=ans/m ; ans*=100 ;
        char c='%' ;
        if(s<n) printf("100.0%c\n",c) ;
        else printf("%.1lf%c\n",ans,c) ;
    }
}
