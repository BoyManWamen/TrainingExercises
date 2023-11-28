#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>

using namespace std;

void fizzbuzz(int count) {
    const vector<string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    const vector<int> divisors{3, 5, 7, 11, 13, 17, 19};

    assert(size(words) == size(divisors) && "Not same size");

    for (int i = 1; i <= count; i++) {
        bool print = false;

        for (size_t j = 0; j < divisors.size(); j++) {
            if (i % divisors[j] == 0) {
                print = true;
                cout << words[j];
            }
        }

        if (!print) {
            cout << i;
        }

        cout << endl;
    }
}

int main() {
    fizzbuzz(170);

    return 0;
}
