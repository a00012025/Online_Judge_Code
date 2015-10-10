#include<bits/stdc++.h>
using namespace std;
char pile[10][6] ;
int pow5[]={1,5,25,125,625,3125,15625,78125,390625,1953125} ;
map<vector<int>,double> d ;

double dp(vector<int> &v,int k)
{
    if(!k) return 1.0 ;
    if(d.count(v)) return d[v] ;
    int cnt=0 ; double ans=0.0 ;
    for(int i=0;i<9;i++) if(v[i])
        for(int j=i+1;j<9;j++) if(v[j] && pile[i][v[i]-1]==pile[j][v[j]-1])
        {
            v[i]-- ; v[j]-- ;
            ans+=dp(v,k-2) ;
            v[i]++ ; v[j]++ ; cnt++ ;
        }
    return d[v]= (cnt ? ans/cnt : 0.0) ;
}

main()
{
    char s[5] ;
    while(scanf("%s",s)!=EOF)
    {
        pile[0][0]=s[0] ;
        for(int i=0;i<9;i++) for(int j=0;j<4;j++) if(i||j)
        {
            scanf("%s",s) ; pile[i][j]=s[0] ;
        }
        d.clear() ;
        vector<int> v ; for(int i=1;i<=9;i++) v.push_back(4) ;
        printf("%lf\n",dp(v,36)) ;
    }
}
