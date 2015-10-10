#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
typedef long long LL;
using namespace std;
const int maxn=1000010;
int l[maxn],r[maxn];
LL sum[maxn],dp[maxn];
int main()
{
        //freopen("1.txt","r",stdin) ;
   int n;
   int cas=0;
   while(~scanf("%d",&n))
   {
       memset(sum,0,sizeof(sum));
       if(cas)
          puts("");
       cas++;
       for(int i=1;i<=n;i++)
       {
           scanf("%lld",&dp[i]);
           sum[i]=sum[i-1]+dp[i];
           l[i]=r[i]=i;
       }
//       cout<<"23333  "<<endl;
       for(int i=1;i<=n;i++)
       {
           if(dp[i]>0)
           {
               while(dp[l[i]-1]>=dp[i])
                  l[i]=l[l[i]-1];
           }
       }
//       cout<<"hahahah  "<<endl;
       for(int i=n;i>=1;i--)
       {
           if(dp[i]>0)
           {
               while(dp[r[i]+1]>=dp[i])
                  r[i]=r[r[i]+1];
           }
       }
//       cout<<"111  "<<endl;
       LL ans=0,temp;
       int ll=1,rr=1;
       for(int i=1;i<=n;i++)
       {
//           cout<<"fuck  "<<endl;
           if(dp[i]>0)
           {
               temp=dp[i]*(sum[r[i]]-sum[l[i]-1]);
               if(temp>ans)
               {
                   ans=temp;
                   ll=l[i];
                   rr=r[i];
               }
               else  if(temp==ans)
               {
                   if(rr-ll==r[i]-l[i]&&l[i]<ll)
                   {
                       ll=l[i];
                       rr=r[i];
                   }
               }
           }
       }
       printf("%I64d\n%d %d\n",ans,ll,rr);
   }
   return 0;
}
