#include<stdio.h>
#include<string.h>

int main()
{
   char s[2005],p[505];
   int a[2005];
   while(scanf("%s",s))
   {
      scanf("%s",p);
      int L1,L2;
      L1=strlen(s),L2=strlen(p);
      for(int i=0;i<=2000;i++)
      {
         a[i]=10000;
      }
      a[0]=0;
      for(int i=1;i<=L1;i++)
      {
         for(int j=i;j;j--)
         {
            if(!(j%L2))
               if(s[i-1]==p[L2])
                  if(a[j-1]+1<a[j])
                     a[j]=a[j-1]+1;
            else
            {
               a[j]++;
               if(s[i-1]==p[j%L2])
                  if(a[j-1]+1<a[j])
                     a[j]=a[j-1]+1;
            }
         }
      }
      for(int i=0;i<=L1;i++)
      {
         if(i)
            printf(" ");
         int count;
         count=(L1-i)/L2;
         while(count)
         {
            if(a[count*L2]-count*L2<=i)
               break;
            else
               count--;
         }
         printf("%d",count);
      }
      printf("\n");
   }
   return 0;
}
