#include <stdio.h>
#include "string.h"
#include <assert.h>

void test_find_1_char_in_string() {
    char *str = "Hello, World!";
    char *res = find(str, str + strlen_(str), 'r');
    assert(res == &str[9]);
}
void test_find_2_char_not_in_string() {
    char *str = "Hello, World!";
    char *res = find(str, str + strlen_(str), 'm');
    assert(res == &str[strlen_(str)]);
}
void test_find_3_void_string() {
    char *str = "";
    char *res = find(str, str + strlen_(str), 'm');
    assert(res == &str[strlen_(str)]);
}
void test_find() {
    test_find_1_char_in_string();
    test_find_2_char_not_in_string();
    test_find_3_void_string();
}
void test_findNonSpace_1_spaces_in_string() {
    char *str = " Hello, World!";
    char *res = findNonSpace(str);
    assert(res == &str[8]);
}
void test_findNonSpace_2_no_spaces_in_string() {
    char *str = "Hello, World!";
    char *res = findNonSpace(str);
    assert(res == &str[0]);
}
void test_findNonSpace_3_string_with_spaces() {
    char *str = " ";
    char *res = findNonSpace(str);
    assert(*res == '\0');
}
void test_findNonSpace() {
    test_findNonSpace_1_spaces_in_string();
    test_findNonSpace_2_no_spaces_in_string();
    test_findNonSpace_3_string_with_spaces();
}
void test_findSpace_1_spaces_in_string() {
    char *str = "Hello, World!";
    char *res = findSpace(str);
    assert(res == &str[6]);
}
void test_findSpace_2_no_spaces_in_string() {
    char *str = "Hello,World!";
    char *res = findSpace(str);
    assert(*res == '\0');
}
void test_findSpace_3_string_with_spaces() {
    char *str = " ";
    char *res = findSpace(str);
    assert(res == &str[0]);
}
void test_findSpace() {
    test_findSpace_1_spaces_in_string();
    test_findSpace_2_no_spaces_in_string();
    test_findSpace_3_string_with_spaces();
}
void test_findNonSpaceReverse_1_spaces_in_string() {
    char *str = "Hello, World! ";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);
    assert(*res == '!');
}
void test_findNonSpaceReverse_2_no_spaces_in_string() {
    char *str = "Hello,World!";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);
    assert(res == &str[11]);
}
void test_findNonSpaceReverse_3_string_with_spaces() {
    char *str = " ";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);
    assert(res == str);
}
void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_1_spaces_in_string();
    test_findNonSpaceReverse_2_no_spaces_in_string();
    test_findNonSpaceReverse_3_string_with_spaces();
}
void test_findSpaceReverse_1_spaces_in_string() {
    char *str = "Hello, World!";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);
    assert(res == &str[8]);
}
void test_findSpaceReverse_2_no_spaces_in_string() {
    char *str = "Hello,World!";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);
    assert(res == str);
}
void test_findSpaceReverse_3_string_with_spaces() {
    char *str = " ";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);
    assert(res == &str[1]);
}
void test_findSpaceReverse() {
    test_findSpaceReverse_1_spaces_in_string();
    test_findSpaceReverse_2_no_spaces_in_string();
    test_findSpaceReverse_3_string_with_spaces();
}
void test_strcmp_1_equal_strings() {
    char *str1 = "Hello, World!";
    char *str2 = "Hello, World!";
    int res = strcmp(str1, str2);
    assert(res == 0);
}
void test_strcmp_2_first_string_larger() {
    char *str1 = "Trap a holics mixtapes";
    char *str2 = "Hello, World!";
    int res = strcmp(str1, str2);
    assert(res > 0);
}
void test_strcmp_3_second_string_larger() {
    char *str1 = "ABCD";
    char *str2 = "Hello, World!";
    int res = strcmp(str1, str2);
    assert(res < 0);
}
void test_strcmp() {
    test_strcmp_1_equal_strings();
    test_strcmp_2_first_string_larger();
    test_strcmp_3_second_string_larger();
}
void test_copy_1_copy_non_empty_string() {
    char *str = "Hello, World!";
    char destination[15];
    char *res = copy(str, str + strlen_(str), destination);
    for (int i = 0; i < strlen_(str); i++)
        assert (destination[i] == str[i]);
    assert(res == destination + strlen_(str));
}
void test_copy_2_copy_empty_string() {
    char *str = "";
    char destination[50] = "Hello, World!";
    char *result = copy(str, str, destination);
    for (int i = 0; i < strlen_(str); i++)
        assert (destination[i] == str[i]);
    assert(result == destination);
}
void test_copy_3_copy_substring() {
    const char *str = "Hello, World!";
    char destination[50];
    char *result = copy(str, str + 5, destination);
    for (int i = 0; i < 5; i++)
        assert (destination[i] == str[i]);
    assert(result == destination + 5);
}
void test_copy() {
    test_copy_1_copy_non_empty_string();
    test_copy_2_copy_empty_string();
    test_copy_3_copy_substring();
}
void test_copyIf_1_digit_copying() {
    char *str = "Hello123World456";
    char destination[50];
    char *result = copyIf(str, str + strlen_(str), destination);
    assert(strcmp(destination, "123456") == 0);
    assert(result == destination + 6);
}
void test_copyIf_2_letter_copying() {
    char *str = "Hello123World456";
    char destination[50];
    char *result = copyIf(str, str + strlen_(str), destination);
    assert(strcmp(destination, "HelloWorld") == 0);
    assert(result == destination + 10);
}
void test_copyIf() {
    test_copyIf_1_digit_copying();
    test_copyIf_2_letter_copying();
}
void test_copyIfReverse_1_digit_copying() {
    char *str = "341224abcde";
    char destination[50] = {0};
    char *result = copyIfReverse(str + strlen_(str) - 1, str - 1,destination);
    assert(strcmp(destination, "edcba") == 0);
    assert(result == destination + 5);
}
void test_copyIfReverse_2_letter_copying() {
    char *str = "341224abcde";
    char destination[50] = {0};
    char *result = copyIfReverse(str + strlen_(str) - 1, str - 1,
                                 destination);
    assert(strcmp(destination, "422143") == 0);
    assert(result == destination + 6);
}
void test_copyIfReverse() {
    test_copyIfReverse_1_digit_copying();
    test_copyIfReverse_2_letter_copying();
}
void test() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}
int main() {
    test();
    return 0;
}