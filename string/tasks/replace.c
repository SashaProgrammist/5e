#include "../test/test.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    Word word1 = {w1, w1 + w1Size};
    Word word2 = {w2, w2 + w2Size};

    replaceWord(source, word1, word2);
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
