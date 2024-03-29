#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int maxn=2022;
int n;
bitset<maxn>cd[maxn],s[maxn];
int k[maxn+20];
char c[maxn];
int pos[maxn]={0};
void input(int th){
	scanf("%s",c);
	int i,j,l=strlen(c),rem;
		for(i=0;i<l;i++)
			k[i]=c[l-i-1]-'0';
		for(i=0;i<maxn;i++)
		{
			for(j=l-1,rem=0;j>=0;j--)
				k[j]+=rem*10,rem=k[j]&1,k[j]>>=1;
			while(l>1&&!k[l-1]) l--;
			cd[th][i]=rem;
		}
		s[th][th]=1;
}
int main(){
    freopen("in","r",stdin) ;
    freopen("out","w",stdout) ;
	memset(pos,255,sizeof(pos));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	input(i);
	//if(n==2000)continue;
	bool can=1;
	for(int j=0;j<maxn;j++)if(cd[i][j]){
	if(pos[j]==-1){can=0;pos[j]=i;break;}
	cd[i]^=cd[pos[j]];
	s[i]^=s[pos[j]];
	}
	if(can==0)printf("0\n");
	else {
	s[i][i]=0;
	printf("%d",s[i].count());
	for(int j=0;j<maxn;j++)if(s[i][j])printf(" %d",j);
	puts("");
	}

	}
	return 0;
}
