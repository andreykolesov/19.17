#ifndef UNTITLED1_AMOUNT_OF_PALINDROMES_H
#define UNTITLED1_AMOUNT_OF_PALINDROMES_H

#include "string_.h"
#include <assert.h>

bool getSeparateWord(char *begin_search, WordDescriptor *word){
    word->begin = findNonSpace(begin_search);

    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    if (ispunct(*(word->end - 1)))
        word->end--;

    return true;
}

int amountOfPalindromes(char *s){
    int amount_of_palindromes = 0;
    char *begin_search = s;
    WordDescriptor word;

    while (getSeparateWord(begin_search, &word)){
        if (isPalindrome(&word))
            amount_of_palindromes++;

        if (ispunct(*(word.end)))
            word.end++;

        begin_search = word.end;
    }

    return amount_of_palindromes;
}

void test_8_non_palindrome() {
    char s[] = "palindrome, not, in, string";
    assert(amountOfPalindromes(s) == 0);
}


void test_8_only_letters() {
    char s[] = "a b c d";
    assert(amountOfPalindromes(s) == 4);
}


void test_8_only_palindrome() {
    char s[] = "radar, non, anna";
    assert(amountOfPalindromes(s) == 3);
}


void test_8_different_string() {
    char s[] = "radar, word, non, anna, vector, heh";
    assert(amountOfPalindromes(s) == 4);
}


void test_8_amountOfPalindromes() {
    test_8_non_palindrome();
    test_8_only_letters();
    test_8_only_palindrome();
    test_8_different_string();
}

#endif //UNTITLED1_AMOUNT_OF_PALINDROMES_H
