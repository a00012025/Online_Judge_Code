#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 510000
#define MOD 1000000009

using namespace std;

typedef long long int LL;

char s[MAXN];
LL hash[MAXN],pow[MAXN];
int n,q;
int sum[MAXN][26];

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

bool check(int L1,int R1,int L2,int R2)
{
    LL hash1=((hash[R1]-pow[R1-L1+1]*hash[L1-1]%MOD)%MOD+MOD)%MOD;
    LL hash2=((hash[R2]-pow[R2-L2+1]*hash[L2-1]%MOD)%MOD+MOD)%MOD;
    return hash1==hash2;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    pow[0]=1;
    for(int i=1;i<=n;i++)
        pow[i]=pow[i-1]*30007%MOD;
    for(int i=1;i<=n;i++)
        hash[i]=(hash[i-1]*30007%MOD+s[i]-'a'+1)%MOD;
    for(int i=1;i<=n;i++)
        for(int alpha=0;alpha<26;alpha++)
        {
            sum[i][alpha]=sum[i-1][alpha];
            sum[i][alpha]+=((s[i]-'a')==alpha);
        }
    scanf("%d",&q);
    while(q--)
    {
        int L,R,ans=0;
        scanf("%d%d",&L,&R);
        int GCD=0,len=R-L+1;
        for(int alpha=0;alpha<26;alpha++)
            GCD=gcd(GCD,sum[R][alpha]-sum[L-1][alpha]);
        for(int i=1;i*i<=GCD;i++)
        {
            if(check(L,R-len/i,L+len/i,R)) ans=max(ans,i);
            if(check(L,R-len/(GCD/i),L+len/(GCD/i),R)) ans=max(ans,GCD/i);
        }
        printf("%d\n",len/ans);
    }
    return 0;
}
