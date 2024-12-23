<h1 style='text-align: center;'> A. Magical Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valery is very interested in magic. Magic attracts him so much that he sees it everywhere. He explains any strange and weird phenomenon through intervention of supernatural forces. But who would have thought that even in a regular array of numbers Valera manages to see something beautiful and magical.

Valera absolutely accidentally got a piece of ancient parchment on which an array of numbers was written. He immediately thought that the numbers in this array were not random. As a result of extensive research Valera worked out a wonderful property that a magical array should have: an array is defined as magic if its minimum and maximum coincide.

He decided to share this outstanding discovery with you, but he asks you for help in return. Despite the tremendous intelligence and wit, Valera counts very badly and so you will have to complete his work. All you have to do is count the number of magical subarrays of the original array of numbers, written on the parchment. Subarray is defined as non-empty sequence of consecutive elements.

## Input

The first line of the input data contains an integer *n* (1 ≤ *n* ≤ 105). The second line contains an array of original integers *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109). 

## Output

Print on the single line the answer to the problem: the amount of subarrays, which are magical.

Please do not use the %lld specificator to read or write 64-bit numbers in C++. It is recommended to use cin, cout streams (you can also use the %I64d specificator).

## Examples

## Input


```
4  
2 1 1 4  

```
## Output


```
5  

```
## Input


```
5  
-2 -2 -2 0 1  

```
## Output


```
8  

```
## Note

## Note

s to sample tests:

Magical subarrays are shown with pairs of indices [a;b] of the beginning and the end.

In the first sample: [1;1], [2;2], [3;3], [4;4], [2;3].

In the second sample: [1;1], [2;2], [3;3], [4;4], [5;5], [1;2], [2;3], [1;3]. 



#### tags 

#1300 #math 