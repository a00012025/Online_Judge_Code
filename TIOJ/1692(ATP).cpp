#define MV 1010
#define ME 60000

#include <cstdio>
#include "lib1692.h"

int nxt[ME*2], from[ME*2], to[ME*2], used[ME], v[MV], ord[ME*2], stk[ME], vst[MV];
int N, M, a, b, t, top, deg[MV], ec, oc, sp[MV];
int hasodd, out[ME], ocnt;

void dfs(int now) {
	vst[now] = true;
	for(int p=v[now]; p; p=nxt[p]) {
		if(!used[ord[p]]) {
			used[ord[p]] = true;
			dfs(to[p]);
			stk[++top] = p;
		}
	}
}

int main() {
	Init();
	GetVE(N, M);
	for(int i=1; i<=M; i++) {
		Get(a,b);
		oc++;
		ec++; t=v[a]; v[a]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=b; from[ec]=a;
		ec++; t=v[b]; v[b]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=a; from[ec]=b;
		deg[a]++; deg[b]++;
	}
	for(int i=1; i<=N; i++) {
		if(deg[i]%2 == 0) continue;
		hasodd = true;
		oc++;
		ec++; t=v[0]; v[0]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=i; from[ec]=0;
		ec++; t=v[i]; v[i]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=0; from[ec]=i;
	}
	if(!hasodd) {
		oc++;
		ec++; t=v[0]; v[0]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=1; from[ec]=0;
		ec++; t=v[1]; v[1]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=0; from[ec]=1;
		oc++;
		ec++; t=v[0]; v[0]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=1; from[ec]=0;
		ec++; t=v[1]; v[1]=ec; nxt[ec]=t; ord[ec]=oc; to[ec]=0; from[ec]=1;
	}
	for(int i=1; i<=N; i++)
		if(!vst[i]) {
			sp[i] = true;
			dfs(i);
		}
	bool start = false;
	for(int i=top; i>0; i--) {
        if(from[stk[i]] == 0) {
            start = true;
        }
        if(start) {
            out[ocnt++] = stk[i];
        }
	}
	for(int i=top; i>0; i--) {
        if(ocnt < oc) {
            out[ocnt++] = stk[i];
        }
        else break;
	}
	for(int i=0; i<oc; i++) {
//		printf("%d %d : %d %d\n", out[i], ord[out[i]], from[out[i]], to[out[i]]);
		if(from[out[i]] == 0) {
			ReportVst(to[out[i]]);
		}
		else if(to[out[i]] == 0) {
			ReportVed(from[out[i]]);
		}
		else {
//			if(sp[from[out[i]]]) ReportVst(from[out[i]]);
			ReportE(ord[out[i]]);
//			if(sp[to[out[i]]]) ReportVed(to[out[i]]);
		}
	}
	Final();
}
