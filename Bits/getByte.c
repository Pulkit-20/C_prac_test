#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int getByte(int x, int n) {
    int byteShift = n << 3;

    int shifted = x >> byteShift;

    return shifted & 0xFF;
}
int main(){
    assert(getByte(0x12345678,1)==0x56);
    return 0;
}

