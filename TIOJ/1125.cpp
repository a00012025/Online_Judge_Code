#include<bits/stdc++.h>
using namespace std;

int cal(int x,int y)
{
    return !(x&&y) ;
}

void cal(int n,int &x,int &y,int &z)
{
    int a[6] ;
    for(int i=0;i<5;i++)
    {
        if(n&(1<<i)) a[5-i]=1 ;
        else a[5-i]=0 ;
    }
    x=cal(cal(a[1],a[2]),cal(a[2],a[3])) ;
    y=cal(cal(a[2],a[3]),cal(a[3],a[4])) ;
    z=cal(cal(a[3],a[4]),cal(a[4],a[5])) ;
}

main()
{
    char s[9] ;
    while(scanf("%s",s)!=EOF)
    {

        if(strlen(s)==5)
        {
            int x,y,z,n=0 ;
            for(int i=0;i<5;i++) n=2*n+(s[i]-'0') ;
            cal(n,x,y,z) ;
            printf("%d%d%d\n",x,y,z) ;
        }
        else
        {
            int x,y,z,ans=0 ;
            for(int i=0;i<(1<<5);i++)
            {
                cal(i,x,y,z) ;
                if(x==s[0]-'0' && y==s[1]-'0' && z==s[2]-'0')
                    ans++ ;
            }
            printf("%d\n",ans) ;
        }
    }
}
