#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int a[26][26] ;
char s[maxn],t[maxn] ;
main()
{
    int n ; scanf("%d%s%s",&n,s+1,t+1) ;
    int cnt=0 ;

    for(int i=1;i<=n;i++) if(s[i]!=t[i])
    {
        a[s[i]-'a'][t[i]-'a']=i ;
        cnt++ ;
    }
    for(int i=0;i<26;i++) for(int j=i+1;j<26;j++)
        if(a[i][j] && a[j][i])
    {
        printf("%d\n%d %d\n",cnt-2,a[i][j],a[j][i]) ;
        return 0 ;
    }
    for(int i=0;i<26;i++) for(int j=i+1;j<26;j++) if(a[i][j])
        for(int k=0;k<26;k++)
    {
        if(a[j][k])
        {
            printf("%d\n%d %d\n",cnt-1,a[i][j],a[j][k]) ;
            return 0 ;
        }
        if(a[k][i])
        {
            printf("%d\n%d %d\n",cnt-1,a[i][j],a[k][i]) ;
            return 0 ;
        }
    }
    printf("%d\n-1 -1\n",cnt) ;
}
