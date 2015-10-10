#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct P{
    int idx;
    short num;
}arr[1000001][3];
int top[1000001]={0};
vector<int> prime;
int s[100005],b[1000001]={0};
int cmp(P x,P y){
    if(x.num!=y.num) return x.num<y.num;
    return x.idx<y.idx;
}
int main(){
    //freopen("odl5b.in","r",stdin);
    int n,i,j,k,l,add,ans,p,q=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
        if(s[i]>q) q=s[i];
    }
    for(i=2;i<=q;i++){
        if(b[i]==0){
            b[i]=1;
            prime.push_back(i);
            for(j=i+i;j<=q;j+=i){
                add=0,k=j;
                while(k%i==0){
                    add++;
                    k/=i;
                }
                b[j]+=add;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j*j<=s[i];j++)
            if(s[i]%j==0){
                arr[j][top[j]++]=((P){i,b[s[i]/j]});
                if(top[j]>2) sort(arr[j],arr[j]+top[j],cmp),top[j]--;
                if(j*j!=s[i])
                arr[s[i]/j][top[s[i]/j]++]=((P){i,b[j]});
                if(top[s[i]/j]>2) sort(arr[s[i]/j],arr[s[i]/j]+top[s[i]/j],cmp),top[s[i]/j]--;
            }
    }
    for(i=1;i<=1000000;i++)
        sort(arr[i],arr[i]+top[i],cmp);
    for(i=0;i<n;i++){
        ans=999999999;
        for(j=1;j*j<=s[i];j++)
            if(s[i]%j==0){
                k=0;
                if(arr[j][k].idx==i) k++;
                if(k<top[j] && (arr[j][k].num+b[s[i]/j]<ans || (arr[j][k].num+b[s[i]/j]==ans && arr[j][k].idx<p)))
                    ans=arr[j][k].num+b[s[i]/j],p=arr[j][k].idx;
                k=0;
                if(arr[s[i]/j][k].idx==i) k++;
                if(k<top[s[i]/j] && (arr[s[i]/j][k].num+b[j]<ans || (arr[s[i]/j][k].num+b[j]==ans && arr[s[i]/j][k].idx<p)))
                    ans=arr[s[i]/j][k].num+b[j],p=arr[s[i]/j][k].idx;
            }
        printf("%d\n",p+1);
    }
}
