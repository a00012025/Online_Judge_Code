#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
struct P {int c,h;};
stack<P> st;
char G[1001][1001] ;
int height[1001],cnt[5000] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c; c=getchar() ;
            while(c!='.' && c!='#') c=getchar() ;
            G[i][j]=c ;
        }
        memset(height,0,sizeof(height)) ;
        memset(cnt,0,sizeof(cnt)) ;
        int M=0 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) height[j]= G[i][j]=='.' ? height[j]+1 : 0 ;
            while(!st.empty()) st.pop() ;
            for(int j=1;j<=m;j++) if(height[j])
            {
                int tmp=j ;
                while(!st.empty() && st.top().h>=height[j]) {tmp=st.top().c ; st.pop() ;}
                if(st.empty() || height[j]-tmp > st.top().h-st.top().c)
                    st.push((P){tmp,height[j]}) ;
                int k=2*(st.top().h-st.top().c+1+j) ;
                cnt[k]++ ; M=max(M,k) ; //printf("%d,%d : %d\n",i,j,k) ;
            }
            else while(!st.empty()) st.pop() ;
        }
        for(int i=1;i<=M;i++) if(cnt[i]) printf("%d x %d\n",cnt[i],i) ;
    }
}
