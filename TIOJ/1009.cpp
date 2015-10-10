#include<bits/stdc++.h>
using namespace std;

int a[4],b[4] ;

main()
{
    scanf("%d:%d:%d",&a[1],&a[2],&a[3]) ;
    scanf("%d:%d:%d",&b[1],&b[2],&b[3]) ;
    int cnt=0 ;
    while(a[1]!=b[1] || a[2]!=b[2] || a[3]!=b[3])
    {
        cnt++ ;
        if((++a[3])==60)
        {
            a[3]=0 ;
            if((++a[2])==60)
            {
                a[2]=0 ;
                if((++a[1])==24) a[1]=0 ;
            }
        }
    }
    printf("%02d:%02d:%02d\n",cnt/3600,(cnt%3600)/60,cnt%60) ;
}
