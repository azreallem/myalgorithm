#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_NUMBER -1.00

int main()
{
	srand (time(NULL));
	int times = 0;
	int best_times = 0;
	int better_times = 0;
	float best_prob =  0.00;
	float better_prob =  0.00;
	int total = 0;
	float sel_average_num = 0.00;

	printf("please input test times: ");
	scanf("%d", &times);
	printf("please input Total Sample Qty: ");
	scanf("%d", &total);

	for (int t = 0; t < times; t++) {
		float *randomNumber = (float *)malloc(total * sizeof(float));
		float sel_max_num = MIN_NUMBER;
		float real_max_num = MIN_NUMBER;
		float ob_max_num = MIN_NUMBER;
		float average_num = 0;
		float pre_ob = total * 0.37;

		for (int i = 0; i < total; i++) {
			randomNumber[i] = (float)(rand() % 10000) / 100; //0.00 ~ 99.99
			average_num += randomNumber[i];
			if (randomNumber[i] > real_max_num)
				real_max_num = randomNumber[i];
			printf("%.2f\t", randomNumber[i]);
			if (i % 10 == 9)
				printf("\n");
		}
		average_num /= total;
		printf("average_num: %.2f\n", average_num);
		printf("real_max_num: %.2f\n", real_max_num);

		for (int i = 0; i < pre_ob; i++)
			if (randomNumber[i] > ob_max_num)
				ob_max_num = randomNumber[i];
		for (int i = pre_ob; i < total; i++) {
			if (randomNumber[i] > ob_max_num) {
				sel_max_num = randomNumber[i];
				break;
			}
			if (i == total - 1)
				sel_max_num = randomNumber[i];
		}
		sel_average_num += sel_max_num;
		printf("sel_max_num: %.2f\n", sel_max_num);

		if (sel_max_num == real_max_num)
			best_times++;
		if (average_num <= sel_max_num)
			better_times++;
		free(randomNumber);
	}

	sel_average_num /= (float)times;
	best_prob = (float)best_times / (float)times * 100.00;
	better_prob = (float)better_times / (float)times * 100.00; 
	printf("-------------------------------------------\n");
	printf("sel_average_num: %.2f\n", sel_average_num);
	printf("times: %d, best_times: %d, better_times: %d\n", times, best_times, better_times);
	printf("best_prob:   %.2f%%\n", best_prob);
	printf("better_prob: %.2f%%\n", better_prob);

	return 0;
}

