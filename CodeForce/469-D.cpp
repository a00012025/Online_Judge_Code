#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int s[100001],group[100001] ;
int A[100001],B[100001] ;
map<int,int> m ;
main()
{
    int n,a,b,no=0 ;
    memset(A,0,sizeof(A)) ;
    memset(B,0,sizeof(B)) ;
    memset(group,0,sizeof(group)) ;
    scanf("%d%d%d",&n,&a,&b) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]) ;
        m[s[i]]=i ;
    }
    for(int i=1;i<=n;i++)
    {
        if(m.count(a-s[i])==1) A[i]=m[a-s[i]] ;
        if(m.count(b-s[i])==1) B[i]=m[b-s[i]] ;
        if(A[i]==0 && B[i]==0) no=1 ;
    }
    if(no==1) {printf("NO\n") ; return 0 ;}
    for(int i=1;i<=n;i++)
    {
        if(A[i]!=0 && B[i]!=0) continue ;
        if(A[i]!=0)
        {
            bool cnt=0 ;
            int j=i ;
            while(1)
            {
                group[j]=1 ;
                if(cnt==0)
                {
                    if(A[j]==0) break ;
                    j=A[j] ;
                }
                else if(cnt==1)
                {
                    if(B[j]==0) break ;
                    j=B[j] ;
                }
                cnt=!cnt ;
            }
            if(A[j]==0) {printf("NO\n") ; return 0 ;}
        }
        else if(B[i]!=0)
        {
            bool cnt=0 ;
            int j=i ;
            while(1)
            {
                group[j]=2 ;
                if(cnt==0)
                {
                    if(B[j]==0) break ;
                    j=B[j] ;
                }
                else if(cnt==1)
                {
                    if(A[j]==0) break ;
                    j=A[j] ;
                }
                cnt=!cnt ;
            }
            if(B[j]==0) {printf("NO\n") ; return 0 ;}
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(group[i]!=0) continue ;
        bool cnt=0 ; group[i]=1 ;
        int j=A[i] ;
        while(1)
        {
            if(j==i) break ;
            group[j]=1 ;
            if(cnt==0) j=B[j] ;
            if(cnt==1) j=A[j] ;
            cnt=!cnt ;
        }
    }
    printf("YES\n") ;
    for(int i=1;i<=n;i++)
        if(group[i]==1) printf("0 ") ;
        else printf("1 ") ;
    printf("\n") ;
}
