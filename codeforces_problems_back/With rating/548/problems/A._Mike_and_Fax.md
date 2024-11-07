<h1 style='text-align: center;'> A. Mike and Fax</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

While Mike was walking in the subway, all the stuff in his back-bag dropped on the ground. There were several fax messages among them. He concatenated these strings in some order and now he has string *s*.

 ![](images/6ad1575448bfc61e22a22cecbcd744ce8a3993a9.png) He is not sure if this is his own back-bag or someone else's. He remembered that there were exactly *k* messages in his own bag, each was a palindrome string and all those strings had the same length.

He asked you to help him and tell him if he has worn his own back-bag. Check if the given string *s* is a concatenation of *k* palindromes of the same length.

## Input

The first line of input contains string *s* containing lowercase English letters (1 ≤ |*s*| ≤ 1000).

The second line contains integer *k* (1 ≤ *k* ≤ 1000).

## Output

Print "YES"(without quotes) if he has worn his own back-bag or "NO"(without quotes) otherwise.

## Examples

## Input


```
saba  
2  

```
## Output


```
NO  

```
## Input


```
saddastavvat  
2  

```
## Output


```
YES  

```
## Note

Palindrome is a string reading the same forward and backward.

In the second sample, the faxes in his back-bag can be "saddas" and "tavvat".



#### tags 

#1100 #brute_force #implementation #strings 