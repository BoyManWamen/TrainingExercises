#include <iostream>
#include <cassert>

/* 
A message has been encoded as a text stream that is to be read character by character. 
The stream contains a series of comma-delimited integers, each a positive number capable 
of being represented by a C++ int. However, the character represented by a particular integer 
depends on the current decoding mode. There are three modes: uppercase, lowercase, and 
punctuation. In uppercase mode, each integer represents an uppercase letter: The integer 
modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an input value of 
143 in uppercase mode would yield the letter H because 143 modulo 27 is 8 and H is the eighth 
letter in the alphabet. The lowercase mode works the same but with lowercase letters; the 
remainder of dividing the integer by 27 represents the lowercase letter (1 = a and so on). So an 
input value of 56 in lowercase mode would yield the letter b because 57 modulo 27 is 2 and b is the 
second letter in the alphabet. In punctuation mode, the integer is instead considered modulo 9, with 
the interpretation given by Table 2-3 below. So 19 would yield an exclamation point because 19 modulo 
9 is 1. At the beginning of each message, the decoding mode is uppercase letters. Each time the 
modulo operation (by 27 or 9, depending on mode) results in 0, the decoding mode switches. If the 
current mode is uppercase, the mode switches to lowercase letters. If the current mode is lowercase, 
the mode switches to punctuation, and if it is punctuation, it switches back to uppercase. 
*/

using namespace std;

int switchModes(char mode) {
    int modulo;

    if (mode == 'U') {
        modulo = 27;
    } else if (mode == 'L') {
        modulo = 27;
    } else {
        modulo = 9;
    }

    return modulo;
}

char convertIntegerToLetter(int integer) {
    char digits[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u',
                     'v', 'w', 'x', 'y', 'z'};

    char digit = digits[integer - 1];

    return digit;
}

int returnRemainder(int firstInteger, int secondInteger);

int testReturnRemainder() {
#ifdef NDEBUG
    cerr << "Tests run with NDEBUG disabled";
    abort();
#endif

    assert(returnRemainder(2, 2) == 0);
    assert(returnRemainder(10, 3) == 1);

    return 0;
}

int returnRemainder(int firstInteger, int secondInteger) {
    if (firstInteger % secondInteger == 0) {
        return 0;
    }

    return (firstInteger % secondInteger);
}

char convertIntegerToPunct(int integer) {
    char puncts[] = {'!', '?', ',', '.', ' ', ';', '\"', '\''};

    char punct = puncts[integer - 1];

    return punct;
}

int main() {
    int integer;
    int remainder;

    char mode = 'U';

    int modulo = switchModes(mode);

    while (cin >> integer) {
        remainder = returnRemainder(integer, modulo);

        char letter;

        if (mode == 'U') {
            letter = toupper(convertIntegerToLetter(remainder));
        } else if (mode == 'L') {
            letter = convertIntegerToLetter(remainder);
        } else {
            letter = convertIntegerToPunct(remainder);
        }

        cout << letter << endl;

        if (remainder == 0) {
            if (mode == 'U') {
                mode = 'L';
            } else if (mode == 'L') {
                mode = 'P';
            } else {
                mode = 'U';
            }
        }
    }

    return 0;
}
