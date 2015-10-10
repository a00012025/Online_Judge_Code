#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int cnt=0 ;
bool check(char *s,char *t,int n)
{
    cnt++ ;
    if(n%2)
    {
        cnt+=n ;
        for(int i=0;i<n;i++) if(s[i]!=t[i])
            return 0 ;
        return 1 ;
    }
    int n2=n/2 ;
//    if(check(s,t,n2)) return check(s+n2,t+n2,n2) ;
//    return check(s,t+n2,n2) && check(s+n2,t,n2) ;
    if(check(s,t,n2) && check(s+n2,t+n2,n2)) return 1 ;
    if(check(s,t+n2,n2) && check(s+n2,t,n2)) return 1 ;
    return 0 ;
}
char s[maxn],t[maxn] ;
main()
{
    scanf("%s%s",s,t) ;
    printf("%s\n",check(s,t,strlen(s))?"YES":"NO") ;
    if(cnt>75e7) printf("cnt = %d\n",cnt) ;
}
