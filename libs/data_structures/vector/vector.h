//
// Created by Влад on 21.03.2024.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);
// изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);
// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);
// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);
// освобождает память, выделенную вектору
void deleteVector(vector *v);
// проверяет, является ли вектор пустым
bool isEmpty(vector *v);
// проверяет, является ли вектор полным
bool isFull(vector *v);
// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);
// добавляет элемент x в конец вектора
void pushBack(vector *v, int x);
// удаляет последний элемент из вектора
void popBack(vector *v);
// возвращает указатель на index-ый элемент вектора
int *atVector(vector *v, size_t index);
// возвращает указатель на последний элемент вектора
int *back(vector *v);
// возвращает указатель на нулевой элемент вектора
int *front(vector *v);

#endif //COURSE_VECTOR_H
