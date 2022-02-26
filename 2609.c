#include <stdio.h>

int gcd(int a, int b)
{
	int r;
	while ( 1 )
	{
		r = a % b;
		if ( r == 0 )
		{
			break;
		}
		a = b;
		b = r;
	}
	return b;
}

int main(void)
{
	int a, b, temp, G, L;
	scanf("%d %d", &a, &b);
	
	if ( a < b )
	{
		temp = a;
		a = b;
		b = temp;
	}
	
	// A * B = G * L  (소인수 곱으로 생각해라!) 
	G = gcd(a, b);
	L = a * b / G;
	
	printf("%d\n", G);
	printf("%d", L);
	
	return 0;
}
