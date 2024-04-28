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



