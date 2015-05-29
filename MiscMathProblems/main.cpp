// ProjectEulerProblems.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

void findSumOf3and5Multiple(){
	bool number[1000];
	for (int i = 0; i < 1000; i++){
		number[i] = false;
	}
	int sum = 0;
	int result = 0;
	int i = 1;
	while (sum < 1000){
		number[i * 3] = true;
		number[i * 5] = true;
		sum = 3 * i;
		i++;
	}

	for (int i = 0; i < 1000; i++){
		if (number[i]){
			result += i;
		}
	}
	cout << "the sum of all the multiples of 3 or 5 below 1000 : " << result << endl;

}

bool isEven(int number){
	if (number & 1){
		//cout << "odd" << endl;
		return false;
	}
	else{
		//cout << "even" << endl;
		return true;
	}
}

void findSumOfEvenFibonacciNumbers(){
	int num1 = 1;
	int num2 = 2;
	int sum = 0;
	int result = 2;
	int MAX_NUMBER = 4000000;

	while (num2 < MAX_NUMBER){
		sum = num1 + num2;

		if (isEven(sum))
		{
			cout << " + " << sum;
			result += sum;
		}

		num1 = num2;
		num2 = sum;
	}

	cout << " considering the terms in the Fibonacci sequence whose values do not exceed " << MAX_NUMBER << " the sum of the even-valued terms : " << result << endl;
}

int sumFiboNumber(int num){
	if (num == 0) return 0;
	if (num == 1) return 1;

	int result = sumFiboNumber(num - 2) + sumFiboNumber(num - 1);

	return result;
}

int reverseNumber(int number){
	int result = 0;

	while (number > 0){
		result = 10 * result + number % 10;
		number /= 10;
	}
	return result;
}

void reverseNumberAndTest(){
	cout << "reverse 53 : " << reverseNumber(53) << endl;
	cout << "reverse 253 : " << reverseNumber(253) << endl;
	cout << "reverse 665 : " << reverseNumber(665) << endl;

}

bool isNumberPalindrome(int num){
	//99 999
	int reverseNum = reverseNumber(num);
	if (num == reverseNum)
		return true;
	else
		return false;

}

void isNumberPalindromeAndTest(){

	if (isNumberPalindrome(1001)){
		cout << "GOOD : 1001 is a palindrome" << endl;
	}
	else{
		cout << "ERROR : 1001 is a palindrome" << endl;
	}

	if (isNumberPalindrome(2222)){
		cout << "GOOD : 2222 is a palindrome" << endl;
	}
	else{
		cout << "ERROR : 2222 is  a palindrome" << endl;
	}

	if (isNumberPalindrome(1000)){
		cout << "ERROR : 1000 is not a palindrome" << endl;
	}
	else{
		cout << "GOOD : 1000 is not a palindrome" << endl;
	}
}

void findLasgestPalindromeProd3DigitsNum(){
	int max = 0;
	for (int num1 = 999; num1 > 100; num1--){

		for (int num2 = 999; num2 > 499; num2--){
			int tot = num1*num2;
			if (isNumberPalindrome(tot)){
				if (tot > max)
					max = tot;
			}
		}
	}
	cout << "largest palindrome made from the product of two 3-digit numbers is : " << max << endl;
}

vector<long long> getPrimeNumbersUpTo(long long max_number){
	vector<long long> primeNum;

	primeNum.push_back(2);
	if (max_number == 2) return primeNum;

	primeNum.push_back(5);
	if (max_number == 5) return primeNum;

	for (long long j = 6; j <= max_number; j++){
		if (fmod(j, 2) && fmod(j, 5)) {
			vector<long long>::iterator it = primeNum.begin();
			bool isPrimeNum = true;
			while (it != primeNum.end() && isPrimeNum){
				if (fmod(j, *it) == 0){
					isPrimeNum = false;
					break;
				}
				it++;
			}
			if (isPrimeNum) {
				primeNum.push_back(j);
			}
		}
	}

	size_t size = primeNum.size();
	cout << "Found " << size << " prime numbers for " << max_number << endl;
	/*for (int i = 0; i < size; i++){
	cout << primeNum.at(i) << " ";
	}*/
	return primeNum;
}


bool isPrimeNumber(long long number){
	for (long long i = number - 1; i > 1; i--){
		if ((number% i) == 0)
			return false;
	}
	return true;
}


bool isPrimeNumberOptimized(long long number){
	if (!(number & 1)) return false; //if even number, this is not a primeNum

	bool remainder1 = static_cast<bool>((number - 1) % 6);
	bool remainder2 = static_cast<bool>((number + 1) % 6);
	if ((remainder1 && remainder2)) return false; //all prime number can be written 6k +- 1

	for (long long i = sqrt(number); i > 1; i--){
		if (!(i % 2) || !(i % 5))break;
		if ((number% i) == 0)
			return false;
	}
	return true;

}

