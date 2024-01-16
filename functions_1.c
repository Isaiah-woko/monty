#include "monty.h"

/**
* isnumber - check if string contian only digit number
* @numbers: the string number
* Return: 1 mean ture 0 is not number
*/

int isnumber(char numbers[])
{
	int i = 0;

	if (numbers[0] == '-')
		i = 1;
	while (numbers[i] != '\0')
	{
		if (!isdigit(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

