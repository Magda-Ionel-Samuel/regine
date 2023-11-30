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