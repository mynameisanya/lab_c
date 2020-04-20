#include <stdio.h>
#include <math.h>
#include <time.h>

//считаем число пи и время затраченное на его подсчет
//получаем простой тест производительности пк

int main()
{
    
	clock_t begin = clock();
	float i=0;
	double pi=0;
    
	while (i < 16000000)
    {
	    pi += pow(-1.0, i)/pow(4, i)*(2.0/(4.0*i+1.0)+2.0/(4.0*i+2.0)+1.0/(4.0*i+3.0));
	    i++;
    }
	    //printf("%.100f\n", pi);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Elapsed: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);
	
    return 0;

}
