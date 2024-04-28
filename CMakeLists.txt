cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c
        libs/string/tasks/string_.h
        libs/string/tasks/string_.c
        libs/string/tasks/remove_non_letters.h
        libs/string/tasks/remove_adjacent_equal_letters.h
        libs/string/tasks/reverse_word.h
        libs/string/tasks/replace_digit_to_space.h
        libs/string/tasks/replace_word_to_word.h
        libs/string/tasks/lexicographical_order.h
        libs/string/tasks/print_reverse_order.h
        libs/string/tasks/amount_of_palindromes.h
        libs/string/tasks/shuffling_words.h
        libs/string/tasks/change_word_order.h
        libs/string/tasks/get_word_before_first_word_with_a.h
        libs/string/tasks/find_last_equal_word.h
        libs/string/tasks/are_equal_words_in_string.h
        libs/string/tasks/find_words_from_same_sets_letters.h
)
