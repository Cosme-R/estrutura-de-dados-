#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int start, end;
    int count = 0;
    printf("Informe o intervalo (início e fim): ");
    scanf("%d %d", &start, &end);

    for (int i = start; i <= end; i++) {
    	end+10;
        if (isPrime(i)) {
            count++;
            printf("%d\n", i);
        }
        
    }
    printf("Existem %d números primos no intervalo [%d, %d]\n", count, start, end);
    return 0;
}

