#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string,int> mp ;
int fa[210000],num[210000],cnt ;
int getfa(int n)
{
    return n==fa[n] ? n : fa[n]=getfa(fa[n]) ;
}

int id(string s)
{
    if(mp.count(s)) return mp[s] ;
    cnt++ ; mp[s]=cnt ; fa[cnt]=cnt ; num[cnt]=1 ;
    return cnt ;
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        mp.clear() ;
        int m ; cnt=0 ;
        scanf("%d",&m) ;
        while(m--)
        {
            char s[100],t[100] ;
            scanf("%s %s",s,t) ;
            int a=id(s) , b=id(t) ;
            if(getfa(a)==getfa(b)) {printf("%d\n",num[getfa(a)]) ; continue ;}
            num[getfa(a)]+=num[getfa(b)] ;
            fa[getfa(b)]=getfa(a) ;
            printf("%d\n",num[getfa(a)]) ;
        }
    }
}
