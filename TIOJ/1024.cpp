#include<bits/stdc++.h>
using namespace std;

string add(const string &a,const string &b)
{
    return "(("+a+"|"+a+")|("+b+"|"+b+"))" ;
}

string mul(const string &a,const string &b)
{
    return "(("+a+"|"+b+")|("+a+"|"+b+"))" ;
}

string f(int x)
{
    if(x==0) { return "((A0|B0)|(A0|B0))" ; }
    string a="A" ; a+=x+'0' ;
    string b="B" ; b+=x+'0' ;
    return add(mul(a,b),mul(add(a,b),f(x-1))) ;
}

string g(int x)
{
    if(x==0) { return "((A0|B0)|(A0|B0))" ; }
    string a="A" ; a+=x+'0' ;
    string b="B" ; b+=x+'0' ;
    return "(("+a+"|"+b+")|("+g(x-1)+"|(("+a+"|"+a+")|("+b+"|"+b+"))))" ;
}

main()
{
    int n ; scanf("%d",&n) ;
    string ans1=f(n) ;
    string ans2=g(n) ;
    int num1=0 , num2=0 ;
    for(int i=0;i<ans1.size();i++) if(ans1[i]=='|') num1++ ;
    for(int i=0;i<ans2.size();i++) if(ans2[i]=='|') num2++ ;
    cout << "ans1:" << endl << ans1 << endl
        << num1 << " NAND(s) used." << endl ;
    cout << "ans2:" << endl << ans2 << endl
        << num2 << " NAND(s) used." << endl ;
}
