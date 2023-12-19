#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char *stack = malloc(strlen(s));
    assert(stack);
    int top =0;
    int i;
    int c, e;
    bool ret = false;

    for(int i=0; i<strlen(s); i++) {
        c = s[i];
        if(c == ')'){
            if(top == 0){
                goto out;
            }
            e = stack[--top];
            if(e != '(')
                goto out;
        }
        else if(c == '}'){
            if(top == 0){
                goto out;
            }
            e = stack[--top];
            if(e != '{')
                goto out;
        }
        else if(c == ']'){
            if(top == 0){
                goto out;
            }
            e = stack[--top];
            if(e != '[')
                goto out;
        }
        else{
            stack[top++] = c;
        }
    }

    ret = top == 0;
out:
    free(stack);
    return ret;
    
}