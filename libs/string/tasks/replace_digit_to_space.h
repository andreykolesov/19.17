#ifndef UNTITLED1_REPLACE_DIGIT_TO_SPACE_H
#define UNTITLED1_REPLACE_DIGIT_TO_SPACE_H

#include "string_.h"

void replaceDigitToSpace(char *s) {
    char *rec_ptr = s;
    char *read_ptr = stringBuffer_;

    char *end_string = getEndOfString(s);
    char *end_string_in_buffer = copy(s, end_string, stringBuffer_);
    *end_string_in_buffer = '\0';

    while (*read_ptr != '\0') {
        if (isdigit(*read_ptr)) {
            for (int i = 0; i < *read_ptr - '0'; i++) {
                *rec_ptr = ' ';
                rec_ptr++;
            }
        } else {
            *rec_ptr = *read_ptr;
            rec_ptr++;
        }

        read_ptr++;
    }

    *rec_ptr = '\0';
}

void test_4_empty() {
    char s[] = "";
    replaceDigitToSpace(s);
    ASSERT_STRING("", s);
}

void test_4_non_digit() {
    char s[] = "abcd";
    replaceDigitToSpace(s);
    ASSERT_STRING("abcd", s);
}

void test_4_non_letters() {
    char s[] = "2";
    replaceDigitToSpace(s);
    ASSERT_STRING("  ", s);
}

void test_4_letters_and_digit() {
    char s[] = "a2b0c3";
    replaceDigitToSpace(s);
    ASSERT_STRING("a  bc   ", s);
}

void test_4_replaceDigitToSpace() {
    test_4_empty();
    test_4_non_digit();
    test_4_non_letters();
    test_4_letters_and_digit();
}

#endif
