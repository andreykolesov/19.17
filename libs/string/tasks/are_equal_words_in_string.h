#ifndef UNTITLED1_ARE_EQUAL_WORDS_IN_STRING_H
#define UNTITLED1_ARE_EQUAL_WORDS_IN_STRING_H

#include "string_.h"
#include <assert.h>

bool areEqualWordsInString(char *s) {
    char *begin_search = s;

    while (getWordWithoutSpace(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    if (_bag.size <= 1)
        return false;

    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (isWordEqual(_bag.words[i], _bag.words[j])) {
                freeBag(&_bag);

                return true;
            }

    freeBag(&_bag);

    return false;
}

void test_13_empty() {
    char s[] = "";
    assert(!areEqualWordsInString(s));
}


void test_13_one_word() {
    char s[] = "word";
    assert(!areEqualWordsInString(s));
}


void test_13_duplicate_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!areEqualWordsInString(s));
}


void test_13_duplicate_in_string() {
    char s[] = "string in string";
    assert(areEqualWordsInString(s));
}


void test_13_areEqualWordsInString() {
    test_13_empty();
    test_13_one_word();
    test_13_duplicate_not_in_string();
    test_13_duplicate_in_string();
}

#endif //UNTITLED1_ARE_EQUAL_WORDS_IN_STRING_H
