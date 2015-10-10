#include<bits/stdc++.h>
using namespace std;

map<char,int> mp=
{
    {'Q',9},{'R',5},{'B',3},{'N',3},{'P',1},
    {'q',-9},{'r',-5},{'b',-3},{'n',-3},{'p',-1}
} ;

char s[10] ;
main()
{
    int ans=0 ;
    for(int i=0;i<8;i++)
    {
        scanf("%s",s) ;
        for(int j=0;j<8;j++) ans+=mp[s[j]] ;
    }
    if(ans==0) printf("Draw\n") ;
    else if(ans>0) printf("White\n") ;
    else printf("Black\n") ;
}
