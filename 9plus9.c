
 #include <stdio.h>
int main() {
    int i = 1 ,j= 1;
    for (i = 1; i < 10; i++) {
        for (j = 1; j <= i; j++) {
            int c = i * j;
            printf("%d * %d = %d " ,i,j,c);
        }
        printf("\n");
    }

}

