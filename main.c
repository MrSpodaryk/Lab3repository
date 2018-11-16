// my comment
#include <stdio.h>
#include <math.h>
void print(int ar[5][5]);
void scan(int ar[5][5]);
void change(int ar[5][5]);
void func(int ar[5][5]);
int main()
{
    int ar[5][5];
    scan(ar);
    printf("початкова матриця: \n");
    print(ar);
    change(ar);
    printf("нова матриця: \n");
    print(ar);
    func(ar);
}
void scan(int ar[5][5])
{
    for(int i=0; i<5; i++) //ввід
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
}
void print(int ar[5][5])
{
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void change(int ar[5][5])
{
    int min, min_y, t;
    for(int k=0; k<4; k++)
    {
        for(int j=0; j<5; j++)
        {
            min=ar[k][j];
            min_y=k;
            for(int i=(k+1); i<5; i++)
            {
                if(ar[i][j]<min)
                {
                    min=ar[i][j];
                    min_y=i;
                }
            }
            t=ar[k][j];
            ar[k][j]=ar[min_y][j];
            ar[min_y][j]=t;
        }
    }
    printf("\n");
}
void func(int ar[5][5])
{
    int s=1, p=0;
    for(int i=0; i<5; i++)
    {
        s=1;
        for(int j=0; j<5; j++)
        {
            if((i+j)<4)
            {
                s*=ar[i][j];
            }
        }
        p+=s;
        printf("s=%d",s);
        printf("\n");
    }
    printf("p=%d",p);
}
