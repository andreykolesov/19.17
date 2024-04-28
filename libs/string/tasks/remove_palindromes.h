#ifndef UNTITLED1_REMOVE_PALINDROMES_H
#define UNTITLED1_REMOVE_PALINDROMES_H

#include "string_.h"

void removePalindromes(char *s) {
    char *read_begin = stringBuffer_;
    char *read_end = copy(s, s + strlen_(s), stringBuffer_);
    char *rec_ptr = s;

    WordDescriptor word;

    while (getWord(read_begin, &word)) {
        if (!isPalindrome(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);

            if (word.end != read_end) {
                *rec_ptr = ' ';
                rec_ptr++;
            }
        }

        read_begin = word.end + 1;
    }

    *rec_ptr = '\0';

    freeString(stringBuffer_);
}

void test_17_empty() {
    char s[] = "";
    removePalindromes(s);
    ASSERT_STRING("", s);
}


void test_17_non_palindrome() {
    char s[] = "none palindrome words";
    removePalindromes(s);
    ASSERT_STRING("none palindrome words", s);
}


void test_17_only_letters() {
    char s[] = "a b c d";
    removePalindromes(s);
    ASSERT_STRING("", s);
}


void test_17_different_string() {
    char s[] = "radar is word a b is letters";
    removePalindromes(s);
    ASSERT_STRING("is word is letters", s);
}


void test_17_removePalindromes() {
    test_17_empty();
    test_17_non_palindrome();
    test_17_only_letters();
    test_17_different_string();
}

#endif //UNTITLED1_REMOVE_PALINDROMES_H
