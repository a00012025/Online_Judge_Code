#include <cstdio>
using namespace std;

char grid[51][51],word[51];
int Case,m,n,k;

void upper_to_lower (char a[])
{
    for (int i=0; a[i]; i++)
        if (a[i]>='A' && a[i]<='Z')
            a[i] += 32;
}
bool Locate (int i, int j)
{
    int x;
    for (x=1; i-x>=0 && word[x]==grid[i-x][j];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; i+x<m  && word[x]==grid[i+x][j];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; j-x>=0 && word[x]==grid[i][j-x];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; j+x<n  && word[x]==grid[i][j+x];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; i-x>=0 && j-x>=0 && word[x]==grid[i-x][j-x];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; i+x<m  && j-x>=0 && word[x]==grid[i+x][j-x];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; i-x>=0 && j+x<n  && word[x]==grid[i-x][j+x];) {x++; if (word[x]=='\0') return 1;}
    for (x=1; i+x<m  && j+x<n  && word[x]==grid[i+x][j+x];) {x++; if (word[x]=='\0') return 1;}
    return 0;
}
int main()
{
 //   freopen("input.txt","rt",stdin);
    scanf("%d",&Case);
    while (Case--){
        scanf("%d%d",&m,&n);
        for (int i=0; i<m; i++){
            scanf("%s",grid[i]);
            upper_to_lower(grid[i]);
        }

        scanf("%d",&k);
        while (k--){
            scanf("%s",word);
            upper_to_lower(word);

            int i,j,ok=0;
            for (i=0; i<m && !ok; i++)
                for (j=0; j<n && !ok; j++)
                    if (grid[i][j] == word[0] && Locate (i,j)){
                        printf("%d %d\n",i+1,j+1);
                        ok = 1;
                    }
        }
        if (Case) printf("\n");
    }
    return 0;
}
