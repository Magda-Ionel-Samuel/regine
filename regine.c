#include <stdlib.h>
#include <stdio.h>

int v[10];
int k, n;
void Init(k) {
	v[k] = 0;
}

int Succesor(k) {
	if (v[k] < n) {
		v[k]++;
		return 1;
	}
	else
		return 0;
}


int Solution(int k) {
	return (k == n);
}

int Valid(k) {
	int i;
	for (i = 1; i <= k - 1; i++)
	{
		if ((v[i] == v[k]) || (abs((v[k] - v[i])) == (k - i)))
			return 0;

	}
	return 1;
}
void Print() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			if (v[i] == j)
				printf("R ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

void Back(int n) {
	k = 1;
	Init(k);
	while (k > 0) {
		int isS = 0;
		int isV = 0;
		if (k <= n)
			do {
				isS = Succesor(k);
				if (isS)
					isV = Valid(k);
			} while (isS && !isV);
			if (isS)
				if (Solution(k))
					Print();
				else {
					k++; Init(k);
				}
			else
				k = k - 1;
	}
}


int main()
{

	printf("Introduceti n: "); scanf("%d", &n);
	Back(n);
	system("pause");
	return 0;
}
