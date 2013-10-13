#include <iostream>
#include <random>

int main() {
  const int nrolls = 10000; // number of experiments
  const int nstars = 100;   // maximum number of stars to distribute

  std::default_random_engine generator;
  std::poisson_distribution<int> distribution(3.3 - 3);

  int p[4]={};

  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
	if (number >= 4) number = 3;
    ++p[number];
  }

  std::cout << "poisson_distribution (mean=3.3):" << std::endl;
  for (int i=0; i<4; ++i) {
    std::cout << (i+3) << ": ";
	for (int j = 0; j < (int)((double)p[i] * 0.003); j++) {
		std::cout << "*";
	}
	std::cout << std::endl;
  }

  return 0;
}