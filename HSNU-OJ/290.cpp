#include<bits/stdc++.h>
#include"interactive/290.h"
const int maxn=5000+10 ;
int n ;
int per[maxn] ;
int ans[maxn],now[maxn] ;

int getval()
{
    int ret=tryCombination(now) ;
    return ret==-1 ? n : ret ;
}

bool done[maxn] ;
main()
{
    n=Initialize() ;
    int res=getval() ;
    for(int i=0;i<n;i++)
    {
        int l=0 , r=n-1 ;
        while(l!=r)
        {
            int mid=(l+r)/2 ;
            for(int j=l;j<=mid;j++) if(!done[j])
                now[j]=1-now[j] ;
            int res2=getval() ;
            if(res>i && res2>i) l=mid+1 ;
            if(res>i && res2<=i) r=mid ;
            if(res<=i && res2>i) r=mid ;
            if(res<=i && res2<=i) l=mid+1 ;
            res=res2 ;
        }
        per[l]=i ;
        if(res>i) ans[l]=now[l] ;
        else
        {
            ans[l]=1-now[l] ;
            now[l]=1-now[l] ;
            res=getval() ;
        }
        done[l]=1 ;
    }
    answer(ans,per) ;
}
