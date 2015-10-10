#include <stdio.h>
#include <algorithm>
using namespace std;
char g[2][1024][1024];
int main() {
    int testcase;
    int n, m, d;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d", &n, &m, &d);
        while(getchar() != '\n');
        int i, j, k, flag = 0;
        for(i = 0; i < n; i++)
            gets(g[0][i]);
        while(d--) {
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    g[!flag][i][j] = g[flag][i][j];
                    if(g[flag][i][j] == 'R') {
                        if(i+1 < n && g[flag][i+1][j] == 'P')
                            g[!flag][i][j] = 'P';
                        else if(i-1 >= 0 && g[flag][i-1][j] == 'P')
                            g[!flag][i][j] = 'P';
                        else if(j+1 < m && g[flag][i][j+1] == 'P')
                            g[!flag][i][j] = 'P';
                        else if(j-1 >= 0 && g[flag][i][j-1] == 'P')
                            g[!flag][i][j] = 'P';
                    }
                    else if (g[flag][i][j] == 'P') {
                        if(i+1 < n && g[flag][i+1][j] == 'S')
                            g[!flag][i][j] = 'S';
                        else if(i-1 >= 0 && g[flag][i-1][j] == 'S')
                            g[!flag][i][j] = 'S';
                        else if(j+1 < m && g[flag][i][j+1] == 'S')
                            g[!flag][i][j] = 'S';
                        else if(j-1 >= 0 && g[flag][i][j-1] == 'S')
                            g[!flag][i][j] = 'S';
                    }
                    else {
                        if(i+1 < n && g[flag][i+1][j] == 'R')
                            g[!flag][i][j] = 'R';
                        else if(i-1 >= 0 && g[flag][i-1][j] == 'R')
                            g[!flag][i][j] = 'R';
                        else if(j+1 < m && g[flag][i][j+1] == 'R')
                            g[!flag][i][j] = 'R';
                        else if(j-1 >= 0 && g[flag][i][j-1] == 'R')
                            g[!flag][i][j] = 'R';
                    }
                }
            }
            flag = !flag;
        }
        for(i = 0; i < n; i++)
            g[flag][i][m] = '\0', puts(g[flag][i]);
        if(testcase)    puts("");
    }
    return 0;
}
