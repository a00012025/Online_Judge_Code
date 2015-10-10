#include<bits/stdc++.h>
using namespace std;
bool vis[100] ;
void prime()
{
    for(int i=2;i*i<100;i++) if(!vis[i])
        for(int j=i*i;j<100;j+=i) vis[j]=1 ;
}

main()
{
    prime() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        if(a==1)
        {
            if(b<=2) printf("1 1\n") ;
            else if(!vis[b]) printf("2 1\n") ;
            else if(b<=6) printf("%d %d\n",b,b-1) ;
            else printf("-1 -1\n") ;
        }
        else if(a==2)
        {
            if(b==2) printf("2 3\n") ;
            else if(b==3) printf("4 5\n") ;
            else printf("-1 -1\n") ;
        }
        else printf("-1 -1\n") ;
    }
}
