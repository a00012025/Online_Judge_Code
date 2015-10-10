#include<bits/stdc++.h>
using namespace std;

int a[2000],pos[2000] ;
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        while(1)
        {
            scanf("%d",&pos[1]) ; if(!pos[1]) break ;
            for(int i=2;i<=n;i++) scanf("%d",&pos[i]) ;
            for(int i=1;i<=n;i++) a[pos[i]]=i ;
            bool ok=1 ;
            for(int i=1;i<n;i++)
            {
                if(a[i+1]>a[i] && a[i]>1 && pos[a[i]-1]>i)
                    {ok=0 ; break ;}
                if(a[i+1]<a[i]-1)
                {
                    bool ok2=1 ;
                    for(int j=a[i+1]+1;j<a[i];j++) if(pos[j]<i)
                        {ok2=0 ; break ;}
                    if(!ok2) { ok=0 ; break ; }
                }
            }
            if(ok) printf("Yes\n") ;
            else printf("No\n") ;
        }
        printf("\n") ;
    }
}
