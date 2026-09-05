#ifndef ALGOCPP_SPARSETABLE_H
#define ALGOCPP_SPARSETABLE_H

#include <vector>
using namespace std;

/*
A data structure useful for running fast range query.
Provided the function used are associative and elements are not updatable.
Additionally for overlap friendly function range query is O(1).

Initializing:
TC: O(n*lg(n))
SC: O(n*lg(n))

Range Query:
SC: O(1)
TC: O(1)     -> for overlap friendly functions (like min, max, gcd)
    O(lg(n)) -> for just associative functions (like add, multiply, etc)
*/
class SparseTable {
	// length of the vector
	int n;

	// log2 lookup table
	vector<int> log2;

	// max power of 2
	int p;

	// sparse table
	vector<vector<int>> dp;
public:
	SparseTable(const vector<int> &v) {
		// initialize size
		n = v.size();

		// initialize the log2 lookup table
		log2 = vector<int>(n+1, 0);
		for (int i = 2; i <= n; i++) {
			log2[i] = log2[i/2] + 1;
		}
		p = log2[n];

		// initialize the sparse table
		dp = vector<vector<int>>(p+1, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			dp[0][i] = v[i];
		}

		// create the sparse table
		for (int i = 1; i <= p; i++) {
			for (int j = 0; j + (1 << i) <= n; j++) {
				auto left = dp[i-1][j];
				auto right = dp[i-1][j+(1<<(i-1))];
				dp[i][j] = min(left, right);
			}
		}
	}

	int query(int left, int right) {
		auto len = right - left + 1;
		auto k = log2[len];
		return min(dp[k][left], dp[k][right - (1<<k) + 1]);
	}
};

#endif // ALGOCPP_SPARSETABLE_H

