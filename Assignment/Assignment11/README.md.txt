
**Assignment 11 Specs**

Use QtConcurrent and the QFuture object to have multiple threads tackle different, computationally heavy functions.

Create 3 functions: 
> A recursive Fibonacci's sequence up using a value passed in to the function 
> An additive series that adds 1/1 + 1/2 + 1/3+...+1/n, where n is passed in 
> An algorithm that finds the prime number at a particular place in the number line.

Send each to their own QFuture object and have them print out incremental results.