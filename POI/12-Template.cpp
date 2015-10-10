#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

char s[maxn] ;
int n,Z[maxn] ;
void getz()
{
    Z[0]=-1 ;
    for(int i=1,L=-1,R=-1;s[i];i++)
    {
        int i2=i-L ;
        if(i>R)
        {
            int R2=i ;
            for(;R2<n && s[R2-i]==s[R2];R2++) ;
            Z[i]=R2-i ;
            L=i ; R=R2-1 ;
        }
        else if(Z[i2]>=R-i+1)
        {
            int R2=R ;
            for(;R2<n && s[R2-i]==s[R2];R2++) ;
            Z[i]=R2-i ;
            L=i ; R=R2-1 ;
        }
        else Z[i]=Z[i2] ;
//        printf("Z[%d] = %d\n",i,Z[i]) ;
    }
}

set<int> st ;
vector<int> v[maxn] ;
main()
{
    scanf("%s",s) ;
    n=strlen(s) ;
    getz() ;
    st.insert(0) ; st.insert(n) ;
    for(int i=1;i<n;i++) if(Z[i])
    {
        v[Z[i]].push_back(i) ;
        st.insert(i) ;
    }

    int ma=0 ;
    for(set<int>::iterator it=st.begin();;)
    {
        set<int>::iterator it0=it++ ;
        if(it==st.end()) break ;
        ma=max(ma,*it - *it0) ;
    }
    for(int i=1;i<=n;i++)
    {
        if(ma <= i){printf("%d\n",i) ; return 0 ;}
        for(int j=0;j<v[i].size();j++)
        {
            int x=v[i][j] ;
            set<int>::iterator it=st.find(x) , it1=it , it2=it ;
            it1-- ; it2++ ;
            ma=max(ma,*it2 - *it1) ;
            st.erase(it) ;
        }
    }
}
