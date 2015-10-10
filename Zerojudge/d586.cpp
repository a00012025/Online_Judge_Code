#include<stdio.h>
#include<stdlib.h>
main()
{
 char c[30];
 int m,n,i,j,ans,d[30],x,lengh;
 char s[30000];
 c[1]='m';c[2]='j';c[3]='q';c[4]='h';c[5]='o';c[6]='f';c[7]='a';
 c[8]='w';c[9]='c';c[10]='p';c[11]='n';c[12]='s';c[13]='e';c[14]='x';
 c[15]='d';c[16]='k';c[17]='v';c[18]='g';c[19]='t';c[20]='z';c[21]='b';
 c[22]='l';c[23]='r';c[24]='y';c[25]='u';c[26]='i';
 d[1]=5;d[2]=16;d[3]=22;d[4]=26;d[5]=19;d[6]=8;d[7]=25;d[8]=13;
 d[9]=7;d[10]=24;d[11]=20;d[12]=18;d[13]=4;d[14]=12;d[15]=10;d[16]=11;
 d[17]=23;d[18]=3;d[19]=17;d[20]=6;d[21]=1;d[22]=15;d[23]=14;d[24]=9;
 d[25]=21;d[26]=2;
 
 while(scanf("%d",&n)==1)
 {
 for(i=1;i<=n;i++)
 {
 scanf("%d",&m);
 gets(s);
 for(lengh=1;s[lengh]!='\0';lengh++);
 if((s[1]>'a'-1)&&(s[1]<'z'+1))
    {
    ans=0;
    for(j=1;j<lengh;j+=2)
        {
        x=s[j]-'a'+1;
        ans+=d[x];
        }
    printf("%d\n",ans);
    }
 else
    {
    for(j=1;j<lengh;j++)
        {
        if(s[j-1]==' ') m=0;
        m=m*10;
        m=m+s[j]-'0';
        if((s[j+1]==' ')||(j==(lengh-1)))
            {
            if((c[m]>'a'-1)&&(c[m]<'z'+1)) 
                {
                printf("%c",c[m]);
                j=j+1;
                }
            }
        }
    printf("\n");
    }
 }
 }
}
