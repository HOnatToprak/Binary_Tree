//Hasan Onat TOPRAK -- 2015555063 Merve ÇALIÞ -- 2016555021
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arr[200];
int size = 0;
void addnode(int input) {
	int current = 0;
	while (arr[current] != -1) {
		if (input < arr[current])
			current = 2 * current + 1;
		else
			current = 2 * current + 2;
	}
	arr[current] = input;
	if (current+1 > size)
		size = current+1;
}
int degree(int input) {
	int i = 0;
	while (1) {
		if (input >= (intpwr(2, i-1))-1 && input < intpwr(2, i)-1) {
			break;
		}
		i++;
	}
	return i-1;
}
int intpwr(int x, int y) {
	int sum = 1;
	if (y < 0) { return 0; }
	if (y == 0) { return 1; }
	int i;
	for (i = 0; i < y; i++) {
		sum *= x;
	}
	return sum;

}

void showtree() {
    int iter;
	for (iter = 0; iter<size; iter++) {
		if(arr[iter] != -1)
			printf("%dth DEGREE Value = %d -- Left Node = %d -- Right Node = %d\n", degree(iter), arr[iter], arr[2 * iter + 1], arr[2 * iter + 2]);
	}
}
int main() {
    int i;
	for (i = 0; i<200; i++) {
		arr[i] = -1;
	}
	int selection;
	int node;
	while (1) {
		printf("1-Insert\n2-Show\n3-Exit\n");
		scanf("%d", &selection);
		switch (selection) {
		case 1: printf("Enter Value = "); scanf("%d", &node); addnode(node); break;
		case 2: showtree(); break;
		case 3: exit(0);
		}
	}

}
