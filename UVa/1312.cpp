#include<stdio.h>
#include<string.h>
#include<deque>
#include<algorithm>
#include<set>
using namespace std;
struct P {int c,h;};
set<int> st[20001];
deque<P> dq ;
int height[20001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m,k ; scanf("%d%d%d",&k,&m,&n) ;
        for(int i=0;i<=n;i++) st[i].clear() ;
        while(k--)
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            st[n-b].insert(a) ;
        }
        memset(height,0,sizeof(height)) ;
        int ans=1,ansx,ansy ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) height[j]=
                st[i-1].find(j-1)!=st[i-1].end() ? 1 : height[j]+1 ;
            P left,up ;
            dq.clear() ;
            for(int j=1;j<=m;j++)
            {
                if(j==1) {left=up=(P){0,1} ; continue ;}
                while(!dq.empty() && dq.back().h>=height[j]) dq.pop_back() ;
                dq.push_back((P){j-1,height[j]}) ;
                if(dq.front().h <= left.h) {left=up=dq.front() ; dq.pop_front() ;}
                else if(dq.front().h <= up.h) {up=dq.front() ; dq.pop_front() ;}
                else while(!dq.empty() && up.c+up.h<=j )
                    {left=up ; up=dq.front() ; dq.pop_front() ;}
                int num=min(j-left.c,up.h) ;
                //printf("(%d,%d) , left=(%d,%d) , up=(%d,%d) , num=%d\n",i,j,left.c,left.h,up.c,up.h,num) ;
                if(num>=ans) {ans=num ; ansx=j-num ; ansy=n-i ;}
            }
        }
        printf("%d %d %d\n",ansx,ansy,ans) ;
        if(T) printf("\n") ;
    }
}
