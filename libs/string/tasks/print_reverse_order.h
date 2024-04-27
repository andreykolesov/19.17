#ifndef UNTITLED1_PRINT_REVERSE_ORDER_H
#define UNTITLED1_PRINT_REVERSE_ORDER_H

#include "string_.h"

void getBagOfWords(BagOfWords *bag, char *s){
    char *begin_search = s;
    bag->size = 0;

    while (getWord(begin_search, &bag->words[bag->size])){
        begin_search = bag->words[bag->size].end;
        bag->size++;
    }
}

void printReverseOrder(char *s){
    getBagOfWords(&_bag, s);

    if (_bag.size != 0)
        for (int i = (int) _bag.size - 1; i >= 0; i--)
            printWord(_bag.words[i]);

    printf("\n");
}

void test_7_empty() {
    char s[] = "";
    printReverseOrder(s);
}


void test_7_one_word() {
    char s[] = "word";
    printReverseOrder(s);
}


void test_7_only_letters() {
    char s[] = "w o r d";
    printReverseOrder(s);
}


void test_7_more_word() {
    char s[] = "city car driving";
    printReverseOrder(s);
}


void test_7_printReverseOrdered() {
    printf("Test 7: \n");
    test_7_empty();
    test_7_one_word();
    test_7_only_letters();
    test_7_more_word();
    printf("\n");
}

#endif //UNTITLED1_PRINT_REVERSE_ORDER_H
