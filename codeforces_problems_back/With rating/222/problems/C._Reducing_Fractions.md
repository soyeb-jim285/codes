<h1 style='text-align: center;'> C. Reducing Fractions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

To confuse the opponents, the Galactic Empire represents fractions in an unusual format. The fractions are represented as two sets of integers. The product of numbers from the first set gives the fraction numerator, the product of numbers from the second set gives the fraction denominator. However, it turned out that the programs that work with fractions in this representations aren't complete, they lack supporting the operation of reducing fractions. Implement this operation and the Empire won't forget you.

## Input

The first input line contains two space-separated integers *n*, *m* (1 ≤ *n*, *m* ≤ 105) that show how many numbers the first set (the numerator) and the second set (the denominator) contain, correspondingly.

The second line contains *n* space-separated integers: *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 107) — the numbers that are multiplied to produce the numerator.

The third line contains *m* space-separated integers: *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ 107) — the numbers that are multiplied to produce the denominator.

## Output

Print the answer to the problem in the form, similar to the form of the input data. The number of values in the sets you print *n**out*, *m**out* must satisfy the inequality 1 ≤ *n**out*, *m**out* ≤ 105, and the actual values in the sets *a**out*, *i* and *b**out*, *i* must satisfy the inequality 1 ≤ *a**out*, *i*, *b**out*, *i* ≤ 107. 

Separate the values in the lines by spaces. The printed fraction must be reduced, that is, there mustn't be such integer *x* (*x* > 1), that the numerator and the denominator of the printed fraction are divisible by *x*. If there are several matching answers, print any of them.

## Examples

## Input


```
3 2  
100 5 2  
50 10  

```
## Output


```
2 3  
2 1  
1 1 1  

```
## Input


```
4 3  
2 5 10 20  
100 1 3  

```
## Output


```
1 1  
20  
3  

```
## Note

In the first test sample the numerator equals 1000, the denominator equals 500. If we reduce fraction 1000/500 by the greatest common divisor of the numerator and the denominator (by 500), we obtain fraction 2/1.

In the second test sample the numerator equals 2000, the denominator equals 300. If we reduce fraction 2000/300 by the greatest common divisor of the numerator and the denominator (by 100), we obtain fraction 20/3.



#### tags 

#1800 #implementation #math #number_theory #sortings 