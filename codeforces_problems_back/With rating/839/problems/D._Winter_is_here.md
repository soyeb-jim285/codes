<h1 style='text-align: center;'> D. Winter is here</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Winter is here at the North and the White Walkers are close. John Snow has an army consisting of *n* soldiers. While the rest of the world is fighting for the Iron Throne, he is going to get ready for the attack of the White Walkers.

He has created a method to know how strong his army is. Let the *i*-th soldier’s strength be *a**i*. For some *k* he calls *i*1, *i*2, ..., *i**k* a clan if *i*1 < *i*2 < *i*3 < ... < *i**k* and *gcd*(*a**i*1, *a**i*2, ..., *a**i**k*) > 1 . He calls the strength of that clan *k*·*gcd*(*a**i*1, *a**i*2, ..., *a**i**k*). Then he defines the strength of his army by the sum of strengths of all possible clans.

Your task is to find the strength of his army. As the number may be very large, you have to print it modulo 1000000007 (109 + 7).

Greatest common divisor (gcd) of a sequence of integers is the maximum possible integer so that each element of the sequence is divisible by it.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 200000) — the size of the army.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1000000) — denoting the strengths of his soldiers.

## Output

Print one integer — the strength of John Snow's army modulo 1000000007 (109 + 7).

## Examples

## Input


```
3  
3 3 1  

```
## Output


```
12  

```
## Input


```
4  
2 3 4 6  

```
## Output


```
39  

```
## Note

In the first sample the clans are {1}, {2}, {1, 2} so the answer will be 1·3 + 1·3 + 2·3 = 12



#### tags 

#2200 #combinatorics #dp #math #number_theory 