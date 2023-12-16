//
// Created by 허은정 on 12/17/23.
//

#include "ShellSort.h"

void shellSort(vector<House> a, int n)
{
    int i, j, h;
    double v;
    h = 1;
    int* arr = new int[2];
    arr[0] = 0, arr[1] = 0;
    do
        h = 3 * h + 1;
    while (h < n);
    do
    {
        h = h / 3;
        for (i = h; i < n; i++)
        {
            v = a[i].totalScore; // ̵
            arr[0]++;
            j = i;
            while (++arr[1]&&(a[j - h].totalScore > v)) //
            {
                a[j].totalScore = a[j - h].totalScore; // ̵
                arr[0]++;
                j -= h;
                if (j <= h - 1)
                    break;
            }
            a[j].totalScore = v; // ̵
            arr[0]++;
        }
    } while (h > 1);

}