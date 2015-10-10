#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

char s[maxn],t[maxn] ;
int a[2][26],b[2][26] ;
main()
{
    scanf("%s%s",s,t) ;
    for(int i=0;s[i];i++)
    {
        if(s[i]>='a') a[0][s[i]-'a']++ ;
        else a[1][s[i]-'A']++ ;
    }
    for(int i=0;t[i];i++)
    {
        if(t[i]>='a') b[0][t[i]-'a']++ ;
        else b[1][t[i]-'A']++ ;
    }
    int x=0,y=0 ;
    for(int i=0;i<2;i++) for(int j=0;j<26;j++)
    {
        int mi=min(a[i][j],b[i][j]) ;
        x+=mi ; a[i][j]-=mi ; b[i][j]-=mi ;
    }
    for(int i=0;i<2;i++) for(int j=0;j<26;j++)
        y+=min(a[i][j],b[i^1][j]) ;
    printf("%d %d\n",x,y) ;
}
