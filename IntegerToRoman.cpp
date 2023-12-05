class Solution {
public:
    int returnLastDigit(int num) {
        return num % 10;
    }

    string returnSingleNumeral(int digit, int base) {
        string fullRomanNumeral = "";
        string romanNumeral = "";
        string romanNumeralForFive;
        string romanNumeralForNine;

        if (base == 1) {
            romanNumeral = "I";
            if (digit >= 4 && digit < 9) {
                romanNumeralForFive = "V";
            } else if (digit == 9) {
                romanNumeralForNine = "X";
            }
        } else if (base == 10) {
            romanNumeral = "X";
            if (digit >= 4 && digit < 9) {
                romanNumeralForFive = "L";
            } else if (digit == 9) {
                romanNumeralForNine = "C";
            }
        } else if (base == 100) {
            romanNumeral = "C";
            if (digit >= 4 && digit < 9) {
                romanNumeralForFive = "D";
            } else if (digit == 9) {
                romanNumeralForNine = "M";
            }
        } else if (base == 1000) {
            romanNumeral = "M";
        }

        if (digit < 4) {
            for (int i = 0; i < digit; i++) {
                fullRomanNumeral += romanNumeral;
            }
        } else if (digit == 4) {
            fullRomanNumeral = romanNumeral + romanNumeralForFive;
        } else if (digit > 4 && digit < 9) {
            int differenceFromFive = digit - 5;
            fullRomanNumeral += romanNumeralForFive;
            for (int i = 0; i < differenceFromFive; i++) {
                fullRomanNumeral += romanNumeral;
            }
        } else {
            fullRomanNumeral = romanNumeral + romanNumeralForNine;
        }



        return fullRomanNumeral;
    }

    string intToRoman(int num) {
        string romanNumeral = "";

        int x = num;
        int currentNumber;
        int base = 1;

        while (x > 0) {
            currentNumber = returnLastDigit(x);
            x /= 10;
            string currentNumeral = returnSingleNumeral(currentNumber, base);
            base *= 10;
            romanNumeral.insert(0, currentNumeral);
        }

        return romanNumeral;
    }
};
