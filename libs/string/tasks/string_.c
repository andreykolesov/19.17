#include "string_.h"

char stringBuffer_[MAX_STRING_SIZE + 1];

BagOfWords _bag;
BagOfWords _bag2;

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

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *(const unsigned char *) lhs - *(const unsigned char *) rhs;
}

char *copy(const char *begin_source, const char *end_source, char *begin_destination) {
    while (begin_source != end_source) {
        *begin_destination = *begin_source;
        ++begin_source;
        ++begin_destination;
    }
    return begin_destination;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    char *start = beginSource;

    while (start != endSource) {
        if (f(*start)) {
            *beginDestination = *start;
            beginDestination++;
        }

        start++;
    }

    return beginDestination;
}

char *copyIfReverse(char *r_beginSource, const char *r_endSource, char *beginDestination, int (*f)(int)) {
    char *start = r_beginSource;

    while (start != r_endSource) {
        if (f(*start)) {
            *beginDestination = *start;
            beginDestination++;
        }

        start--;
    }

    return beginDestination;
}

char *getEndOfString(char *s) {
    char *start = s;

    while (*start != '\0')
        start++;

    return start;
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    if (word->begin == rend)
        return false;

    word->end = findNonSpaceReverse(rbegin, rend);

    word->begin = findSpaceReverse(rbegin, rend);

    word->begin = word->begin == rend ? word->begin : word->begin + 1;

    return true;
}

void freeString(char *s) {
    char *ptr = s;

    while (*ptr != '\0') {
        *ptr = '\0';
        ptr++;
    }
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (*w1.begin != '\0' && *w2.begin != '\0' && (*w1.begin == *w2.begin)) {
        w1.begin++;
        w2.begin++;
    }

    return *(const unsigned char *) w1.begin - *(const unsigned char *) w2.begin;
}

void printWord(WordDescriptor word){
    while (word.begin != word.end){
        printf("%c", *word.begin);
        word.begin++;
    }

    printf(" ");
}