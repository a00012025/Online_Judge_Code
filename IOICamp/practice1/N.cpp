#include <bits/stdc++.h>
using namespace std;
int a[510][4][4],score,tmp[4],tn,gg[510];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool same(int lv){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[lv][i][j]!=a[lv+1][i][j])return 0;
    return 1;
}
void print(int lv){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j)printf(" ");
            printf("%d",a[lv][i][j]);
        }
        puts("");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        score=0;
        memset(a,0,sizeof(a));
        memset(gg,0,sizeof(gg));
        int lv=0;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++)scanf("%d",&a[0][i][j]);
        int n;
        scanf("%d",&n);
        char s[12];
        while(n--){
            scanf("%s",s);
            int new_x,new_y;
            if(s[1]!='n')scanf("%d%d",&new_x,&new_y);
            new_x--;new_y--;
            if(s[0]=='D'){
                for(int j=0;j<4;j++){
                    tn=0;
                    for(int i=3;i>=0;i--){
                        if(a[lv][i][j])tmp[tn++]=a[lv][i][j];
                    }
                    int k=0,nk=0;
                    while(k<tn){
                        if(k+1<tn&&tmp[k]==tmp[k+1]){
                            tmp[nk++]=tmp[k]<<1;
                            gg[lv]+=tmp[nk-1];
                            k+=2;
                        }
                        else{
                            tmp[nk++]=tmp[k];
                            k++;
                        }
                    }
                    while(nk<4)tmp[nk++]=0;
                    nk=0;
                    for(int i=3;i>=0;i--)a[lv+1][i][j]=tmp[nk++];
                }
                score+=gg[lv];
                if(!same(lv))a[lv+1][new_x][new_y]=2;
                lv++;
            }
            else if(s[0]=='R'){
                for(int i=0;i<4;i++){
                    tn=0;
                    for(int j=3;j>=0;j--){
                        if(a[lv][i][j])tmp[tn++]=a[lv][i][j];
                    }
                    int k=0,nk=0;
                    while(k<tn){
                        if(k+1<tn&&tmp[k]==tmp[k+1]){
                            tmp[nk++]=tmp[k]<<1;
                            gg[lv]+=tmp[nk-1];
                            k+=2;
                        }
                        else{
                            tmp[nk++]=tmp[k];
                            k++;
                        }
                    }
                    while(nk<4)tmp[nk++]=0;
                    nk=0;
                    for(int j=3;j>=0;j--)a[lv+1][i][j]=tmp[nk++];
                }
                score+=gg[lv];
                if(!same(lv))a[lv+1][new_x][new_y]=2;
                lv++;
            }
            else if(s[0]=='L'){
                for(int i=0;i<4;i++){
                    tn=0;
                    for(int j=0;j<4;j++){
                        if(a[lv][i][j])tmp[tn++]=a[lv][i][j];
                    }
                    int k=0,nk=0;
                    while(k<tn){
                        if(k+1<tn&&tmp[k]==tmp[k+1]){
                            tmp[nk++]=tmp[k]<<1;
                            gg[lv]+=tmp[nk-1];
                            k+=2;
                        }
                        else{
                            tmp[nk++]=tmp[k];
                            k++;
                        }
                    }
                    while(nk<4)tmp[nk++]=0;
                    nk=0;
                    for(int j=0;j<4;j++)a[lv+1][i][j]=tmp[nk++];
                }
                score+=gg[lv];
                if(!same(lv))a[lv+1][new_x][new_y]=2;
                lv++;
            }
            else if(s[1]=='p'){
                for(int j=0;j<4;j++){
                    tn=0;
                    for(int i=0;i<4;i++){
                        if(a[lv][i][j])tmp[tn++]=a[lv][i][j];
                    }
                    int k=0,nk=0;
                    while(k<tn){
                        if(k+1<tn&&tmp[k]==tmp[k+1]){
                            tmp[nk++]=tmp[k]<<1;
                            gg[lv]+=tmp[nk-1];
                            k+=2;
                        }
                        else{
                            tmp[nk++]=tmp[k];
                            k++;
                        }
                    }
                    while(nk<4)tmp[nk++]=0;
                    nk=0;
                    for(int i=0;i<4;i++)a[lv+1][i][j]=tmp[nk++];
                }
                score+=gg[lv];
                if(!same(lv))a[lv+1][new_x][new_y]=2;
                lv++;
            }
            else if(s[1]=='n'){
                int x;
                scanf("%d",&x);
                while(x&&lv){
                    x--;
                    lv--;
                    score-=gg[lv];
                }
            }
        }
        print(lv);
        printf("Score: %d\n",score);
    }
    return 0;
}
