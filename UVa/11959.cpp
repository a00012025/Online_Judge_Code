#include<stdio.h>
#include<vector>
using namespace std;

vector<int> up(vector<int> a)
{
    vector<int> newa ;
    newa.push_back(a[2]) ;
    newa.push_back(a[4]) ;
    newa.push_back(a[1]) ;
    newa.push_back(a[3]) ;
    newa.push_back(a[0]) ;
    newa.push_back(a[5]) ;
    return newa ;
}

vector<int> right(vector<int> a)
{
    vector<int> newa ;
    newa.push_back(a[0]) ;
    newa.push_back(a[1]) ;
    newa.push_back(a[3]) ;
    newa.push_back(a[4]) ;
    newa.push_back(a[5]) ;
    newa.push_back(a[2]) ;
    return newa ;
}

main()
{
    vector<int> a[100] ;
    for(int i=0;i<6;i++) a[0].push_back(i) ;
    int num=1 ;
    for(int i=0;i<3;i++) for(int j=0;j<4;j++)
    {
        vector<int> newa=a[0] ;
        for(int z=1;z<=i+1;z++) newa=right(newa) ;
        newa=up(newa) ;
        for(int z=1;z<=j;z++) newa=right(newa) ;
        a[num++]=newa ;

        if(i==0 && j==0) continue ;
        newa=a[0] ;
        for(int z=1;z<=i;z++) newa=up(newa) ;
        for(int z=1;z<=j;z++) newa=right(newa) ;
        a[num++]=newa ;
    }
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        char s[10],t[10] ;
        scanf("%s %s",s,t) ;
        int yes=0 ;
        for(int i=0;i<24;i++)
        {
            int no=0 ;
            for(int j=0;j<6;j++) if(s[j]!=t[a[i][j]]) no=1 ;
            if(no==0) yes=1 ;
        }
        if(yes) printf("Equal\n") ;
        else printf("Not Equal\n") ;
    }
}
