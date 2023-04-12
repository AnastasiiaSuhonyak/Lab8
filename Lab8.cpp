#include <iostream>
#include <cmath>

int main() {
    const int n = 10;
    int arr[n] = {5, -4, 2, 6, 0, -3, 8, -7, -2, 9};
    int sum_odd = 0;
    int sum_between_negatives = 0;
    int neg_count = 0;
    int neg_start = -1;
    int neg_end = -1;

    // обчислюємо суму елементів масиву з непарними номерами
    for (int i = 0; i < n; i += 2) {
        sum_odd += arr[i];
    }

    // знаходимо перший та останній від'ємні елементи та обчислюємо суму елементів між ними
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            neg_count++;
            if (neg_start == -1) {
                neg_start = i;
            } else {
                neg_end = i;
            }
        }
        if (neg_count == 2) {
            break;
        }
    }
    if (neg_start != -1 && neg_end != -1) {
        for (int i = neg_start + 1; i < neg_end; ++i) {
            sum_between_negatives += arr[i];
        }
    }

    // стискаємо масив, видаляючи всі елементи, модуль яких не перевищує 1
    int new_end = n - 1;
    for (int i = 0; i <= new_end; ++i) {
        if (std::abs(arr[i]) <= 1) {
            for (int j = i; j < new_end; ++j) {
                arr[j] = arr[j + 1];
            }
            new_end--;
            i--;
        }
    }
    for (int i = new_end + 1; i < n; ++i) {
        arr[i] = 0;
    }

    // виводимо результати
    std::cout << "Sum of elements with odd indexes: " << sum_odd << std::endl;
    std::cout << "Sum of elements between first and last negative elements: " << sum_between_negatives << std::endl;
    std::cout << "Compressed array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;




    return 0;
}

