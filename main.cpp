#include <iostream>
#include <vector>
#include <ctime> 
#include <cmath> 
#include <chrono>


int moreefficient_prime(int N) {
	if (N == 1) return 2;

	std::vector<int>primeList;
	primeList.reserve(N);
	primeList.push_back(2);
	int numfound = 1;
	int i = 3;

	while (numfound < N) {
		bool isPrime = true;
		int square = static_cast<int>(sqrt(i)) + 1;

		for (int factor : primeList) {
			if (factor >= square) break;
			if (i % factor == 0) {
				isPrime = false;
				break;
			}	
		}

		if (isPrime) {
			primeList.push_back(i);
			numfound++;
		}
		i += 2;
	}	

	return primeList.back();

}
  




int main() {

	int exp;
	std::cout << "Enter exponent to 10^"; std::cin >> exp;

	int N = pow(10, exp);


	auto start = std::chrono::high_resolution_clock::now();
	std::ios_base::sync_with_stdio(false);

	int prime = moreefficient_prime(N);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_taken = end - start;

	std::cout << "The " << N << "th prime number is: " << prime << std::endl;
	std::cout << "Time taken: " << time_taken.count() << " seconds." << std::endl;
}
