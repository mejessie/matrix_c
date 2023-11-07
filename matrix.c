// This code has been written by Jedsada Aimjit.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

Matrix *create_matrix(int row, int col) {
    Matrix *new_matrix = (Matrix *)malloc(sizeof(Matrix));
    new_matrix->row = row;
    new_matrix->col = col;
    new_matrix->arr = (double **)malloc(row * sizeof(double *));
    for(int i = 0; i < new_matrix->row; i++) {
        new_matrix->arr[i] = (double *)malloc(col * sizeof(double));
    }
    return new_matrix;
}

Matrix *create_matrix_rand(int row, int col, double start, double end) {
    Matrix *new_matrix = create_matrix(row, col);
    for(int i = 0; i < new_matrix->row; i++) {
        for(int j = 0; j < new_matrix->col; j++) {
            new_matrix->arr[i][j] = start + ((double)rand() / RAND_MAX) * (end - start);
        }
    }
    return new_matrix;
}

Matrix *create_matrix_number(int row, int col, double n) {
    n *= 1;
    Matrix *new_matrix = create_matrix(row, col);
    for(int i = 0; i < new_matrix->row; i++) {
        for(int j = 0; j < new_matrix->col; j++) {
            new_matrix->arr[i][j] = n;
            n++;
        }
    }
    return new_matrix;
}

Matrix *add_matrix(Matrix *matrix_a, Matrix *matrix_b) {
    if((matrix_a->col != matrix_b->col) || (matrix_a->row != matrix_b->row)) {
        printf("ERROR() -> add_matrix() : Matrices must be of the same size.\n");
        return NULL;
    }
    Matrix *new_matrix = create_matrix(matrix_a->row, matrix_a->col);
    for(int i = 0; i < matrix_a->row; i++) {
        for(int j = 0; j < matrix_a->col; j++) {
            new_matrix->arr[i][j] = matrix_a->arr[i][j] + matrix_b->arr[i][j];
        }
    }
    return new_matrix;
}

Matrix *subtract_matrix(Matrix *matrix_a, Matrix *matrix_b) {
    if((matrix_a->col != matrix_b->col) || (matrix_a->row != matrix_b->row)) {
        printf("ERROR() -> subtract_matrix() : Matrices must be of the same size.\n");
        return NULL;
    }
    Matrix *new_matrix = create_matrix(matrix_a->row, matrix_a->col);
    for(int i = 0; i < matrix_a->row; i++) {
        for(int j = 0; j < matrix_a->col; j++) {
            new_matrix->arr[i][j] = matrix_a->arr[i][j] - matrix_b->arr[i][j];
        }
    }
    return new_matrix;
}

Matrix *number_multiply_matrix(Matrix *matrix, double n) {
    Matrix *new_matrix = create_matrix(matrix->row, matrix->col);
    for(int i = 0; i < matrix->row; i++) {
        for(int j = 0; j < matrix->col; j++) {
            new_matrix->arr[i][j] = matrix->arr[i][j] * n;
        }
    }
    return new_matrix;
}

Matrix *dot_matrix(Matrix *matrix_a, Matrix *matrix_b) {
    if(matrix_a->col != matrix_b->row) {
        printf("ERROR() -> dot_matrix() : The number of columns in the first matrix should be equal to the number of rows in the second.\n");
        return NULL;
    }
    Matrix *new_matrix = create_matrix(matrix_a->row, matrix_b->col);
    for(int ar = 0; ar < matrix_a->row; ar++) {
        for(int bc = 0; bc < matrix_b->col; bc++) {
            double total = 0;
            for(int ab = 0; ab < matrix_a->col; ab++) {
                total += matrix_a->arr[ar][ab] * matrix_b->arr[ab][bc];
            }
            new_matrix->arr[ar][bc] = total;
        }
    }
    return new_matrix;
}

Matrix *transpose_matrix(Matrix *matrix) {
    Matrix *new_matrix = create_matrix(matrix->col, matrix->row);
    for(int i = 0; i < matrix->col; i++) {
        for(int j = 0; j < matrix->row; j++) {
            new_matrix->arr[i][j] = matrix->arr[j][i];
        }
    }
    return new_matrix;
}

void free_matrix(Matrix *matrix) {
    for(int i = 0; i < matrix->row; i++) {
        free(matrix->arr[i]);
    }
    free(matrix);
    matrix = NULL;
}

double matrix_conv_last(Matrix *matrix) {
    double n = matrix->arr[0][0];
    free_matrix(matrix);
    return n;
}

void print_matrix(Matrix *matrix) {
    for(int i = 0; i < matrix->row; i++) {
        for(int j = 0; j < matrix->col; j++) {
            printf("%lf ", matrix->arr[i][j]);
        }
        printf("\n");
    }
}
