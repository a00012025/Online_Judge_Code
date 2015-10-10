#include<bits/stdc++.h>
using namespace std;

vector<int> tmp ;
int find_in_v(int x)
{
    if(tmp[0]==x) return 0 ;
    int l=0 , r=tmp.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(tmp[mid]>=x) r=mid ;
        else l=mid ;
    }
    return r ;
}

int a[80001],num[191][80001] ;
int val[191][191],cnt[191][191] ;
int nownum[80001] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp.push_back(a[i]) ;
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    for(int i=1;i<=n;i++) a[i]=find_in_v(a[i])+1 ;
    int k=min(190,(int)sqrt(n+0.5)) ;
    int n2=tmp.size() , m=n/k , r=n-m*k ; /// n=k*m+r
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n2;j++) num[i][j]=num[i-1][j] ;
        for(int j=m*(i-1)+1 ; j<=m*i ; j++) num[i][a[j]]++ ;
    }
    for(int i=1;i<=k;i++)
    {
        memset(nownum,0,sizeof(nownum)) ;
        int Mval=0,Mcnt=0 ;
        for(int j=(i-1)*m+1 ; j<=k*m ; j++)
        {
            nownum[a[j]]++ ; if(nownum[a[j]]>Mcnt) Mcnt=nownum[Mval=a[j]] ;
            if(j%m==0) val[i][j/m]=Mval , cnt[i][j/m]=Mcnt ;
        }
    }
    while(Q--)
    {
        int L,R ; scanf("%d%d",&L,&R) ;
        int l,r ;
        for(l=1 ; (l-1)*m+1<L ; l++) ;
        for(r=k ; r*m>R ; r--) ;
        int ans=0 ;
        for(int i=1;i<=n2;i++) nownum[i]=0 ;
        if(l>r)
        {
            for(int i=L;i<=R;i++) ans=max(ans,++nownum[a[i]]) ;
            printf("%d\n",ans) ; continue ;
        }
        ans=cnt[l][r] ;
        for(int i=L;i<=(l-1)*m;i++)
        {
            ans=max(ans,num[r][a[i]]-num[l-1][a[i]]+(++nownum[a[i]])) ;
        }
        for(int i=r*m+1;i<=R;i++)
        {
            ans=max(ans,num[r][a[i]]-num[l-1][a[i]]+(++nownum[a[i]])) ;
        }
        printf("%d\n",ans) ;
    }
}
