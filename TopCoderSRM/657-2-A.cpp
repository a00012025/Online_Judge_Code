#include<bits/stdc++.h>
using namespace std;

struct EightRooks
{
    string isCorrect(vector<string> G)
    {
        for(int i=0;i<7;i++)
        {
            int cnt=0 ;
            for(int j=0;j<7;j++) if(G[i][j]=='R')
                cnt++ ;
            if(cnt!=1) return "Incorrect" ;
            cnt=0 ;
            for(int j=0;j<7;j++) if(G[j][i]=='R')
                cnt++ ;
            if(cnt!=1) return "Incorrect" ;
        }
        return "Correct" ;
    }
};
