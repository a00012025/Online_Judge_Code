#include<bits/stdc++.h>
using namespace std;
main()
{
    int len,n ; while(scanf("%d%d",&len,&n)!=EOF){
    if(n==0 && len==1) {printf("0 0\n") ; return 0 ;}
    if(n==0 || n>len*9) {printf("-1 -1\n") ; return 0 ;}
    if(n==len*9) for(int i=1;i<=len;i++) printf("9") ;
    else
    {
        int k=0 ;
        while(9*(len-k-1)>=n) k++ ; k-- ;
        if(k==-1)
        {
            printf("%d",n%9) ;
            for(int i=1;i<len;i++) printf("9") ;
        }
        else
        {
            printf("1") ;
            for(int i=1;i<=k;i++) printf("0") ;
            int tmp=len-k-1 ;
            if(tmp)
            {
                printf("%d",(n-1)%9) ;
                for(int i=1;i<tmp;i++) printf("9") ;
            }
        }
    }
    printf(" ") ;
    while(n>=9) {printf("9") ; len-- ; n-=9 ; }
    if(len)
    {
        printf("%d",n) , len-- ;
        while(len) printf("0") , len-- ;
    }
    printf("\n") ;
}
}
