#include <stdio.h>
#include <stdlib.h>

int main()  
{  
    int pages, frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages in the incoming stream: ");
    scanf("%d", &pages);
    
    int *incomingStream = (int *)malloc(pages * sizeof(int));
    printf("Enter the incoming stream: ");
    for(int i = 0; i < pages; i++) {
        scanf("%d", &incomingStream[i]);
    }

    int pageFaults = 0;  
    int m, n, s;   
    
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");  
    
    int *temp = (int *)malloc(frames * sizeof(int));
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s = 1;  
                break;  
            }  
        }  
        
        if(s == 0)  
        {  
            temp[pageFaults % frames] = incomingStream[m];  
            pageFaults++;  
        }  
        
        printf("%d\t\t", incomingStream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf("%d\t\t", temp[n]);  
            else  
                printf("-\t\t");  
        }  
        printf("\n");  
    }  
    
    printf("\nTotal Page Faults (FIFO):\t%d\n", pageFaults);  
    
    free(incomingStream);
    free(temp);
    
    return 0;  
}
