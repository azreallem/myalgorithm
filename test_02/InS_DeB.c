#include <stdio.h>

int main()
{
	float capital;
	float in_precent;
	float de_precent;
	float InS[10];
	float DeB[10];
	int total;
	int InS_quantity[11];
	int DeB_quantity[11];

	printf("please input capital: ");
	scanf("%f", &capital);
	printf("please input total: ");
	scanf("%d", &total);
	printf("please input in_precent: ");
	scanf("%f", &in_precent);
	printf("please input de_precent: ");
	scanf("%f", &de_precent);

	InS_quantity[0] = total;
	DeB_quantity[0] = total;

	for (int i = 0; i < 10; i++) {
		InS[i] = capital * (in_precent * (i + 1) + 1.00);
		DeB[i] = capital * (1.00 - de_precent * (i + 1));
		InS_quantity[i + 1] = InS_quantity[i] / 2;
		DeB_quantity[i + 1] = DeB_quantity[i] / 2;
	}

	printf("InS\t\tInS_quantity\n");
	for (int i = 0; i < 10; i++) {
		printf("%.4f\t\t%d\n", InS[i], InS_quantity[i + 1]);
	}

	printf("DeB\t\tDeB_quantity\n");
	for (int i = 0; i < 10; i++) {
		printf("%.4f\t\t%d\n", DeB[i], DeB_quantity[i + 1]);
	}

	return 0;
}
