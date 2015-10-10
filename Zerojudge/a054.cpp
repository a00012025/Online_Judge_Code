#include<stdio.h>
#include<map>
using namespace std;
map<char,int> m ;
main()
{
    m['A']=1;m['B']=10;m['C']=19;m['D']=28;m['E']=37;m['F']=46;m['G']=55;
    m['H']=64;m['I']=39;m['J']=73;m['K']=82;m['L']=2;m['M']=11;m['N']=20;
    m['O']=48;m['P']=29;m['Q']=38;m['R']=47;m['S']=56;m['T']=65;m['U']=74;
    m['V']=83;m['W']=21;m['X']=3;m['Y']=12;m['Z']=30;
    char s[20] ;
    while(scanf("%s",s)!=EOF)
    {
        int check=s[8]-'0' ;
        int a=0 ;
        for(int i=0;i<8;i++) a+=(8-i)*(s[i]-'0') ;
        for(int i=0;i<26;i++)
        {
            char c='A'+i ;
            if((m[c]+a+check)%10 == 0) printf("%c",c) ;
        }
        printf("\n") ;
    }
}
