class Solution {
public:
    bool checkOnesSegment(string s) {
        int stringSize = s.size();

        int counter = 0;

        for (int i = 0; i < stringSize; i++) {
            if (s[i] == '1') {
                counter++;
            }
        }

        if (counter == 1) {
             return true;
        }
        
        for (int i = 1; i < stringSize-1; i++) {

            if(s[i] == '0' && s[i+1] == '1') {

                return false;
            }
        }

        return true;
    }
};
