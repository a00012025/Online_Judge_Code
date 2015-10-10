#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int ar[1100005];
vector<int>ram[2200005];
typedef pair<int,int> par;
bool tmp[1100005];
vector<par> ans;
int main(){
    int m;
    scanf("%d",&m);
    int l=0;
    for(int i=0;i<m;i++)
        scanf("%d",&ar[i]);
    for(int i=0;i<m;i++){
        int k=ar[i]-i+m;
        int sz=ram[k].size();
        if(sz){
            for(int f=sz-1;f>=0;f--){
                int x=ram[k][f];
                if(x<l)continue;
                for(int j=ar[x];j<=ar[i];j++)
                    tmp[j]=0;
                for(int j=x;j<=i;j++)
                    tmp[ar[j]]=1;
                bool chk=1;
                for(int j=ar[x];j<=ar[i];j++)
                    if(!tmp[j]){chk=0;break;}
                if(chk){
                    ans.push_back(par(x+1,i+1)),l=i;
                    ram[k].clear();
                    break;
                    }
                }
            }
        ram[k].push_back(i);
        }
    sort(ans.begin(),ans.end());
    int sz=ans.size();
    printf("%d\n",sz);
    for(int i=0;i<sz;i++)
        printf("%d %d\n",ans[i].f,ans[i].s);
    return 0;
    }
