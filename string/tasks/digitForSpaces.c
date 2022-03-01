#include "../test/test.h"

void digitForSpaces(char *beginString) {
    char *currentChar = beginString;
    char *currentRecordableInBuffer = getStringBuffer();

    while (*currentChar != '\0') {
        if (isdigit(*currentChar))
            while (--(*currentChar) >= '0')
                *(currentRecordableInBuffer++) = ' ';
        else
            *(currentRecordableInBuffer++) = *currentChar;

        currentChar++;
    }

    *(currentRecordableInBuffer++) = '\0';

    copy(getStringBuffer(),
         currentRecordableInBuffer,
         beginString);
}

void test_digitForSpaces_null() {
    char s[] = "";
    digitForSpaces(s);
    ASSERT_STRING ("", s);
}

void test_digitForSpaces_oneDigit() {
    char s[] = "5";
    digitForSpaces(s);
    ASSERT_STRING ("     ", s);
}

void test_digitForSpaces_manyDigit() {
    char s[] = "402";
    digitForSpaces(s);
    ASSERT_STRING ("      ", s);
}

void test_digitForSpaces_presentNotDigit() {
    char s[] = "a3c0b1";
    digitForSpaces(s);
    ASSERT_STRING ("a   cb ", s);
}

void test_digitForSpaces() {
    test_digitForSpaces_null();
    test_digitForSpaces_oneDigit();
    test_digitForSpaces_manyDigit();
    test_digitForSpaces_presentNotDigit();
}
