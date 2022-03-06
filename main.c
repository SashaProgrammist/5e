#include "string/test/test.h"

int main() {
    test();

    char s[] = "7 2 9 1 35 5 6 4 8";
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, s);
    sortBagOfWords(bag);
    bagToString(bag, getStringBuffer());
    printf(getStringBuffer());
    Word word = {s + 4, s + 9};
    printf("\nres - %d \n", isWordInSortBag(word, bag));

    return *getLincExitCode();
}
