#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/algoritm/algoritms.h"
#include <assert.h>
void test_swapMaxMinRows_1_standard_swap() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   4, 5, 6,
                                                   1, 2, 3}, 3, 3);
    swapMaxMinRows(&m);
    assert (areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}
void test_swapMaxMinRows_2_min_and_max_element_in_one_row() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 9,
                                              1, 1, 1,
                                              1, 1, 1}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 1, 9,
                                                  1, 1, 1,
                                                  1, 1, 1}, 3, 3);
    swapMaxMinRows(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_swapMaxMinRows() {
    test_swapMaxMinRows_1_standard_swap();
    test_swapMaxMinRows_2_min_and_max_element_in_one_row();
}
void test_sortRowsByMaxElem_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);
    sortRowsByMaxElem(&m);
    assert (areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}
void test_sortRowsByMaxElem_2_max_value_equal() {matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                                                                           9, 5, 6,
                                                                                           9, 2, 4}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   9, 5, 6,
                                                   9, 2, 4}, 3, 3);
    sortRowsByMaxElem(&m);
    assert (areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}
void test_sortRowsByMaxElem() {
    test_sortRowsByMaxElem_1_standard_value();
    test_sortRowsByMaxElem_2_max_value_equal();
}
void test_sortColsByMinElem_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);
    sortColsByMinElem(&m);
    assert (areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}
void test_sortColsByMinElem_2_min_value_equal() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              1, 1, 6,
                                              8, 7, 1}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   1, 1, 6,
                                                   8, 7, 1}, 3, 3);
    sortColsByMinElem(&m);
    assert (areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}
void test_sortColsByMinElem() {
    test_sortColsByMinElem_1_standard_value();
    test_sortColsByMinElem_2_min_value_equal();
}
void test_mulMatrices_1_standard_value() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix result = mulMatrices(m1, m2);
    matrix check = createMatrixFromArray((int[]) {30, 36, 42,
                                                  66, 81, 96,
                                                  102, 126, 150}, 3, 3);
    assert(areTwoMatricesEqual(&result, &check));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}
void test_mulMatrices_2_mul_to_e_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1}, 3, 3);
    matrix result = mulMatrices(m1, m2);
    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);
    assert(areTwoMatricesEqual(&result, &check));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}
void test_mulMatrices_3_mul_to_null_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {0, 0, 0,
                                               0, 0, 0,
                                               0, 0, 0}, 3, 3);
    matrix result = mulMatrices(m1, m2);
    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                  0, 0, 0,
                                                  0, 0, 0}, 3, 3);
    assert(areTwoMatricesEqual(&result, &check));freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}
void test_mulMatrices() {
    test_mulMatrices_1_standard_value();
    test_mulMatrices_2_mul_to_e_matrix();
    test_mulMatrices_3_mul_to_null_matrix();
}
void test_getSquareOfMatrixIfSymmetric_1_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 5, 6,
                                              3, 6, 9}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {14, 30, 42,
                                                  30, 65, 90,
                                                  42, 90, 126}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_getSquareOfMatrixIfSymmetric_2_not_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_getSquareOfMatrixIfSymmetric_3_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);freeMemMatrix(&check);
}
void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_1_symmetric_matrix();
    test_getSquareOfMatrixIfSymmetric_2_not_symmetric_matrix();
    test_getSquareOfMatrixIfSymmetric_3_e_matrix();
}
void test_transposeIfMatrixHasNotEqualSumOfRows_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_transposeIfMatrixHasNotEqualSumOfRows_2_not_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              4, 5, 6,
                                              0, 3, 0}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                  4, 5, 6,
                                                  0, 3, 0}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_1_standard_value();
    test_transposeIfMatrixHasNotEqualSumOfRows_2_not_different_sum();
}
void test_isMutuallyInverseMatrices_1_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);
    bool result = isMutuallyInverseMatrices(m1, m2);
    assert(result == 1);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);}
void test_isMutuallyInverseMatrices_2_not_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, -5,
                                               1, -2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);
    bool result = isMutuallyInverseMatrices(m1, m2);
    assert(result == 0);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}
