<h1 style='text-align: center;'> A. Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A bracket sequence is a string, containing only characters "(", ")", "[" and "]".

A correct bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example, bracket sequences "()[]", "([])" are correct (the resulting expressions are: "(1)+[1]", "([1+1]+1)"), and "](" and "[" are not. The empty string is a correct bracket sequence by definition.

A substring *s*[*l*... *r*] (1 ≤ *l* ≤ *r* ≤ |*s*|) of string *s* = *s*1*s*2... *s*|*s*| (where |*s*| is the length of string *s*) is the string *s**l**s**l* + 1... *s**r*. The empty string is a substring of any string by definition.

You are given a bracket sequence, not necessarily correct. Find its substring which is a correct bracket sequence and contains as many opening square brackets «[» as possible.

## Input

The first and the only line contains the bracket sequence as a string, consisting only of characters "(", ")", "[" and "]". It is guaranteed that the string is non-empty and its length doesn't exceed 105 characters.

## Output

In the first line print a single integer — the number of brackets «[» in the required bracket sequence. In the second line print the optimal sequence. If there are more than one optimal solutions print any of them.

## Examples

## Input


```
([])  

```
## Output


```
1  
([])  

```
## Input


```
(((  

```
## Output


```
0  
  

```


#### tags 

#1700 #data_structures #expression_parsing #implementation 