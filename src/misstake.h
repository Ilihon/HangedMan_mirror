#include <iostream>

int endg = 0;

int misstake(char* righ, char* mem, int i, int r)
{
    int pass = 0;
    for (int b = 0; b < r; b++) {
        if ((b == i) && (mem[b] == '_')) {
            mem[b] = righ[i];
            endg++;
            for (int c = b + 1; c < r; c++) {
                if ((righ[c] == mem[b]) && (mem[c] == '_')) {
                    mem[c] = righ[c];
                    endg++;
                } else {
                    if (mem[c] == '_')
                        mem[c] = '_';
                }
            }
            pass = 1;
            break;
        }
    }
    if (endg == r) {
        pass = 2;
    }
    return pass;
}
