#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRIALS 684739

int main()
{
    srand(0x6969);
    signed int consumed[4] = {-1,-1,-1,-1};
    signed int i, attempts, current, j;
    float probsum;
    for (i = 0, probsum=0; i < TRIALS; i++) {
        for (attempts = 0; attempts < 4;) {
            if ((current=(rand()%55))<20) {
                attempts++;
                break;
            }
            consumed[attempts] = current;
            for (j = attempts-1; j > -1; j--) {
                if (consumed[j] == current)
                    attempts--;
            }
            attempts++;
        }
        for (; attempts < 4; attempts) {
            if ((current=(rand()%8))<3) {
                probsum++;
                attempts++;
                break;
            }
            consumed[attempts] = current;
            for (j = attempts-1; j > -1; j--) {
                if (consumed[j] == current)
                    attempts--;
            }
            attempts++;
        }
        for (j = 0; j < 4; j++)
            consumed[j] = -1;
    }
    printf("%f\n", (probsum/TRIALS));
}
