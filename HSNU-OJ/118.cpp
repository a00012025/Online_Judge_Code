#include<bits/stdc++.h>
#include"interactive/118.h"
using namespace std;

int a[101],ans[101] ;
main()
{
    int n=Init() ;
    for(int i=1;i<=n;i++)
    {
        int l=1 , r=n ;
        while(r>l)
        {
            int mid=(r+l)/2 ;
            memset(a,0,sizeof(a)) ;
            for(int j=l;j<=mid;j++) a[j]=i ;
            if(Answer(a)==1) r=mid ;
            else l=mid+1 ;
        }
        ans[l]=i ;
    }
    for(int i=1;i<=n;i++) a[i]=ans[i] ;
    Answer(a) ;
}
