#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
int main(){
    assert(bitAnd(4,5)==4&5);
    return 0;
}
