#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

// сортировка методом Шелла
void ShellSort(int n, vector<int>& mass)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

int main()
{
    // ввод N
    int N;
    cout << "Input N: ";
    cin >> N;

    // выделение памяти под массив
    vector<int> mass(N);

    // ввод элементов массива
    cout << "Input the array elements:\n";
    for (int i = 0; i < N; i++)
        cin >> mass[i];

    // сортировка методом Шелла
    ShellSort(N, mass);

    // вывод отсортированного массива на экран
    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++)
        cout << mass[i] << " ";
    cout << endl;

    _getch();
    return 0;
}
