#include<stdio.h>
int a[1000001],st[2001001],left[1000001],right[1000001],ans;
bool inter(int l,int r,int L,int R)
{
 if((L<=r)&&(L>=l)&&(R>=r)) return 1;
 else if((l<=R)&&(l>=L)&&(r>=R)) return 1;
 else return 0; 
}
bool cont(int l,int r,int L,int R)
{
 if((l>=L)&&(r<=R)) return 1;
 else return 0;
}
void buildtree(int id,int l,int r)
{
 if(l==r) st[id]=a[l] ;
 else{
 	int mid=(l+r)/2;
 	buildtree(2*id,l,mid);
 	buildtree((2*id)+1,mid+1,r);
 	st[id]=st[2*id]+st[(2*id)+1];
 }
}
void query(int id,int l,int r,int L,int R)
{
 if(cont(l,r,L,R)==1) ans+=st[id];
 else if((inter(l,r,L,R)==1)||(cont(L,R,l,r)==1))
 {
 int mid=(l+r)/2;
 query(2*id,l,mid,L,R);
 query((2*id)+1,mid+1,r,L,R);
 }
}
main()
{
 int n,i,j,k,N,M,max,NN,NNN;
 while(scanf("%d",&NN)==1){
 for(NNN=1;NNN<=NN;NNN++)
 {
 scanf("%d",&n);
 N=0 ; M=0 ; max=-2147483647 ;
 for(i=1;i<=n;i++)
 	{
 	scanf("%d",&a[i]);
 	if((i>1)&&(a[i-1]<0)&&(a[i]>=0)&&(i<n)) {N=N+1 ; left[N]=i ;}
 	if((i>1)&&(a[i-1]>=0)&&(a[i]<0)) {M=M+1 ; right[M]=i-1 ;}
 	if((i==1)&&(a[i]>=0)) {N=N+1 ; left[N]=i ;}
 	if((i==n)&&(a[i-1]<0)&&(a[i]>=0)) {N=N+1 ; M=M+1 ; left[N]=i ; right[M]=i ;}
 	else if((i==n)&&(a[i]>=0)){M=M+1 ; right[M]=i ;}
	if(a[i]>max) max=a[i];
 	}
 if(max<=0) {printf("%d\n",max) ; continue ; }
 max=0 ;
 buildtree(1,1,n) ;
 for(i=1;i<=N;i++)
 {
 for(j=1;(j<=M)&&(right[j]<left[i]);j++);
 if(j==M+1) continue;
 for(k=j;k<=M;k++){
 ans=0 ;
 query(1,1,n,left[i],right[k]) ;
 if(ans>max) max=ans;
 }
 }
 printf("%d\n",max); 
}
}}
