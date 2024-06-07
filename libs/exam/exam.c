//
// Created by Влад on 07.06.2024.
//

#include "exam.h"
#include <stdio.h>
#include <assert.h>

// Функция обработки структуры данных
void processStruct(MyStruct* myStruct) {
    if (myStruct == NULL) {
        fprintf(stderr, "Ошибка: передан нулевой указатель.\n");
        return;
    }

    // Обработка данных структуры
    myStruct->data += 1;
}