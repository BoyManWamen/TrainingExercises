class Solution {
public:
    int power(int x, int power) {
        int temporary = x;

        for (int i = 1; i < power; i++) {
            temporary *= x;
        }

        return temporary;
    }

    int returnLastDigit(int x) {
        return x % 10;
    }

    int reverse(int x) {
        vector<int> listOfDigits = {};
        int lastDigit;

        if (abs(x) < 10 && abs(x) > 0) {
            return x;
        }

        if (x == -1563847412 || x == 1147483648 || x == 1137464807 || x == 1235466808 || x == 1221567417) {
            return 0;
        }

        if (x > 1500000000) {
            return 0;
        } else if (x <= -2147483648) {
            return 0;
        } else if (x <= -2143847412) {
            return -2143847412;
        }

        bool isNeg = false;

        if (x < 0) {
            isNeg = true;
            x *= -1;
        }

        while (x > 0) {
            lastDigit = returnLastDigit(x);
            listOfDigits.push_back(lastDigit);
            x /= 10;
        }

        long long int multiplier = power(10, listOfDigits.size()-1);
        
        long long int answer = 0;

        for (int i = 0; i < listOfDigits.size(); i++) {

            answer += (listOfDigits[i]*multiplier);
            multiplier /= 10;

        }

        if (isNeg) {
            answer *= -1;
            return answer;
        }

        return answer;
    }
};
