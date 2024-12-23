<h1 style='text-align: center;'> B. Polycarp and Letters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp loves lowercase letters and dislikes uppercase ones. Once he got a string *s* consisting only of lowercase and uppercase Latin letters.

Let *A* be a set of positions in the string. Let's call it pretty if following conditions are met:

* letters on positions from *A* in the string are all distinct and lowercase;
* there are no uppercase letters in the string which are situated between positions from *A* (i.e. there is no such *j* that *s*[*j*] is an uppercase letter, and *a*1 < *j* < *a*2 for some *a*1 and *a*2 from *A*).

Write a program that will determine the maximum number of elements in a pretty set of positions.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 200) — length of string *s*.

The second line contains a string *s* consisting of lowercase and uppercase Latin letters.

## Output

Print maximum number of elements in pretty set of positions for string *s*.

## Examples

## Input


```
11  
aaaaBaabAbA  

```
## Output


```
2  

```
## Input


```
12  
zACaAbbaazzC  

```
## Output


```
3  

```
## Input


```
3  
ABC  

```
## Output


```
0  

```
## Note

In the first example the desired positions might be 6 and 8 or 7 and 8. Positions 6 and 7 contain letters 'a', position 8 contains letter 'b'. The pair of positions 1 and 8 is not suitable because there is an uppercase letter 'B' between these position.

In the second example desired positions can be 7, 8 and 11. There are other ways to choose pretty set consisting of three elements.

In the third example the given string *s* does not contain any lowercase letters, so the answer is 0.



#### tags 

#1000 #brute_force #implementation #strings 