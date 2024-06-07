
#include <stdio.h>
#include <assert.h>
#include "libs/exam/exam.h"


// Тестовые функции
void testProcessStructWithNull() {
    printf("Running the test: testProcessStructWithNull\n");
    processStruct(NULL);
    printf("The test was completed successfully.\n");
}

void testProcessStructWithData() {
    printf("Running the test: testProcessStructWithData\n");
    MyStruct myStruct = { .data = 5 };
    processStruct(&myStruct);
    assert(myStruct.data == 6);
    printf("The test was completed successfully\n");
}

// Новый тестовый случай, который вызывает ошибку
void testProcessStructWithError() {
    printf("Running the test: testProcessStructWithError\n");
    MyStruct* myStruct = NULL;
    processStruct(myStruct);
    assert(myStruct != NULL);
    printf("The test was completed successfully\n");
}

// Функция, объединяющая все тесты
void test() {
    testProcessStructWithNull();
    testProcessStructWithData();
    testProcessStructWithError();
}

// Главная функция
int main() {
    // Вызов функции тестирования
    test();

    return 0;
}





