#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n ;
    scanf("%d", &n);
    while(n--){
        char arr[100][1000];
        scanf("%s",arr[0]);
        int i=0;
        while(arr[i][0]!='?'){
            scanf("%s",arr[++i]);
        }
        int stack[1000];
        int top = -1;
        int ans =0;
        for(int j=0;j<i;j++){
            if(arr[j][0]=='+'){
                ans = stack[top] + stack[top-1];
                top = top - 2;
                stack[++top] = ans;
            }
            else if(arr[j][0]=='-'){
                ans = stack[top-1] - stack[top];
                top = top - 2;
                stack[++top] = ans;
            }
            else if(arr[j][0]=='*'){
                ans = stack[top-1] * stack[top];
                top = top - 2;
                stack[++top] = ans;
            }
            else if(arr[j][0]=='/'){
                ans = stack[top-1] / stack[top];
                top = top - 2;
                stack[++top] = ans;
            }
            else{
                int curr = atoi(arr[j]);
                ans = curr;
                stack[++top] = curr;
            }
        }
        printf("%d",ans);

    }
    return 0;
}