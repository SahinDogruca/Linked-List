
#include "intlist.h"

int main() {
    struct Node * first = NULL;

    
    int arr[] = {1,2,3,4,5};
    
    first = create(first, arr, 5);
    display(first);
    printf("%d\n", find(first, 3));
    first = insert(first, 6, 0);
    display(first);
    first = delete(first, 6);
    display(first);

    
    
    
    return 0;
}
