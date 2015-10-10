#include<bits/stdc++.h>
using namespace std;

bool big(string a,string c,string b,string d)
{
    if(a.size()!=b.size()) return a.size()>b.size() ;
    if(a!=b) return a>b ;
    return c>d ;
}

main()
{
    string a,b ;
    cin >> a >> b ;
    string c,d ; c.push_back('0'-1) ; d.push_back('0'-1) ;
    bool da=0 , db=0 ;
    for(int i=0;i<a.size();i++) if(a[i]=='.')
        c=a.substr(i+1,a.size()-i-1) , a.resize(i) , da=1 ;
    for(int i=0;i<b.size();i++) if(b[i]=='.')
        d=b.substr(i+1,b.size()-i-1) , b.resize(i) , db=1 ;
    if(big(a,c,b,d))
    {
        if(!da) cout << a ;
        else cout << a << "." << c ;
    }
    else
    {
        if(!db) cout << b ;
        else cout << b << "." << d ;
    }
    cout << endl ;
}
