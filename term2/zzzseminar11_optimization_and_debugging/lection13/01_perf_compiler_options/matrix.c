#include <stdlib.h>

#define N 1024

float a[N][N];
float b[N][N];
float c[N][N];

void init_matrix() {
    unsigned long long int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = random()/RAND_MAX;
            b[i][j] = random()/RAND_MAX;
        }
    }
}

void mult() {
    unsigned long long int i, j, k;
    
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                c[k][i] = c[k][i] + a[k][j]*b[j][i];
            }
        }
    }
}

int main(int argc, char **argv) {

    init_matrix();
    mult();

    return 0;
}