void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_1_inverse_matrices();
    test_isMutuallyInverseMatrices_2_not_inverse_matrices();
}
void test_findSumOfMaxesOfPseudoDiagonal_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);
    long long result = findSumOfMaxesOfPseudoDiagonal(m);
    assert(result == 20);
    freeMemMatrix(&m);
}
void test_findSumOfMaxesOfPseudoDiagonal_2_one_element() {
    matrix m = createMatrixFromArray((int[]) {3}, 1, 1);
    long long int result = findSumOfMaxesOfPseudoDiagonal(m);
    assert(result == 0);
    freeMemMatrix(&m);
}
void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_1_standard_value();
    test_findSumOfMaxesOfPseudoDiagonal_2_one_element();
}
void test_getMinInArea_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);
    int result = getMinInArea(m);
    assert(result == 5);
    freeMemMatrix(&m);
}void test_getMinInArea_2_max_value_in_first_row() {
    matrix m = createMatrixFromArray((int[]) {10, 12, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 7, 2}, 3, 4);
    int result = getMinInArea(m);
    assert(result == 12);
    freeMemMatrix(&m);
}
void test_getMinInArea_3_equal_element() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                              0, 0}, 2, 2);
    int result = getMinInArea(m);
    assert(result == 0);
    freeMemMatrix(&m);
}
void test_getMinInArea() {
    test_getMinInArea_1_standard_value();
    test_getMinInArea_2_max_value_in_first_row();
    test_getMinInArea_3_equal_element();
}
void test_sortByDistance_1_different_distance() {
    matrix m = createMatrixFromArray((int[]) {2, 2, 2,
                                              3, 3, 3,
                                              1, 1, 1}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                  2, 2, 2,
                                                  3, 3, 3}, 3, 3);
    sortByDistances(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_sortByDistance_2_equal_distance() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 1, 3,
                                              3, 1, 2}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 1, 3,
                                                  3, 1, 2}, 3, 3);
    sortByDistances(&m);
    assert(areTwoMatricesEqual(&m, &check));freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_sortByDistance() {
    test_sortByDistance_1_different_distance();
    test_sortByDistance_2_equal_distance();
}
void test_countEqClassesByRowsSum_1_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              12, 1, 2}, 4, 3);
    int result = countEqClassesByRowsSum(m);
    assert(result == 3);
    freeMemMatrix(&m);
}
void test_countEqClassesByRowsSum_2_all_sum_different() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 11, 12}, 4, 3);
    int result = countEqClassesByRowsSum(m);
    assert(result == 4);
    freeMemMatrix(&m);
}
void test_countEqClassesByRowsSum_3_equal_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 3, 2,
                                              2, 1, 3,
                                              2, 3, 1}, 4, 3);
    int result = countEqClassesByRowsSum(m);
    assert(result == 1);
    freeMemMatrix(&m);
}
void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_1_different_sum();
    test_countEqClassesByRowsSum_2_all_sum_different();
    test_countEqClassesByRowsSum_3_equal_sum();
}
void test_getNSpecialElement_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,12, 2, 1, 2}, 3, 4);
    int result = getNSpecialElement(m);
    assert(result == 2);
    freeMemMatrix(&m);
}
void test_getNSpecialElement_2_not_have_special_element() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 2,
                                              3, 2, 1, 2}, 3, 4);
    int result = getNSpecialElement(m);
    assert(result == 0);
    freeMemMatrix(&m);
}
void test_getNSpecialElement() {
    test_getNSpecialElement_1_standard_value();
    test_getNSpecialElement_2_not_have_special_element();
}
void test_swapPenultimateRow_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);
    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  1, 4, 7,
                                                  7, 8, 1}, 3, 3);
    swapPenultimateRow(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_swapPenultimateRow_2_one_row() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix check = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    swapPenultimateRow(&m);
    assert(areTwoMatricesEqual(&m, &check));
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}
void test_swapPenultimateRow() {
    test_swapPenultimateRow_1_standard_value();
    test_swapPenultimateRow_2_one_row();
}void test_countNonDescendingRowsMatrices_1_standard_values() {
    int values[] = {7, 1, 1, 1, 1, 6, 2, 2, 5,
                    4, 2, 3, 1, 3, 7, 9};
    matrix *ms = createArrayOfMatrixFromArray(values, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
    freeMemMatrices(ms, 4);
}
void
test_countNonDescendingRowsMatrices_2_rows_are_ordered_in_non_decreasing_order() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                    14, 15, 16, 17, 18};
    matrix *ms = createArrayOfMatrixFromArray(values, 2, 3, 3);
    assert(countNonDescendingRowsMatrices(ms, 2) == 2);
    freeMemMatrices(ms, 2);
}
void
test_countNonDescendingRowsMatrices_3_some_rows_are_not_ordered_in_non_decreasing_order() {
    int values[] = {5, 4, 3, 2, 1, 0, 9, 8, 7, 10, 11, 12, 15,
                    14, 13, 18, 17, 16};
    matrix *ms = createArrayOfMatrixFromArray(values, 2, 3, 3);
    assert(countNonDescendingRowsMatrices(ms, 2) == 0);
    freeMemMatrices(ms, 2);
}
void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_1_standard_values();
    test_countNonDescendingRowsMatrices_2_rows_are_ordered_in_non_decreasing_order();
    test_countNonDescendingRowsMatrices_3_some_rows_are_not_ordered_in_non_decreasing_order();
}
void test_countZeroRows_1_standard_values() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                              0, 0,
                                              4, 7}, 3, 2);
    assert(countZeroRows(m) == 2);
    freeMemMatrix(&m);
}
void test_countZeroRows_2_without_zero_rows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    assert(countZeroRows(m) == 0);
    freeMemMatrix(&m);
}void test_countZeroRows() {
    test_countZeroRows_1_standard_values();
    test_countZeroRows_2_without_zero_rows();
}
void test_matrixNorm_1_all_elements_are_positive() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    assert(matrixNorm(m) == 9);
    freeMemMatrix(&m);
}
void test_matrixNorm_2_all_elements_are_negative() {
    matrix m = createMatrixFromArray((int[]) {-1, -2, -3,
                                              -4, -5, -6,
                                              -7, -8, -9}, 3, 3);
    assert(matrixNorm(m) == 9);
    freeMemMatrix(&m);
}
void test_matrixNorm_3_some_elements_are_negative() {
    matrix m = createMatrixFromArray((int[]) {-1, -2, -3,
                                              -4, 5, 10,
                                              -7, -8, 9}, 3, 3);
    assert(matrixNorm(m) == 10);
    freeMemMatrix(&m);
}
void test_matrixNorm() {
    test_matrixNorm_1_all_elements_are_positive();
    test_matrixNorm_2_all_elements_are_negative();
    test_matrixNorm_3_some_elements_are_negative();
}
void test_getNSpecialElement2_1_have_special_element() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                              6, 2, 3, 8, 12,
                                              12, 12, 2, 1, 2}, 3, 5);
    int result = getNSpecialElement2(m);
    assert(result == 4);
    freeMemMatrix(&m);
}
void test_getNSpecialElement2_2_not_have_special_element() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 5, 4,
                                              6, 2, 3, 12, 9,
                                              12, 12, 2, 1, 2}, 3, 5);
    int result = getNSpecialElement2(m);
    assert(result == 0);
    freeMemMatrix(&m);}
