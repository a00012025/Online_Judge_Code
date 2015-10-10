#include<bits/stdc++.h>
using namespace std;

int num[7][2] ;

main()
{
    freopen("geteven.in","r",stdin) ;
    freopen("geteven.out","w",stdout) ;
    map<char,int> mp={{'M',0},{'B',1},{'I',2},{'G',3},{'O',4},{'E',5},{'S',6}} ;
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        char s[3] ; int t ;
        scanf("%s%d",s,&t) ;
        num[mp[s[0]]][(t%2+2)%2]++ ;
    }
    int ans=1 ;
    for(int i=0;i<7;i++) ans*=(num[i][0]+num[i][1]) ;
    int num1=num[1][0]*num[2][1]+num[2][0]*num[1][1] ;
    int num2=0 ;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
        num2+=num[3][i]*num[4][j]*num[5][k]*num[6][(i+j+k+1)%2] ;
    ans-=num1*num2*num[0][1] ;
    printf("%d\n",ans) ;
}
