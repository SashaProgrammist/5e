#include "test.h"

void test_strlen() {
    assert(strlen("") == 0);
    assert(strlen("0") == 1);
    assert(strlen("42") == 2);
}

void test_find(){
    char st[] = "aaabbb";
    assert(find(st, st + 6, 'b') == st + 3);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 4);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 5);
    *find(st, st + 6, 'b') = 'a';
    assert(find(st, st + 6, 'b') == st + 6);

    char *begin = st;
    while (*begin != '\0'){
        assert(*begin == 'a');
        begin++;
    }
}

void test_findNonSpace(){
    char st[] = " \n\t";
    assert(findNonSpace(st) == st + 3);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st + 2);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st + 1);
    findNonSpace(st)[-1] = 'a';
    assert(findNonSpace(st) == st);

    char *begin = st;
    while (*begin != '\0'){
        assert(*begin == 'a');
        begin++;
    }
}

void test_findSpace(){
    char st[] = "aa ";
    assert(findSpace(st) == st + 2);
    *findSpace(st) = '\n';
    assert(findSpace(st) == st + 2);
    *findSpace(st) = '\t';
    assert(findSpace(st) == st + 2);
    *findSpace(st) = 'a';
    assert(findSpace(st) == st + 3);

    char *begin = st;
    while (*begin != '\0'){
        assert(*begin == 'a');
        begin++;
    }
}

void test_findNonSpaceReverse(){
    char st[] = "aaa \n\t";
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 2);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaa\n\t"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 3);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaaa\t"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 4);
    findNonSpaceReverse(st + 5, st - 1)[1] = 'a'; // "aaaaaa"
    assert(findNonSpaceReverse(st + 5, st - 1) == st + 5);

    char *begin = st;
    while (*begin != '\0'){
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
    while (*begin != '\0'){
        assert(*begin == 'a');
        begin++;
    }
}

void test_allFind(){
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}

void test() {
    test_allFind();
}
