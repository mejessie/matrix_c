// This code has been written by Jedsada Aimjit.
#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double **arr;
    int row;
    int col;
} Matrix;

Matrix *create_matrix(int row, int col);
Matrix *create_matrix_rand(int row, int col, double start, double end);
Matrix *create_matrix_number(int row, int col, double n);
Matrix *add_matrix(Matrix *matrix_a, Matrix *matrix_b);
Matrix *subtract_matrix(Matrix *matrix_a, Matrix *matrix_b);
Matrix *number_multiply_matrix(Matrix *matrix, double n);
Matrix *dot_matrix(Matrix *matrix_a, Matrix *matrix_b);
Matrix *transpose_matrix(Matrix *matrix);
void free_matrix(Matrix *matrix);
double matrix_conv_last(Matrix *matrix);
void print_matrix(Matrix *matrix);

#endif
