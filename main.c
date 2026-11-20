#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdint.h>




int main() {

   for (int i = 1; i < 10; i++) {
      for (int j = 1; j <= i; j++) {
         int c = i * j;
         printf("%d * %d = %d " ,i,j,c);
      }
      printf("\n");
   }
   return 0;
}
