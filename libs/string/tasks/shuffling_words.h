#ifndef UNTITLED1_SHUFFLING_WORDS_H
#define UNTITLED1_SHUFFLING_WORDS_H

#include "string_.h"

void appendWord(char *res_string, WordDescriptor *word) {
    char *ptr = res_string;

    while (*ptr != '\0')
        ptr++;

    char *begin = word->begin;
    while (*begin != *word->end) {
        *ptr = *begin;
        ptr++;
        begin++;
    }

    *ptr = ' ';
    ptr++;
    *ptr = '\0';
}

void shufflingWords(char *s1, char *s2, char *res_string) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            appendWord(res_string, &word1);
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            appendWord(res_string, &word2);
            beginSearch2 = word2.end;
        }
    }
}

void test_9_empty() {
    char res_string[50] = "";

    char s1[] = "";
    char s2[] = "";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("", res_string);
}


void test_9_one_string_empty_1() {
    char res_string[50] = "";

    char s1[] = "";
    char s2[] = "word";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("word ", res_string);
}


void test_9_one_string_empty_2() {
    char res_string[50] = "";

    char s1[] = "word";
    char s2[] = "";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("word ", res_string);
}


void test_9_different_string() {
    char res_string[50] = "";

    char s1[] = "word";
    char s2[] = "vector";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("word vector ", res_string);
}


void test_9_different_amount_word_1() {
    char res_string[50] = "";

    char s1[] = "word";
    char s2[] = "vector love";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("word vector love ", res_string);
}


void test_9_different_amount_word_2() {
    char res_string[50] = "";

    char s1[] = "word vector";
    char s2[] = "love";

    shufflingWords(s1, s2, res_string);

    ASSERT_STRING("word love vector ", res_string);
}


void test_9_shufflingWords() {
    test_9_empty();
    test_9_one_string_empty_1();
    test_9_one_string_empty_2();
    test_9_different_string();
    test_9_different_amount_word_1();
    test_9_different_amount_word_2();
}

#endif //UNTITLED1_SHUFFLING_WORDS_H