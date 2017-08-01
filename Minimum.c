#include <stdio.h> 
#include <stdint.h> 
#include "library.h"

extern int Minimum(int data[], int count);

//C implementation
int Minimum2(int data[], int count) {
    int i = 1;
    int min = data[0];
    
Loop: if (i >= count) goto End;
    if (data[i] < min) min = data[i];
    i++;
    goto Loop;
End: return min;
}

int main(void) {
    InitializeHardware(HEADER, PROJECT_NAME);
    
    int a[] =  {7, 6, -5, -4};
    int size = sizeof(a)/sizeof(a[0]);
    
    //Print the array
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("{%d, ", a[i]);
        } else if (i + 1 == size) {
            printf("%d}", a[i]);
        } else {
            printf("%d, ", a[i]);
        }
    }
    
    //Print the minimum
    printf("\nMinimum: %d", Minimum(a, size));
}
