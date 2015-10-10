#include<bits/stdc++.h>
using namespace std;

vector<int> v[10]={{0,1,2,3,4,5},{1,2},{0,1,3,4,6},{0,1,2,3,6},
{1,2,5,6},{0,2,3,5,6},{0,2,3,4,5,6},{0,1,2},{0,1,2,3,4,5,6},{0,1,2,3,5,6}} ;
int a[10] ;

main()
{
    for(int i=0;i<10;i++) for(auto j : v[i])
        a[i]|=(1<<j) ;
    char s[3] ; scanf("%s",s) ;
    int ans=1 ;
    for(int i=0;i<2;i++)
    {
        int x=s[i]-'0',cnt=0 ;
        for(int j=0;j<10;j++) if((a[x]&a[j])==a[x])
            cnt++ ;
        ans*=cnt ;
    }
    printf("%d\n",ans) ;
}
