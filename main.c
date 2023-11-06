#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int main(void) {
    srand(time(NULL)); // Needed
    
    Matrix *x = create_matrix_rand(1, 3, 1, 10);
    Matrix *w = create_matrix_rand(3, 1, 1, 10);
    Matrix *b = create_matrix_rand(1, 1, 1, 10);

    print_matrix(x);
    printf("\nx\n\n");
    print_matrix(w);
    printf("\n+\n\n");
    print_matrix(b);
    printf("\nResult:\n");
    print_matrix(add_matrix(dot_matrix(x, w), b));
    

    free_matrix(x);
    free_matrix(w);
    free_matrix(b);
    return 0;
}
