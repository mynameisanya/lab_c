#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


//Парарельное соединение
int Bernoulli(float x) //Распределение Бернулли:
{
    setlocale(LC_ALL, "Rus");
    if (x == -1)
    {
        return x;
    }
    int max = 1000, y;
    //srand((unsigned)time(NULL)); //При использовании генерирует одни и те же числа.
    y = rand() % (max + 1);
    if ((y > ((1 - x) * max)) || (x == 1))
    {
        //printf(" %d ", y); //Вывод сгенерированного числа.
        return 1;
    }
    else
    {
        //printf(" %d ", y); //Вывод сгенерированного числа.
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
 
    int ParCompWork[CompCount][2]; //Массив, показывающий состояние 2-х параллельных компонентов устройства.
    int CompWork[CompCount]; //Массив, показывающий состояние компонента в целом, в зависимости от состояний параллельных компонентов.
    int Work; //Индикатор, показывающий, работает устройство в целом или нет.
    int ExpWorkCount = 0; //Кол-во экспериментов, в которых устройство работает.
    int i, j, k; //Счётчики.
    float P[CompCount][2]; //Массив вероятностей, которые задаются для каждого компонента. Если параллельный компонент отсутствует, то его вероятность записывается как "-1".

    printf("Enter Probabilities (from 0 to 1 for '0', and (from 0 to 1) or (-1) for '1'): \n");

    for (j = 0; j < CompCount; ++j) //Ввод вероятностей работы компонентов. Если параллельного компонента нет, то его вероятность записывается как "-1".
    {
     
        for (i = 0; i < 2; ++i)
        {
            printf("P[%d][%d] = ", j, i);
            scanf("%f", &P[j][i]);
        }
  
        printf("\n");
    }
 
    for (k = 0; k < ExpCount; ++k) //Цикл проведения экспериментов.
    {
     
        for (j = 0, Work = 1; j < CompCount ; ++j) //Цикл, определяющий, работает устройство или нет.
        {
      
            for (i = 0; i < 2; ++i) //Цикл, определяющий, работает компонент/параллельный компонент или нет.
            {
                ParCompWork[j][i] = Bernoulli(P[j][i]);
            }
            
            //Условие работы компонента в целом.
            if (ParCompWork[j][1] == -1) //Если параллельного компонента нет, то работоспособность компонента в целом определяется по состоянию основного компонента.
            {
                CompWork[j] = ParCompWork[j][0];
            }
            else
            {
                if ((ParCompWork[j][0] == 1) || (ParCompWork[j][1] == 1))
                {
                    CompWork[j] = 1;
                }
                else
                {
                    CompWork[j] = 0;
                    Work = 0;
                }
            }
        }
  
        for (j = 0; j < CompCount; ++j)
        {
      
            for (i = 0; i < 2; ++i)
            {
                printf("\nParCompWork[%d][%d] = %2d", j, i, ParCompWork[j][i]); //Вывод состояния каждого компонента.
            }
   
            printf("\nCompWork[%d] = %d", j, CompWork[j]); //Вывод состояния компонента в целом.
        }
  
        printf("\n\tWork = %d\n------------------", Work); //Вывод состояния устройства.
        ExpWorkCount += Work; //Нахождение кол-ва экспериментов, в которых устройство работает.
    }
 
    float PWork; //Вероятность работы усройства по результатам экспериментов.
    PWork = ExpWorkCount / (float)ExpCount;
 
    printf("\nExpWorkCount = %d", ExpWorkCount); //Вывод кол-ва экспериментов, в которых устройство работает.
    printf("\nPWork = %f", PWork); //Вывод вероятности работы устройства по результатам экспериментов.
 
    getchar();
    return 0;
}