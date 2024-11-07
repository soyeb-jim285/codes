<h1 style='text-align: center;'> D. High Cry</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Disclaimer: there are lots of untranslateable puns in the Russian version of the statement, so there is one more reason for you to learn Russian :)

Rick and Morty like to go to the ridge High Cry for crying loudly — there is an extraordinary echo. Recently they discovered an interesting acoustic characteristic of this ridge: if Rick and Morty begin crying simultaneously from different mountains, their cry would be heard between these mountains up to the height equal the bitwise OR of mountains they've climbed and all the mountains between them. 

Bitwise OR is a binary operation which is determined the following way. Consider representation of numbers *x* and *y* in binary numeric system (probably with leading zeroes) *x* = *x**k*... *x*1*x*0 and *y* = *y**k*... *y*1*y*0. Then *z* = *x* | *y* is defined following way: *z* = *z**k*... *z*1*z*0, where *z**i* = 1, if *x**i* = 1 or *y**i* = 1, and *z**i* = 0 otherwise. In the other words, digit of bitwise OR of two numbers equals zero if and only if digits at corresponding positions is both numbers equals zero. For example bitwise OR of numbers 10 = 10102 and 9 = 10012 equals 11 = 10112. In programming languages C/C++/Java/Python this operation is defined as «|», and in Pascal as «or».

Help Rick and Morty calculate the number of ways they can select two mountains in such a way that if they start crying from these mountains their cry will be heard above these mountains and all mountains between them. More formally you should find number of pairs *l* and *r* (1 ≤ *l* < *r* ≤ *n*) such that bitwise OR of heights of all mountains between *l* and *r* (inclusive) is larger than the height of any mountain at this interval.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 200 000), the number of mountains in the ridge.

Second line contains *n* integers *a**i* (0 ≤ *a**i* ≤ 109), the heights of mountains in order they are located in the ridge.

## Output

Print the only integer, the number of ways to choose two different mountains.

## Examples

## Input


```
5  
3 2 1 6 5  

```
## Output


```
8  

```
## Input


```
4  
3 3 3 3  

```
## Output


```
0  

```
## Note

In the first test case all the ways are pairs of mountains with the numbers (numbering from one):

(1, 4), (1, 5), (2, 3), (2, 4), (2, 5), (3, 4), (3, 5), (4, 5)In the second test case there are no such pairs because for any pair of mountains the height of cry from them is 3, and this height is equal to the height of any mountain.



#### tags 

#2200 #binary_search #bitmasks #combinatorics #data_structures #divide_and_conquer 