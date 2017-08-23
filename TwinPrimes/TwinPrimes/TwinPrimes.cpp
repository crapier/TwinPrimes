// TwinPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// determines probability of primality test 25 is "magic" number in documentation examples
	int iterations = 25;

	// count of twin primes
	mpz_class count(0);

	// file to write data points too
	FILE* output_file;
	output_file = fopen("output.txt", "w");

	// Start with 3
	mpz_class a(3);

	// end at max
	mpz_class max("1000000000");

	time_t timer = clock();

	while (a < max) {

		int prime_test = mpz_probab_prime_p(a.get_mpz_t(), iterations);

		if (prime_test == 1 || prime_test == 2) {

			mpz_class b = a + 90;
			int prime_test = mpz_probab_prime_p(b.get_mpz_t(), iterations);

			if (prime_test == 1 || prime_test == 2) {
				gmp_fprintf(output_file, "%Zd\t%Zd\n", a, count);
				count++;
			}
			
		}

		a += 2;
	}

	timer = clock() - timer;

	printf("Time taken: %f sec\n", timer / (double)CLOCKS_PER_SEC);

	gmp_printf("Probable number of twin prime pairs less than %Zd: %Zd\n", max, count);

	return 0;
}

