#include <iostream>
#include <omp.h>

using namespace std;

double factorial1(int arr[], size_t size) {
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
    for (j = 0; j < size; j++)
    {
        fact = 1;
        for (int i = 1; i <= arr[j]; i++) {
            fact *= i;
        }
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}

double parallel_factorial1(int arr[], size_t size)
{
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
#pragma omp parallel for ordered shared(arr) private(j,fact)
    for (j = 0; j < size; j++)
    {
        fact = 1;
        for (int i = 1; i <= arr[j]; i++) {
            fact *= i;
        }
#pragma omp ordered
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}

unsigned long long int fact2(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * fact2(num - 1);
    }
}

double parallel_factorial2(int arr[], size_t size)
{
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
#pragma omp parallel for ordered shared(arr) private(j,fact)
    for (j = 0; j < size; j++)
    {
        fact = fact2(arr[j]);
#pragma omp ordered
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}

unsigned long long int tree(int left, int right) {
    if (left > right) {
        return 1;
    }
    if (left == right) {
        return 1;
    }
    if (right - left == 1) {
        return (unsigned long long int)left * right;
    }
    int middle = (left + right) / 2;
    return tree(left, middle) * tree(middle + 1, right);
}

unsigned long long int fact3(int num) {
    if (num < 0) {
        return 0;
    }
    if (num == 0) {
        return 1;
    }
    if (num == 1 || num == 2) {
        return num;
    }
    return tree(2, num);
}
double parallel_factorial3(int arr[], size_t size)
{
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
#pragma omp parallel for ordered shared(arr) private(j,fact)
    for (j = 0; j < size; j++)
    {
        fact = fact3(arr[j]);
#pragma omp ordered
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}

double factorial3(int arr[], size_t size) {
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
    for (j = 0; j < size; j++)
    {
        fact = fact3(arr[j]);
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}

void parallel_factorial3() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = factorial3(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}

void ordinary_factorial3() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = factorial3(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}

double factorial2(int arr[], size_t size) {
    double start, finish, result;
    int j;
    unsigned long long int fact;
    start = omp_get_wtime();
    for (j = 0; j < size; j++)
    {
        fact = fact2(arr[j]);
        cout << "Факторiал числа " << arr[j] << " = " << fact << endl;
    }
    finish = omp_get_wtime();
    result = finish - start;
    return result;
}
void parallel_factorial2() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = parallel_factorial2(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}


void ordinary_factorial2() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = factorial2(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}

void parallel_factorial1() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = parallel_factorial1(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}


void ordinary_factorial1() {
    int to_arr[] = { 5, 10, 15, 20, 25, 50 };
    size_t size = sizeof(to_arr) / sizeof(to_arr[0]);
    double time = factorial1(to_arr, size);
    cout << "\nЧас виконання: " << time << endl;
}

int main()
{
    setlocale(LC_ALL, "ukrainian");
    cout << "Розпаралельована функцiя пiдрахунку факторiалу за допомогою рекурсiї:" << endl;
    parallel_factorial2();
    cout << "Звичайна функцiя пiдрахунку факторiалу за допомогою рекурсiї:" << endl;
    ordinary_factorial2();
    cout << "Розпаралельована функцiя пiдрахунку факторiалу за допомогою циклу:" << endl;
    parallel_factorial1();
    cout << "Звичайна функцiя пiдрахунку факторiалу за допомогою циклу:" << endl;
    ordinary_factorial1();
    cout << "Розпаралельована функцiя пiдрахунку факторiалу за алгоритму обчислення деревом:" << endl;
    parallel_factorial3();
    cout << "Звичайна функцiя пiдрахунку факторiалу за допомогою алгоритму обчислення деревом:" << endl;
    ordinary_factorial3();
}
