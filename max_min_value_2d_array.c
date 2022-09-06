#include <stdio.h>

int a[100][100];

void input(int n, int n2, int index, int index2) {
    if(index==n && index2==n2) return;
    if(n2==index2) {
        ++index;
        index2 = 0;
    }
    if(index<n) scanf("%d", &a[index][index2]);
    if(index2<n2) ++index2;
    input(n, n2, index, index2);
}

int min(int n, int n2, int i, int j, int m) {
    if(i==n && j==n2) return m;

    if(m>a[i][j] && i<n) m = a[i][j];

    if(j<n2) ++j;

    if(j==n2 && i<n) {
        ++i;
        j = 0;
    }

    return min(n, n2, i, j, m);
}

int max(int n, int n2, int i, int j, int m) {
    if(i==n && j==n2) return m;

    if(m<a[i][j] && i<n) m = a[i][j];


    if(j<n2) ++j;

    if(j==n2 && i<n) {
        ++i;
        j = 0;
    }

    return max(n, n2, i, j, m);
}

int main() {

    int n, n2;
    scanf("%d %d", &n, &n2);

    input(n, n2, 0, 0);

    int m2 = a[0][0];

    printf("Minimum value in 2d array is %d\n", min(n, n2, 0, 0, m2));
    printf("Maximum value in 2d array is %d\n", max(n, n2, 0, 0, m2));

    return 0;

}