/* 

1. n-1���� ������ 2�� ������� �ű� ��. (n-1���� ������ �ű������ Ƚ��)
2. 1������� n��° ������ 3��������� �ű��. (Ƚ�� 1�� �߰�)
3. 2������� n-1��° ������ 3��������� �ű��. (n-1���� ������ �ű������ Ƚ��)

��� �˰����� �̿��Ͽ� c��� �ҽ��ڵ� �ۼ�. 
*/

#include <stdio.h>

int num = 0; // ���� �ű�� Ƚ���� count �ϱ����� ����.

void hanoi(int n, int a, int b, int c) { 
	/*
	�ϳ��� �Լ� ����. 3���� ����� ���� a,b,c ��� ǥ��. 
	�Ű������� �ǹ� : "n���� ������ ��� a���� ��� b�� ���� ��� c�� �ű��."
	*/
	if (n == 1) {
		printf("The upmost disk in rod %d is moved to rod %d\n", a, c);
		num++;
	}
	
	else {
		hanoi(n - 1, a, c, b);
		printf("The upmost disk in rod %d is moved to rod %d\n", a, c);
		num++;
		hanoi(n - 1, b, a, c);
	}

}

int main(void) {
	int n;
	printf("Enter the desired number (Hanoi_Tower) : ");
	scanf_s("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("Thus the minimal number of moves is %d", num);

	return 0;
}