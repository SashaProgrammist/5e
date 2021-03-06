#include "../test/test.h"

void outputWordForReversOrdered(char *beginString) {
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, beginString);
    Word *firstWord = bag->words;

    for (Word *current = getEndWord(bag);
         firstWord <= current;
         current--) {
        outputWord(*current);
        printf(" ");
    }
}

void test_outputWordForReversOrdered(){
    char s[] = "\n 1 22\t333 4\n";
    outputWordForReversOrdered(s);
    printf("\n");
}
