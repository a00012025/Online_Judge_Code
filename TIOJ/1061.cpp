#include<bits/stdc++.h>
using namespace std;
int l[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},
                {1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;

char s[10] ;
bool line(char c)
{
    for(int i=0;i<8;i++)
    {
        bool all=1 ;
        for(int j=0;j<3;j++) if(s[l[i][j]]!=c) all=0 ;
        if(all) return 1 ;
    }
    return 0 ;
}

set<string> a,b,c ;

void dfs(int x,char ch)
{
    if(line('O')) { a.insert(string(s)) ; return ; }
    else if(line('X')) { b.insert(string(s)) ; return ; }
    else if(x==0) { c.insert(string(s)) ; return ; }

    for(int i=0;i<9;i++) if(s[i]=='-')
    {
        s[i]=ch ;
        dfs(x-1,'O'+'X'-ch) ;
        s[i]='-' ;
    }
}

main()
{
    scanf("%s",s) ;
    int num=0,o=0,x=0 ;
    for(int i=0;i<9;i++)
    {
        if(s[i]=='-') num++ ;
        if(s[i]=='O') o++ ;
        if(s[i]=='X') x++ ;
    }
    dfs(num,o==x?'O':'X') ;
    printf("%d %d %d %d\n",a.size()+b.size()+c.size(),a.size(),b.size(),c.size()) ;
}
