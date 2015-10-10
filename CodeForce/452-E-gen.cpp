#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10 ;
char s[maxn] ;
main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int n=1000 ;
    for(int i=0;i<3;i++)
    {
        if(!i) for(int j=0;j<n;j++)
            s[j]='a'+rand()%26 ;
        printf("%s\n",s) ;
    }
}
