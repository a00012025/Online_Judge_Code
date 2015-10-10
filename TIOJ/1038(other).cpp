#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int pr(char c)
{
    if( c == '-' ) return 0;

    if( 'a' <= c && c <= 'z' ) return c-'a'+1;
    else return c-'A'+31;
}

int r, c;
vector<int> v[60];

char s[300][10];
bool use[300];

int ans[300][300];
int dir[300][300];

char rev(char x)
{
    if( x == '-' ) return x;

    if( 'a' <= x && x <= 'z' ) return x-'a'+'A';
    else return x-'A'+'a';
}

bool DFS(int ri, int ci)
{
    if( ri == r ) return true;
    if( ci == c ) return DFS(ri+1, 0);

    char u, l;

    if( ri == 0 ) u = '-';
    else u = rev(s[ans[ri-1][ci] ][(dir[ri-1][ci]+3)%4 ] );

    if( ci == 0 ) l = '-';
    else l = rev(s[ans[ri][ci-1] ][(dir[ri][ci-1]+2)%4 ] );

    int sp = pr(l);

    for(int vi = 0; vi < v[sp].size(); vi+=2)
    {
        int t = v[sp][vi];

        if( use[t] ) continue;

        ans[ri][ci] = t;
        dir[ri][ci] = v[sp][vi+1];

        if( s[ans[ri][ci] ][(dir[ri][ci]+1)%4 ] != u ) continue;
        if( ci == c-1 )
        {
            if( s[ans[ri][ci] ][(dir[ri][ci]+2)%4 ] != '-' ) continue;
        }
        if( ri == r-1 )
        {
            if( s[ans[ri][ci] ][(dir[ri][ci]+3)%4 ] != '-' ) continue;
        }

        use[t] = true;

        if( DFS(ri, ci+1) ) return true;
        use[t] = false;
    }

    return false;
}

int main()
{

    while( scanf("%d %d", &r, &c) )
    {

        if( !r && !c ) break;

        for(int i = 0; i < 60; i++)
            v[i].clear();

        for(int i = 0; i < r*c; i++)
        {
            s[i][0]=getchar() ;
            while(s[i][0]=='\n')
                s[i][0]=getchar() ;
            for(int j=1;j<8;j++) s[i][j]=getchar() ;
        }

        for(int i = 0; i < r*c; i++)
            for(int j = 0; j < 4; j++)
            {
                int p = pr(s[i][j]);
                v[p].push_back(i);
                v[p].push_back(j);
            }

        fill(use, use+r*c, false);

        DFS(0, 0);

        for(int ri = 0; ri < r; ri++)
        {
            for(int ci = 0; ci < c; ci++)
                printf("%c", s[ans[ri][ci] ][4+dir[ri][ci] ] );

            puts("");
        }

        puts("");

    }
}
