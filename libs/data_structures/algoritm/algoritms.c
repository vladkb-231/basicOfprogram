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

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;
    return true;
}
long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {long long sum[m->nRows];
    for (int i = 0; i < m->nRows; i++)
        sum[i] = getSum(m->values[i], m->nCols);
    if (isUnique(sum, m->nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix multiplication = mulMatrices(m1, m2);
    if (isEMatrix(&multiplication))
        return true;
    return false;
}
int max(int a, int b) {
    return a > b ? a : b;
}
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int r = m.nRows;
    int c = m.nCols;
    int *max_values = (int *) malloc(sizeof(int) * (r + c - 1));
    for (int i = 0; i < r + c - 1; i++)
        max_values[i] = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (i != j)
                max_values[i - j + c - 1] = max(max_values[i - j + c - 1],
                                                m.values[i][j]);
    long long sum = 0;
    for (int i = 0; i < r + c - 1; i++)
        sum += max_values[i];
    return sum;
}

bool valueInArea(position max, int i, int j) {
    position new_pos = {i - max.rowIndex, j - max.colIndex};
    return (new_pos.rowIndex <= new_pos.colIndex) && (new_pos.rowIndex <= -
            new_pos.colIndex);
}
int getMinInArea(matrix m) {
    position max_value = getMaxValuePos(m);
    int min = INT_MAX;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (valueInArea(max_value, i, j) && m.values[i][j] < min)
                min = m.values[i][j];
    return min;
}float getDistance(int *a, int n) {
    long long sum_square = 0;
    for (int i = 0; i < n; i++)
        sum_square += a[i] * a[i];
    return sqrt(sum_square);
}
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *,
                                                                       int)) {
    for (int i = 1; i < m.nRows; i++) {
        float key = criteria(m.values[i], m.nCols);
        int j = i - 1;
        while (j >= 0 && criteria(m.values[j], m.nCols) > key) {
            swapRows(m, j, j + 1);
            j--;
        }
    }
}
void sortByDistances(matrix *m) {
    insertionSortRowsMatrixByRowCriteriaF(*m, getDistance);
}
int cmp_long_long(const void *pa, const void *pb) {
    return (int) (*(long long int *) pa - *(long long int *) pb);
}
int countNUnique(long long *a, int n) {
    if (n == 0)
        return 0;
    qsort(a, n, sizeof(long long), cmp_long_long);
    int amount_elem = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            amount_elem++;
    return amount_elem;
}
int countEqClassesByRowsSum(matrix m) {
    long long sums_of_row_elements[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sums_of_row_elements[i] = getSum(m.values[i], m.nCols);
    int result = countNUnique(sums_of_row_elements, m.nRows);
    return result;
}
int getNSpecialElement(matrix m) {
    int amount_elem = 0;
    for (int i = 0; i < m.nCols; i++) {
        int max_value = m.values[0][i];
        int sum = m.values[0][i];for (int j = 1; j < m.nRows; j++) {
            sum += m.values[j][i];
            if (m.values[j][i] > max_value)
                max_value = m.values[j][i];
        }
        if (max_value > (sum - max_value))
            amount_elem++;
    }
    return amount_elem;
}
position getLeftMin(matrix m) {
    position pos_min = getMinValuePos(m);
    return pos_min;
}
void swapPenultimateRow(matrix *m) {
    if (m->nRows < 2)
        return;
    position pos_min = getLeftMin(*m);
    int *temp = (int *) malloc(sizeof(int) * m->nRows);
    for (int i = 0; i < m->nRows; i++)
        temp[i] = m->values[i][pos_min.colIndex];
    for (int i = 0; i < m->nCols; i++)
        m->values[m->nRows - 2][i] = temp[i];
    free(temp);
}
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int amount_matrices = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            amount_matrices++;
    return amount_matrices;
}
int countValues(const int *a, int n, int value) {int amount_values = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            amount_values++;
    return amount_values;
}
int countZeroRows(matrix m) {
    int amount_zero_rows = 0;
    for (int i = 0; i < m.nRows; i++) {
        int amount_zero = countValues(m.values[i], m.nCols, 0);
        if (amount_zero == m.nCols)
            amount_zero_rows++;
    }
    return amount_zero_rows;
}
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int amount_zero[nMatrix];
    int max_zero_rows = 0;
    for (int i = 0; i < nMatrix; i++) {
        int amount_zero_rows = countZeroRows(ms[i]);
        amount_zero[i] = amount_zero_rows;
        if (amount_zero_rows > max_zero_rows)
            max_zero_rows = amount_zero_rows;
    }
    for (int i = 0; i < nMatrix; i++)
        if (amount_zero[i] == max_zero_rows)
            outputMatrix(*ms);
}

int matrixNorm(matrix m) {
    int max = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > max)
                max = abs(m.values[i][j]);
    return max;
}
void printMinNormMatrix(matrix *ms, int nMatrix) {
    int min_norm = matrixNorm(ms[0]);
    int min_index = 0;
    for (int i = 0; i < nMatrix; i++) {
        int norm = matrixNorm(ms[i]);
        if (norm < min_norm) {
            min_norm = norm;
            min_index = i;
        }
    }
    outputMatrix(ms[min_index]);}

int min2(int a, int b) {
    return a < b ? a : b;
}
bool isSpecial(int *a, int n, int index) {
    for (int i = 0; i < index; i++)
        if (a[index] != max(a[i], a[index]))
            return false;
    for (int i = index + 1; i < n; i++)
        if (a[index] != min2(a[i], a[index]))
            return false;
    return true;
}
int getNSpecialElement2(matrix m) {
    int amount = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (isSpecial(m.values[i], m.nCols, j))
                amount++;
    return amount;
}

double getScalarProduct(int *a, int *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += (double) a[i] * b[i];
    return sum;
}
double getVectorLength(int *a, int n) {
    double sum = getScalarProduct(a, a, n);
    double length = sqrt(sum);
    return length;
}
double getCosine(int *a, int *b, int n) {
    double scalar_product = getScalarProduct(a, b, n);
    double length_first_vector = getVectorLength(a, n);
    double length_second_vector = getVectorLength(b, n);
    return scalar_product / (length_first_vector * length_second_vector);
}
int getVectorIndexWithMaxAngle(matrix m, int *v) {
    double max_cosine = getCosine(m.values[0], v, m.nCols);
    int max_index = 0;
    for (int i = 0; i < m.nRows; i++) {
        double cosine = getCosine(m.values[i], v, m.nCols);
        if (cosine < max_cosine) {
            max_cosine = cosine;
            max_index = i;}
    }
    return max_index;
}

