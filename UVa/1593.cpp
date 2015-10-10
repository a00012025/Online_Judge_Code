#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
vector<string> v[20000] ;
int length[20000][2000] ;
int num[1000000] ;
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;

    int n,len=0 ;
    for(n=1;;n++)
    {
        char c ;
        string s ;
        if((c=getchar())==EOF) break ;
        int cnt=0 ;
        while(1)
        {
            if(c==' ' && s.size())
            {
                v[n].push_back(s) ;
                length[n][cnt]=s.size() ;
                cnt++ ; len=max(len,cnt) ;
                s.clear() ;
            }
            else if(c!=' ') s.push_back(c) ;
            if(((c=getchar())==EOF) || c=='\n' || c=='\r')
            {
                if(s.size())
                {
                    v[n].push_back(s) ;
                    length[n][cnt]=s.size() ;
                    cnt++ ; len=max(len,cnt) ;
                    s.clear() ;
                }
                break ;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        num[i]=0 ;
        for(int j=1;j<=n;j++) if(i<v[j].size())
            num[i]=max(num[i],length[j][i]) ;
    }
    for(int j=1;j<=n;j++) for(int i=0;i<v[j].size();i++)
    {
        for(int k=0;k<v[j][i].size();k++) printf("%c",v[j][i][k]) ;
        if(i!=v[j].size()-1)
            for(int k=0;k<=num[i]-v[j][i].size();k++) printf(" ") ;
        else printf("\n") ;
    }
}
