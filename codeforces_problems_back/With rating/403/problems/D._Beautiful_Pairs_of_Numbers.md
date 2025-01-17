<h1 style='text-align: center;'> D. Beautiful Pairs of Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The sequence of integer pairs (*a*1, *b*1), (*a*2, *b*2), ..., (*a**k*, *b**k*) is beautiful, if the following statements are fulfilled: 

* 1 ≤ *a*1 ≤ *b*1 < *a*2 ≤ *b*2 < ... < *a**k* ≤ *b**k* ≤ *n*, where *n* is a given positive integer;
* all numbers *b*1 - *a*1, *b*2 - *a*2, ..., *b**k* - *a**k* are distinct.

For the given number *n* find the number of beautiful sequences of length *k*. As the answer can be rather large, print the remainder after dividing it by 1000000007 (109 + 7).

## Input

The first line contains integer *t* (1 ≤ *t* ≤  2·105) — the number of the test data.

Each of the next *t* lines contains two integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 1000).

## Output

For each test from the input print the answer to the problem modulo 1000000007 (109 + 7). Print the answers to the tests in the order in which the tests are given in the input.

## Examples

## Input


```
6  
1 1  
2 1  
2 2  
3 1  
3 2  
3 3  

```
## Output


```
1  
3  
0  
6  
2  
0  

```
## Note

In the first test sample there is exactly one beautiful sequence: (1, 1).

In the second test sample, the following sequences are beautiful: 

* (1, 1);
* (1, 2);
* (2, 2).

In the fourth test sample, the following sequences are beautiful: 

* (1, 1);
* (1, 2);
* (1, 3);
* (2, 2);
* (2, 3);
* (3, 3).

In the fifth test sample, the following sequences are beautiful: 

* (1, 1), (2, 3);
* (1, 2), (3, 3).

In the third and sixth samples, there are no beautiful sequences.



#### tags 

#2300 #combinatorics #dp 