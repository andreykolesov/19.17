#ifndef UNTITLED1_FIND_WORDS_FROM_SAME_SETS_LETTERS_H
#define UNTITLED1_FIND_WORDS_FROM_SAME_SETS_LETTERS_H

#include "string_.h"
#include <assert.h>

int compareLetters(const void *s1, const void *s2){
    return *(char *) s1 - *(char *) s2;
}

void sortWordLetters(WordDescriptor *word){
    qsort(word->begin, word->end - word->begin, sizeof(char),
          compareLetters);
}

bool areIdenticalWordsInString(char* s){
    char *begin_buffer = s;

    copy(begin_buffer, s + strlen_(s), stringBuffer_);

    while (getWordWithoutSpace(begin_buffer, &_bag.words[_bag.size])){
        begin_buffer = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    freeString(stringBuffer_);

    if (_bag.size <= 1)
        return false;

    for (int i = 0; i < _bag.size; i++)
        sortWordLetters(&_bag.words[i]);

    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (isWordEqual(_bag.words[i], _bag.words[j])) {
                freeBag(&_bag);

                return true;
            }

    freeBag(&_bag);

    return false;
}

void test_14_empty() {
    char s[] = "";
    assert(!areIdenticalWordsInString(s));
}


void test_14_one_word() {
    char s[] = "word";
    assert(!areIdenticalWordsInString(s));
}


void test_14_anagram_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!areIdenticalWordsInString(s));
}


void test_14_anagram_in_string() {
    char s[] = "string in string";
    assert(areIdenticalWordsInString(s));
}


void test_14_areIdenticalWordsInString() {
    test_14_empty();
    test_14_one_word();
    test_14_anagram_not_in_string();
    test_14_anagram_in_string();
}

#endif //UNTITLED1_FIND_WORDS_FROM_SAME_SETS_LETTERS_H
