<h1 style='text-align: center;'> E. Polycarpus the Safecracker</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus has *t* safes. The password for each safe is a square matrix consisting of decimal digits '0' ... '9' (the sizes of passwords to the safes may vary). Alas, Polycarpus has forgotten all passwords, so now he has to restore them.

Polycarpus enjoys prime numbers, so when he chose the matrix passwords, he wrote a prime number in each row of each matrix. To his surprise, he found that all the matrices turned out to be symmetrical (that is, they remain the same after transposition). Now, years later, Polycarp was irritated to find out that he remembers only the prime numbers *p**i*, written in the first lines of the password matrices.

For each safe find the number of matrices which can be passwords to it.

The number of digits in *p**i* determines the number of rows and columns of the *i*-th matrix. One prime number can occur in several rows of the password matrix or in several matrices. The prime numbers that are written not in the first row of the matrix may have leading zeros.

## Input

The first line of the input contains an integer *t* (1 ≤ *t* ≤ 30) — the number of safes. Next *t* lines contain integers *p**i* (10 ≤ *p**i* ≤ 99999), *p**i* is a prime number written in the first row of the password matrix for the *i*-th safe. All *p**i*'s are written without leading zeros.

## Output

Print *t* numbers, the *i*-th of them should be the number of matrices that can be a password to the *i*-th safe. Print the numbers on separate lines.

## Examples

## Input


```
4  
11  
239  
401  
9001  

```
## Output


```
4  
28  
61  
2834  

```
## Note

Here is a possible password matrix for the second safe: 


```
  
239  
307  
977  

```
Here is a possible password matrix for the fourth safe: 


```
  
9001  
0002  
0002  
1223   

```


#### tags 

#2500 #brute_force #dp 