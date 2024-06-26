#include "libs/string/tasks/remove_non_letters.h"
#include "libs/string/tasks/remove_adjacent_equal_letters.h"
#include "libs/string/tasks/reverse_word.h"
#include "libs/string/tasks/replace_digit_to_space.h"
#include "libs/string/tasks/replace_word_to_word.h"
#include "libs/string/tasks/lexicographical_order.h"
#include "libs/string/tasks/print_reverse_order.h"
#include "libs/string/tasks/amount_of_palindromes.h"
#include "libs/string/tasks/shuffling_words.h"
#include "libs/string/tasks/change_word_order.h"
#include "libs/string/tasks/get_word_before_first_word_with_a.h"
#include "libs/string/tasks/find_last_equal_word.h"
#include "libs/string/tasks/are_equal_words_in_string.h"
#include "libs/string/tasks/find_words_from_same_sets_letters.h"
#include "libs/string/tasks/get_word_except_last.h"
#include "libs/string/tasks/find_preceding_word.h"
#include "libs/string/tasks/remove_palindromes.h"
#include "libs/string/tasks/balance_string.h"
#include "libs/string/tasks/letters_belong_string.h"

int main() {
    test_1_removeNonLetters();
    test_2_removeAdjacentEqualLetters();
    test_3_reverseWord();
    test_4_replaceDigitToSpace();
    test_5_replace_word_to_word();
    test_6_lexicographicalOrder(); // bool, поэтому нет вывода
    test_7_printReverseOrder(); // выводит строки
    test_8_amountOfPalindromes();
    test_9_shufflingWords();
    test_10_changeWordOrder();
    test_11_all_tests_getWordBeforeFirstWordWithA();
    test_12_findLastEqualWord();
    test_13_areEqualWordsInString(); // bool, поэтому нет вывода
    test_14_areIdenticalWordsInString();
    test_15_getWordExceptLast();
    test_16_findPrecedingWord();
    test_17_removePalindromes();
    test_18_balanceString();
    test_19_lettersBelongString(); // bool, поэтому нет вывода

    return 0;
}