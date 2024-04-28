//
// Created by Влад on 13.03.2024.
//
#include "algoritms.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

void swapMaxMinRows(matrix *m) {
    position max_value = getMaxValuePos(*m);
    position min_value = getMinValuePos(*m);
    swapRows(*m, max_value.rowIndex, min_value.rowIndex);
}

int getMax(int *a, const int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMaxElem(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(*m, getMax);
}
int getMin(int *a, const int n) {
    int min = a[0];for (int i = 0; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElem(matrix *m) {
    selectionSortColsMatrixByColCriteria(*m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "Different matrix dimensions");
        exit(1);
    }
    matrix result = getMemMatrix(m1.nRows, m2.nRows);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            result.values[i][j] = 0;
            for (int h = 0; h < m2.nCols; h++) {
                result.values[i][j] += m1.values[i][h] * m2.values[h][j];
            }
        }
    }
    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(m))
        return;
    matrix result = mulMatrices(*m, *m);
    freeMemMatrix(m);
    m->values = result.values;
    m->nRows = result.nRows;
    m->nCols = result.nCols;
}

