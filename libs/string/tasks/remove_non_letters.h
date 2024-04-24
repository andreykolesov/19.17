#ifndef UNTITLED1_REMOVE_NON_LETTERS_H
#define UNTITLED1_REMOVE_NON_LETTERS_H

#include <ctype.h>
#include "string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_1_empty() {
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}


void test_1_non_space() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_space() {
    char s[] = "Hi 123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_space_in_border() {
    char s[] = "   Hi 123   ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_removeNonLetters() {
    test_1_empty();
    test_1_non_space();
    test_1_space();
    test_1_space_in_border();
}

#endif //UNTITLED1_REMOVE_NON_LETTERS_H
