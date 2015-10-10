#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a[30] ;

vector<int> up(vector<int> v)
{
    vector<int> ret ;
    ret.clear() ;
    ret.push_back(v[1]) ;
    ret.push_back(v[5]) ;
    ret.push_back(v[2]) ;
    ret.push_back(v[3]) ;
    ret.push_back(v[0]) ;
    ret.push_back(v[4]) ;
    return ret ;
}

vector<int> right(vector<int> v)
{
    vector<int> ret ;
    ret.clear() ;
    ret.push_back(v[0]) ;
    ret.push_back(v[2]) ;
    ret.push_back(v[4]) ;
    ret.push_back(v[1]) ;
    ret.push_back(v[3]) ;
    ret.push_back(v[5]) ;
    return ret ;
}

void initialize()
{
    for(int i=1;i<=6;i++) a[0].push_back(i);
    int cnt=0 ;
    for(int i=0;i<=2;i++) for(int j=0;j<=3;j++)
    {
        a[cnt]=a[0] ;
        for(int z=1;z<=i;z++) a[cnt]=up(a[cnt]) ;
        for(int z=1;z<=j;z++) a[cnt]=right(a[cnt]) ;
        cnt++ ;
        a[cnt]=a[0] ;
        for(int z=1;z<=i+1;z++) a[cnt]=right(a[cnt]);
        a[cnt]=up(a[cnt]) ;
        for(int z=1;z<=j;z++) a[cnt]=right(a[cnt]) ;
        cnt++ ;
    }
}

main()
{
    initialize() ;
        //for(int i=0;i<24)
    char s[30] ;
    while(gets(s))
    {
        int yes=0 ;
        for(int i=0;i<24;i++)
        {
            bool no=0 ;
            for(int j=0;j<6;j++) if(s[a[i][j]-1]!=s[j+6]) no=1 ;
            if(no==0) {yes=1 ; break ;}
        }
        if(yes) printf("TRUE\n");
        else printf("FALSE\n");
    }
}
