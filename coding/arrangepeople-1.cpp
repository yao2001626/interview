#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,x;
    int i = 0;
    unsigned int *arr;
    scanf("%d, %d", &n, &x);
    arr = (unsigned int *)malloc(sizeof(unsigned int)*n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int tmp = 0;
    for(int j=x-1; ; --j){//
        if(j < 0){
            j = j + n;
        }
        if(arr[j] >= 0){
            arr[j] -= 1;
            tmp++;
        }else{
            arr[j] = tmp;
     		break;
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}
