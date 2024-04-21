//
// Created by Влад on 15.04.2024.
//
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <assert.h>
# include <string.h>
# include <math.h>
# include "../matrix/matrix.h"

// task 1
void swap_max_min_row_element ( matrix *m) {
    int max_num = m-> values [0][0];
    int min_num = m-> values [0][0];
    int index_max = 0;
    int index_min = 0;
    for ( int row = 0; row < m-> nRows ; row ++) {
        for ( int col = 0; col < m-> nCols ; col ++) {
            if ( max_num < m-> values [ row ][ col ]) {
                max_num = m-> values [row ][ col ];
                index_max = row ;
            } else if ( min_num > m-> values [ row ][ col ]) {
                min_num = m-> values [row ][ col ];
                index_min = row ;
            }
        }
    }
    if ( index_min != index_max ) {
        swapRows (*m, index_max , index_min );
    }
}
// task 2
int getMax ( int *a, int n) {
    int max_num = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max_num)
            max_num = a[i];
    }
    return max_num;
}
void sortRowsByMinElement ( matrix m) {
    insertionSortRowsMatrixByRowCriteria (m, getMax );
}

// task 3
int getMin ( int *a, int n) {
    int min_num = a [0];
    for ( int i = 0; i < n; i++) {
        if (a[i] < min_num )
            min_num = a[i];
    }
    return min_num ;
}
void sortColsByMinElement ( matrix m) {
    selectionSortColsMatrixByColCriteria (m, getMin );
}

// task 4
matrix mulMatrices ( matrix m1 , matrix m2) {
    assert (m1. nCols == m2. nRows );
    matrix result = getMemMatrix (m2.nRows , m1. nCols );
    for ( int row = 0; row < m1. nRows ; row ++)
        for ( int col = 0; col < m2. nCols ; col ++) {
            result . values [ row ][ col ] = 0;
            for ( int k = 0; k < m1. nCols ; k ++)
                result . values [ row ][ col ] += m1. values [ row ][k] *
                                                  m2. values [k][ col ];
        }
    return result ;
}
void getSquareOfMatrixIfSymmetric ( matrix *m) {
    assert ( isSymmetricMatrix (m));
    matrix result = mulMatrices (*m, *m);
    freeMemMatrix (m);
    m-> values = result . values ;
    m-> nRows = result . nRows ;
    m-> nCols = result . nCols ;
}



