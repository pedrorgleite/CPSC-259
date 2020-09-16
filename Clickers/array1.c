
#include <stdio.h>
int main() {
    int data[] = {2, 4, 8, 16, 32, 64};
    int sum = 0;
    int index = 1;
    while (index < 4) {
    sum += data[index];
    printf("%d\n",sum);
    index++;
    }
    printf("%d",sum);
}