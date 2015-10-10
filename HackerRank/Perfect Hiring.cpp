#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int main()
{
    int n,p,x ; scanf("%d%d%d",&n,&p,&x) ;
    int id=-1 ; LL M=-1 ;
    for(int i=1;i<=n;i++,p-=x)
    {
        int y ; scanf("%d",&y) ;
        LL v=(LL)y*p ;
        if(v>M) M=v , id=i ;
    }
    printf("%d\n",id) ;
}
