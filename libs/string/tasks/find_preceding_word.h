#ifndef UNTITLED1_FIND_PRECEDING_WORD_H
#define UNTITLED1_FIND_PRECEDING_WORD_H

#include "string_.h"

WordDescriptor findPrecedingWord(char *s1, char *s2){
    char *begin_search1 = s1;
    char *begin_search2 = s2;

    while (getWordWithoutSpace(begin_search1, &_bag.words[_bag.size])){
        begin_search1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (getWordWithoutSpace(begin_search2, &_bag2.words[_bag2.size])){
        begin_search2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    WordDescriptor preceding_word = {.begin = NULL, .end = NULL};
    bool stop = false;

    for (int i = 0; i < _bag.size; i++) {
        for (int j = 0; j < _bag2.size; j++)
            if (isWordEqual(_bag.words[i], _bag2.words[j])) {
                stop = true;
                break;
            }

        if (stop){
            preceding_word = _bag.words[i - 1];
            break;
        }
    }

    freeBag(&_bag);
    freeBag(&_bag2);

    return preceding_word;
}

void test_16_empty() {
    char s1[] = "";
    char s2[] = "";

    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_first_empty() {
    char s1[] = "";
    char s2[] = "word";

    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_second_empty() {
    char s1[] = "i love";
    char s2[] = "";

    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_not_in_string() {
    char s1[] = "i love music";
    char s2[] = "city car driving";

    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_first_in_string() {
    char s1[] = "i love music";
    char s2[] = "is love cars";

    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("i", dest);
}


void test_16_findPrecedingWord() {
    test_16_empty();
    test_16_first_empty();
    test_16_second_empty();
    test_16_not_in_string();
    test_16_first_in_string();
}

#endif //UNTITLED1_FIND_PRECEDING_WORD_H
