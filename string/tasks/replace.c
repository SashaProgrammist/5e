#include "../test/test.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        char *endBuf = copy(source,
                            getEndOfString(source),
                            getStringBuffer());
        *endBuf = '\0';
        readPtr = getStringBuffer();
        recPtr = source;
    }

    while (*readPtr != '\0') {
        char *beginSource;
        char *endSource;

        if (isspace(*readPtr)) {
            beginSource = readPtr;
            readPtr = endSource = findNonSpace(readPtr);
        } else {
            char *endWord = findSpace(readPtr);
            char currentChar = *endWord;
            *endWord = '\0';

            if (strcmp_(readPtr, word1.begin)) {
                beginSource = readPtr;
                endSource = endWord;
            } else {
                beginSource = word2.begin;
                endSource = word2.end;
            }

            readPtr = endWord;
            *endWord = currentChar;
        }

        recPtr = copy(beginSource,
                      endSource,
                      recPtr);
    }

    *recPtr = '\0';
}

void test_replace_null() {
    char s[] = "";
    replace(s, "1", "2");
    ASSERT_STRING ("", s);
}

void test_replace_onlyOneReplace() {
    char s[] = "11";
    replace(s, "11", "2");
    ASSERT_STRING ("2", s);

    replace(s, "2", "11");
    ASSERT_STRING ("11", s);
}

void test_replace_onlyManyReplace() {
    char s[] = "\n11\n  11  \t11 ";
    replace(s, "11", "2");
    ASSERT_STRING ("\n2\n  2  \t2 ", s);

    replace(s, "2", "11");
    ASSERT_STRING ("\n11\n  11  \t11 ", s);
}

void test_replace_manyReplace() {
    char s[] = "\n11\n  113  5  \t11 22";
    replace(s, "11", "2");
    ASSERT_STRING ("\n2\n  113  5  \t2 22", s);

    replace(s, "2", "11");
    ASSERT_STRING ("\n11\n  113  5  \t11 22", s);
}

void test_replace() {
    test_replace_null();
    test_replace_onlyOneReplace();
    test_replace_onlyManyReplace();
    test_replace_manyReplace();
}
