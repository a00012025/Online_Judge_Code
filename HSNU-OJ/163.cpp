#include<bits/stdc++.h>
using namespace std;
struct P{int num ; char c;};
vector<P> ans ;

int n ;
inline int move(int x,int dis)
{
    return ((((x+dis-1)%n)+n)%n)+1 ;
}

inline int dis(int x,int y)
{
    return y>=x ? y-x : y-x+n ;
}

int a[3000],now ;
void f1(int num)
{
    if(!num) return ;
    now=move(now,num) ;
    ans.push_back((P){n-num,'a'}) ;
}

void f2(int num)
{
    int &x=a[now],&y=a[move(now,1)],&z=a[move(now,2)] ;
    if(num==1) swap(x,y) , swap(x,z) ;
    else swap(x,y) , swap(y,z) ;
    ans.push_back((P){num,'b'}) ;
}

bool check()
{
    if(n%2==0) return 1 ;
    int inv=0 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(a[i]>a[j]) inv++ ;
    return (inv%2==0) ;
}

void swap_last_two()
{
    f2(2) ;
    for(int i=1;i<(n/2)-1;i++) f1(2) , f2(2) ;
    f1(1) ;
    f2(1) ;
    f1(2) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    if(!check()) { printf("NIE DA SIE\n") ; return 0 ; }

    now=1 ;
    for(int i=1;i<=n-3;i++)
    {
        int x,y ;
        for(x=1;a[x]!=i;x++) ;
        for(y=1;a[y]!=i+1;y++) ;
        if(y==move(x,1)) continue ;
        while(dis(x,y)>2)
        {
            f1(dis(now,move(y,-2))) ;
            f2(1) ;
            y=move(y,-2) ;
        }
        if(y!=move(x,1))
        {
            f1(dis(now,move(y,-1))) ;
            f2(2) ;
        }
    }

    int x ;
    for(x=1;a[x]!=1;x++) ;
    f1(dis(now,x)) ;
    if(a[move(now,-1)]!=n) swap_last_two() ;

    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++)
        printf("%d%c%c",ans[i].num,ans[i].c," \n"[i==ans.size()-1]) ;
}
