//
//  sort3.c
//  
//
//  Created by Jason Yu on 12/3/18.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int first,second,third;
    scanf("%d %d %d", &first, &second, &third);
    if (first > second) {
        //?Third First ?Third Second ?Third
        if (second > third) {
            printf("%d\n%d\n%d\n",third,second,first);
        } else {
            if (first > third) {
                printf("%d\n%d\n%d\n",second,third,first);
            } else {
                printf("%d\n%d\n%d\n",second,first,third);
            }
        }
    } else {
        // ?Third Second ?Third First ?Third
        if (third > second) {
            printf("%d\n%d\n%d\n",first,second,third);
        } else {
            if (third > first) {
                printf("%d\n%d\n%d\n",first,third,second);
            } else {
                printf("%d\n%d\n%d\n",third,first,second);
            }
        }
    }
    return EXIT_SUCCESS;
}
