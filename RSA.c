#include <stdio.h>
#include <string.h>

void select_e(int pi, int *e, int *count) {
	int i, j, temp = 0;
	int flag = 0;
	for (i = 2;i < pi;i++) {
		for (j = 1;j <= i;j++)
			if (i % j == 0 && pi % j == 0)temp = j;
		if (temp == 1) {
			e[flag] = i;
			flag++;
			temp = 1;
		}
		if (flag == 20) break;
	}
	*count = flag;
}

void select_d(int e, int pi, int *d) {
	int i;
	for (i = 2;i < pi;i++)
		if ((e * i) % pi == 1) *d = i;
}

int main() {
	int p = 7, q = 3, n = 0, e = 0, d = 0, pi = 0, m = 1, c = 1;
	int count = 0, flag = 0;
	int i, j;
	int elist[20] = { 0 };
	float encrypt = 0, decrypt = 0;
	int plaintext = 0;

	n = p * q;
	pi = (p - 1) * (q - 1);
	select_e(pi, &elist, &count);		//e값(공개키) 구하기
	
	while (1) {
		printf("e 값(공개키) : ");
		for (i = 0;i < count;i++)
			printf("%d ", elist[i]);
		printf("\n원하는 공개키 값을 위에서 고르시오 : ");
		scanf("%d", &e);
		for (i = 0;i < count;i++) {
			if (e == elist[i]) flag++;
		}
		if (flag == 0) printf("해당하는 공개키 값이 없습니다. 다시 고르십시오.\n\n");
		else
			break;
	}
	printf("\n선택하신 공개키: %d\n", e);

	select_d(e, pi, &d);		//d값(비밀키) 구하기
	printf("d 값(비밀키): %d\n\n", d);

	printf("암호화를 시작합니다.\n");
	printf("암호화할 평문을 입력하시오 : ");
	scanf("%d", &plaintext);

	
	for (j = 0;j < e;j++)
		m *= plaintext;
	encrypt = m % n;
	
	printf("암호화가 완료되었습니다.\n");
	printf("암호문: ");
	printf("%f\n\n", encrypt);

	printf("복호화를 시작합니다.\n");

	for (j = 0;j < d;j++)
		c *= encrypt;
	decrypt = m % n;
		
	
	printf("복호화가 완료되었습니다.\n");
	printf("복호문: ");
	printf("%f", decrypt);
}