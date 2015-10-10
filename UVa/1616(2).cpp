#define NDEBUG
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define LL long long
#define LD long double
#define DB double
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) fprintf(stderr,__VA_ARGS__)
#endif // NDEBUG
using namespace std;
const DB eps=1e-10;
int n;
LL son,mother ;
struct range{int l,r;}intervals[100010];

inline void updateans(LL nson,LL nmother)
{
    debugf("find %lld,%lld\n",nson,nmother) ;
	if(nson*mother>son*nmother) {son=nson,mother=nmother;}
}
bool checki(LL val,LL mul)
{
    if(mul*son >= val*mother) return 0 ;
    LL now=0LL ;
    for(int i=0;i<n;i++)
    {
        LL l=(LL)intervals[i].l , r=(LL)intervals[i].r ;
        if(mul*(r-l)<val || now+val > mul*r) return 0;
        now=max(now,mul*l)+val ;
        if(val==5 && (i+1)%10000==0) debugf("%lld\n",now) ;
    }
    return 1;
}
bool checkd(DB val)
{
    DB now=0.0 ;
    for(int i=0;i<n;i++)
    {
        if(now+val > (DB)intervals[i].r) return 0;
        now=max(now,(DB)intervals[i].l)+val ;
    }
    return 1;
}
inline void bs()
{
	DB l=0,r=1000001.0;
	for(int i=0;i<n;i++) r=min(r,(DB)intervals[i].r-intervals[i].l) ;
	while(r-l>eps)
	{
		DB mid=(l+r)/2;
		if(checkd(mid)) l=mid;
		else r=mid;
	}
	debugf("%f\n",r);
	son=0LL ; mother=1LL;
	for(LL i=1LL;i<=n;i++)
	{
		LD test=i*((LD)(l+eps)) ; LL ts=(LL)(test+0.5) ;
		if(fabsl(ts-test)>(1e-4))
            continue ;
        //if(i>3) break ;
        if(i%10000==0)debugf("%lld,%lld\n",i,ts) ;
        //if(i>10000) break ;
		//printf("check %d and %d with %d\n",(int)test,(int)test+1,i);
		if(checki(ts,i)) updateans(ts,i);
		else if(ts>1 && checki(ts-1,i)) updateans(ts-1,i);
	}
	printf("%lld/%lld\n",son,mother);
}
bool cmp(range a,range b)
{
	return a.l<b.l||(a.l==b.l && a.r<b.r);
}
int main()
{
        //freopen("15","r",stdin) ;
        //freopen("out38.txt","w",stdout) ;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++) scanf("%d%d",&intervals[i].l,&intervals[i].r);
		sort(intervals,intervals+n,cmp);
		bs();
	}
}
