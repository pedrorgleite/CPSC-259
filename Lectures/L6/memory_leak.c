#include <stdio.h>
#include <stdlib.h>

/* Memory leak example: memory is never freed;  so, eventually
 we run out.  It is recommended that you start Windows Task Manager
 (control-alt-delete, Task Manager), and watch the "Working Set (Memory)"
 column to see how the amount of RAM used grows.  Stop the program
 (i.e., end the process using Task Manager) before the RAM is
 totally consumed. */

int main(void)
{
    char * getMemory;
    
    while (1)   /* endless loop */
    {
        getMemory = (char *) malloc(40960); /* get 40k of memory at a time */
        if (getMemory == NULL)
        {
            printf("Error: no more memory available\n");
            system("pause");
            return -1;
        }
        printf("got memory at location %p\n", getMemory);
    }
    
    system("pause");
    return 0;
}
