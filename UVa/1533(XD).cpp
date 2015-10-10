#include<stdio.h>
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        switch(n)
        {
            case 1 :
                printf("9\n4 1 6 4 11 2 14 11 15 6 1 10 10 7 11 4 4 1\n");
                break ;
            case 2 :
                printf("9\n7 2 1 4 10 1 14 2 1 7 11 14 15 13 13 4 7 2\n");
                break ;
            case 3 :
                printf("9\n10 3 1 6 7 1 12 3 1 10 14 12 11 13 13 6 15 3\n");
                break ;
            case 4 :
                printf("9\n1 4 6 1 13 6 10 3 11 13 3 12 15 11 11 2 1 4\n");
                break ;
            case 5 :
                printf("10\n12 5 3 8 15 12 6 13 7 9 1 7 10 8 7 9 11 14 14 5\n");
                break ;
            case 6 :
                printf("9\n1 6 4 1 13 4 7 2 15 13 2 14 11 15 15 3 1 6\n");
                break ;
            case 7 :
                printf("9\n1 7 6 1 11 4 9 7 14 11 11 2 15 6 6 4 1 7\n");
                break ;
            case 8 :
                printf("10\n3 8 12 5 15 3 13 6 1 10 2 9 11 2 14 5 2 9 10 8\n");
                break ;
            case 9 :
                printf("10\n2 9 11 2 12 5 3 8 13 4 1 7 14 5 15 3 3 8 7 9\n");
                break ;
            case 10 :
                printf("9\n1 10 4 1 11 4 4 6 12 5 10 8 15 12 12 3 1 10\n");
                break ;
            case 11 :
                printf("9\n4 11 1 4 10 1 14 2 1 7 11 14 15 13 13 4 4 11\n");
                break ;
            case 12 :
                printf("9\n14 12 2 14 7 2 1 4 15 13 3 15 11 14 4 13 15 12\n");
                break ;
            case 13 :
                printf("9\n4 13 1 4 11 2 13 11 15 13 2 14 3 15 15 12 11 13\n");
                break ;
            case 14 :
                printf("9\n11 14 2 11 3 12 10 3 1 6 11 13 15 12 6 13 12 14\n");
                break ;
            case 15 :
                printf("9\n6 15 1 6 7 1 12 3 1 10 15 12 11 13 13 6 6 15\n");
                break ;
        }
    }
}
