#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int bitXor(int x, int y) {
    int a = ~(x & y);
    int b = ~(~x & ~y);
    return a & b;
}
int main(){
    assert(bitXor(4,5)==4^5);
    return 0;
}
