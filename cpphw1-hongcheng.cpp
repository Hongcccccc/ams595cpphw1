#include <iostream>
#include <vector>

// Q1: MATLAB to C++
void transCode() {
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    switch (n) {
        case -1:
            std::cout << "negative one" << std::endl;
            break;
        case 0:
            std::cout << "zero" << std::endl;
            break;
        case 1:
            std::cout << "positive one" << std::endl;
            break;
        default:
            std::cout << "other value" << std::endl;
            break;
    }
}

// Q2: print a C++ vector of integers
void print_vector(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Q3: Fibonacci sequence
void FibSeq() {
    int first = 1;
    int second = 2;

    std::cout << first << ", " << second << ", ";

    while (second <= 4000000) {
        int next = first + second;
        if (next <= 4000000) {
            std::cout << next;
            if (next + second <= 4000000) {
                std::cout << ", ";
            }
        }

        first = second;
        second = next;
    }

    std::cout << std::endl;
}

// Q4a: Check prime
bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Q4b: factorize
std::vector<int> factorize(int n) {
    std::vector<int> factors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

// Q4c: prime factorization
std::vector<int> prime_factorize(int n) {
    std::vector<int> primeFactors;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0 && isprime(i)) {
            primeFactors.push_back(i);
            n /= i;
        }
    }
    return primeFactors;
}

// Q5: calculate binomial coefficient
int binCoef(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binCoef(n - 1, k - 1) + binCoef(n - 1, k);
    }
}
//print the first n rows of Pascal's Triangle
void PasTriangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << binCoef(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void runTestCases() {


    // Q2:
       std::vector<int> testVector = {1, 2, 3, 4, 5};
       print_vector(testVector);

    // Q3:
    FibSeq();
    
    // Q4a:
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';

    // Q4b:
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));

    // Q4c:
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));

    // Q5:
    PasTriangle(5);

}

int main() {
    runTestCases();

    return 0;
}
