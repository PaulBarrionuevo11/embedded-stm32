/******************************************************************************

        Swapping arrays exercise. Moves array elements from one array to another
        Depending on size, it will keep the remainder of the original size when len 1 > len 2 or len1 < len2

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
void arraySwap(uint32_t *array1, uint32_t *array2, uint32_t len1, uint32_t len2);

int main()
{
    uint32_t sizeofArray1;
    uint32_t sizeofArray2;

    printf("Array swapping program \n");
    printf("Enter the size of Array 1: \n ");
    scanf("%d", &sizeofArray1);
    printf("Enter the size of Array2: \n ");
    scanf("%d", &sizeofArray2);
    
    
    
    uint32_t array1[sizeofArray1];
    uint32_t array2[sizeofArray2];
    
    arraySwap(array1, array2, sizeofArray1, sizeofArray2);
    
    // Print array after swap
    printf("Array-1 is now: ");
    for(int i = 0; i<sizeofArray1; i++)
    {
        printf("%d", array1[i]);
    }
    printf("\n");

    printf("Array-2 is now: ");
    for(int i = 0; i<sizeofArray2; i++)
    {
        printf("%d", array2[i]);
    }
    return 0;
}

void arraySwap(uint32_t *array1, uint32_t *array2, uint32_t len1, uint32_t len2)
{
    uint32_t ptempArray[] = {};
    
    for (uint32_t i=0; i<len1; i++)
    {
        printf("Enter element %d of Array-1: ", i);
        scanf("%d", &array1[i]);
    }
    for (uint32_t i=0; i<len2; i++)
    {
        printf("Enter element %d of Array-2: ", i);
        scanf("%d",&array2[i]);
    }

   
    uint32_t len = len1 < len2 ? len1 : len2;
    
    for(uint32_t i=0; i<len; i++)
    {
        int32_t temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
}