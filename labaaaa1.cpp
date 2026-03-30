#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;
using namespace chrono;

bool find_element(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int find_second_max(int arr[], int size) {
    int max1 = arr[0];
    int max2 = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
}

bool binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

void multipl_table(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int product = i * j;
        }
    }
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10001;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int sizes[] = { 1000, 5000, 10000, 50000 };
    int num_sizes = 4;

  

    cout << "Линейный поиск" << endl;
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* arr = new int[n];
        generate_array(arr, n);

        auto start = high_resolution_clock::now();
        find_element(arr, n, 5000);
        auto end = high_resolution_clock::now();

        duration<double> duration = end - start;
        cout << n << " - " << duration.count() << " сек" << endl;

        delete[] arr;
    }
    cout << endl;

    cout << "Второй максимум" << endl;
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* arr = new int[n];
        generate_array(arr, n);

        auto start = high_resolution_clock::now();
        find_second_max(arr, n);
        auto end = high_resolution_clock::now();

        duration<double> duration = end - start;
        cout << n << " - " << duration.count() << " сек" << endl;

        delete[] arr;
    }
    cout << endl;

    cout << "Бинарный поиск" << endl;
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* arr = new int[n];
        generate_array(arr, n);

        bubble_sort(arr, n);

        auto start = high_resolution_clock::now();
        binary_search(arr, n, 5000);
        auto end = high_resolution_clock::now();

        duration<double> duration = end - start;
        cout << n << " - " << duration.count() << " сек" << endl;

        delete[] arr;
    }
    cout << endl;

    cout << "Таблица умножения" << endl;
    int table_sizes[] = { 100, 200, 500, 1000 };
    int num_table = 4;

    for (int i = 0; i < num_table; i++) {
        int n = table_sizes[i];

        auto start = high_resolution_clock::now();
        multipl_table(n);
        auto end = high_resolution_clock::now();

        duration<double> duration = end - start;
        cout << n << " - " << duration.count() << " сек" << endl;
    }
    cout << endl;

    cout << "Сортировка пузырьком" << endl;
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* arr = new int[n];
        generate_array(arr, n);

        auto start = high_resolution_clock::now();
        bubble_sort(arr, n);
        auto end = high_resolution_clock::now();

        duration<double> duration = end - start;
        cout << n << " - " << duration.count() << " сек" << endl;

        delete[] arr;
    }

    return 0;
}