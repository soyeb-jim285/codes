<h1 style='text-align: center;'> E. Alien DNA</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Professor Bajtocy is conducting experiments on alien DNA. He has discovered that it is subject to repetitive mutations — each mutation happens in the same way: some continuous subsequence of the alien DNA becomes active, copies itself, the copy gets mangled and inserts itself right after the original subsequence. The mangled copy of the activated continuous subsequence is formed by first joining all the elements at the even positions in that subsequence, and then joining all the elements at the odd ones at the end. That is, if the activated subsequence consists of 11 elements and represented as *s*1*s*2... *s*11, its mangled copy is *s*2*s*4*s*6*s*8*s*10*s*1*s*3*s*5*s*7*s*9*s*11.

For example, if the original sequence was "ACTGG" and the mutation happened on the segment [2, 4] (that is the activated subsequence is "CTG"), the mutated DNA is: "ACTGTCGG". The mangled copy of the activated subsequence is marked with bold font.

Professor Bajtocy has written down the original DNA sequence and the mutations that sequentially happened to it, and he now asks you to recover the first *k* elements of the DNA sequence after all the mutations.

## Input

The first line of input contains the original DNA sequence, consisting only of letters "A", "C", "T" and "G" and not exceeding 3·106 in length. 

The second line contains a single integer *k* (1 ≤ *k* ≤ 3·106).

The third line contains a single integer *n* (0 ≤ *n* ≤ 5000) — the number of mutations. The next *n* lines describe the mutations in chronological order — each mutation is described by two numbers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ 109), meaning that the continuous subsequence [*l**i*, *r**i*] has become active and cloned itself, joining itself with the mangled copy. 

It is guaranteed that the input data is correct, that is, no mutation acts on non-existing elements of the DNA sequence, and the resulting DNA sequence has at least *k* elements.

Assume that the DNA elements are indexed starting from 1 and that the notation [*l*, *r*] meaning the continuous subsequence of DNA sequence that consists of *r* - *l* + 1 elements starting at the *l*-th DNA sequence element and ending at the *r*-th DNA sequence element.

## Output

## Output

 a single line, containing the first *k* letters of the mutated DNA sequence.

## Examples

## Input


```
GAGA  
4  
0  

```
## Output


```
GAGA  

```
## Input


```
ACGTACGT  
16  
2  
1 2  
2 8  

```
## Output


```
ACCAGTACCGACATCG  

```
## Note

In the second example, after the first mutation the sequence is "ACCAGTACGT". After the second mutation it's "ACCAGTACCGACATCGT".



#### tags 

#2800 #data_structures #dsu #trees 