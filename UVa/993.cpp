#include<stdio.h>
#include<string.h>
main()
{
 int n,p[5],ans[1000];
 long long a;
 scanf("%d",&n) ;
 for(int z=1;z<=n;z++)
 	{
 	scanf("%lld",&a) ;
 	if(a==1){printf("1\n") ; continue ;}
 	memset(ans,0,sizeof(ans)) ;
 	memset(p,0,sizeof(p));
 	if(a%2==0)	for(;(a%2==0);a=a/2) p[1]+=1 ;
 	if(a%3==0)	for(;(a%3==0);a=a/3) p[2]+=1 ;
 	if(a%5==0)	for(;(a%5==0);a=a/5) p[3]+=1 ;
 	if(a%7==0)	for(;(a%7==0);a=a/7) p[4]+=1 ;
 	if(a!=1){printf("-1\n") ; continue ;}
 	int num=0 ;
 	if(p[2]!=0){
	 	for(int i=p[2];i>=2;i=i-2){num++ ; ans[num]=9 ;}
	 	p[2]=p[2]%2 ;
 		}
 	if(p[1]!=0){
 		for(int i=p[1];i>=3;i=i-3){num++ ; ans[num]=8 ;}
 		p[1]=p[1]%3 ;
 		}
 	if(p[4]!=0){
 		for(int i=p[4];i>=1;i--){num++ ; ans[num]=7 ;}
 		p[4]=0 ;
		}
	if((p[1]!=0)&&(p[2]!=0)){num++ ; ans[num]=6 ; p[1]-- ; p[2]-- ;}
	if(p[3]!=0){
		for(int i=p[3];i>=1;i--){num++ ; ans[num]=5 ;}
		p[3]=0 ;
		}
	if(p[1]==2){num++ ; ans[num]=4 ; p[1]=0 ;}
	if(p[2]==1){num++ ; ans[num]=3 ; p[2]=0 ;}
	if(p[1]==1){num++ ; ans[num]=2 ; p[1]=0 ;}
	for(int i=num;i>=1;i--)printf("%d",ans[i]) ;
	printf("\n") ;
 	}

}
