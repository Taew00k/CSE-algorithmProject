#include "ShellSort.h"

void shellSort(vector<House>& a, int n) {
    int h = 1;
    do {
        h = 3 * h + 1;
    } while (h < n);

    do {
        h = h / 3;
        for (int i = h; i < n; i++) {
            House v = a[i];
            int j = i;
            while (j >= h && a[j - h].totalScore < v.totalScore) {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
    } while (h > 1);
}