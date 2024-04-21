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
