#include <stdio.h>
#include <stdlib.h>

int findLFU(int freq[], int n) {
    int i, minimum = freq[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(freq[i] < minimum) {
            minimum = freq[i];
            pos = i;
        }
    }
    return pos;
}

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
    int m, n, s, pos;   
    int *freq = (int *)malloc(frames * sizeof(int));   
    
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");  
    
    int *temp = (int *)malloc(frames * sizeof(int));
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
        freq[m] = 0;  
    }  
    
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s = 1;  
                freq[n]++;  
                break;  
            }  
        }  
        
        if(s == 0)  
        {  
            if(pageFaults < frames) {
                temp[pageFaults] = incomingStream[m];  
                freq[pageFaults] = 1;
            } else {
                pos = findLFU(freq, frames);
                temp[pos] = incomingStream[m];
                freq[pos] = 1;
            }
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
    
    printf("\nTotal Page Faults (LFU):\t%d\n", pageFaults);  
    
    free(incomingStream);
    free(temp);
    free(freq);
    
    return 0;  
}
