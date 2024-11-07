<h1 style='text-align: center;'> C. Jon Snow and his Favourite Number</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jon Snow now has to fight with White Walkers. He has *n* rangers, each of which has his own strength. Also Jon Snow has his favourite number *x*. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number *x*, he might get soldiers of high strength. So, he decided to do the following operation *k* times: 

1. Arrange all the rangers in a straight line in the order of increasing strengths.
2. Take the bitwise XOR (is written as ![](images/c4b7092c0f7ce6535f2574569c98f7b3c2fe2c5f.png)) of the strength of each alternate ranger with *x* and update it's strength.

 Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with *x* = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following: 1. The strength of first ranger is updated to ![](images/b989fec42185029adec488aa738b78d9de953aef.png), i.e. 7.
2. The strength of second ranger remains the same, i.e. 7.
3. The strength of third ranger is updated to ![](images/3c7c9436158c0744fffbc90f5dcf6769683b82c2.png), i.e. 11.
4. The strength of fourth ranger remains the same, i.e. 11.
5. The strength of fifth ranger is updated to ![](images/842bb4d07e058ad06611d99fc15455f0a936cb03.png), i.e. 13.

 The new strengths of the 5 rangers are [7, 7, 11, 11, 13]Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations *k* times. He wants your help for this task. Can you help him?

## Input

First line consists of three integers *n*, *k*, *x* (1 ≤ *n* ≤ 105, 0 ≤ *k* ≤ 105, 0 ≤ *x* ≤ 103) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of *n* integers representing the strengths of the rangers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 103).

## Output

## Output

 two integers, the maximum and the minimum strength of the rangers after performing the operation *k* times.

## Examples

## Input


```
5 1 2  
9 7 11 15 5  

```
## Output


```
13 7
```
## Input


```
2 100000 569  
605 986  

```
## Output


```
986 605
```


#### tags 

#1800 #brute_force #dp #implementation #sortings 