#include<stdio.h>
main(){int n,m;scanf("%d%d",&n,&m);for(int i=0;i<n;i++)for(int j=1;j<=m;j++){
printf("%c",!(i%2)||(i%4==1&&j==m)||(i%4==3&&j==1)?'#':'.');if(j==m)puts("");}}
