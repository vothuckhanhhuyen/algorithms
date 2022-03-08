// A naive recursive C++ program to
// find number of non-negative solutions
// for a given linear equation
#include<bits/stdc++.h>
using namespace std;

// Recursive function that returns
// count of solutions for given rhs
// value and coefficients coeff[start..end]
int countSol(int coeff[], int start,
			int end, int rhs)
{
	// Base case
	if (rhs == 0)
	return 1;

	// Initialize count
	// of solutions
	int result = 0;

	// One by subtract all smaller or
	// equal coefficiants and recur
	for (int i = start; i <= end; i++)
	if (coeff[i] <= rhs)
		result += countSol(coeff, i, end,
						rhs - coeff[i]);

	return result;
}

// Driver Code
int main()
{
	int coeff[] = {5, 7, 8, 2};
	int rhs = 38;
	int n = sizeof(coeff) / sizeof(coeff[0]);
	cout << countSol(coeff, 0, n - 1, rhs);
	return 0;
}
