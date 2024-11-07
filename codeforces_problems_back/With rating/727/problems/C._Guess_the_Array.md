<h1 style='text-align: center;'> C. Guess the Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. You should use flush operation after each printed line. For example, in C++ you should use fflush(stdout), in Java you should use System.out.flush(), and in Pascal — flush(output).

In this problem you should guess an array *a* which is unknown for you. The only information you have initially is the length *n* of the array *a*.

The only allowed action is to ask the sum of two elements by their indices. Formally, you can print two indices *i* and *j* (the indices should be distinct). Then your program should read the response: the single integer equals to *a**i* + *a**j*.

It is easy to prove that it is always possible to guess the array using at most *n* requests.

Write a program that will guess the array *a* by making at most *n* requests.

## Interaction

In each test your program should guess a single array.

The input starts with a line containing integer *n* (3 ≤ *n* ≤ 5000) — the length of the array. Your program should read it at first.

After that your program should print to the standard output the requests about the sum of two elements or inform that the array is guessed.

* In case your program is making a request to ask the sum of two elements, it should print line in the format "? i j" (*i* and *j* are distinct integers between 1 and *n*), where *i* and *j* are indices in the array *a*.
* In case your program informs that the array is guessed, it should print line in the format "! *a*1 *a*2 ... *a**n*" (it is guaranteed that all *a**i* are positive integers not exceeding 105), where *a**i* is the *i*-th element of the array *a*.

The response on a request is a single integer equal to *a**i* + *a**j*, printed on a separate line.

Your program can do at most *n* requests. ## Note

 that the final line «! *a*1 *a*2 ... *a**n*» is not counted as a request.

Do not forget about flush operation after each printed line.

After you program prints the guessed array, it should terminate normally.

## Example

Input
```
5  
   
9  
   
7  
   
9  
   
11  
   
6  
 
```
Output
```
   
? 1 5  
   
? 2 3  
   
? 4 1  
   
? 5 2  
   
? 3 4  
   
! 4 6 1 5 5
```
## Note

The format of a test to make a hack is:

* The first line contains an integer number *n* (3 ≤ *n* ≤ 5000) — the length of the array.
* The second line contains *n* numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105) — the elements of the array to guess.


#### tags 

#1400 #constructive_algorithms #interactive #math 