#include "constants.h"
#include "stfu.h"

int* generateSerialNumber(byte serialFlags)
{
    bool serialOdd = (serialFlags & SERIAL_LAST_DIGIT_ODD) > 0;
    bool serialVowel = (serialFlags & SERIAL_CONTAINS_VOWEL) > 0;
    static int generatedSerialNumber[8] = { SERIAL_NUMBER_CONSONANTS[random(SERIAL_NUMBER_CONSONANTS_COUNT)],
        SERIAL_NUMBER_CONSONANTS[random(SERIAL_NUMBER_CONSONANTS_COUNT)],
        SERIAL_NUMBER_NUMBERS[random(SERIAL_NUMBER_NUMBERS_COUNT)],
        SERIAL_NUMBER_NUMBERS[random(SERIAL_NUMBER_NUMBERS_COUNT)],
        SERIAL_NUMBER_CONSONANTS[random(SERIAL_NUMBER_CONSONANTS_COUNT)],
        SERIAL_NUMBER_CONSONANTS[random(SERIAL_NUMBER_CONSONANTS_COUNT)],
        SERIAL_NUMBER_CONSONANTS[random(SERIAL_NUMBER_CONSONANTS_COUNT)],
        serialOdd ? SERIAL_NUMBER_NUMBERS_ODD[random(SERIAL_NUMBER_NUMBERS_ODD_COUNT)]
                  : SERIAL_NUMBER_NUMBERS_EVEN[random(SERIAL_NUMBER_NUMBERS_EVEN_COUNT)] };

    if (serialVowel) {
        int vowelPosition = random(5);
        if (vowelPosition > 1) {
            vowelPosition += 2;
        }
        generatedSerialNumber[vowelPosition] = SERIAL_NUMBER_VOWELS[random(SERIAL_NUMBER_VOWELS_COUNT)];
    }
    return generatedSerialNumber;
}

byte generateSerialConfig()
{
    bool serialOdd = random(2) == 1;
    bool serialVowel = random(2) == 1;
    byte serialConfig = 0;
    if (serialOdd) {
        serialConfig |= SERIAL_LAST_DIGIT_ODD;
    }
    if (serialVowel) {
        serialConfig |= SERIAL_CONTAINS_VOWEL;
    }
    return serialConfig;
}