#ifndef UNTITLED1_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H
#define UNTITLED1_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H

#include "string_.h"
#include <assert.h>

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

bool isLetterInWord(WordDescriptor word, char letter) {
    char *begin = word.begin;

    if (begin != word.end) {
        if (*begin == letter)
            return true;

        begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    char *begin_search = s;
    WordDescriptor word1;

    if (!getWord(begin_search, &word1))
        return EMPTY_STRING;

    begin_search = word1.end + 1;

    if (isLetterInWord(word1, 'a') || isLetterInWord(*w, 'A'))
        return FIRST_WORD_WITH_A;

    WordDescriptor word2;

    while (getWord(begin_search, &word2)) {
        if (isLetterInWord(word2, 'a') || isLetterInWord(word2, 'A')){
            *w = word1;
            return WORD_FOUND;
        }

        word1 = word2;
        begin_search = word2.end + 1;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_11_all_tests_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);

    char s2[] = "abc";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "bc a";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("bc", got);

    char s4[] = "b q we nw";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

#endif //UNTITLED1_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H
