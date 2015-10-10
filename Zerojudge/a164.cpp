#include<stdio.h>
int a[1000001],st2[2001001],left[1000001],right[1000001],maxnum[2001001],ans3;
long long ans,ma,st[2001001] ;
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
 if(l==r) {st[id]=a[l] ; st2[id]=a[l] ; maxnum[id]=l ;}
 else{
 	int mid=(l+r)/2;
 	buildtree(2*id,l,mid);
 	buildtree((2*id)+1,mid+1,r);
 	st[id]=st[2*id]+st[(2*id)+1];
 	if(st2[2*id]>=st2[(2*id)+1]) {st2[id]=st2[2*id] ; maxnum[id]=maxnum[2*id] ;}
 	else {st2[id]=st2[(2*id)+1] ; maxnum[id]=maxnum[(2*id)+1] ; }
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
void query2(int id,int l,int r,int L,int R)
{
 if(cont(l,r,L,R)==1) {if(st2[id]>ma) {ma=st2[id] ; ans3=maxnum[id] ; }}
 else if((inter(l,r,L,R)==1)||(cont(L,R,l,r)==1))
 {
 int mid=(l+r)/2;
 query2(2*id,l,mid,L,R);
 query2((2*id)+1,mid+1,r,L,R);
 }
}
main()
{
 int n,i,j,k,N,M,max,Q,QQ,NNN=0,x,y,ans1,ans2;
 int left_fir,left_las,right_fir,right_las;
 while(scanf("%d %d",&n,&Q)!=EOF)
 {
 NNN++ ; N=0 ; M=0 ; ma=-200000000000001 ;
 right[0]=0 ; left[0]=0 ;
 for(i=1;i<=n;i++)
 	{
 	scanf("%d",&a[i]);
 	if((i>1)&&(a[i-1]<0)&&(a[i]>=0)&&(i<n)) {N=N+1 ; left[N]=i ;}
 	if((i>1)&&(a[i-1]>=0)&&(a[i]<0)) {M=M+1 ; right[M]=i-1 ;}
 	if((i==1)&&(a[i]>=0)) {N=N+1 ; left[N]=i ;}
 	if((i==n)&&(a[i-1]<0)&&(a[i]>=0)) {N=N+1 ; M=M+1 ; left[N]=i ; right[M]=i ;}
 	else if((i==n)&&(a[i]>=0)){M=M+1 ; right[M]=i ;}
 	}
 printf("Case %d:\n",NNN);
 left[N+1]=n+1 ; right[M+1]=n+1 ;
 			//for(i=0;i<=N+1;i++) printf("%d,",left[i]);printf("\n\n");
 			//for(i=0;i<=M+1;i++) printf("%d,",right[i]);printf("\n\n");
 ma=-200000000000001 ;
 buildtree(1,1,n) ;
 			//for(i=1;i<=32;i++)printf("%lld,",st[i]);printf("\n\n");
 			//for(i=1;i<=32;i++)printf("%d,",st2[i]);printf("\n\n");
 for(QQ=1;QQ<=Q;QQ++)
 	{
 	ma=-200000000000001 ;
 	scanf("%d %d",&x,&y);
 	for(i=0;(left[i]<x)&&(i<=N);i++) ;
 	left_fir=i ;
 	for(i=i-1;(left[i]<=y)&&(i<=N);i++) ;
 	left_las=i-1 ;
 	for(i=0;(right[i]<x)&&(i<=M);i++) ;
 	right_fir=i ;
 	for(i=i-1;(right[i]<=y)&&(i<=M);i++) ;
 	right_las=i-1 ;
 					//printf("left:%d,%d , right:%d,%d\n\n",left_fir,left_las,right_fir,right_las);
 	if((left_fir>left_las)&&(right_fir>right_las)
	 						&&(left[left_las+1]<=right[right_las+1])
							 	&&(left[left_fir-1]<=right[right_fir-1]))
 		{
 		ma=-200000000000001 ; query2(1,1,n,x,y) ;
		printf("%d %d %lld\n",ans3,ans3,ma) ; continue ;
 		}
 	if((right[right_fir]>=x)&&(right[right_fir]<=y))
 		{
	 	for(i=right_fir;right[i]<=y;i++)
 			{
 			ans=0 ; query(1,1,n,x,right[i]) ;
 			if(ans>ma) {ma=ans ; ans1=x ; ans2=right[i] ;}
 			}
 		}
 	ans=0 ; query(1,1,n,x,y) ;
 	if(ans>ma) {ma=ans ; ans1=x ; ans2=y ;}
 	if((left[left_fir]>=x)&&(left[left_fir]<=y))
		{
		for(i=left_fir;left[i]<=y;i++)
			{
			ans=0 ; query(1,1,n,left[i],y) ;
			if(ans>ma) {ma=ans ; ans1=left[i] ; ans2=y ;}
			}
		}
	if((left[left_fir]>y)||(right[right_fir]>y))
		{
		for(j=ans2;a[j]==0;j--) ; ans2=j ;
		printf("%d %d %lld\n",ans1,ans2,ma) ; continue ;
		}
	for(i=left_fir;i<=left_las;i++)
		{
		for(j=right_fir;j<=right_las;j++)
			{
			if(right[j]<left[i]) continue;
			ans=0 ; query(1,1,n,left[i],right[j]);
			if(ans>ma) {ma=ans ; ans1=left[i] ; ans2=right[j] ;}
			}
		}
	for(j=ans2;a[j]==0;j--) ; ans2=j ;
 	printf("%d %d %lld\n",ans1,ans2,ma);
	}
}
}
}
 }
 	else {st2[id]=st2[(2*id)+1] ; maxnum[id]=maxnum[(2*id)+1] ; } 
 	if(st2[2*id]>=st2[(2*id)+1]) {st2[id]=st2[2*id] ; maxnum[id]=maxnum[2*id] ;}
 	st[id]=st[2*id]+st[(2*id)+1]
 if((L<=r)&&(L>=l)&&(R>=r)) return 1;
 else if((l<=R)&&(l>=L)&&(r>=R)) return 1;
 else return 0; 
}
 	buildtree((2*id)+1,mid+1,r);
 	buildtree(2*id,l,mid)
 if((l>=L)&&(r<=R)) return 1;
 else return 0;
}
 	int mid=(l+r)/2;
 else
 if(l==r) {st[id]=a[l] ; st2[id]=a[l] ; maxnum[id]=l ;}
