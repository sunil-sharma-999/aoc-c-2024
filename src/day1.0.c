
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/string.c"

int compare(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int main(void)
{
	FILE *file = fopen("data/day1.0.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(1);
	}

	int *nums1 = NULL;
	int *nums2 = NULL;
	char *line;
	int i = 0;
	int distance = 0;

	while ((line = readline(file)) != NULL)
	{
		int num1, num2;
		sscanf(line, "%d%d", &num1, &num2);

		nums1 = realloc(nums1, (size_t)(i + 1) * sizeof(int));
		nums2 = realloc(nums2, (size_t)(i + 1) * sizeof(int));

		if (nums1 == NULL || nums2 == NULL)
		{
			perror("Error reallocating memory");
			exit(1);
		}

		nums1[i] = num1;
		nums2[i] = num2;
		i++;
		free(line);
	}
	qsort(nums1, (size_t)i, sizeof(int), compare);
	qsort(nums2, (size_t)i, sizeof(int), compare);
	for (int j = 0; j < i; j++)
	{
		distance += abs(nums1[j] - nums2[j]);
	}
	printf("%d\n", distance);

	// clean up
	free(nums1);
	free(nums2);
	fclose(file);
	return 0;
}
