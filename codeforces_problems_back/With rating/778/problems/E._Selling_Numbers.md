<h1 style='text-align: center;'> E. Selling Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Boris really likes numbers and even owns a small shop selling interesting numbers. He has *n* decimal numbers *B**i*. Cost of the number in his shop is equal to the sum of costs of its digits. You are given the values *c**d*, where *c**d* is the cost of the digit *d*. Of course, Boris is interested in that numbers he owns have the maximum cost possible.

Recently Boris got hold of the magical artifact *A*, which can allow him to increase the cost of his collection. Artifact is a string, consisting of digits and '?' symbols. To use the artifact, Boris must replace all '?' with digits to get a decimal number without leading zeros (it is also not allowed to get number 0). After that, the resulting number is added to all numbers *B**i* in Boris' collection. He uses the artifact exactly once.

What is the maximum cost of the collection Boris can achieve after using the artifact?

## Input

First line contains artifact *A*, consisting of digits '0'–'9' and '?' symbols (1 ≤ |*A*| ≤ 1000). Next line contains *n* — the amount of numbers in Boris' collection (1 ≤ *n* ≤ 1000). Next *n* lines contain integers *B**i* (1 ≤ *B**i* < 101000). *A* doesn't start with '0'.

Last line contains ten integers — costs of digits *c*0, *c*1, ..., *c*9 (0 ≤ *c**i* ≤ 1000).

## Output

## Output

 one integer — the maximum possible cost of the collection after using the artifact.

## Examples

## Input


```
42  
3  
89  
1  
958  
0 0 1 1 2 2 3 3 4 4  

```
## Output


```
4  

```
## Input


```
?5?  
4  
2203  
5229  
276  
6243  
2 1 6 1 1 2 5 2 2 3  

```
## Output


```
62  

```
## Note

In the second sample input, the optimal way is to compose the number 453. After adding this number, Boris will have numbers 2656, 5682, 729 and 6696. The total cost of all digits in them is equal to 18 + 15 + 11 + 18 = 62. 



#### tags 

#3000 #dp #sortings 