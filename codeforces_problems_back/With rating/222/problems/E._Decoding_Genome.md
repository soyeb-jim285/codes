<h1 style='text-align: center;'> E. Decoding Genome</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently a top secret mission to Mars has taken place. As a result, scientists managed to obtain some information about the Martian DNA. Now we know that any Martian DNA contains at most *m* different nucleotides, numbered from 1 to *m*. Special characteristics of the Martian DNA prevent some nucleotide pairs from following consecutively in this chain. For example, if the nucleotide 1 and nucleotide 2 can not follow consecutively in the Martian DNA, then the chain of nucleotides [1, 2] is not a valid chain of Martian DNA, but the chain of nucleotides [2, 1] can be a valid chain (if there is no corresponding restriction). The number of nucleotide pairs that can't follow in the DNA chain consecutively, is *k*. 

The needs of gene research required information about the quantity of correct *n*-long chains of the Martian DNA. Your task is to write a program that will calculate this value.

## Input

The first line contains three space-separated integers *n*, *m*, *k* (1 ≤ *n* ≤ 1015, 1 ≤ *m* ≤ 52, 0 ≤ *k* ≤ *m*2).

Next *k* lines contain two characters each, without a space between them, representing a forbidden nucleotide pair. The first character represents the first nucleotide in the forbidden pair, the second character represents the second nucleotide.

The nucleotides with assigned numbers from 1 to 26 are represented by English alphabet letters from "a" to "z" (1 is an "a", 2 is a "b", ..., 26 is a "z"). Nucleotides with assigned numbers from 27 to 52 are represented by English alphabet letters from "A" to "Z" (27 is an "A", 28 is a "B", ..., 52 is a "Z").

It is guaranteed that each forbidden pair occurs at most once in the input. It is guaranteed that nucleotide's numbers in all forbidden pairs cannot be more than *m*. ## Note

 that order is important in nucleotide pairs.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Output

Print a single integer — the sought number modulo 1000000007 (109 + 7).

## Examples

## Input


```
3 3 2  
ab  
ba  

```
## Output


```
17  

```
## Input


```
3 3 0  

```
## Output


```
27  

```
## Input


```
2 1 1  
aa  

```
## Output


```
0  

```
## Note

In the second test case all possible three-nucleotide DNAs are permitted. Each nucleotide can take one of three values, thus in total there are 27 distinct three nucleotide DNAs.

In the third test sample we cannot make any DNA of two nucleotides — the only possible nucleotide "a" cannot occur two times consecutively.



#### tags 

#1900 #dp #matrices 