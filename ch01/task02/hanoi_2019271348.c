/* 

1. n-1개의 원판을 2번 기둥으로 옮긴 다. (n-1개의 원판을 옮기기위한 횟수)
2. 1번기둥의 n번째 원판을 3번기둥으로 옮긴다. (횟수 1번 추가)
3. 2번기둥의 n-1번째 원판을 3번기둥으로 옮긴다. (n-1개의 원판을 옮기기위한 횟수)

재귀 알고리즘을 이용하여 c언어 소스코드 작성. 
*/

#include <stdio.h>

int num = 0; // 원판 옮기는 횟수를 count 하기위한 변수.

void hanoi(int n, int a, int b, int c) { 
	/*
	하노이 함수 구현. 3개의 기둥을 각각 a,b,c 라고 표현. 
	매개변수의 의미 : "n개의 원판을 기둥 a에서 기둥 b를 거쳐 기둥 c로 옮긴다."
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