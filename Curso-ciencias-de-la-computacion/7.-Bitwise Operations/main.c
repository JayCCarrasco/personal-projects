#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int v = -6;
    int sign;

    //to avoid branching in CPUs with flag registers (IA32)
    sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT -1));

    printf("case 1: %d\n",sign);

    //One less instructions, not portable
    sign = v >> (sizeof(int) * CHAR_BIT -1);
    printf("case 2: %d\n",sign);

    /*The last expression above evaluates to sign = v >> 31 for 32-bit integers. 
    This is one operation faster than the obvious way, sign = -(v < 0). 
    This trick works because when signed integers are shifted right, the value 
    of the far left bit is copied to the other bits. 
    The far left bit is 1 when the value is negative and 0 otherwise; all 1 bits gives -1.
    Unfortunately, this behavior is architecture-specific.
    So for portability is better to use previous code*/

    //If you prefer the result be either -1 or +1
    sign = +1 | (v >> sizeof(int) * CHAR_BIT - 1);
    printf("case 3: %d\n",sign);

    //If you prefer the result be either -1 or 0 or +1
    sign = (v != 0) | -(int)((unsigned int)((int)v) >> sizeof(int) * CHAR_BIT - 1);
    printf("case 4: %d\n",sign);

    //For more speed, less portability
    sign = (v != 0) | (v >> sizeof(int) * CHAR_BIT - 1);
    printf("case 5: %d\n",sign);

    //For portability, brevity and perhaps speed
    printf("case 6: %d\n",sign);
    sign = (v > 0) - (v < 0);

    //If instead wanna know if something is non-negative
    //resulting in +1 or else 0 then use:

    sign = 1 ^ ((unsigned int)v >> (sizeof(int) * CHAR_BIT - 1));

    //Detect if two integers have opposite signs
    int x = 3;
    int y = 3;
    bool f = ((x ^y) < 0);
    printf("Result x and y comparison: %d\n", f);

    //Compute the integer absolute value without branching
    v = 6;
    unsigned int r;
    int const mask = v >> (sizeof(int) * CHAR_BIT - 1);

    r = (mask + v) ^ mask;
    printf("The abs for %d is %d\n", v, r);

    return 0;
}