#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

struct big
{
    int a[maxn] ;
    big()
    {
        memset(a,0,sizeof(a)) ;
    }
    bool operator == (const big &rhs) const
    {
        for(int i=0;i<maxn;i++) if(a[i]!=rhs.a[i])
            return 0 ;
        return 1 ;
    }
    void print()
    {
        int h ;
        for(h=maxn-1;h && !a[h];h--) ;
        for(int i=h;i>=0;i--) printf("%d",a[i]) ;
        printf("\n") ;
    }
};

big operator + (const big &x,const big &y)
{
    big ret ;
    for(int i=0;i<maxn;i++)
    {
        ret.a[i]+=x.a[i]+y.a[i] ;
        if(ret.a[i]>9) ret.a[i]-=10 , ret.a[i+1]++ ;
    }
    return ret ;
}

big div2(const big &x)
{
    big ret ;
    for(int i=maxn-1,j=0;i>=0;i--)
    {
        j=j*10+x.a[i] ;
        ret.a[i]=j/2 ; j%=2 ;
    }
    return ret ;
}

big sub1(const big &x)
{
    big ret=x ; ret.a[0]-- ;
    for(int i=0;ret.a[i]<0;i++)
        ret.a[i]+=10 , ret.a[i+1]-- ;
    return ret ;
}

big zero,one,neg ;
big solve(const string &x,big p)
{
    if(p==zero) return x=="0" ? zero : one ;
    string l,r ;
    cout << x << endl ;
    cin >> l >> r ;
    if(p.a[0]==-1)
    {
        if(l=="0" && r=="0") return one ;
        else if(r=="0") return one+one ;
        big sz=solve(r,neg) ;
        return sz+solve(l,sz)+one ;
    }
    else
    {
        if(p.a[0]%2)
        {
            big sz=solve(l,div2(p)) ;
            if((sz+sz+one)==p) return p ;
            else return p+one ;
        }
        else
        {
            big sz=solve(r, sub1(div2(p)) ) ;
            if(sz+sz==p) return p+one ;
            else return p ;
        }
    }
}

main()
{
    one.a[0]=1 ;
    neg.a[0]=-1 ;
    big ans=solve("1",neg) ;
    printf("Answer ") ;
    ans.print() ;
}
