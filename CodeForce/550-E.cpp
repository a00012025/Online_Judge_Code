#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

map<pii,int> mp ;
int a[maxn] ;
void print(int l,int r)
{
    if(l==r){printf("%d",a[l]) ; return ;}
    int mid=mp[pii(l,r)] ;
    printf("(") ; print(l,mid) ; printf(")") ;
    printf("->") ;
    printf("(") ; print(mid+1,r) ; printf(")") ;
}

int pos[maxn] ;
main()
{
    int n,cnt=0 ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , cnt+=(a[i]==0) ;
    if(a[n]==1){printf("NO\n") ; return 0 ;}
    if(cnt==2 && a[n-1]==0){printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
    if(cnt==2)
    {
        int p=1 ;
        while(a[p]) p++ ;
        for(int i=p+2;i<=n-1;i++) mp[pii(p+1,i)]=i-1 ;
        mp[pii{p,n-1}]=p ;
        mp[pii{p,n}]=n-1 ;
        for(int i=1;i<p;i++) mp[pii{i,n}]=i ;
        print(1,n) ;
    }
    else
    {
        cnt=0 ;
        for(int i=1;i<=n;)
        {
            int j=i ;
            while(a[j]) j++ ; pos[++cnt]=j ;
            for(int k=i;k<j;k++) mp[pii(k,j)]=k ;
            i=j+1 ;
        }
        if(cnt%2==0)
        {
            mp[pii(pos[cnt-3]+1,pos[cnt-1])]=pos[cnt-2] ;
            mp[pii(pos[cnt-4]+1,pos[cnt-1])]=pos[cnt-3] ;
            mp[pii(pos[cnt-4]+1,n)]=pos[cnt-1] ;
            pos[cnt-3]=n ; cnt-=3 ;
        }
        if(cnt==1){print(1,n) ; return 0 ;}
        mp[pii(1,n)]=pos[cnt-1] ;
        for(int i=1;i<=cnt-1;i+=2)
            mp[pii(pos[i-1]+1,pos[i+1])]=pos[i] ,
            mp[pii(pos[i-1]+1,n)]=pos[i+1] ;
        print(1,n) ;
    }
}
