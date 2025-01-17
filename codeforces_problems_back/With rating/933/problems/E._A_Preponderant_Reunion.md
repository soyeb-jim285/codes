<h1 style='text-align: center;'> E. A Preponderant Reunion</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

East or west, home is best. That's why family reunion, the indispensable necessity of Lunar New Year celebration, is put in such a position.

After the reunion dinner, Little Tommy plays a game with the family. Here is a concise introduction to this game: 

1. There is a sequence of *n* non-negative integers *p*1, *p*2, ..., *p**n* in the beginning. It is ruled that each integer in this sequence should be non-negative at any time.
2. You can select two consecutive positive integers in this sequence, *p**i* and *p**i* + 1 (1 ≤ *i* < *n*), and then decrease them by their minimum (i. e. *min*(*p**i*, *p**i* + 1)), the cost of this operation is equal to *min*(*p**i*, *p**i* + 1). We call such operation as a descension.
3. The game immediately ends when there are no two consecutive positive integers. Your task is to end the game so that the total cost of your operations is as small as possible.

Obviously, every game ends after at most *n* - 1 descensions. Please share your solution of this game with the lowest cost.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 3·105).

The second line contains *n* space-separated integers *p*1, *p*2, ..., *p**n* (0 ≤ *p**i* ≤ 109, *i* = 1, 2, ..., *n*).

## Output

In the first line print one integer as the number of descensions *m* (0 ≤ *m* ≤ *n* - 1).

In the next *m* lines print the descensions chronologically. More precisely, in each line of the next *m* lines print one integer *i* (1 ≤ *i* < *n*) representing a descension would operate on *p**i* and *p**i* + 1 such that all the descensions could be utilized from top to bottom.

If there are many possible solutions to reach the minimal cost, print any of them.

## Examples

## Input


```
4  
2 1 3 1  

```
## Output


```
2  
1  
3  

```
## Input


```
5  
2 2 1 3 1  

```
## Output


```
3  
2  
1  
4  

```
## Note

In the first sample, one possible best solution is ![](images/9248227dd2a5fa16d275273b9219a6e5a3560846.png), of which the cost is 1 + 1 = 2.

In the second sample, one possible best solution is ![](images/8f91058897d4137e5df572ebfbf65e2a7d88692a.png), of which the cost is 1 + 1 + 1 = 3.



#### tags 

#3200 #constructive_algorithms #dp 