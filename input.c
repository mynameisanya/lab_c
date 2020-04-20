#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
#include<math.h>

int main() {
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	FILE *f; fopen_s(&f, "input.txt", "r");
	int **a, n, i, j, k = 0, o = 1, x, y, d = 1;
	fscanf_s(f, "%d", &n); a = new int*[n];
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf_s(f,"%d",&a[i][j]);
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	i = (n-1)/2;
	j = (n - 1) / 2;
	while (k!=3) {
		for (x=0; x< abs(o); x++,i=i+d) {
			printf("%d ", a[j][i]); 
		}
		k++;
		for (y = 0; y < abs(o); y++, j = j + d) {
			printf("%d ", a[j][i]);
		}
		k++;
		if (o < 0) {
			o = -o;
		}
		if (o < n) {
			o++;
			d = -d;
		}
		if (d < 0) {
			o = -o;
		}
		if (abs(o) == n) {
			for (x = 0; x < abs(o); x++, i = i + d) {
				printf("%d ", a[j][i]);
			}
			k++;
		}
		else k = 0;
	}
	fclose(f);
	_getch();
	return 0;
}