void test_getNSpecialElement2() {
    test_getNSpecialElement2_1_have_special_element();
    test_getNSpecialElement2_2_not_have_special_element();
}
void test_getVectorIndexWithMaxAngle_1_different_angle() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 3, 3,
                                              1, 3, 5}, 3, 3);
    int v[3] = {3, 1, 2};
    int result = getVectorIndexWithMaxAngle(m, v);
    assert(result == 2);
    freeMemMatrix(&m);
}
void test_getVectorIndexWithMaxAngle_2_equal_angle() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3}, 3, 3);
    int v[3] = {3, 1, 2};
    int result = getVectorIndexWithMaxAngle(m, v);
    assert(result == 0);
    freeMemMatrix(&m);
}
void test_getVectorIndexWithMaxAngle() {
    test_getVectorIndexWithMaxAngle_1_different_angle();
    test_getVectorIndexWithMaxAngle_2_equal_angle();
}
void test_getSpecialScalarProduct_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 3,
                                              3, 1, 2,
                                              2, 2, 3}, 3, 3);
    long long int result = getSpecialScalarProduct(m);
    assert(result == 16);
    freeMemMatrix(&m);
}
void test_getSpecialScalarProduct_2_max_min_element_in_equal_row_and_col() {
    matrix m = createMatrixFromArray((int[]) {4, 1, 3,
                                              3, 2, 2,
                                              2, 2, 3}, 3, 3);
    long long int result = getSpecialScalarProduct(m);
    assert(result == 12);freeMemMatrix(&m);
}
void test_getSpecialScalarProduct() {
    test_getSpecialScalarProduct_1_standard_value();
    test_getSpecialScalarProduct_2_max_min_element_in_equal_row_and_col();
}
void test() {
    test_swapMaxMinRows();
    test_sortRowsByMaxElem();
    test_sortColsByMinElem();
    test_mulMatrices();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistance();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
// функции с выводом были протестированы вручную
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_matrixNorm();
    test_getNSpecialElement2();
    test_getVectorIndexWithMaxAngle();
    test_getSpecialScalarProduct();
}
int main() {
    test();
    return 0;
}