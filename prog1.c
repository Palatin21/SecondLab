#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main123() {

  int i;
  int maximum, minimum;
  int size;
  const long double RAND_MAX_F = RAND_MAX;

  //Диалоговые строки
  printf("Сколько элементов должен содержать массив ");
  scanf("%d",&size);
  printf("Укажите минимальное значение массива ");
  scanf("%d", &minimum);
  printf("Укажите максимальное значение массива ");
  scanf("%d", &maximum);

  //Пользовательские ошибки
  if (minimum > maximum) {
  printf("Минимальное значение не может быть выше минимального");
  return 0;
  }

  if (size <= 0 ) {
  printf("Генерируемый массив не может быть пустым");
  return 0;
  }

  //Создание файла
  srand(time(NULL));
  FILE* file = 0;
  file = fopen("textFile.txt", "w");
  for(i=0; i<size; i++){
  fprintf(file, "%Lf\n", ((maximum - minimum) * ((long double)rand() / RAND_MAX)) + minimum);
  }
  fclose(file);

  return 0;
}
