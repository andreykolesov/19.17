#include "libs/string/tasks/remove_non_letters.h"
#include "libs/string/tasks/remove_adjacent_equal_letters.h"
#include "libs/string/tasks/reverse_word.h"
#include "libs/string/tasks/replace_digit_to_space.h"
#include "libs/string/tasks/replace_word_to_word.h"
#include "libs/string/tasks/lexicographical_order.h"

int main() {
    test_1_removeNonLetters();
    test_2_removeAdjacentEqualLetters();
    test_3_reverseWord();
    test_4_replaceDigitToSpace();
    test_5_replace_word_to_word();
    test_6_lexicographicalOrder(); // bool функция, поэтому нет вывода

    return 0;
}