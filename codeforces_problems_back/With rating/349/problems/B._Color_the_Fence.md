<h1 style='text-align: center;'> B. Color the Fence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Igor has fallen in love with Tanya. Now Igor wants to show his feelings and write a number on the fence opposite to Tanya's house. Igor thinks that the larger the number is, the more chance to win Tanya's heart he has. 

Unfortunately, Igor could only get *v* liters of paint. He did the math and concluded that digit *d* requires *a**d* liters of paint. Besides, Igor heard that Tanya doesn't like zeroes. That's why Igor won't use them in his number.

Help Igor find the maximum number he can write on the fence.

## Input

The first line contains a positive integer *v* (0 ≤ *v* ≤ 106). The second line contains nine positive integers *a*1, *a*2, ..., *a*9 (1 ≤ *a**i* ≤ 105).

## Output

Print the maximum number Igor can write on the fence. If he has too little paint for any digit (so, he cannot write anything), print -1.

## Examples

## Input


```
5  
5 4 3 2 1 2 3 4 5  

```
## Output


```
55555  

```
## Input


```
2  
9 11 1 12 5 8 9 10 6  

```
## Output


```
33  

```
## Input


```
0  
1 1 1 1 1 1 1 1 1  

```
## Output


```
-1  

```


#### tags 

#1700 #data_structures #dp #greedy #implementation 