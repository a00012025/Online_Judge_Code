#include<stdio.h>
#include<string.h>
#include<math.h>
int p[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,
43,47,53,59,61,67,71,73,79,83,89,97,101,103,107} ;
int a[7],num[26],M,ans,now,NUM ;
void dfs(int n)
{
 if((now==M)&&(NUM==3)) ans++ ;
 for(int i=n+1;i<=6;i++) if((M%(now*a[i]))==0)
    {
    now*=a[i] ; NUM++ ;
    dfs(i) ;
    now/=a[i] ; NUM-- ;
    }
}
main()
{
 int N,MM=0;
 scanf("%d",&N) ;
 while(N--)
 {//MM++ ; if(MM>3009) MM-- ;
 memset(num,0,sizeof(num)) ;
 for(int i=1;i<=6;i++) 
    {
    scanf("%d",&a[i]) ;
    int n=a[i],j=0 ;
    while(n!=1)
        {
        while(n%p[j]==0) {n=n/p[j] ; num[j]+=1 ;}
        j++ ;
        }
    }       //if(MM==3009)printf("%d,%d",a[5],a[6]);
 int yes=1 ;
 for(int i=0;i<25;i++) if(num[i]%2!=0) {yes=0;printf("0\n");break;}
 if(yes==0) continue ;
 M=1 ; now=1 ; ans=0 ;
 for(int i=0;i<=24;i++) for(int j=1;j<=num[i]/2;j++) M*=p[i] ;
 NUM=0 ;
 dfs(0) ;
 if(yes==1)printf("%d\n",ans/2) ;
 }
}
