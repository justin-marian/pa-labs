#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n - 1 disks from source to auxiliary
    hanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n - 1 disks from auxiliary to destination
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Tower of Hanoi sequence:\n");
    hanoi(n, 'A', 'B', 'C');

    printf("Total number of moves: %d\n", (1 << n) - 1);

    return 0;
}
