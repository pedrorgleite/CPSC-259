
#include <stdio.h>

#define SIZE 3
void process(int data[]);
int main() {
    int data[SIZE] = {5, -1, 2};
    process(data);
    for (int index = 0; index < SIZE; index++) {
        printf("%d", data[index]);
    }
}
void process(int data[]) {
for (int index = 0; index < SIZE; index++)
    data[index] = 0;
}
