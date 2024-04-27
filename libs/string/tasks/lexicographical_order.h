#ifndef UNTITLED1_LEXICOGRAPHICAL_ORDER_H
#define UNTITLED1_LEXICOGRAPHICAL_ORDER_H

#include "string_.h"
#include <assert.h>

bool isLexicographicalOrder(char *s) {
    char *begin_search = s;
    WordDescriptor w1, w2;

    if (!getWord(begin_search, &w1))
        return true;

    begin_search = w1.end;

    while (getWord(begin_search, &w2)) {
        if (areWordsEqual(w1, w2) <= 0)
            w1 = w2;
        else
            return false;

        begin_search = w2.end;
    }

    return true;
}

void test_6_empty() {
    char s[] = "";
    assert(isLexicographicalOrder(s));
}


void test_6_one_letters() {
    char s[] = "a";
    assert(isLexicographicalOrder(s));
}


void test_6_only_letters_ordered() {
    char s[] = "a b c d";
    assert(isLexicographicalOrder(s));
}


void test_6_only_letters_unordered() {
    char s[] = "c a r";
    assert(!isLexicographicalOrder(s));
}


void test_6_one_word_ordered() {
    char s[] = "car";
    assert(isLexicographicalOrder(s));
}


void test_6_word_ordered() {
    char s[] = "abc abc begin end";
    assert(isLexicographicalOrder(s));
}


void test_6_word_unordered() {
    char s[] = "zero answer";
    assert(!isLexicographicalOrder(s));
}


void test_6_lexicographicalOrder() {
    test_6_empty();
    test_6_one_letters();
    test_6_only_letters_ordered();
    test_6_only_letters_unordered();
    test_6_one_word_ordered();
    test_6_word_ordered();
    test_6_word_unordered();
}

#endif //UNTITLED1_LEXICOGRAPHICAL_ORDER_H
