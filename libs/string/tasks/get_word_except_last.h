#ifndef UNTITLED1_GET_WORD_EXCEPT_LAST_H
#define UNTITLED1_GET_WORD_EXCEPT_LAST_H

#include "string_.h"

void getWordExceptLast(char *s, char *destination) {
    char *begin_search = s;

    while (getWordWithoutSpace(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    if (_bag.size == 0) {
        return;
    }

    WordDescriptor last_word = _bag.words[_bag.size - 1];

    for (int i = 0; i < _bag.size - 1; i++) {
        if (!isWordEqual(_bag.words[i], last_word)) {
            destination = copy(_bag.words[i].begin, _bag.words[i].end + 1, destination);

            if (i != _bag.size - 2) {
                *destination = ' ';
                destination++;
            }
        }
    }

    *destination = '\0';

    freeBag(&_bag);
}

void test_15_empty() {
    char s[] = "";
    char destination[40] = "";

    getWordExceptLast(s, destination);

    ASSERT_STRING("", destination);
}


void test_15_one_word() {
    char s[] = "word";
    char destination[40] = "";

    getWordExceptLast(s, destination);

    ASSERT_STRING("", destination);
}


void test_15_last_unique() {
    char s[] = "word map";
    char destination[40] = "";

    getWordExceptLast(s, destination);

    ASSERT_STRING("word", destination);
}


void test_15_last_not_unique() {
    char s[] = "word map is map";
    char destination[40] = "";

    getWordExceptLast(s, destination);

    ASSERT_STRING("word is", destination);
}


void test_15_getWordExceptLast() {
    test_15_empty();
    test_15_one_word();
    test_15_last_unique();
    test_15_last_not_unique();
}

#endif //UNTITLED1_GET_WORD_EXCEPT_LAST_H
