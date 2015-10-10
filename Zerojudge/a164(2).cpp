#include<stdio.h>
long long st[1000001],lmax[1000001],rmax[1000001],midmax[1000001];
long long ans,ext,noext ;
int a[200001],lmaxnum[1000001],rmaxnum[1000001],midnum1[1000001];
int midnum2[1000001];
int ans_x,ans_y,noext_r,noext_l,ext_l;
long long maxx(long long a,long long b)
{
if(a>b) return a;
else return b;
}
long long maxxx(long long a,long long b,long long c)
{
 if((a>=b)&&(a>=c)) return a;
 else if((b>=a)&&(b>=c)) return b;
 else if((c>=a)&&(c>=b)) return c;
}
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
 if(l==r) {
 	 st[id]=a[l] ;
	 rmax[id]=a[l] ; lmax[id]=a[l] ; midmax[id]=a[l] ;
	 lmaxnum[id]=l ; rmaxnum[id]=l ; midnum1[id]=l ; midnum2[id]=l ;
	 }
 else{
    int mid=(l+r)/2;
 	buildtree(2*id,l,mid);
 	buildtree((2*id)+1,mid+1,r);
 	st[id]=st[2*id]+st[(2*id)+1];
  	lmax[id]=maxx(lmax[2*id],st[2*id]+lmax[(2*id)+1]) ;
 	if(lmax[id]==lmax[2*id]) lmaxnum[id]=lmaxnum[2*id] ;
 	else lmaxnum[id]=lmaxnum[(2*id)+1] ;
 	rmax[id]=maxx(rmax[(2*id)+1],st[(2*id)+1]+rmax[2*id]);
 	if(rmax[id]==(st[(2*id)+1]+rmax[2*id])) rmaxnum[id]=rmaxnum[2*id] ;
 	else rmaxnum[id]=rmaxnum[(2*id)+1] ;
 	long long R=rmax[2*id]+lmax[(2*id)+1] ;
 	midmax[id]=maxxx(midmax[2*id],midmax[(2*id)+1],R) ;
	if(midmax[id]==midmax[2*id])
		{
		if(R<midmax[id]) 
			{midnum1[id]=midnum1[2*id] ; midnum2[id]=midnum2[2*id] ;}
		else if(rmaxnum[2*id]>=midnum1[2*id])
			{midnum1[id]=midnum1[2*id] ; midnum2[id]=midnum2[2*id] ;}
		else
			{midnum1[id]=rmaxnum[2*id] ; midnum2[id]=lmaxnum[(2*id)+1] ;}
		}
	else if(midmax[id]==midmax[(2*id)+1])
		{
		if(R<midmax[id]) 
		{midnum1[id]=midnum1[(2*id)+1] ; midnum2[id]=midnum2[(2*id)+1];}
		else
		{midnum1[id]=rmaxnum[2*id] ; midnum2[id]=lmaxnum[(2*id)+1] ;}
		}
	else
		{midnum1[id]=rmaxnum[2*id] ; midnum2[id]=lmaxnum[(2*id)+1] ;}
	}
}
void query(int id,int l,int r,int L,int R)
{
 if(cont(l,r,L,R)==1)
 	{
 	long long e=ext,ne=noext;
 	int el=ext_l,nor=noext_r,nol=noext_l ;		
	if(ext_l==0) {
        ext=rmax[id] ;
        ext_l=rmaxnum[id] ;
        noext_l=midnum1[id] ; 
        noext_r=midnum2[id] ; 
        noext=midmax[id] ;
        }		
	else{
        ext=maxx(st[id]+e,rmax[id]) ;
	    if(ext!=(st[id]+e)) ext_l=rmaxnum[id];
 	    noext=maxxx(midmax[id],lmax[id]+e,ne) ;
 	    if((noext!=ne)&&(noext==(lmax[id]+e)))
 		    {
 		    noext_l=el ; noext_r=lmaxnum[id] ;
 		    }
    	else if((noext!=ne)&&(noext==midmax[id]))
     		{
     		noext_l=midnum1[id] ; noext_r=midnum2[id] ;
     		}
    	else if(ne==(lmax[id]+e))
      		{
    		if(el<nol) {noext_l=el ; noext_r=lmaxnum[id] ;}
    		}
    	}
	if(noext>ans) 
	 	{
	 	ans=noext ; ans_x=noext_l ; ans_y=noext_r ;
		}
 	}
 else if((inter(l,r,L,R)==1)||(cont(L,R,l,r)==1))
 	{
 	int mid=(l+r)/2 ;
 	query(2*id,l,mid,L,R) ;
 	query((2*id)+1,mid+1,r,L,R) ;
 	}
}
main()
{
 int n,Q,QQ,i,j,k,NNN=0,x,y;
 while(scanf("%d %d",&n,&Q)!=EOF)
 {
 NNN++ ;
 for(i=1;i<=n;i++) scanf("%d",&a[i]) ;
 printf("Case %d:\n",NNN) ;
 buildtree(1,1,n) ;
 for(QQ=1;QQ<=Q;QQ++)
 {
 scanf("%d %d",&x,&y) ;
 ext=0 ; ext_l=0 ;
 noext=-200000001 ; ans=-200000001 ;
 query(1,1,n,x,y) ;
 int z;
 if(a[ans_x]==0){
	for(z=ans_x;(a[z]==0)&&(z>=x);z--) ; 
	ans_x=z+1 ;
	}
 if(a[ans_y]==0){
	for(z=ans_y;(a[z]==0)&&(z>=ans_x);z--) ; 
	if(z!=(ans_x-1)) ans_y=z ;
	else ans_y=ans_x ;
	}
 printf("%d %d %lld\n",ans_x,ans_y,ans);
 }
 }
}
