<h1 style='text-align: center;'> D. Hyper String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Paul Erdős's prediction came true. Finally an alien force landed on the Earth. In contrary to our expectation they didn't asked the humans to compute the value of a Ramsey number (maybe they had solved it themselves). They asked another question which seemed as hard as calculating Ramsey numbers. Aliens threatened that if humans don't solve this problem in less than 2 hours they will destroy the Earth. 

Before telling the problem they introduced the concept of Hyper Strings. A Hyper String is made by concatenation of some base strings. Suppose you are given a list of base strings *b*1, *b*2, ..., *b**n*. Now the Hyper String made from indices list *i*1, *i*2, ..., *i**m* is concatenation of base strings *b**i*1, *b**i*2, ..., *b**i**m*. A Hyper String can be very large and doing operations on it is very costly for computers. 

The aliens asked humans to compute the length of the longest common sub-sequence of a Hyper String *t* with a string *s*.

## Input

The first line of input contains the single integer *n* (1 ≤ *n* ≤ 2000) — the number of base strings. 

The next *n* lines contains values of base strings. Each base string is made of lowercase Latin letters. A base string cannot be empty string and the sum of lengths of all *n* base strings doesn't exceed 106. 

The next line contains the single integer *m* (1 ≤ *m* ≤ 2000) — the number of base strings in the given Hyper String *t*. 

The next line contains *m* space-separated integer numbers *i*1, *i*2, ..., *i**m* (1 ≤ *i**j* ≤ *n*) — the indices of base strings in the Hyper String *t*.

The last line contains a non-empty string *s*. String *s* is made of lowercase Latin letters and its length is no more than 2000 characters.

## Output

Print the length of longest common sub-sequence of Hyper String *t* and string *s*. If there is no common sub-sequence print 0.

## Examples

## Input


```
2  
cba  
dgh  
2  
1 2  
aedfhr  

```
## Output


```
3  

```
## Input


```
2  
b  
a  
5  
1 2 1 2 1  
aaa  

```
## Output


```
2  

```
## Note

The length of string *s* is the number of characters in it. If the length of string *s* is marked as |*s*|, then string *s* can be represented as *s* = *s*1*s*2... *s*|*s*|.

A non-empty string *y* = *s*[*p*1*p*2... *p*|*y*|] = *s**p*1*s**p*2... *s**p*|*y*| (1 ≤ *p*1 < *p*2 < ... < *p*|*y*| ≤ |*s*|) is a subsequence of string *s*. For example, "coders" is a subsequence of "codeforces".



#### tags 

#2500 #dp 