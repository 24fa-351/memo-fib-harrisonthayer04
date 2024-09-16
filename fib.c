/*
Name: Harrison Thayer
Email: harrisonthayer@csu.fullerton.edu
Class: CPSC 351 Section 13
Date Last Modified: 9/5/2024 

Program description:
   Calculates fibonacci numbers. User has the option to calculate 
   iteratively or recursively.

*/


#include <stdio.h> // fopen()
#include <stdlib.h> // atoi()
#include <string.h>  // strcmp()

unsigned long long int *memoizedFibonacciNumbersArray;

/*
 Function fibRecursivelyWrapper takes in 1
 integer, and calculates the Nth fibonacci
 number recursively.
*/

unsigned long long int fibRecursivelyWrapper(unsigned long long int number){
   if(number < 1){
      return 0;
   }
   if(number == 1){
      return 1;
   }
   return fibRecursivelyWrapper(number-1) + fibRecursivelyWrapper(number-2);
}

/*
 Function fibRecursivelyWrapper takes in 1
 integer, and calculates the Nth fibonacci
 number recursively using memoization to speed
 up the process.
*/

unsigned long long int fibRecursively(unsigned long long int number){
   if (number < 1) {
      return 0;
   }
   if (memoizedFibonacciNumbersArray[number] != -1){
      return memoizedFibonacciNumbersArray[number]; 
   }
   memoizedFibonacciNumbersArray[number] = fibRecursivelyWrapper(number-1) + fibRecursivelyWrapper(number-2);
   return memoizedFibonacciNumbersArray[number];
}

/*
 Function fibIterativelyWrapper takes in 1
 integer, and calculates the Nth fibonacci
 number iteratively.
*/

unsigned long long int fibIterativelyWrapper(int number){
   // Calculate the actual Fibonacci number,
   // final answer will be stored in "fibonacci" when the loop finishes.
   unsigned long long int nMinusTwo = 0;
   unsigned long long int nMinusOne = 1; 
   unsigned long long int fibonacci;
    for (int index = 0; index < number ; index++) {
        fibonacci = nMinusTwo + nMinusOne; 
        nMinusTwo = nMinusOne;
        nMinusOne = fibonacci;
    }
   return fibonacci;
}

/*
 Function fibIteratively takes in 1
 integer, and calculates the Nth fibonacci
 number iteratively using memoization.
*/

unsigned long long int fibIteratively(int number){
   if (memoizedFibonacciNumbersArray[number] != -1){
      return memoizedFibonacciNumbersArray[number];
   }
   return fibIterativelyWrapper(number);
}

int main(int argc, char *argv[]) {
   int inputNumber = atoi(argv[1]);
   char *rORi = argv[2];
   // Read the number in the file, calculate
   // what fib number we will be going to...
   // Initialize the memoized array
   memoizedFibonacciNumbersArray = (unsigned long long int*) malloc((inputNumber+1) * sizeof(unsigned long long int)); 
   for (int index = 0; index <= inputNumber; index++){
      memoizedFibonacciNumbersArray[index] = -1;
   }

   memoizedFibonacciNumbersArray[0] = 1;
   memoizedFibonacciNumbersArray[1] = 1; 

   unsigned long long int computedFibNumber;
   if(strcmp(rORi,"i") == 0){
      computedFibNumber = fibIteratively(inputNumber-2);
      printf("%llu\n", computedFibNumber);
   }
   if(strcmp(rORi,"r") == 0){
      computedFibNumber = fibRecursively(inputNumber-1);
      printf("%llu\n", computedFibNumber);
   }
   return computedFibNumber;
}
