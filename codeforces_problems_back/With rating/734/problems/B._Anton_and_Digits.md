<h1 style='text-align: center;'> B. Anton and Digits</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Anton found a box with digits in his room. There are *k*2 digits 2, *k*3 digits 3, *k*5 digits 5 and *k*6 digits 6.

Anton's favorite integers are 32 and 256. He decided to compose this integers from digits he has. He wants to make the sum of these integers as large as possible. Help him solve this task!

Each digit can be used no more than once, i.e. the composed integers should contain no more than *k*2 digits 2, *k*3 digits 3 and so on. Of course, unused digits are not counted in the sum.

## Input

The only line of the input contains four integers *k*2, *k*3, *k*5 and *k*6 — the number of digits 2, 3, 5 and 6 respectively (0 ≤ *k*2, *k*3, *k*5, *k*6 ≤ 5·106).

## Output

Print one integer — maximum possible sum of Anton's favorite integers that can be composed using digits from the box.

## Examples

## Input


```
5 1 3 4  

```
## Output


```
800  

```
## Input


```
1 1 1 1  

```
## Output


```
256  

```
## Note

In the first sample, there are five digits 2, one digit 3, three digits 5 and four digits 6. Anton can compose three integers 256 and one integer 32 to achieve the value 256 + 256 + 256 + 32 = 800. ## Note

, that there is one unused integer 2 and one unused integer 6. They are not counted in the answer.

In the second sample, the optimal answer is to create on integer 256, thus the answer is 256.



#### tags 

#800 #brute_force #greedy #implementation #math 