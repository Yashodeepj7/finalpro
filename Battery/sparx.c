#include <stdio.h>

#define MAX 10

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int terms;
    struct Element data[MAX];
};

void addElement(struct SparseMatrix *matrix, int row, int col, int value) {
    if (value != 0) {
        matrix->data[matrix->terms].row = row;
        matrix->data[matrix->terms].col = col;
        matrix->data[matrix->terms].value = value;
        matrix->terms++;
    }
}

void display(struct SparseMatrix matrix) {
    int i, j, k = 0;
    for (i = 0; i < matrix.rows; i++) {
        for (j = 0; j < matrix.cols; j++) {
            if (k < matrix.terms && matrix.data[k].row == i && matrix.data[k].col == j) {
                printf("%d ", matrix.data[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct SparseMatrix transpose(struct SparseMatrix matrix) {
    struct SparseMatrix transposedMatrix;
    transposedMatrix.rows = matrix.cols;
    transposedMatrix.cols = matrix.rows;
    transposedMatrix.terms = matrix.terms;

    int current = 0;
    int i, j;  // Declare loop variables outside the loop
    for (i = 0; i < matrix.cols; i++) {
        for (j = 0; j < matrix.terms; j++) {
            if (matrix.data[j].col == i) {
                transposedMatrix.data[current].row = matrix.data[j].col;
                transposedMatrix.data[current].col = matrix.data[j].row;
                transposedMatrix.data[current].value = matrix.data[j].value;
                current++;
            }
        }
    }

    return transposedMatrix;
}

int main() {
    struct SparseMatrix matrix;
    matrix.rows = 3;
    matrix.cols = 4;
    matrix.terms = 0;

    addElement(&matrix, 0, 1, 5);
    addElement(&matrix, 1, 2, 8);
    addElement(&matrix, 2, 0, 3);

    printf("Original Matrix:\n");
    display(matrix);

    struct SparseMatrix transposedMatrix = transpose(matrix);

    printf("\nTransposed Matrix:\n");
    display(transposedMatrix);

    return 0;
}

