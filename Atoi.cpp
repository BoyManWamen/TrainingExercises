class Solution {
public:
    int myAtoi(string s) {
        int stringLength = s.size();
        double number = 0;

        int i = 0;

        while (s[i] == ' ') {
            i++;
        }

        bool positive = (s[i] == '+');
        bool negative = (s[i] == '-');

        positive == true ? i++ : i;
        negative == true ? i++ : i;

        while (i < stringLength && s[i] >= '0' && s[i] <= '9') {
            number = (number*10) + (s[i]-'0');
            i++;
        }

        number = (negative) ? -number : number;

        number = (number > INT_MAX) ? INT_MAX : number;
        number = (number < INT_MIN) ? INT_MIN : number;

        return int(number);
    }
};
