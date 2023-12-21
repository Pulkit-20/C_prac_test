#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sign(int x) {
    int s = (((1<<30)|x)>>30)&(~(!x));
    return s;
}
int main(){
    printf("%d\n",sign(4));
    assert(sign(4)==1);
    return 0;
}
