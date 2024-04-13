#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;

    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace((unsigned char) *begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace((unsigned char) *begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *r_begin, const char *r_end) {
    while (r_begin != r_end && isspace((unsigned char) *r_begin))
        r_begin--;

    return r_begin;
}

char *findSpaceReverse(char *r_begin, const char *r_end) {
    while (r_begin != r_end && !isspace((unsigned char) *r_begin))
        r_begin--;

    return r_begin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && (*lhs == *rhs)) {
        lhs++;
        rhs++;
    }

    return *(const unsigned char *) lhs - *(const unsigned char *) rhs;
}
