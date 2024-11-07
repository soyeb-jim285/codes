<h1 style='text-align: center;'> E. Bash Plays with Functions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bash got tired on his journey to become the greatest Pokemon master. So he decides to take a break and play with functions.

Bash defines a function *f*0(*n*), which denotes the number of ways of factoring *n* into two factors *p* and *q* such that *gcd*(*p*, *q*) = 1. In other words, *f*0(*n*) is the number of ordered pairs of positive integers (*p*, *q*) such that *p*·*q* = *n* and *gcd*(*p*, *q*) = 1.

But Bash felt that it was too easy to calculate this function. So he defined a series of functions, where *f**r* + 1 is defined as:

![](images/b101481fcdac88d9015ae47191122daa3d5b0f7a.png)Where (*u*, *v*) is any ordered pair of positive integers, they need not to be co-prime.

Now Bash wants to know the value of *f**r*(*n*) for different *r* and *n*. Since the value could be huge, he would like to know the value modulo 109 + 7. Help him!

## Input

The first line contains an integer *q* (1 ≤ *q* ≤ 106) — the number of values Bash wants to know.

Each of the next *q* lines contain two integers *r* and *n* (0 ≤ *r* ≤ 106, 1 ≤ *n* ≤ 106), which denote Bash wants to know the value *f**r*(*n*).

## Output

Print *q* integers. For each pair of *r* and *n* given, print *f**r*(*n*) modulo 109 + 7 on a separate line.

## Example

## Input


```
5  
0 30  
1 25  
3 65  
2 5  
4 48  

```
## Output


```
8  
5  
25  
4  
630  

```


#### tags 

#2500 #brute_force #combinatorics #dp #number_theory 