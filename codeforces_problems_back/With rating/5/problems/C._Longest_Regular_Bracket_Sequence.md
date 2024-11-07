<h1 style='text-align: center;'> C. Longest Regular Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is yet another problem dealing with regular bracket sequences.

We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not. 

You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.

## Input

The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

## Output

Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".

## Examples

## Input


```
)((())))(()())  

```
## Output


```
6 2  

```
## Input


```
))(  

```
## Output


```
0 1  

```


#### tags 

#1900 #constructive_algorithms #data_structures #dp #greedy #sortings #strings 