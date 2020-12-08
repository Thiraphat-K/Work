// #include<stdio.h>
// #include<string.h>

// unsigned Faculty(unsigned n)
// {
//   return n ? n*Faculty(n-1) : 1;
// }

// char* PermN(unsigned target)
// {
//   const char cdigits[] = "0123456789 ";
//   const char cnumber[] = "           ";

//   static char digits[] = "           ";
//   static char number[] = "           ";

//   strcpy(digits, cdigits);  //init source buffer
//   strcpy(number, cnumber);  //init destination buffer

//   target--;                 

//   unsigned n=10;
//   unsigned ndigits = 0;

//   do
//   {
//     unsigned fn = Faculty(n-1);
//     unsigned i = target/fn;       //calculate index from source buffer
//     target -= i*fn;               //adjust target for next loop

//     //put calculated digit in destination buffer
//     number[ndigits++] = digits[i];
    
//     //remove digit from source buffer
//     for(unsigned r=i; r<n; r++)
//     {
//       digits[r] = digits[r+1];
//     }    
//   }while(--n);
//   return number;
// }

// int main()
// {
//   const unsigned target=1000000;
//   printf("\nperm(%7d) = %s", target, PermN(target));
// }

#include <stdio.h>

// Not more than 21 (because of long long int borders)
#define OBJECTS_COUNT 10

const long long int REQUIRED_OBJECT = 1e6;

// Elements: 0 1 2 … 8 9 A B …

long long int factorial(int n)
{
	long long int res = 1;
	for (int i = n; i > 1; i--)
	{
		res *= i;
	}
	return res;
}

int main(void)
{
	long long int stage = factorial(OBJECTS_COUNT - 1); // The length of current piece
	if (stage <= (REQUIRED_OBJECT - 1) / OBJECTS_COUNT)
	// is equal to "OBJECTS_COUNT! < REQUIRED_OBJECT"
	{
		printf("Error: REQUIRED_OBJECT cannot be more than factorial of OBJECTS_COUNT.");
		return 0;
	}
	long long int number = REQUIRED_OBJECT - 1; // Required object's number in the current piece
	int result[OBJECTS_COUNT]; // The result (reversed)
	int locked[OBJECTS_COUNT] = { 0 }; // The locked objects
	
	for (int i = OBJECTS_COUNT - 1; i > 0; i--)
	{
		// Er… it is difficult to explain
		// (especially in English, because it isn't my native language)
		// I hope you'll understand what is happening in this loop
		int digit = number / stage;
		int j;
		for (j = 0; digit >= 0 && j < OBJECTS_COUNT; j++)
		{
			if (!locked[j])
			{
				digit--;
			}
		}
		j--;

		result[i] = j;
		locked[j] = 1;

		number %= stage;
		stage /= i;
	}

	// The last object
	for (int i = 0; i < OBJECTS_COUNT; i++)
	{
		if (!locked[i])
		{
			result[0] = i;
			break;
		}
	}

	// Print result
	for (int i = OBJECTS_COUNT - 1; i >= 0; i--)
	{
		if (result[i] < 10)
		{
			printf("%d", result[i]);
		}
		else
		{
			printf("%c", result[i] + 55);
			// 55 is ['A' code - 10]
		}
	}

	return 0;
}