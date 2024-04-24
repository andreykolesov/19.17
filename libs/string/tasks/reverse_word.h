#ifndef UNTITLED1_REVERSE_WORD_H
#define UNTITLED1_REVERSE_WORD_H

#include "string_.h"

void reverseWord(WordDescriptor word) {
    char *begin = word.begin;
    char *end = word.end - 1;

    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;

        begin++;
        end--;
    }
}

void reverseWordsInString(char *s) {
    char *begin_search = s;
    WordDescriptor word;

    while (getWord(begin_search, &word)) {
        reverseWord(word);
        begin_search = word.end;
    }
}

void test_3_empty() {
    char s[] = "";
    reverseWordsInString(s);
    ASSERT_STRING("", s);
}


void test_3_one_letters() {
    char s[] = "a";
    reverseWordsInString(s);
    ASSERT_STRING("a", s);
}


void test_3_one_word() {
    char s[] = "word";
    reverseWordsInString(s);
    ASSERT_STRING("drow", s);
}


void test_3_two_word() {
    char s[] = "string word";
    reverseWordsInString(s);
    ASSERT_STRING("gnirts drow", s);
}


void test_3_reverseWord() {
    test_3_empty();
    test_3_one_letters();
    test_3_one_word();
    test_3_two_word();
}

#endif
