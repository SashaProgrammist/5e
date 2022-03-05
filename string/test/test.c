#include "test.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got) == 0)
        fprintf(stderr, "%s - OK\n", funcName);
    else {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
        (*getLincExitCode())++;
    }
}

void test_strlen() {
    assert(strlen("") == 0);
    assert(strlen("0") == 1);
    assert(strlen("42") == 2);
}

void test_find() {
    char st[] = "aaabbb";
    assert(find(st, st + 6, 'b') == st + 3);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 4);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 5);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 6);

    char *begin = st;
    while (*begin != '\0') {
        assert(*begin == 'a');
        begin++;
    }
}

void test_findNonSpace() {
    char st[] = " \n\t";
    assert(findNonSpace(st) == st + 3);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st + 2);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st + 1);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st);

    char *begin = st;
    while (*begin != '\0') {
        assert(*begin == 'a');
        begin++;
    }
}

void test_findSpace() {
    char st[] = "aa ";
    assert(findSpace(st) == st + 2);
    *findSpace(st) = '\n';
    assert(findSpace(st) == st + 2);
    *findSpace(st) = '\t';
    assert(findSpace(st) == st + 2);
    *findSpace(st) = 'a';
    assert(findSpace(st) == st + 3);

    char *begin = st;
    while (*begin != '\0') {
        assert(*begin == 'a');
        begin++;
    }
}

void test_findNonSpaceReverse() {
    char st[] = "aaa \n\t";
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 2);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaa\n\t"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 3);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaaa\t"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 4);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaaaa"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 5);

    char *begin = st;
    while (*begin != '\0') {
        assert(*begin == 'a');
        begin++;
    }
}

void test_findSpaceReverse() {
    char st[] = "a \n\taaa";
    assert(findSpaceReverse(st + 5, st - 1) == st + 3);
    *findSpaceReverse(st + 5, st - 1) = 'a'; // "a \naaaa"
    assert(findSpaceReverse(st + 5, st - 1) == st + 2);
    *findSpaceReverse(st + 5, st - 1) = 'a'; // "a aaaaa"
    assert(findSpaceReverse(st + 5, st - 1) == st + 1);
    *findSpaceReverse(st + 5, st - 1) = 'a'; // "aaaaaaa"
    assert(findSpaceReverse(st + 5, st - 1) == st - 1);

    char *begin = st;
    while (*begin != '\0') {
        assert(*begin == 'a');
        begin++;
    }
}

void test_allFind() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}

void test_strcmp() {
    char st1[] = "11";  //    1   2    3    4
    char st2[] = "21";  // 1  0  -1  -'1' -'3'
    char st3[] = "111"; // 2  1   0    1    1
    char st4[] = "113"; // 3 '1' -1    0   -2
    //                     4 '3' -1    2    0

    assert(strcmp_(st1, st1) == 0);
    assert(strcmp_(st1, st2) == -1);
    assert(strcmp_(st1, st3) == -'1');
    assert(strcmp_(st1, st4) == -'3');

    assert(strcmp_(st2, st1) == 1);
    assert(strcmp_(st2, st2) == 0);
    assert(strcmp_(st2, st3) == 1);
    assert(strcmp_(st2, st4) == 1);

    assert(strcmp_(st3, st1) == '1');
    assert(strcmp_(st3, st2) == -1);
    assert(strcmp_(st3, st3) == 0);
    assert(strcmp_(st3, st4) == -2);

    assert(strcmp_(st4, st1) == '3');
    assert(strcmp_(st4, st2) == -1);
    assert(strcmp_(st4, st3) == 2);
    assert(strcmp_(st4, st4) == 0);
}

void test_copy() {
    char stSource[] = "1234567890";
    char stDestination[11];

    char *result = copy(stSource,
                        stSource + 11,
                        stDestination);
    assert(result == stDestination + 11);

    for (int i = 0; i < 11; ++i)
        assert(stSource[i] == stDestination[i]);
}

void test_copyReverse() {
    char s[] = "123456789";
    char *end = copyReverse(getEndOfString(s) - 1,
                            s - 1,
                            getStringBuffer());
    *end = '\0';
    ASSERT_STRING ("987654321", getStringBuffer());
}

int isNotEven(int ch) {
    return ch % 2;
}

void test_copyTf() {
    char stSource[] = "abcdefg12";
    char stResult[] = "aceg1";
    char stDestination[8];

    char *result = copyIf(stSource,
                          stSource + 9,
                          stDestination,
                          isNotEven);
    *result = '\0';

    ASSERT_STRING(stResult, stDestination);
}

