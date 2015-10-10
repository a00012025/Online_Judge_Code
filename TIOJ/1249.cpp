#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=6000+10 ;

map<string,vector<int> > mp ;

string s[maxn] ;
vector<string> v,ans[maxn] ;

bool cmp(const vector<string> &a,const vector<string> &b)
{
    return a[0]<b[0] ;
}

main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        mp.clear() ;
        for(int i=1;i<=n;i++)
        {
            cin >> s[i] ;
            string t = s[i] ;
            sort(t.begin(),t.end()) ;
            mp[t].push_back(i) ;
        }
        int cnt=0 ;
        for(auto it : mp) if(it.S.size()>1)
        {
            cnt++ ;
            for(auto i : it.S) ans[cnt].push_back(s[i]) ;
            sort(ans[cnt].begin(),ans[cnt].end()) ;
        }
        if(!cnt) { printf("No Answer\n") ; return 0 ; }
        sort(ans+1,ans+cnt+1,cmp) ;
        for(int i=1;i<=cnt;i++)
        {
            bool fir=1 ;
            for(auto j : ans[i])
            {
                if(fir) fir=0 ;
                else printf(",") ;
                cout << j ;
            }
            printf("\n") ;
        }
    }
}
