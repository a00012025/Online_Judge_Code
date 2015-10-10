#include<stdio.h>
#define ULL unsigned long long

ULL get_min(ULL low,int num)
{
    int o[70] ;
    o[0]= low%2 ? 1 : 0 ;
    for(int i=1;i<64;i++)
    {
        o[i]=o[i-1] ;
        if(low & ( ((ULL)1)<<i ) ) o[i]++ ;
    }
    int i ;
    for(i=0;;i++)
    {
        if(low & (((ULL)1)<<i)) continue ;
        if(!(o[63]-o[i]+1<=num)) continue ;
        if(!(o[63]-o[i]+1+i>=num)) continue ;
        break ;
    }
    if(o[63]==num) return low ;
    ULL ret=low ; ret ^= (((ULL)1)<<i) ;
    for(int j=0;j<i;j++) if(ret & (((ULL)1)<<j)) ret ^= (((ULL)1)<<j) ;
    int need=num - (o[63]-o[i]+1) ;
    for(int j=0;j<need;j++) ret ^= (((ULL)1)<<j) ;
    return ret ;
}
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        ULL l,r ; scanf("%I64u%I64u",&l,&r) ;
        for(int i=63;i>=0;i--)
        {
            ULL val=get_min(l,i) ;
            if(val<=r) {printf("%I64u\n",val) ; break ;}
        }
    }
}
