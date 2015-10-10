#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+1000 ;

LL MOD ;
LL power[65] ;
void get_pow()
{
    power[0]=2%MOD ;
    for(int i=1;i<65;i++) power[i]=((power[i-1]*power[i-1]) % MOD) ;
}

char A1[maxn] ;
int cnt1[2*maxn],cnt2[2*maxn],tmp1[2*maxn],tmp2[2*maxn],len ;
LL ans[5] ;

void cal_ans1()
{
    memset(cnt1,0,sizeof(cnt1)) ;
    cnt1[0+maxn]++ ;
    int dif=0 ;
    for(int i=1;i<=len;i++)
    {
        if(A1[i]=='0') dif++ ;
        else dif-- ;
        cnt1[dif+maxn]++ ;
    }
    ans[1]=0LL ;
    for(int i=maxn-len-1;i<=maxn+len+1;i++)
        ans[1]+=(((LL)cnt1[i])*((LL)cnt1[i]-1)/2)%MOD , ans[1]%=MOD ;
}

void get_next_cnt(int k)
{
    memset(tmp1,0,sizeof(tmp1)) ;
    memset(tmp2,0,sizeof(tmp2)) ;
    for(int i=maxn-len-1;i<=maxn+len+1;i++)
        tmp1[i]=cnt1[i] , tmp2[i]=cnt2[i] ;
    for(int i=maxn-len-1;i<=maxn+len+1;i++) cnt2[i]=tmp2[2*maxn-i] ;
    for(int i=maxn-len-1;i<=maxn+len+1;i++)
        cnt1[i]+=tmp1[2*maxn-(i-k)] , cnt2[i]+=tmp2[i+k] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    LL n,x,y,t ; /// a2=2*a1+x , a3=2*a2+y , an=2*a(n-1)+t*4^(n-4) for all n>=4
    while(T--)
    {
        scanf("%s%lld%lld",A1+1,&n,&MOD) ; len=strlen(A1+1) ;
        get_pow() ; debugf("n=%lld\n",n) ;
        cal_ans1() ;
        memset(cnt1,0,sizeof(cnt1)) ;
        memset(cnt2,0,sizeof(cnt2)) ;

        int dif=0 ;
        for(int i=1;i<=len;i++)
        {
            if(A1[i]=='0') dif++ ;
            else dif-- ;
            cnt1[dif+maxn]++ ;
        }

        dif=0 ;
        for(int i=len;i>=1;i--)
        {
            if(A1[i]=='0') dif++ ;
            else dif-- ;
            cnt2[dif+maxn]++ ;
        }

        x=0LL ; for(int i=maxn-len-1;i<=maxn+len+1;i++)
            x+=( ((LL)cnt1[i])*((LL)cnt2[i]) % MOD) , x%=MOD ;

        get_next_cnt(dif) ;

        y=0LL ; for(int i=maxn-len-1;i<=maxn+len+1;i++)
            y+=( ((LL)cnt1[i])*((LL)cnt2[i]) % MOD) , y%=MOD ;

        get_next_cnt(0) ;

        t=0LL ; for(int i=maxn-len-1;i<=maxn+len+1;i++)
            t+=( ((LL)cnt1[i])*((LL)cnt2[i]) % MOD) , t%=MOD ;
        ans[2]=(2*ans[1]+x) % MOD ;
        ans[3]=(2*ans[2]+y) % MOD ;
        ans[4]=(2*ans[3]+t) % MOD ;

        debugf("x,y,t = %lld,%lld,%lld\n",x,y,t) ;
        debugf("ans 1~4 : %lld,%lld,%lld,%lld\n",ans[1],ans[2],ans[3],ans[4]);

        if(n<=4) { printf("%lld\n",ans[n]) ; continue ; }
        LL tmp=1LL ;
        LL pw=n-4 ;
        while(pw)
        {
            int i ;
            for(i=62;(1LL<<i)>pw;i--) ;
            pw-=(1LL<<i) ;
            tmp*=power[i] ; tmp%=MOD ; /// tmp = 2^(n-4)
        }
        LL ANS=((2*tmp-1+MOD) % MOD)*t ; ANS%=MOD ;
        ANS+=2*ans[3] ; ANS%=MOD ;
        ANS*=tmp ; ANS%=MOD ;

        printf("%lld\n",ANS) ;
    }
}
