#include<stdio.h>
#include<stack>
using namespace std;
int a[2000],right[2000],left[2000],right2[2000],left2[2000] ;
main()
{
    int l,r ;
    while(scanf("%d%d",&l,&r)!=EOF)
    {
        if(l==0 && r==0) break ;

        for(int i=1;i<=(r-l)/2+1;i++) scanf("%d",&a[i]) ;
        int zero=(-l+1)/2 , n=(r-l)/2+1 ;

        stack<int> st; int now=0 ;
        for(int i=1;i<=n;i++)
        {
            while(!st.empty() && a[i]>=a[st.top()])
                {right[st.top()]=i ; st.pop() ;}
            st.push(i) ;
            if(i==1) {left2[1]=0 ; now=1 ;}
            else if(a[i]>a[now]) {left2[i]=now ; now=i ; }
            else left2[i]=now ;
        }
        while(!st.empty()) {right[st.top()]=n+1 ; st.pop() ;}

        for(int i=n;i>=1;i--)
        {
            while(!st.empty() && a[i]>=a[st.top()])
                {left[st.top()]=i ; st.pop() ;}
            st.push(i) ;
            if(i==n) {right2[n]=n+1 ; now=n ;}
            else if(a[i]>a[now]) {right2[i]=now ; now=i ;}
            else right2[i]=now ;
        }
        while(!st.empty()) {left[st.top()]=0 ; st.pop() ;}

        //for(int i=1;i<=n;i++) printf("%d%c",right2[i],i==n?'\n':',') ;
        //for(int i=1;i<=n;i++) printf("%d%c",left2[i],i==n?'\n':',') ;

        int i,j,ans=0 ;
        for(i=1;right[i]<=zero;i=right[i]) ;
        for(j=n;left[j]>zero;j=left[j]) ;

        if(right[i]!=n+1 && a[right[i]]!=a[i])
            for(int k=1;k!=right[i];k=right[k]) ans+=2*a[k]*(right[k]-k) ;

        else if(left[j]!=0 && a[left[j]]!=a[j])
            for(int k=n;k!=left[j];k=left[k]) ans+=2*a[k]*(k-left[k]) ;

        else if(right[i]!=n+1)
        {
            int i2=right[i] ;
            ans+=2*a[i]*(i2-i) ;
            int ansl=0,ansr=0 ;
            for(int k=i;k!=1;k=left2[k]) ansl+=2*a[left2[k]]*(k-left2[k]) ;
            if(right2[i2]!=n+1 && a[right2[i2]]>a[i2])
            {
                for(int k=i2;k<n && a[k]<=a[i];k++) ansr+=2*a[i] ;
                ans+= ansr>ansl ? 2*ansl : ansr+ansl ;
            }
            else
            {
                for(int k=i2;k!=n;k=right2[k]) ansr+=2*a[right2[k]]*(right2[k]-k) ;
                ans+= ansl>ansr ? 2*ansr : 2*ansl ;
            }
        }

        else if(left[j]!=0)
        {
            int j2=left[j] ;
            ans+=2*a[j]*(j-j2) ;
            int ansl=0 , ansr=0 ;
            for(int k=j;k!=n;k=right2[k]) ansr+=2*a[right2[k]]*(right2[k]-k) ;
            if(left2[j2]!=0 && a[left2[j2]]>a[j2])
            {
                for(int k=j2;k>1 && a[k]<=a[j];k--) ansl+=2*a[j] ;
                ans+= ansl>ansr ? 2*ansr : ansr+ansl ;
            }
            else
            {
                for(int k=j2;k!=1;k=left2[k]) ansr+=2*a[left2[k]]*(k-left2[k]) ;
                ans+= ansl>ansr ? 2*ansr : 2*ansl ;
            }
        }
        printf("%d\n",ans) ;
    }
}
