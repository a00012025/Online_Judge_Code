#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

vector<int> v[maxn] ;
bool have[maxn] ;
char s[maxn] ;
stack<int> st ;
main()
{
    int n,k ; scanf("%d%d%s",&n,&k,s+1) ;
    st.push(1) ;
    for(int i=1,j=1;i<=n;i++)
    {
        if(st.empty()) st.push(++j) ;
        if(s[i]=='c')
        {
            if(have[st.top()])
            {
                st.push(++j) ;
                v[j].push_back(i) ;
                have[j]=1 ;
            }
            else
            {
                v[st.top()].push_back(i) ;
                have[st.top()]=1 ;
            }
        }
        else
        {
            if(v[st.top()].size()==k && !have[st.top()])
            {
                st.push(++j) ;
                v[j].push_back(i) ;
            }
            else v[st.top()].push_back(i) ;
        }
        if(v[st.top()].size()==k+1) st.pop() ;
    }
    for(int i=1;i<=n/(k+1);i++)
    {
        assert(v[i].size()==k+1) ;
        for(int j=0;j<v[i].size();j++)
            printf("%d%c",v[i][j],j+1==v[i].size()?'\n':' ') ;
    }
}
