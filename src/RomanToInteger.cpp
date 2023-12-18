class Solution {
public:
    int returnIntegerBasedOnRoman(char s) {
        if (s == 'I') {
            return 1;
        } else if (s == 'V') {
            return 5;
        } else if (s == 'X') {
            return 10;
        } else if (s == 'L') {
            return 50;
        } else if (s == 'C') {
            return 100;
        } else if (s == 'D') {
            return 500;
        } else {
            return 1000;
        }
    }

    int returnLastDigit(int digit) {
        return digit % 10;
    }

    int romanToInt(string s) {
        int answer = 0;

        int x = answer;

        int currentInteger;

        int lastDigit;

        int base = 1;

        char lastLetter = s[s.length()-1];

        for (int i = s.length()-1; i >= 0; i--) {
            lastDigit = returnLastDigit(x);
            currentInteger = returnIntegerBasedOnRoman(s[i]);
            
            if (lastDigit == 5 && currentInteger < (5*base)) {
                currentInteger = -(currentInteger);
            } else if (returnIntegerBasedOnRoman(lastLetter) > returnIntegerBasedOnRoman(s[i])) {
                currentInteger = -(currentInteger);
            }

            answer += currentInteger;
            if (x >= 10) {
                x /= 10;
                base *= 10;
            }

            lastLetter = s[i];
        }

        return answer;
    }
};
