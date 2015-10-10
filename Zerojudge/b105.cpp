#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
struct z{int c;int d;};
bool k(struct z x,struct z y)
    {
    return x.d>y.d;
    } 
int max(int x,int y)
    {
    if(x>=y) return x ;
    else return y; 
    }
main()
{
 int n,i,M,N;
 struct z a[10001];
 while(scanf("%d",&n)==1)
    {
    if(n==0) break;
    for(i=0;i<n;i++) scanf("%d %d",&a[i].c,&a[i].d);
    sort(a,a+n,k);
    M=a[0].c;
    N=a[0].c+a[0].d;
    for(i=1;i<n;i++)
        {
        N=max(M+a[i].c+a[i].d,N);
        M=M+a[i].c;
        }
    printf("%d\n",N);
    }
}
