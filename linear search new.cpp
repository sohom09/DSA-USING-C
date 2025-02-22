#include <stdio.h>
int main() {
    int n, i, s;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &s);
    for(i = 0; i < n; i++) {
        if(arr[i] == s) {
            printf("Element %d found at position %d.\n", s, i + 1);
            return 0;
        }
}	
    printf("Element %d not found in the array.\n", s);
    
    return 0;
}

