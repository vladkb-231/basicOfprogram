
#include <stdio.h>
#include <assert.h>
#include "libs/exam/exam.h"

// Тестовая функция для проверки нулевого указателя
void testProcessStructNull() {
    MyStruct* myStruct = NULL;
    processStruct(myStruct);
    // Здесь мы ожидаем, что функция не вызовет ошибку сегментации
}

// Тестовая функция для проверки обработки данных структуры
void testProcessStructData() {
    MyStruct myStruct;
    myStruct.data = 5;
    processStruct(&myStruct);
    assert(myStruct.data == 6); // Проверяем, что данные увеличились на 1
}

// Объединяющая функция для всех тестов
void Tests() {
    testProcessStructNull();
    testProcessStructData();
    printf("all tests passed\n");
}

int main() {
    Tests();

    return 0;
}





