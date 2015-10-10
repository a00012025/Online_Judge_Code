#include<bits/stdc++.h>
using namespace std;
const int maxn=3000000+10 ;

int num[maxn],ri[maxn] ;
bool used[maxn] ;
int tmp[maxn] ;
main()
{
    freopen("empty.in","r",stdin) ;
    freopen("empty.out","w",stdout) ;
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=0;i<n;i++) ri[i]= ( i==n-1 ? 0 : i+1 ) ;
    while(k--)
    {
        int x,y,a,b ; scanf("%d%d%d%d",&x,&y,&a,&b) ;
        for(int i=1,j=(a+b)%n;i<=y;i++,j=(j+a)%n)
            num[j]+=x ;
    }

    for(int i=0;i<n;i++) if(num[i])
    {
        int cnt=0 , j=i ;
        for(int k=1;k<=num[i];j=ri[j])
        {
            if(!used[j]) k++ , used[j]=1 ;
            tmp[cnt++]=j ;
        }
        for(int k=0;k<cnt;k++) ri[tmp[k]]=j ;
    }

    for(int i=0;i<n;i++) if(!used[i])
        { printf("%d\n",i) ; return 0 ; }
}
