#include <stdio.h>
main()
{
 int a,b,c,d,e,f,n ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6)
 {
 if ((c==e)&&(d==f)) printf ("�Ӧ����F��!�����Q���ڦ��I\n") ;
 else if ((a==e)&&(b==f)) printf ("�Ӧ����F��!�����Q���ڦ��I\n") ;
 else if ((a==c)&&(c==e)&&(b*f+f*d-f*f-b*d>0)) printf ("�Ӧ����F��!�����Q���ڦ��I\n") ;
 else if ((b==d)&&(d==e)&&(a*e+e*c-e*e-a*c>0)) printf ("�Ӧ����F��!�����Q���ڦ��I\n") ;
 else if ((a*d+e*f-e*d-a*f==b*c+e*f-c*f-b*e)&&(a*e+e*c-e*e-a*c>0)) printf ("�Ӧ����F��!�����Q���ڦ��I\n") ;
 else printf ("���ˤj�H!���ˤj�H!�ڧ֨�F�I\n") ;
 }
}
