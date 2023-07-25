#include "main.h"

/**
<<<<<<< HEAD
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
=======
 * get_flags - active number of  flags
 * @format: Formatted string to print arguments
 * Written by Joylene Edited By Tuwei
 * @i: parameter.
>>>>>>> baaf0fc9348c67d2cd4ca3b0a0898630440a7c42
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
<<<<<<< HEAD
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
=======
        /* - + 0 # ' ' */
        
        /* 1 2 4 8  16 */
        
        int j, curr_i;
        int flags = 0;
        const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
>>>>>>> baaf0fc9348c67d2cd4ca3b0a0898630440a7c42

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
