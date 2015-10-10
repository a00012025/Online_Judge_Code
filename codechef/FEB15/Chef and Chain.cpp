#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) , ans=0 ;
        for(int i=0;i<n;i++)
        {
            if(i%2==0 && s[i]=='+') ans++ ;
            if(i%2==1 && s[i]=='-') ans++ ;
        }
        printf("%d\n",min(ans,n-ans)) ;
    }
}
