#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


//Последовательное соединение
//Распределение Бернулли:
int Bernoulli(float P)
{
 setlocale(LC_ALL, "Rus");
 int max = 1000, y;
 //srand((unsigned)time(NULL));
 y = rand() % (max + 1);
 //if (((rand() % (max + 1)) > ((1 - P) * max)) || (P == 1))
 if ((y > ((1 - P) * max)) || (P == 1))
 {
  //printf(" %d ", y);
  return 1;
 }
 else
 {
  //printf(" %d ", y);
  return 0;
 }
}

int main()
{

 int CompCount; //Кол-во компонентов устройства.
 printf("Enter Count of Components: ");
 scanf("%d", &CompCount);

 int ExpCount; //Кол-во экспериментов.
 printf("Enter Count of Experiments: ");
 scanf("%d", &ExpCount);

 int CompWork[CompCount]; //Массив, показывающий, работает или нет определённый компонент устройства.
 int Work; //Индикатор, показывающий, работает устройство в целом или нет.
 int ExpWorkCount = 0; //Кол-во экспериментов, в которых устройство работает.
 int i, j;
 float P[CompCount]; //Массив вероятностей, каждая из которых задаётся для определённого элемента.

 printf("Enter Probabilities: \n");

 for (i = 0; i < CompCount; ++i) //
 {                               //
  printf("P[%d] = ", i);         //Ввод вероятностей для элементов устройства.
  scanf("%f", &P[i]);            //
 }                               //

 for (j = 0; j < ExpCount; ++j)                                                           //Цикл
 {                                                                                        //
                                                                                          //
  for (i = 0, Work = 1; (i < CompCount) && !(Work == 0); ++i) //Цикл, определяющий,       //
  {                                                           //                          //
   if (Bernoulli(P[i]))                                       //                          //
   {                                                          //                          //
    CompWork[i] = 1;                                          //работает устройство       //
   }                                                          //                          //проведения
   else                                                       //                          //
   {                                                          //                          //
    CompWork[i] = 0;                                          //или нет.                  //
    Work = 0;                                                 //                          //
   }                                                          //                          //
  }                                                           //                          //
                                                                                          //
  for (i = 0; i < CompCount; ++i)                 //                                      //экспериментов.
  {                                               //Вывод состояния каждого компонента.   //
   printf("\nCompWork[%d] = %d", i, CompWork[i]); //                                      //
  }                                               //                                      //
                                                                                          //
  printf("\n\tDeviceWork = %d", Work); //Вывод состояния устройства.                      //
  ExpWorkCount += Work; //Нахождение кол-ва экспериментов, в которых устройство работает. //
 }                                                                                        //

 float PWork; //Вероятность работы усройства по результатам экспериментов.
 PWork = ExpWorkCount / (float)ExpCount;
 //printf("\nExpWorkCount = %d", ExpWorkCount);
 printf("\nPWork = %f", PWork);
 getchar();
 return 0;
}