int deleteMultiSpace(char *ch) {
    if (!isspace(*ch)) return 1;
    return !isspace(ch[1]);
}

void test_copyIfExtended() {
    char stSource[] = "1    2     3   42  6";
    char stResult[] = "1 2 3 42 6";
    char stDestination[11];

    char *result = copyIfExtended(stSource,
                                  stSource + 21,
                                  stDestination,
                                  deleteMultiSpace);
    assert(result == stDestination + 11);

    for (int i = 0; i < 11; ++i)
        assert(stResult[i] == stDestination[i]);
}

void test_copyIfReverse() {
    char s[] = " Hi123 111 3 51     0      ";
    char *end = copyIfReverse(getEndOfString(s) - 1,
                              s - 1,
                              getStringBuffer(),
                              isdigit);
    *end = '\0';
    ASSERT_STRING ("0153111321", getStringBuffer());
}

void test_copyIfReverseExtended() {
    char stSource[] = "1    2     3   24  6";
    char stResult[] = "6 42 3 2 1";
    char stDestination[21];

    char *result = copyIfReverseExtended(stSource + 19,
                                         stSource - 1,
                                         stDestination,
                                         deleteMultiSpace);
    assert(result == stDestination + 10);

    for (int i = 0; i < 10; ++i)
        assert(stResult[i] == stDestination[i]);
}

void test_allCopy() {
    test_copy();
    test_copyReverse();
    test_copyTf();
    test_copyIfExtended();
    test_copyIfReverse();
    test_copyIfReverseExtended();
}

void test_reverseOrder() {
    char s[] = "GU56743JwfjM  \n";
    reverseOrder(s, getEndOfString(s));
    ASSERT_STRING ("\n  MjfwJ34765UG", s);
}

void test_transform() {
    test_reverseOrder();
}

void test_tasks() {
    test_removeNonLetters();
    test_AdjacentEqualLetters();
    test_forWordInString();
    test_digitForSpaces();
    test_replace();
    test_isOrderedString();
    test_getCountPalindromes();
}

void test_areWordsEqual() { // TODO
    char sours[] = "123456789";

    assert(0 == areWordsEqual(
            (WordDescriptor) {sours, sours + 9},
            (WordDescriptor) {sours, sours + 9}
    ));

    assert(1 == areWordsEqual(
            (WordDescriptor) {sours + 1, sours + 9},
            (WordDescriptor) {sours, sours + 9}
    ));

    assert(-1 == areWordsEqual(
            (WordDescriptor) {sours, sours + 9},
            (WordDescriptor) {sours + 1, sours + 9}
    ));

    assert(-'6' == areWordsEqual(
            (WordDescriptor) {sours, sours + 5},
            (WordDescriptor) {sours, sours + 9}
    ));

    assert('6' == areWordsEqual(
            (WordDescriptor) {sours, sours + 6},
            (WordDescriptor) {sours, sours + 5}
    ));
}

void test_getBagOfWords() {
    //              0123456789
    char sours[] = " a  r aa a"  // 00
                   "agg     12"; // 10

    getBagOfWords(getBagOfWordsBuffer(), sours);

    assert(getBagOfWordsBuffer()->size == 5);

    WordDescriptor *word = getBagOfWordsBuffer()->words;
    assert(word->begin == sours + 1 &&
           word->end == sours + 2);
    word++;
    assert(word->begin == sours + 4 &&
           word->end == sours + 5);
    word++;
    assert(word->begin == sours + 6 &&
           word->end == sours + 8);
    word++;
    assert(word->begin == sours + 9 &&
           word->end == sours + 13);
    word++;
    assert(word->begin == sours + 18 &&
           word->end == sours + 20);
}

void test_getEndWord() {
    BagOfWords *bag = getBagOfWordsBuffer();
    for (int i = 0; i < MAX_N_WORDS_IN_STRING / 10; ++i) {
        bag->size = i;
        assert(getEndWord(bag) == bag->words + i - 1);
    }

    //              0123456789
    char sours[] = " a  r aa a"  // 00
                   "agg     12"; // 10
    getBagOfWords(bag, sours);

    ASSERT_STRING(sours + 18,
                  getEndWord(bag)->begin);
}

void test_word_WordDescriptor() {
    test_areWordsEqual();
    test_getBagOfWords();
    test_getEndWord();
}

void test() {
    test_allFind();
    test_strcmp();
    test_allCopy();
    test_transform();
    test_tasks();
    test_word_WordDescriptor();
}

int *getLincExitCode() {
    static int exitCode = 0;
    return &exitCode;
}
