#include "main.h"

/**
 * get_flags - Calculate active flags in a formatted string.
 *
 * This function scans the provided formatted string to find and calculate
 * the active flags that represent various formatting options.
 * Mathew & Joylene
 * @format: The formatted string to search for flags.
 * @index: Pointer to the current index in the format string.
 *
 * Return: An integer representing the active flags (bitmask).
 */
int get_flags(const char *format, int *index)
{
	int j, current_index;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_VALUES[j];
				break;
			}
		}

		if (FLAGS_CHARS[j] == 0)
			break;
	}

	*index = current_index - 1;

	return (flags);
}
