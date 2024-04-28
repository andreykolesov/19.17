#ifndef UNTITLED1_LETTERS_BELONG_STRING_H
#define UNTITLED1_LETTERS_BELONG_STRING_H

#include "string_.h"
#include <assert.h>

bool lettersBelongString(char *s, WordDescriptor word) {
    bool include[26] = {0};

    char *begin = s;
    char *end = getEndOfString(s);

    while (begin != end) {
        if (isalpha(*begin))
            include[*begin - 'a'] = true;

        begin++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - 'a'])
            return false;

        word.begin++;
    }

    return true;
}

void test_19_empty() {
    char string[] = "";
    WordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(string, word));
}


void test_19_empty_word() {
    char string[] = "word";
    WordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(string, word));
}


void test_19_empty_string() {
    char string[] = "";
    WordDescriptor word;
    getWord("word", &word);

    assert(!lettersBelongString(string, word));
}


void test_19_letters_not_in_string() {
    char string[] = "abc";
    WordDescriptor word;
    getWord("word", &word);

    assert(!lettersBelongString(string, word));
}


void test_19_letters_in_string() {
    char string[] = "world";
    WordDescriptor word;
    getWord("word", &word);

    assert(lettersBelongString(string, word));
}


void test_19_lettersBelongString() {
    test_19_empty();
    test_19_empty_word();
    test_19_empty_string();
    test_19_letters_not_in_string();
    test_19_letters_in_string();
}

#endif //UNTITLED1_LETTERS_BELONG_STRING_H
