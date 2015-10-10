#include<bits/stdc++.h>
#define DB double
using namespace std;

int n,a[10],b[10] ;
main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]) ;
    DB ans=0.0 ;
    for(int i=0;i<n;i++) for(int j=1;j<(1<<n);j++)
    {
        if(j&(1<<i)) continue ;
        DB add=0.0 ;

        int low=-1 , upp=b[i]-1 ;
        for(int z=0;z<n;z++) if(j&(1<<z))
            low=max(low,a[z]) , upp=min(upp,b[z]) ;

        for(int k=low;k<=upp;k++)
        {
            DB exp= ((DB)k) * ((DB)b[i]-max(k+1,a[i])+1)/((DB)b[i]-a[i]+1) ;
            for(int l=0;l<n;l++) if(l!=i && !(j&(1<<l)))
            {
                if(a[l]>=k) { exp=0.0 ; break ; }
                exp *= ((DB)min(b[l],k-1)-a[l]+1)/((DB)b[l]-a[l]+1) ;
            }
            add+=exp ;
        }

        for(int z=0;z<n;z++) if(j&(1<<z))
            add/=((DB)b[z]-a[z]+1) ;
        ans+=add ;
    }

    for(int i=1;i<(1<<n);i++)
    {
        int num=0 ;
        for(int z=0;z<n;z++) if(i&(1<<z)) num++ ;
        if(num<2) continue ;

        DB add=0.0 ;
        int low=-1 , upp=10001 ;
        for(int z=0;z<n;z++) if(i&(1<<z))
            low=max(low,a[z]) , upp=min(upp,b[z]) ;
        for(int k=low;k<=upp;k++)
        {
            DB exp= (DB)k ;
            for(int l=0;l<n;l++) if(!(i&(1<<l)))
            {
                if(a[l]>=k) { exp=0.0 ; break ; }
                exp *= ((DB)min(b[l],k-1)-a[l]+1)/((DB)b[l]-a[l]+1) ;
            }
            add+=exp ;
        }

        for(int z=0;z<n;z++) if(i&(1<<z))
            add/=((DB)b[z]-a[z]+1) ;
        ans+=add ;
    }
    printf("%.10f\n",ans) ;
}
