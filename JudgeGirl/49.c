#include<stdio.h>
int s[1010],M[1010],m[1010] ;
main()
{
    int n,k,x ; scanf("%d%d",&n,&k) ;
    for(int i=0;i<k;i++) m[i]=100000 , M[i]=-1 ;
    while(n--)
    {
        scanf("%d",&x) ;
        s[x%k]+=x ;
        if(m[x%k]>x) m[x%k]=x ;
        if(M[x%k]<x) M[x%k]=x ;
    }
    for(int i=0;i<k;i++) printf("%d %d %d\n",s[i],M[i],m[i]) ;
}
