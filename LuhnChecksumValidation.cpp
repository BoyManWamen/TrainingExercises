#include <iostream>

/* 
Problem: The Luhn formula is a widely used system for validating identification numbers. 
Using the original number, double the value of every other digit. Then add the values 
of the individual digits together (if a doubled value now has two digits, add the digits 
individually). The identification number is valid if the sum is divisible by 10. Write a 
program that takes an identification number of arbitrary length and determines whether the 
number is valid under the Luhn formula. The program must process each character before reading 
the next one. 
*/

using namespace std;

int intLength(int integer) {
    int number_of_digits = 0;

    do {
        ++number_of_digits;
        integer /= 10;
    } while (integer);

    return number_of_digits;
}

int lastDigit(int integer) {
    return (integer) - ((integer / 10) * 10);
}

template<typename T>
T max(T x, T y) {
    return x + y;
}

string validateID(int id) {
    int temp = 0;
    int digit;

    int temp_id = id;

    int total = 0;

    for (int i = 0; i < intLength(id); i++) {
        if (temp == 0) {
            ++temp;
            digit = lastDigit(temp_id);

            temp_id = (temp_id / 10);

            digit = digit * 2;

            if (digit >= 10) {
                total = total + lastDigit(digit);
                total += 1;
            } else {
                total = total + digit;
            }
        } else {
            --temp;
            digit = lastDigit(temp_id);

            temp_id = (temp_id / 10);

            total = total + digit;
        }
    }

    cout << total << endl;

    if ((total + 3) % 10 == 0) {
        return "Validated";
    }

    return "Not Validated";
}

int main() {
    int id;

    cin >> id;

    cout << validateID(id) << endl;

    while (cin >> id) {
        cout << validateID(id) << endl;
    }
}
