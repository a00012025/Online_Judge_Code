#include<stdio.h>
#include<string.h> 
main()
{
 int n,i,j,k1,k2,m1,m2,mm,pow,l,ll,str,kk,Z,m,k,mmm;
 char s[200],t[200]; 
 while(scanf("%d",&n)==1)
    {
    gets(s); 
    for(i=1;i<=n;i++)
     {
     gets(s);
     str=strlen(s) ; 
     for(ll=0;ll<str;ll++) t[ll]=s[ll];
     for(j=0;j<str;j++)
        {
        if (s[j]!='*') continue;
        m1=0; 
        m2=0; 
        for(k1=j-1;(s[k1]<='9')&&(s[k1]>='0')&&(k1>=0);k1--);
        for(k2=j+1;(s[k2]<='9')&&(s[k2]>='0')&&(k2<str);k2++)
            {
            m2*=10;
            m2+=s[k2]-'0';          
            } 
        for(kk=k1+1;kk<=j-1;kk++)
            {
            m1*=10;
            m1+=s[kk]-'0'; 
            }
        mm=m1*m2;
        pow=0; 
        for(ll=1;ll<=mm;ll=ll*10) pow+=1; 
        for(l=k1+pow;l>=k1+1;l--)
            {
            s[l]=mm-(mm/10*10)+'0';
            mm=mm/10; 
            }
        for(l=k2;l<str;l++) s[l-k2+k1+pow+1]=s[l] ;
        str=str-k2+k1+pow+1; 
        mmm=1;
        for(ll=0;ll<str;ll++)
            {
            if(s[ll]=='*')
                {
                mmm=0;
                break;
                }
            }
        if (mmm==0) j=0;
        } 
        
            Z=0;
            for(j=0;j<str;)
            {
            m=0; 
            m+=s[j]-'0';
            for(k=j+1;(s[k]>='0')&&(s[k]<='9')&&(k<str);k++)
                {
                m=m*10;
                m+=s[k]-'0';
                }
            Z+=m ; 
            for(l=k;(s[l]>'9')||(s[l]<'0');l++);
            j=l;
            }
            printf("%d\n",Z);
     }
    } 
} 
