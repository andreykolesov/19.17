#ifndef UNTITLED1_CHANGE_WORD_ORDER_H
#define UNTITLED1_CHANGE_WORD_ORDER_H

#include "string_.h"

void changeWordOrder(char *s) {
    if (strlen_(s) == 0)
        return;

    char *rec_ptr = s;
    char *r_buffer_begin = copy(s, s + strlen_(s), stringBuffer_) - 1;
    char *r_buffer_end = stringBuffer_;
    WordDescriptor word;

    while (getWordReverse(r_buffer_begin, r_buffer_end, &word)) {
        rec_ptr = copy(word.begin, word.end + 1, rec_ptr);
        if (word.begin != r_buffer_end) {
            *rec_ptr = ' ';
            rec_ptr++;
        }

        r_buffer_begin = word.begin - 2;
    }

    *rec_ptr = '\0';

    freeString(stringBuffer_);
}

void test_10_empty() {
    char s[] = "";
    changeWordOrder(s);
    ASSERT_STRING("", s);
}


void test_10_one_word() {
    char s[] = "word";
    changeWordOrder(s);
    ASSERT_STRING("word", s);
}


void test_10_only_letters() {
    char s[] = "a b c d";
    changeWordOrder(s);
    ASSERT_STRING("d c b a", s);
}


void test_10_different_word() {
    char s[] = "world map vector";
    changeWordOrder(s);
    ASSERT_STRING("vector map world", s);
}


void test_10_changeWordOrder() {
    test_10_empty();
    test_10_one_word();
    test_10_only_letters();
    test_10_different_word();
}

#endif //UNTITLED1_CHANGE_WORD_ORDER_H
