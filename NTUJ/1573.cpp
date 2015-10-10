#include<bits/stdc++.h>
using namespace std;
const int maxn=1000 ;

char s[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        int dif=0 , mi=0 ;
        for(int i=0;s[i];i++) dif+=(s[i]=='(' ? 1 : -1) , mi=min(mi,dif) ;
        dif-=mi ;
        printf("%d\n",-mi+dif) ;
    }
}
