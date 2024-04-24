#ifndef UNTITLED1_REMOVE_ADJACENT_EQUAL_LETTERS_H
#define UNTITLED1_REMOVE_ADJACENT_EQUAL_LETTERS_H

#include "string_.h"
#include <ctype.h>

void removeAdjacentEqualLetters(char *s) {
    char *i_write = s;
    char *i_read = s;
    char last_symbol = *s;

    while (*i_read != '\0') {
        while (*i_read == last_symbol)
            i_read++;

        *i_write = last_symbol;
        i_write++;
        last_symbol = *i_read;
    }

    *i_write = '\0';
}

void test_2_empty() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}


void test_2_one_letters() {
    char s[] = "a";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a", s);
}

void test_2_one_letters_duplicate() {
    char s[] = "aa";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a", s);
}


void test_2_two_letters_duplicate() {
    char s[] = "aaa bbb";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a b", s);
}


void test_2_removeAdjacentEqualLetters() {
    test_2_empty();
    test_2_one_letters();
    test_2_one_letters_duplicate();
    test_2_two_letters_duplicate();
}

#endif //UNTITLED1_REMOVE_ADJACENT_EQUAL_LETTERS_H
