<h1 style='text-align: center;'> G. Combining Slimes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Your friend recently gave you some slimes for your birthday. You have a very large amount of slimes with value 1 and 2, and you decide to invent a game using these slimes.

You initialize a row with *n* empty spaces. You also choose a number *p* to be used in the game. Then, you will perform the following steps while the last space is empty. 

1. With probability ![](images/1a0b7c2218ab69e18b6b844a8281449c263537e3.png), you will choose a slime with value 1, and with probability ![](images/917b5cdb9a29867fbc458c1e248e1c7e8a28e099.png), you will choose a slime with value 2. You place the chosen slime on the last space of the board.
2. You will push the slime to the left as far as possible. If it encounters another slime, and they have the same value *v*, you will merge the slimes together to create a single slime with value *v* + 1. This continues on until the slime reaches the end of the board, or encounters a slime with a different value than itself.

You have played the game a few times, but have gotten bored of it. You are now wondering, what is the expected sum of all values of the slimes on the board after you finish the game.

## Input

The first line of the input will contain two integers *n*, *p* (1 ≤ *n* ≤ 109, 1 ≤ *p* < 109).

## Output

Print the expected sum of all slimes on the board after the game finishes. Your answer will be considered correct if its absolute or relative error does not exceed 10- 4.

Namely, let's assume that your answer is *a* and the answer of the jury is *b*. The checker program will consider your answer correct, if ![](images/49eb236611e23b2e7c8e81e9516771daca716eec.png).

## Examples

## Input


```
2 500000000  

```
## Output


```
3.562500000000000  

```
## Input


```
10 1  

```
## Output


```
64.999983360007620  

```
## Input


```
100 123456789  

```
## Output


```
269.825611298854770  

```
## Note

In the first sample, we have a board with two squares, and there is a 0.5 probability of a 1 appearing and a 0.5 probability of a 2 appearing.

Our final board states can be 1 2 with probability 0.25, 2 1 with probability 0.375, 3 2 with probability 0.1875, 3 1 with probability 0.1875. The expected value is thus (1 + 2)·0.25 + (2 + 1)·0.375 + (3 + 2)·0.1875 + (3 + 1)·0.1875 = 3.5625.



#### tags 

#3300 #dp #math #matrices #probabilities 