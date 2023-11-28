#include <iostream>
#include <array>
#include <chrono>

using namespace std;

class Timer {
private:
    // Type aliases to make accessing nested type easier
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

template<typename T, std::size_t N>
void bubbleSort(std::array<T, N> &arr) {
    const int length = static_cast<int>(std::size(arr));

    int swapCounter = 0;

    for (int j = 0; j < length - 1; j++) {
        swapCounter = 0;

        int endOfArray = length - j;

        for (int index = 0; index < endOfArray - 1; index++) {
            if (arr[index] > arr[index + 1]) {
                int temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
                swapCounter++;
            }

            for (int i = 0; i < length; i++) {
                cout << arr[i] << ' ';
            }

            cout << endl;
        }

        if (swapCounter == 0) {
            cout << "Early termination on iteration " << j + 1 << endl;
            break;
        }
    }
}

int main() {
    Timer t;

    std::array list{6, 3, 2, 9, 7, 1, 5, 4, 8};

    bubbleSort(list);

    cout << "Time elapsed: " << t.elapsed() << " seconds" << endl;

    return 0;
}
