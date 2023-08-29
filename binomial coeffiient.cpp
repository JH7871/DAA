#include<stdio.h>
int main() {
    int i, j, n, k, min, c[20][20]={0};
    printf("This program will help us to find the binomial Coefficient" );
    printf("\n Enter the value of n: ");
    scanf("%d", &n);
    printf("\n Enter the value of k: ");
    scanf("%d", &k);
    if(n >= k) {
        for(i=0; i<=n; i++) {
            min = i<k? i:k;
            for(j = 0; j <= min; j++) {
                 if(j==0 || j == i) {
                     c[i][j] = 1;
                 } else {
                     c[i][j] = c[i-1][j-1] + c[i-1][j];
                 }
             }
         }
         printf("%d\t",c[n][k]);
         printf("\n");
     } else {
         printf("\n Invalid input \n Enter value n>=k \n");
     }
}