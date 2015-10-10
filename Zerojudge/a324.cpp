#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;
map<string,char> mp ;
main()
{
    mp["---."]='A' ; mp["--...."]='B' ; mp[".-..-"]='C' ; mp["-----"]='D' ; mp[".--"]='E' ;
    mp["..-.-"]='F' ; mp["--..--"]='G' ; mp["-..."]='H' ; mp["-.--"]='I' ; mp["..-..-.--"]='J' ;
    mp["..-..--"]='K' ; mp["----."]='L' ; mp["..---"]='M' ; mp["-.-."]='N' ; mp["--.-"]='O' ;
    mp["--...-"]='P' ; mp["..-..-..-"]='Q' ; mp[".-.-"]='R' ; mp["-..-"]='S' ; mp["..."]='T' ;
    mp[".-..."]='U' ; mp["..-..."]='V' ; mp["..--."]='W' ; mp["..-..-.-."]='X' ; mp["--..-."]='Y' ;
    mp["..-..-..."]='Z' ;
    int T ; scanf("%d",&T) ;
    string s ;
    char t[300] ; fgets(t,299,stdin) ;
    while(T--)
    {
        fgets(t,299,stdin) ;
        s.clear() ;
        for(int i=0;i<strlen(t) && t[i]!='\n';i++) s.push_back(t[i]) ;
        int now=0 ;
        while(now<s.size())
        {
            if(s[now]==' ') {printf(" ") ; now++ ; continue ;}
            int len=1 ;
            for(;!mp.count(s.substr(now,len));len++) ;
            printf("%c",mp[s.substr(now,len)]) ;
            now+=len ;
        }
        printf("\n") ;
    }
}
