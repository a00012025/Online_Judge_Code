#include<stdio.h>
int min(int x,int y){return x>y?y:x ;}
int max(int x,int y){return x>y?x:y ;}
main()
{
    int mx=10001,my=10001,Mx=-10001,My=-10001,x,y ;
    while(scanf("%d%d",&x,&y)!=EOF)
        mx=min(mx,x) , my=min(my,y) ,
        Mx=max(Mx,x) , My=max(My,y) ;
    printf("%d\n",(Mx-mx)*(My-my)) ;
}
