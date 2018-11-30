#include <stdio.h>
#include <math.h>

#define size_of_matrix 5

void print_array(int array[size_of_matrix][size_of_matrix]);
void scan_array(int array[size_of_matrix][size_of_matrix]);
void selection_sort_columns_by_increas(int array[size_of_matrix][size_of_matrix]);
void product_of_rows_above_auxiliary_diagonal(int array[size_of_matrix][size_of_matrix]);

int main()
{
    int array[size_of_matrix][size_of_matrix];
    printf("введіть матрицю\n");
    scan_array(array);
    printf("початкова матриця: \n");
    print_array(array);
    selection_sort_columns_by_increas(array);
    printf("нова матриця: \n");
    print_array(array);
    product_of_rows_above_auxiliary_diagonal(array);
}

void scan_array(int array[size_of_matrix][size_of_matrix])
{
    for(int i=0; i<size_of_matrix; i++)
    {
        for(int j=0; j<size_of_matrix; j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
}

void print_array(int array[size_of_matrix][size_of_matrix])
{
    for(int i=0; i<size_of_matrix; i++)
    {
        for(int j=0; j<size_of_matrix; j++)
        {
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void selection_sort_columns_by_increas(int array[size_of_matrix][size_of_matrix])
{
    int min_value, coordinate_in_columns, temporary;
    for(int k=0; k<(size_of_matrix-1); k++)
    {
        for(int j=0; j<size_of_matrix; j++)
        {
            min_value=array[k][j];
            coordinate_in_columns=k;
            for(int i=(k+1); i<size_of_matrix; i++)
            {
                if(array[i][j]<min_value)
                {
                    min_value=array[i][j];
                    coordinate_in_columns=i;
                }
            }
            temporary=array[k][j];
            array[k][j]=array[coordinate_in_columns][j];
            array[coordinate_in_columns][j]=temporary;
        }
    }
    printf("\n");
}

void product_of_rows_above_auxiliary_diagonal(int array[size_of_matrix][size_of_matrix])
{
    int sum_of_product_of_rows_above_auxiliary_diagonal=0;
    for(int i=0; i<size_of_matrix; i++)
    {
        int product_of_one_of_rows_above_auxiliary_diagonal=1;
        for(int j=0; j<size_of_matrix; j++)
        {
            if((i+j)<(size_of_matrix-2))
            {
                product_of_one_of_rows_above_auxiliary_diagonal*=array[i][j];
            }
        }
        sum_of_product_of_rows_above_auxiliary_diagonal+=product_of_one_of_rows_above_auxiliary_diagonal;
        printf("product of one of rows above auxiliary diagonal = %d",product_of_one_of_rows_above_auxiliary_diagonal);
        printf("\n");
    }
    printf("sum of product of rows above auxiliary diagonal = %d\n",sum_of_product_of_rows_above_auxiliary_diagonal);
}
