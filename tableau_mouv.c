#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void delay(float temps){
  usleep(temps);
}
int main()
{
  char tab [100] = {};
  for(int i = 0;i<100;i++){
    system("clear");
    tab[i] = '*';
    printf("%s\n",tab);
    tab[i] = '#';
    delay(50000);
  }
}
