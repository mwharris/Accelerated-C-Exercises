#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::srand;
using std::time;

//Return a random integer between [0 and n)
int nrand(int n)
{
	int ret;

	//If n doesn't exceed our maximum random number...
	if (n <= RAND_MAX)
	{
		//Separate MY_RAND_MAX into an n-amount of (MY_RAND_MAX/n) sized buckets
		const int bucket_size = RAND_MAX / n;
		//Randomly choose numbers between 0 and RAND_MAX.
		//Divide the random value by the amount of buckets we have in order to determine which bucket it lands.
		//Stop once we get a value that lands in our range of buckets (0 - n)
		do ret = rand() / bucket_size;
		while (ret >= n);
	}
	//If n matches or exceeds our maximum random number...
	else
	{
		//Separate n by MY_RAND_MAX-amount of (n/MY_RAND_MAX) sized buckets called n-buckets.
		//Call ceil() to round up instead of down.
		const int bucket_size = ceil(n / RAND_MAX);
		//Recursively find our random number
		do
		{
			//Randomly choose a bucket within n-buckets
			int bucket = nrand(RAND_MAX);
			//Randomly determine which element in the chosen bucket will be selected
			int remainder = nrand(bucket_size);
			//Translate both numbers back into the real n number
			ret = (bucket * bucket_size) + remainder;
		} while (ret >= n);
	}

	return ret;
}

int main()
{
	// Uncomment this line to see new randomness every time the job is run.
	srand(time(NULL));

	// Generate random numbers within the range [0, n)
	const int n = 999999999;  // try n = 10, and n = 3276700
	const int numbersPerLine = 5;

	// Display the limits
	cout << "n is: " << n << endl;
	cout << "my_rand_max is: " << (RAND_MAX + 1) << endl;

	// Display the randomOutcomes
	for (int i = 0; i != 100; ++i) {
		if (i == 0)
			cout << nrand(n);
		else {
			cout << ", " << nrand(n);

			// start a new line
			if (i != 0 && (i + 1) % numbersPerLine == 0)
				cout << endl;
		}
	}
	return 0;
}

