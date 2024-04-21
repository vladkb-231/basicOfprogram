//
// Created by Влад on 15.04.2024.
//

#ifndef COURSE_LAB_TASKS_H
#define COURSE_LAB_TASKS_H

#include "../matrix/matrix.h"

// task 1
// меняет местами строки с максимальными минимальным элементом
void swap_max_min_row_element ( matrix *m);
// task 2
//возвращает максимальный элемент массива
int getMax ( int *a, int n);
//упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMinElement ( matrix m);
// task 3
//выводит минимальный элемент матрицы
int getMin ( int *a, int n);
//упорядочивает столбцы матрицы понеубыванию минимальных элементов столбцов
void sortColsByMinElement ( matrix m);
// task 4
//умножает матрицы друг на друга
matrix mulMatrices ( matrix m1 , matrix m2);
//если матрица симметрична , то заменяет ее квадратом этой матрицы
void getSquareOfMatrixIfSymmetric ( matrix *m);
// task 5
//возвращает истину если в массиве нет одинаковых элементов
bool isUnique ( long long *a, int n);
//возвращает суммуэлементов
long long getSum (int *a, int n);
// транспонирует матрицу если суммы строк различны
void transposeIfMatrixHasNotEqualSumOfRows ( matrix m);
// task 6
//возвращает истинна если матрицы явл . взаимнообратными
bool isMutuallyInverseMatrices ( matrix m1 , matrix m2);
// task 7
//из a и b выбирает максимальныйи возвращает его
int max (int a, int b);
//находит сумму максимальных элементов псевдодиагонали
long long findSumOfMaxesOfPseudoDiagonal ( matrix m);
// task 8
//находит минимальный элемен тматрицы в выделенной области
int getMinInArea ( matrix m);
// task 9
//возвращает расстояние до начала координат
float getDistance (int *a, int n);
//сортирует строкиматрицы m понеубыванию , основываясь на критерии
criteria
void insertionSortRowsMatrixByRowCriteriaF ( matrix m, float
(* criteria )( int *, int ));
// сортируетстрокиматрицы m, относительно их удалённости от начала координат
void sortByDistances ( matrix m);
// task 10
int cmp_long_long ( const void *pa , const void *pb);
//возвращает количество уникальных элементов массива a размера n
int countNUnique ( long long *a, int n);
//возвращает количествоуникальныхсуммстрокматрицы m
int countEqClassesByRowsSum ( matrix m);
// task 11
//возвращает колво- элементовстолбцов , которые больше суммы остальных элементов
int getNSpecialElement ( matrix m);
// task 12
//возвращает позицию первого столбца с минимальным элементом
position getLeftMin ( matrix m);
//заменяет предпоследную строчку матрицы на первый столбец с минимальным элементом
void swapPenultimateRow ( matrix m);
// task 13
//возвращает true , еслимассив a размера n отсортированпонеубыванию
bool isNonDescendingSorted ( int *a, int n);
// возвращает true , есливсестрокиматрицы m отсортированы по неубыванию
bool hasAllNonDescendingRows ( matrix m);
//возвращает количествоматриц , измассиваматриц ms размера n_matrix , строки в которых упорядоченыпонеубыванию
int countNonDescendingRowsMatrices ( matrix *ms , int nMatrix );
// task 14
//возвращает колво- эл. value вмассива a размером n
int countValues ( const int *a, int n, int value );
//считает нулевыестроки
int countZeroRows ( matrix m);
//выводит матрицысмаксимальнымколом - нулевыхстрок
void printMatrixWithMaxZeroRows ( matrix *ms , int nMatrix );
// task 15
//возвращает максимальныйпомодулюэлементматрицы
int get_max_abs_value ( matrix m);
//выводит матрицуукотороймаксимальныйэл . помодулюменьшечемуостальных
void print_matrix_min_standart ( int *ms , int nMatrix );
// task 16
//возвращает меньшийиздвухэлементов
int min2 (int a, int b);
//выводит колво- особыхэл . если(слеваотчиславсечисламеньшеилисправаотчиславсечислабольше)
int getNSpecialElement2 ( matrix m);
// task 17
// возвращаетскалярноепроизведениемассива a размера n намассив b размера n
double getScalarProduct ( int *a, int *b, int n);
// возвращаетдлинувектора a размера n
double getVectorLength ( int *a, int n);
// возвращаеткосинусмеждувектором a размера n ивектором b размера n
double getCosine ( int *a, int *b, int n);
// возвращаетиндексстрокиматрицы m, которая образует максимальный угол с данным вектором b
int getVectorIndexWithMaxAngle ( matrix m, int *b);
// task 18
// возвращает скалярное произведение строк и на столбец
long long getScalarProductRowAndCol ( matrix m, int i, int j)
// возвращает скалярное произведение строки c  наибольшим элементом, на столбец с минимальным элементом
long long getSpecialScalarProduct ( matrix m);

#endif //COURSE_LAB_TASKS_H
