<h1 style='text-align: center;'> A. Kefa and First Steps</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kefa decided to make some money doing business on the Internet for exactly *n* days. He knows that on the *i*-th day (1 ≤ *i* ≤ *n*) he makes *a**i* money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence *a**i*. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105).

The second line contains *n* integers *a*1,  *a*2,  ...,  *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print a single integer — the length of the maximum non-decreasing subsegment of sequence *a*.

## Examples

## Input


```
6  
2 2 1 3 4 1  

```
## Output


```
3
```
## Input


```
3  
2 2 9  

```
## Output


```
3
```
## Note

In the first test the maximum non-decreasing subsegment is the numbers from the third to the fifth one.

In the second test the maximum non-decreasing subsegment is the numbers from the first to the third one.



#### tags 

#900 #brute_force #dp #implementation 