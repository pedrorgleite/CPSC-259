#include <stdio.h>
#include <stdlib.h>
int main()
{
    char strings[9][100] = {"one","two","three","four","five",
                                "six","seven","eight","nine"};
    int n;
    scanf("%d",&n);
    // Write Your Code Here
    if(n<=9&&n>0){
        printf("%s",strings[n-1]);
    }
    else{
        printf("Greater than 9");
    }

    return 0;
}