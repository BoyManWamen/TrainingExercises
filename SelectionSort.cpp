#include <iostream>
#include <array>

using namespace std;

template<typename T, std::size_t N>
void smallestSelectionSort(std::array<T, N> &arr) {
    const int length{static_cast<int>(std::size(arr))};

    for (int i = 0; i < length - 1; i++) {
        int smallestIndex = i;

        for (int j = smallestIndex + 1; j < length; j++) {
            if (arr[smallestIndex] > arr[j]) {
                smallestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;

        for (int d = 0; d < length; d++) {
            cout << arr[d] << ' ';
        }

        cout << endl;
    }
}

template<typename T, std::size_t N>
void biggestSelectionSort(std::array<T, N> &arr) {
    const int length{static_cast<int>(std::size(arr))};

    for (int i = 0; i < length - 1; i++) {
        int biggestIndex = i;

        for (int j = biggestIndex + 1; j < length; j++) {
            if (arr[biggestIndex] < arr[j]) {
                biggestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[biggestIndex];
        arr[biggestIndex] = temp;

        for (int d = 0; d < length; d++) {
            cout << arr[d] << ' ';
        }

        cout << endl;
    }
}

int main() {
    std::array<int, 5> arr{7, 8, 3, 1, 6};

    smallestSelectionSort(arr);
    biggestSelectionSort(arr);

    return 0;
}
