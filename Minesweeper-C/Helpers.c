#include <stdio.h>

/// <summary>
/// Return the Square of the given x value
/// </summary>
/// <returns></returns>
int Square(int x) {
	return x * x;
}

void Repeat(char c, int count) {
	for (int i = 0; i < count; i++)
	{
		printf("%c", c);
	}
}