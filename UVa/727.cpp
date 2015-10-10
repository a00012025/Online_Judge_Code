#include<stdio.h>
#include<map>
#include<stack>
#include<stdlib.h>
using namespace std;
map<char,int> mp ;
char xd[10]={' ','+','-','*','/'} ;
bool valid(char c)
{
    if(( (c>'9')||(c<'0') )&&(!mp.count(c))) return false ;
    return true ;
}
char inv(int n)
{
    if(n>=0) return n+'0' ;
    if(n==-1) return '+' ;
    if(n==-2) return '-' ;
    if(n==-3) return '*' ;
    if(n==-4) return '/' ;

}
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    mp['+']=-1 ; mp['-']=-2 ; mp['*']=-3 ; mp['/']=-4 ; mp['(']=-5 ; mp[')']=-6 ;
    int T,ans[1000];
    stack<int> ch;
    char s[1000] ;
    scanf("%d",&T);
    gets(s) ; gets(s) ;
    while(T--)
    {
        while(!ch.empty()) ch.pop() ;
        int num=0 ;
        while(1)
        {
            if(gets(s)==NULL) break ;
            if(!valid(s[0])) break ;
            char c=s[0] ;
            if( (c>='0')&&(c<='9') ) ans[num++]=c-'0' ;
            else
            {
                if(c!='(') while(!ch.empty() && ch.top()>=-4 && ch.top()<=-3)
                {
                    ans[num++]=ch.top() ;
                    ch.pop() ;
                }
                if(mp[c]>=-2) while(!ch.empty())
                {
                    if(ch.empty() || ch.top()==-5) break ;
                    ans[num++]=ch.top() ;
                    ch.pop() ;
                }
                if(mp[c]>=-5) ch.push(mp[c]) ;
                else if(mp[c]==-6)
                {
                    while(!ch.empty() && ch.top()!=-5)
                    {
                        ans[num++]=ch.top() ;
                        ch.pop() ;
                    }
                    ch.pop() ;
                }
            }
        }
        while(!ch.empty())
        {
            ans[num++]=ch.top() ;
            ch.pop() ;
        }
        for(int i=0;i<num;i++) printf("%c",inv(ans[i])) ;
        printf("\n") ;
        if(T)printf("\n") ;
    }
}