long long getNextPrimeNumberOptimized(long long number){
	bool foundNumber = false;
	if (number < 2) return  2;
	if (number == 2) return  3;

	while (!foundNumber){
		number++;

		while (!(number & 1) || !(number % 5)){
			if (number == 2 || number == 5) return number;
			number++;
		}
		foundNumber = isPrimeNumberOptimized(number);
		//foundNumber = isPrimeNumber(number);
	}
	return number;
}
long long getNextPrimeNumber(long long number){
	bool foundNumber = false;
	if (number < 2) return  2;
	if (number == 2) return  3;

	while (!foundNumber){
		number++;

		while (!(number % 2) || !(number % 5)){
			if (number == 2 || number == 5) return number;
			number++;
		}
		//foundNumber = isPrimeNumberOptimized(number);
		foundNumber = isPrimeNumber(number);
	}
	return number;
}

long long getLargestPrimeFactor(long long number){
	long long primeFactor = 2;
	while (number != 1){
		while (number% primeFactor){
			primeFactor = getNextPrimeNumber(primeFactor);
		}
		number /= primeFactor;
	}
	return primeFactor;
}

long long getSmallestEvenlyDivBy1to(int max){
	long long primeFactor = 2;
	long long sum = 1;
	while (primeFactor <= max){
		sum *= primeFactor;
		primeFactor = getNextPrimeNumber(primeFactor);
	}
	bool found = false;
	while (!found){
		for (int i = 3; i <= max; i++){
			if (sum%i) {
				found = false;
				break;
			}
			else
				found = true;
		}
		if (!found)
			sum += 5;
	}

	return sum;

}

int findDifferenceOfSumOfSquares(int max){
	int result = 0;
	for (int i = 1; i <= max; i++){
		for (int j = i + 1; j <= max; j++){
			result += i*j;
			//cout << i << " * " << j << " + ";
		}
	}
	result *= 2;
	return result;
}

long long getPrimeNumber(int index){
	long long primeNum = 2;
	for (int i = 1; i < index; i++){
		primeNum = getNextPrimeNumber(primeNum);
	}

	return primeNum;
}


long long getPrimeNumberTest(int index){
	long long primeNum = 2;
	for (int i = 1; i < index; i++){
		primeNum = getNextPrimeNumberOptimized(primeNum);
	}

	return primeNum;
}

void pythagoreanTriplet(){
	//a + b + c = 1000
	int a = 1, b = 2;
	float c = 3;
	bool found = false;
	for (a = 1; a < 333; a++){
		if (found)break;
		for (b = a + 1; b < 499; b++){
			c = sqrtf((float)(a*a + b*b));
			bool testEntier = static_cast<int>(c) == c;
			bool testGrandC = (c > b);
			bool testadd1000 = ((a + b + c) == 1000);
			if (testEntier && testGrandC && testadd1000){ //test si "c" est un entier
				found = true;
				break;
			}
		}
	}
	a -= 1;
	if (found)
		cout << "one Pythagorean triplet for which a + b + c = 1000 is " << a << " " << b << " " << c << endl;
	else
		cout << "ERROR" << endl;

}

int matrix[20][20] = {};

long long sumOfPrimeNumBelow(long long max_number){
	long long sum = 0;
	long long prime_num = 2;

	while (prime_num < max_number){
		sum += prime_num;
		prime_num = getNextPrimeNumberOptimized(prime_num);
	}

	return sum;
}

int main(int argc, char* argv[])
{
	//findSumOf3and5Multiple();
	//findSumOfEvenFibonacciNumbers();
	//isNumberPalindromeAndTest();
	//reverseNumberAndTest();
	//findLasgestPalindromeProd3DigitsNum();
	//getPrimeNumbersUpTo(13195);
	/*long long number = 13195;
	cout << "getLargestPrimeFactor for 13195 is : " << getLargestPrimeFactor(number) << endl;
	long long long_number = 600851475143;
	cout << "getLargestPrimeFactor for " << long_number << " is : " << getLargestPrimeFactor(long_number) << endl;
	*/
	/*long long num = 13;
	cout << "next prime number 13 is : " << getNextPrimeNumber(num) << endl;*/
	//int max = 20;
	//cout << "the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is : " << getSmallestEvenlyDivBy1to(max) << endl;
	//cout << "findDifferenceOfSumOfSquares numbers up to 10 is :" << findDifferenceOfSumOfSquares(100) << endl;
	/*cout << "the 6 st prime is : " << getPrimeNumber(6) << endl;
	int num = 10001;
	cout << "the " << num << "st prime is : " << getPrimeNumberTest(num) << endl;
	cout << "the 6 st prime is : " << getPrimeNumberTest(6) << endl;*/

	//pythagoreanTriplet();
	long long big_number = 2000000;
	cout << "The sum of the primes below " << big_number << " is : " << sumOfPrimeNumBelow(big_number) << endl;
	system("pause");
	return 0;
}
