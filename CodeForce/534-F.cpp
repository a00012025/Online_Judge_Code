#include<bits/stdc++.h>
using namespace std;
const int maxn=20+2,stnum=250000 ;

void decode(int *v,int x)
{
    for(int i=0;i<5;i++)
        v[i]=x%6 , x/=6 ;
}
int encode(int *v)
{
    int ret=0 ;
    for(int i=4;i>=0;i--) ret=ret*6+v[i] ;
    return ret ;
}

vector<int> v[maxn] ;
int n,m,a[maxn],b[maxn] ;
void pre_cal()
{
    for(int i=1;i<=m;i++)
    {
        int num=b[i] ;
        for(int j=0;j<(1<<n);j++)
        {
            int num2=0 ;
            for(int k=0;k<n;k++) if(j&(1<<k))
                if(k==0 || (!(j&(1<<(k-1))))) num2++ ;
            if(num==num2) v[i].push_back(j) ;
        }
    }
}

int fa[maxn][stnum] ;
int st[maxn][stnum],cnt[maxn] ;
int tmp[5] ;
bool dfs(int now,int S1,int S2,int *num)
{
    if(now==n)
    {
        memset(tmp,0,sizeof(tmp)) ;
        for(int i=0;i<n;i++) tmp[i]=num[i] ;
        if(fa[m/2][32*encode(tmp)+S1]==-1) return 0 ;
        for(int i=0;i<n;i++)
        {
            tmp[i]=a[i]-num[i] ;
            if((S1&(1<<i)) && (S2&(1<<i))) tmp[i]++ ;
            if(tmp[i]>5 || tmp[i]<0) return 0 ;
        }
        if(fa[m/2+1][32*encode(tmp)+S2]==-1) return 0 ;
        return 1 ;
    }
    for(int i=0;i<6;i++)
    {
        num[now]=i ;
        if(dfs(now+1,S1,S2,num)) return 1 ;
    }
    return 0 ;
}

char ans[maxn][maxn] ;
void find_ans(int S1,int S2,int *num)
{
    int st1,st2 ;
    memset(tmp,0,sizeof(tmp)) ;
    for(int i=0;i<n;i++) tmp[i]=num[i] ;
    st1=32*encode(tmp)+S1 ;

    for(int i=0;i<n;i++)
    {
        tmp[i]=a[i]-num[i] ;
        if((S1&(1<<i)) && (S2&(1<<i))) tmp[i]++ ;
    }
    st2=32*encode(tmp)+S2 ;

    for(int i=m/2,now=st1;i>=1;i--)
    {
        for(int j=0;j<n;j++) ans[j][i]=((now&(1<<j)) ? '*' : '.') ;
        now=fa[i][now] ;
    }
    for(int i=m/2+1,now=st2;i<=m;i++)
    {
        for(int j=0;j<n;j++) ans[j][i]=((now&(1<<j)) ? '*' : '.') ;
        now=fa[i][now] ;
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    if(m==1)
    {
        for(int i=0;i<n;i++) printf("%c\n",a[i]?'*':'.') ;
        return 0 ;
    }
    pre_cal() ;

    memset(fa,-1,sizeof(fa)) ;
    st[0][++cnt[0]]=0 ;
    st[m+1][++cnt[m+1]]=0 ;
    for(int i=m,i0=m+1;;)
    {
        for(int j=1;j<=cnt[i0];j++)
        {
            int val=st[i0][j]/32 , S=st[i0][j]%32 ;
            for(auto S2 : v[i])
            {
                decode(tmp,val) ;
                for(int k=0;k<n;k++) if(!(S&(1<<k)) && (S2&(1<<k)))
                    tmp[k]++ ;
                int newval=32*encode(tmp)+S2 ;
                if(fa[i][newval]==-1)
                    st[i][++cnt[i]]=newval ,
                    fa[i][newval]=st[i0][j] ;
            }
        }
        if(i==(m+1)/2) break ;
        if(i>m/2) i=m+1-i , i0=i-1 ;
        else i=m-i , i0=i+1 ;
    }

    int num[5] , found=0 ;
    for(auto i : v[m/2])
    {
        for(auto j : v[m/2+1]) if(dfs(0,i,j,num))
        {
             found=1 ;
             find_ans(i,j,num) ;
             break ;
        }
        if(found) break ;
    }
    for(int i=0;i<n;i++) printf("%s\n",ans[i]+1) ;
}
