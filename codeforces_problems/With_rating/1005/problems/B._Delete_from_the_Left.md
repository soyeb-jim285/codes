<h1 style='text-align: center;'> B. Delete from the Left</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$. In a single move, you can choose any of two strings and delete the first (that is, the leftmost) character. After a move, the length of the string decreases by $1$. You can't choose a string if it is empty.

For example:

* by applying a move to the string "where", the result is the string "here",
* by applying a move to the string "a", the result is an empty string "".

You are required to make two given strings equal using the fewest number of moves. It is possible that, in the end, both strings will be equal to the empty string, and so, are equal to each other. In this case, the answer is obviously the sum of the lengths of the initial strings.

Write a program that finds the minimum number of moves to make two given strings $s$ and $t$ equal.

###### Input

The first line of the input contains $s$. In the second line of the input contains $t$. Both strings consist only of lowercase Latin letters. The number of letters in each string is between 1 and $2\cdot10^5$, inclusive.

###### Output

###### Output

 the fewest number of moves required. It is possible that, in the end, both strings will be equal to the empty string, and so, are equal to each other. In this case, the answer is obviously the sum of the lengths of the given strings.

## Examples

###### Input


```text
test  
west  

```
###### Output


```text
2  

```
###### Input


```text
codeforces  
yes  

```
###### Output


```text
9  

```
###### Input


```text
test  
yes  

```
###### Output


```text
7  

```
###### Input


```text
b  
ab  

```
###### Output


```text
1  

```
## Note

In the first example, you should apply the move once to the first string and apply the move once to the second string. As a result, both strings will be equal to "est".

In the second example, the move should be applied to the string "codeforces" $8$ times. As a result, the string becomes "codeforces" $\to$ "es". The move should be applied to the string "yes" once. The result is the same string "yes" $\to$ "es".

In the third example, you can make the strings equal only by completely deleting them. That is, in the end, both strings will be empty.

In the fourth example, the first character of the second string should be deleted.



#### Tags 

#900 #NOT OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_496_(Div._3).md)
- [Tutorial](../blogs/Tutorial.md)
