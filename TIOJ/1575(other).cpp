#include<stdio.h>
#define MAXN 2000100
struct edge{
    int j;
    edge *next;
}*v[MAXN],e[MAXN*2],*ptr,*nowe;
void set(int i,int j){
    static int cnt=0;
    nowe=&e[cnt++];
    ptr=v[i];
    v[i]=nowe;
    nowe->j=j;
    nowe->next=ptr;
}
int ar[MAXN],top;
int dp[MAXN],dmax,dnow;
int max[MAXN],min[MAXN],fa[MAXN];
int n,m,k,a,b;
bool can,visited[MAXN];
bool chk(){
    can=1;dnow=0;
    for(int i=0;i<=n;i++)
        visited[i]=0;
    ar[1]=top=1;
    while(top){
        int now=ar[top];
        if(!can)return 0;
        if(now>0){
            max[now]=-1;min[now]=0;
            visited[now]=1;
            dp[now]=0;
            ar[top]=-now;
            int max=-1,min=0;
            for(edge *ptr=v[now];ptr;ptr=ptr->next){
                if(visited[ptr->j]){
                    fa[now]=ptr->j;
                    continue;
                }
                ar[++top]=ptr->j;
            }
        }else{
            now=-now;
            if(max[now]>=dmax-1){
                dp[now]=-dmax;
                dnow++;
                if(dnow>k)
                    can=0;
            }
            else if(max[now]<0){
                if(min[now]<0)
                    dp[now]=min[now]+1;
            }
            else{
                if(-min[now]-2>=max[now])
                    dp[now]=min[now]+1;
                else
                    dp[now]=max[now]+1;
            }
            if(dp[now]>max[fa[now]])
                max[fa[now]]=dp[now];
            if(dp[now]<min[fa[now]])
                min[fa[now]]=dp[now];
            top--;
        }
    }
    if(dp[1]>0)dnow++;
    return can&&dnow<=k;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    if(n==k){puts("0");return 0;}
    else if(k==0){printf("%d\n",n-1);return 0;}
    if(n-1!=m)for(;;)puts("XDD");
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        set(a,b);
        set(b,a);
    }
    int _l=0,_r=n;
    while(_l!=_r){
        dmax=(_l+_r)/2;
        if(!chk())
            _l=dmax+1;
        else _r=dmax;
    }
    printf("%d\n",_l);
}
