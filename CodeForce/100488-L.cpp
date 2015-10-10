#include<stdio.h>
#include<deque>
#include<string.h>
using namespace std;
main()
{
    int n,l,r ;
    char s[101000] ;
    deque<char> q1,q2,q3 ;
    scanf("%d%d%d",&n,&l,&r) ;
    scanf("%s",s) ;
    q1.clear() ; q2.clear() ; q3.clear() ;
    for(int i=0;i<l-1;i++) q1.push_back(s[i]) ;
    for(int i=l-1;i<=r-1;i++) q2.push_back(s[i]) ;
    for(int i=r;i<n;i++) q3.push_back(s[i]) ;
    bool rev=0 ; int q;
    scanf("%d",&q) ;
    for(int i=1;i<=q;i++)
    {
        char c,c1,c2 ;
        scanf("%c",&c);
        while(c!='Q' && c!='S' && c!='R') scanf("%c",&c) ;
        if(c=='R') {rev=!rev ; continue ;}
        if(c=='Q')
        {
            scanf("%c",&c1) ;
            while(c1!='L' && c1!='R') scanf("%c",&c1) ;
            if(c1=='L' && !rev) printf("%c",q2.front()) ;
            if(c1=='R' && !rev) printf("%c",q2.back()) ;
            if(c1=='L' && rev)  printf("%c",q2.back()) ;
            if(c1=='R' && rev)  printf("%c",q2.front()) ;
            continue ;
        }
        scanf("%c",&c1) ;
        while(c1!='L' && c1!='R') scanf("%c",&c1) ;
        scanf("%c",&c2) ;
        while(c2!='L' && c2!='R') scanf("%c",&c2) ;
        if(c1=='L')
        {
            if(c2=='L')
            {
                char tem=q1.back() ;
                q1.pop_back() ;
                if(!rev) q2.push_front(tem) ;
                else q2.push_back(tem) ;
            }
            else if(!rev)
            {
                char tem=q2.front() ;
                q2.pop_front() ;
                q1.push_back(tem) ;
            }
            else if(rev)
            {
                char tem=q2.back() ;
                q2.pop_back() ;
                q1.push_back(tem) ;
            }
        }
        else
        {
            if(c2=='R')
            {
                char tem=q3.front() ;
                q3.pop_front() ;
                if(!rev) q2.push_back(tem) ;
                else q2.push_front(tem) ;
            }
            else if(!rev)
            {
                char tem=q2.back() ;
                q2.pop_back() ;
                q3.push_front(tem) ;
            }
            else if(rev)
            {
                char tem=q2.front() ;
                q2.pop_front() ;
                q3.push_front(tem) ;
            }
        }
    }
}
