#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,a[1001],A,B,tc=0;
    int gs[1001],num1[11],num2[11] ;
    while(scanf("%d",&n)==1 && n)
    {
        printf("Game %d:\n",++tc);
        for(int i=1;i<=9;i++) num1[i]=0 ;
        for(int i=1;i<=n;i++)
            {scanf("%d",&a[i]) ; num1[a[i]]++ ;}
        while(1)
        {
            int fin=1 ;
            for(int i=1;i<=n;i++) {scanf("%d",&gs[i]) ; if(gs[i]) fin=0;}
            if(fin) break ;
            A=0 ; B=0 ;
            for(int i=1;i<=9;i++) num2[i]=0 ;
            for(int i=1;i<=n;i++)
                {if(gs[i]==a[i]) A++ ; num2[gs[i]]++ ;}
            for(int i=1;i<=9;i++) B+=min(num1[i],num2[i]) ;
            printf("    (%d,%d)\n",A,B-A) ;
        }
    }
}
