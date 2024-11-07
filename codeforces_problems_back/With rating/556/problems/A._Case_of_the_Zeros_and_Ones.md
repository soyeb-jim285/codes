<h1 style='text-align: center;'> A. Case of the Zeros and Ones</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Andrewid the Android is a galaxy-famous detective. In his free time he likes to think about strings containing zeros and ones.

Once he thought about a string of length *n* consisting of zeroes and ones. Consider the following operation: we choose any two adjacent positions in the string, and if one them contains 0, and the other contains 1, then we are allowed to remove these two digits from the string, obtaining a string of length *n* - 2 as a result.

Now Andreid thinks about what is the minimum length of the string that can remain after applying the described operation several times (possibly, zero)? Help him to calculate this number.

## Input

First line of the input contains a single integer *n* (1 ≤ *n* ≤ 2·105), the length of the string that Andreid has.

The second line contains the string of length *n* consisting only from zeros and ones.

## Output

## Output

 the minimum length of the string that may remain after applying the described operations several times.

## Examples

## Input


```
4  
1100  

```
## Output


```
0  

```
## Input


```
5  
01010  

```
## Output


```
1  

```
## Input


```
8  
11101111  

```
## Output


```
6  

```
## Note

In the first sample test it is possible to change the string like the following: ![](images/10df55364c21c6e8d5da31b6ab6f6294c4fc26b3.png).

In the second sample test it is possible to change the string like the following: ![](images/19ec5dcd85f0b5cf757aa076ace72df39634de2d.png).

In the third sample test it is possible to change the string like the following: ![](images/dc34a159e4230375fa325555527ebc748811f188.png).



#### tags 

#900 #greedy 