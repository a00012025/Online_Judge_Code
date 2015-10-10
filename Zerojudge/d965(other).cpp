
#include <cstdio>
#include <algorithm>

int dp[2010][2010], tmp[2010], ary[2010], n;

int find(int ob, int l, int r){
	while(l != r){
		int m = (l + r) >> 1;
		if(tmp[m] >= ob) r = m;
		else l = m + 1;
	}
	return l;
}

int query(int ob, int *ary){
	int ret = 0;
	ob--;
	while(ob > 0){
		if(ret < ary[ob]) ret = ary[ob];
		ob -= (ob & -ob);
	}
	return ret;
}

void insert(int *ary, int ob, int val){
	while(ob <= n){
		if(ary[ob] < val) ary[ob] = val;
		ob += (ob & -ob);
	}
}

int main(){
	int t;
	scanf("%d" ,&t);
	while(t--){
		int ans = 0, lim = 1;
		scanf("%d" ,&n);
		for(int i = 1; i <= n; i++){
			scanf("%d" ,&ary[i]);
			tmp[i] = ary[i];
		}
		for(int i = 0; i <= n; i++){
			for(int I = 0; I <= n; I++) dp[i][I] = 0;
		}
		ary[0] = tmp[n + 1] = 0;
		std::sort(tmp + 1, tmp + n + 2);
		for(int i = 2; i <= n + 1; i++){
			if(tmp[i] != tmp[i - 1]){
				tmp[++lim] = tmp[i];
			}
		}
		for(int i = 0; i <= n; i++){
			ary[i] = find(ary[i], 1, lim); printf("a[%d]=%d\n",i,ary[i]);
		}
		for(int i = 1; i <= n; i++){
			for(int I = 0; I < i; I++){
				int get = query(ary[i], dp[I]) + 1;
				//printf("i=%d , j=%d , get=%d\n",i,I,get) ;
				insert(dp[I], ary[i], get);
				insert(dp[i], ary[I], get);
				if(ans < get) ans = get;
			}
		}
		printf("%d\n" ,ans);
	}
}

