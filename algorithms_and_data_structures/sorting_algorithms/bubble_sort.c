#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Invalid number of arguments! Usage: ./bubble_sort [LIST OF INTEGERS]");
        return EXIT_FAILURE;
    }

    int arr[argc - 1];
    for (int i = 1; i < argc; i++)
        arr[i - 1] = atoi(argv[i]);

    bubble_sort(arr, argc - 1);
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", arr[i]);
    putchar('\n');
    return 0;
}


void bubble_sort(int *arr, int size)
{
    int swap_count = 1;
    int temp_var;
    for (int i = 0; i < size; i++)
    {
        if (swap_count)
        {
            swap_count = 0;
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap the two variables
                    swap_count = 1;
                    temp_var = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp_var;
                }
            }
        }
        
    }
}
