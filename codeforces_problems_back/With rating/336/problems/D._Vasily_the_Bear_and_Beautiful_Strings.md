<h1 style='text-align: center;'> D. Vasily the Bear and Beautiful Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasily the Bear loves beautiful strings. String *s* is beautiful if it meets the following criteria: 

1. String *s* only consists of characters 0 and 1, at that character 0 must occur in string *s* exactly *n* times, and character 1 must occur exactly *m* times.
2. We can obtain character *g* from string *s* with some (possibly, zero) number of modifications. The character *g* equals either zero or one.

A modification of string with length at least two is the following operation: we replace two last characters from the string by exactly one other character. This character equals one if it replaces two zeros, otherwise it equals zero. For example, one modification transforms string "01010" into string "0100", two modifications transform it to "011". It is forbidden to modify a string with length less than two.

Help the Bear, count the number of beautiful strings. As the number of beautiful strings can be rather large, print the remainder after dividing the number by 1000000007 (109 + 7). 

## Input

The first line of the input contains three space-separated integers *n*, *m*, *g* (0 ≤ *n*, *m* ≤ 105, *n* + *m* ≥ 1, 0 ≤ *g* ≤ 1).

## Output

Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
1 1 0  

```
## Output


```
2  

```
## Input


```
2 2 0  

```
## Output


```
4  

```
## Input


```
1 1 1  

```
## Output


```
0  

```
## Note

In the first sample the beautiful strings are: "01", "10".

In the second sample the beautiful strings are: "0011", "1001", "1010", "1100".

In the third sample there are no beautiful strings.



#### tags 

#2100 #combinatorics #math #number_theory 