#include "string/test/test.h"

int main() {
    test();

    printf("%d\n", sizeof(BagOfWords));
    test_outputWordForReversOrdered();

    return *getLincExitCode();
}
