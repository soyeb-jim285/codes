<h1 style='text-align: center;'> A. Plus and Square Root</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

ZS the Coder is playing a game. There is a number displayed on the screen and there are two buttons, ' + ' (plus) and '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' (square root). Initially, the number 2 is displayed on the screen. There are *n* + 1 levels in the game and ZS the Coder start at the level 1.

When ZS the Coder is at level *k*, he can :

1. Press the ' + ' button. This increases the number on the screen by exactly *k*. So, if the number on the screen was *x*, it becomes *x* + *k*.
2. Press the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button. Let the number on the screen be *x*. After pressing this button, the number becomes ![](images/dd68ff2d8e5b97302506ac32d308bb521ab84a26.png). After that, ZS the Coder levels up, so his current level becomes *k* + 1. This button can only be pressed when *x* is a perfect square, i.e. *x* = *m*2 for some positive integer *m*.

Additionally, after each move, if ZS the Coder is at level *k*, and the number on the screen is *m*, then *m* must be a multiple of *k*. ## Note

 that this condition is only checked after performing the press. For example, if ZS the Coder is at level 4 and current number is 100, he presses the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button and the number turns into 10. ## Note

 that at this moment, 10 is not divisible by 4, but this press is still valid, because after it, ZS the Coder is at level 5, and 10 is divisible by 5.

ZS the Coder needs your help in beating the game — he wants to reach level *n* + 1. In other words, he needs to press the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button *n* times. Help him determine the number of times he should press the ' + ' button before pressing the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button at each level. 

Please note that ZS the Coder wants to find just any sequence of presses allowing him to reach level *n* + 1, but not necessarily a sequence minimizing the number of presses.

## Input

The first and only line of the input contains a single integer *n* (1 ≤ *n* ≤ 100 000), denoting that ZS the Coder wants to reach level *n* + 1.

## Output

Print *n* non-negative integers, one per line. *i*-th of them should be equal to the number of times that ZS the Coder needs to press the ' + ' button before pressing the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button at level *i*. 

Each number in the output should not exceed 1018. However, the number on the screen can be greater than 1018.

It is guaranteed that at least one solution exists. If there are multiple solutions, print any of them.

## Examples

## Input


```
3  

```
## Output


```
14  
16  
46  

```
## Input


```
2  

```
## Output


```
999999999999999998  
44500000000  

```
## Input


```
4  

```
## Output


```
2  
17  
46  
97  

```
## Note

In the first sample case:

On the first level, ZS the Coder pressed the ' + ' button 14 times (and the number on screen is initially 2), so the number became 2 + 14·1 = 16. Then, ZS the Coder pressed the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button, and the number became ![](images/c3d2663f5f74e9220fd5cbccbfaf4ca76ef7284f.png). 

After that, on the second level, ZS pressed the ' + ' button 16 times, so the number becomes 4 + 16·2 = 36. Then, ZS pressed the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button, levelling up and changing the number into ![](images/49ab1d31f1435b7c7b96550d63a35be671d3d85a.png).

After that, on the third level, ZS pressed the ' + ' button 46 times, so the number becomes 6 + 46·3 = 144. Then, ZS pressed the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button, levelling up and changing the number into ![](images/499b57d4b7ba5e1e0957767cc182808ca48ef722.png). 

## Note

 that 12 is indeed divisible by 4, so ZS the Coder can reach level 4.

Also, note that pressing the ' + ' button 10 times on the third level before levelling up does not work, because the number becomes 6 + 10·3 = 36, and when the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button is pressed, the number becomes ![](images/49ab1d31f1435b7c7b96550d63a35be671d3d85a.png) and ZS the Coder is at Level 4. However, 6 is not divisible by 4 now, so this is not a valid solution.

In the second sample case:

On the first level, ZS the Coder pressed the ' + ' button 999999999999999998 times (and the number on screen is initially 2), so the number became 2 + 999999999999999998·1 = 1018. Then, ZS the Coder pressed the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button, and the number became ![](images/f07f2a60ab6cecbd2507861a0df57a16a015fd86.png). 

After that, on the second level, ZS pressed the ' + ' button 44500000000 times, so the number becomes 109 + 44500000000·2 = 9·1010. Then, ZS pressed the '![](images/c77ded9b8209a8cb488cc2ec7b7fe1dae32a5309.png)' button, levelling up and changing the number into ![](images/4c4d8829d987a7bcfd597cd1aa101327a66c0eca.png). 

## Note

 that 300000 is a multiple of 3, so ZS the Coder can reach level 3.



#### tags 

#1600 #constructive_algorithms #math 