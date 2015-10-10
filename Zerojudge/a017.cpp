#include<stdio.h>
#include<stack>
#include<string.h>
#include<map>
using namespace std;
map<char,int> m ;
stack<int> ch,post ;
int cal(int a,int b,int type)
{
        //printf("%d,%d,%d\n",a,b,type) ;
    if(type==-1) return a+b ;
    if(type==-2) return a-b ;
    if(type==-3) return a*b ;
    if(type==-4) return a/b ;
    if(type==-5) return a%b ;
    return 0 ;
}

void process(int c)
{
    int a,b,type ;
    type=c ;
    b=post.top() ; post.pop() ;
    a=post.top() ; post.pop() ;
    post.push(cal(a,b,type)) ;
}

main()
{
    m['+']=-1 ; m['-']=-2 ; m['*']=-3 ; m['/']=-4 ;
    m['%']=-5 ; m['(']=-6 ; m[')']=-7 ;
    char s[100] ;
    while(gets(s))
    {
        if(strlen(s)<=1) continue ;
        while(!ch.empty()) ch.pop();
        while(!post.empty()) post.pop();
        int left=-1 ;
        for(int i=0;i<strlen(s);)
        {
            int add=0 ;
            if(s[i]<'0' || s[i]>'9')
            {
                char c=s[i] ; add=1 ;

                if(c!='(') while(!ch.empty() && ch.top()<=-3 && ch.top()>=-5)
                {
                    process(ch.top()) ;
                    ch.pop() ;
                }
                while(!ch.empty() && m[c]>=-2)
                {
                    if(ch.top()==-6) break ;
                    process(ch.top()) ;
                    ch.pop() ;
                }

                if(m[c]>=-6)
                    ch.push(m[c]) ;
                else if(c==')')
                {
                    while(ch.top()!=-6)
                    {
                        process(ch.top()) ;
                        ch.pop() ;
                    }
                    ch.pop() ;
                }
            }
            else
            {
                int a ;
                sscanf(&s[i],"%d",&a) ;
                post.push(a) ;
                while(a) {a=a/10 ; add++ ;}
            }
            i+=add ;
            while(s[i]==' ') i++ ;
        }
        while(!ch.empty())
        {
            process(ch.top()) ;
            ch.pop() ;
        }
        printf("%d\n",post.top()) ;
    }
}
