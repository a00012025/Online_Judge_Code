#include<stdio.h>
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;

    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int now=0,a,b,c ;
        scanf("%d%d%d",&a,&b,&c) ;
        int n=a+b+c ;
        printf("0") ;

        int t ;
        for(t=0;2*t+2<=b && 2*t+1<=c;t++) ; t-- ;
        printf(" 3 1 2") ; now=2 ; a-- ; b-- ; c-- ;
        for(int i=1;i<=t;i++)
        {
            printf(" %d %d %d %d",now+3,now+5,now+2,now+4) ;
            now+=4 ; b-=2 ; c-=2 ;
        }
        printf(" %d",now+2) ; now+=2 ; b-- ;

        if(b==0 && c==0)
        {
            for(int i=1;i<=a;i++) printf(" %d",now+i) ;
            printf("\n") ; continue ;
        }

        if(b==0 && c)
        {
            for(int i=1;i<=a-2;i++) printf(" %d",now+i) ;
            now+=a-2 ; a=2 ;
            int tmp=now ;
            while(now+3<=n) {printf(" %d",now+3) ; c-- ; now+=3 ;}
            if(now==n) {printf(" %d",n-1) ; now-- ; a-- ;}
            else {printf(" %d",now+1) ; now++ ; a-- ;}
            while(now!=tmp+2 && now!=tmp+1) {printf(" %d",now-3) ; c-- ; now-=3 ;}
            if(now==tmp+1) {printf(" %d",now+1) ; now++ ; a-- ;}
            else {printf(" %d",now-1) ; now-- ; a-- ;}
            while(now+3<=n) {printf(" %d",now+3) ; c-- ; now+=3 ;}
            printf("\n") ; continue ;
        }

        if(c==1 && b>=2)
        {
            printf(" %d %d %d %d",now+3,now+1,now+2,now+4) ;
            now+=4 ; c-- ; b-=2 ; a-- ;
            if(b==0)
            {
                for(int i=1;i<=a;i++) printf(" %d",now+i) ;
                printf("\n") ; continue ;
            }
        }

        if(c==0 && b)
        {
            for(int i=1;i<=a-1;i++) printf(" %d",now+i) ;
            now+=a-1 ; a=1 ;
            while(now+2<=n) {printf(" %d",now+2) ; now+=2 ; b-- ;}
            if(now==n-1) {printf(" %d",n) ; now+=1 ; a-- ;}
            else {printf(" %d",n-1) ; now-=1 ; a-- ;}
            while(b) {printf(" %d",now-2) ; now-=2 ; b-- ;}
            printf("\n") ; continue ;
        }

        if(c==1 && b==1)
        {
            for(int i=1;i<=a-1;i++) printf(" %d",now+i) ;
            now+=a-1 ; a=1 ;
            printf(" %d %d %d",now+3,now+1,now+2) ;
            printf("\n") ; continue ;
        }

        if(b==1 && c>=2)
        {
            for(int i=1;i<=a-c;i++) printf(" %d",now+i) ;
            now+=a-c ; a-=(a-c) ;
            printf(" %d %d %d",now+3,now+1,now+2) ; now+=2 ;
            for(int i=1;i<=c-1;i++) {printf(" %d %d",now+3,now+2) ; now+=2 ;}
            printf("\n") ; continue ;
        }
    }
}
