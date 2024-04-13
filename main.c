#include <stdio.h>
#include "libs/string/tasks/string_.h"
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
    char *str = "        Hello, World!";
    char *res = findNonSpace(str);

    assert(res == &str[8]);
}

void test_findNonSpace_2_no_spaces_in_string() {
    char *str = "Hello, World!";
    char *res = findNonSpace(str);

    assert(res == &str[0]);
}

void test_findNonSpace_3_string_with_spaces() {
    char *str = "    ";
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
    char *str = "   ";
    char *res = findSpace(str);

    assert(res == &str[0]);
}

void test_findSpace() {
    test_findSpace_1_spaces_in_string();
    test_findSpace_2_no_spaces_in_string();
    test_findSpace_3_string_with_spaces();
}

void test_findNonSpaceReverse_1_spaces_in_string() {
    char *str = "Hello, World!    ";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == &str[12]);
}

void test_findNonSpaceReverse_2_no_spaces_in_string() {
    char *str = "Hello,World!";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == &str[11]);
}

void test_findNonSpaceReverse_3_string_with_spaces() {
    char *str = "  ";
    char *res = findNonSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == str);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_1_spaces_in_string();
    test_findNonSpaceReverse_2_no_spaces_in_string();
    test_findNonSpaceReverse_3_string_with_spaces();
}

void test_findSpaceReverse_1_spaces_in_string() {
    char *str = "Hello,   World!";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == &str[8]);
}

void test_findSpaceReverse_2_no_spaces_in_string() {
    char *str = "Hello,World!";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == str);
}

void test_findSpaceReverse_3_string_with_spaces() {
    char *str = "  ";
    char *res = findSpaceReverse(str + strlen_(str) - 1, str);

    assert(res == &str[1]);
}

void test_findSpaceReverse(){
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

void test_strcmp(){
    test_strcmp_1_equal_strings();
    test_strcmp_2_first_string_larger();
    test_strcmp_3_second_string_larger();
}

int main() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();

    return 0;
}