<h1 style='text-align: center;'> A. Berland Miners</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The biggest gold mine in Berland consists of *n* caves, connected by *n* - 1 transitions. The entrance to the mine leads to the cave number 1, it is possible to go from it to any remaining cave of the mine by moving along the transitions. 

The mine is being developed by the InMine Inc., *k* miners work for it. Each day the corporation sorts miners into caves so that each cave has at most one miner working there. 

For each cave we know the height of its ceiling *h**i* in meters, and for each miner we know his height *s**j*, also in meters. If a miner's height doesn't exceed the height of the cave ceiling where he is, then he can stand there comfortably, otherwise, he has to stoop and that makes him unhappy.

Unfortunately, miners typically go on strike in Berland, so InMine makes all the possible effort to make miners happy about their work conditions. To ensure that no miner goes on strike, you need make sure that no miner has to stoop at any moment on his way from the entrance to the mine to his cave (in particular, he must be able to stand comfortably in the cave where he works). 

To reach this goal, you can choose exactly one cave and increase the height of its ceiling by several meters. However enlarging a cave is an expensive and complex procedure. That's why InMine Inc. asks you either to determine the minimum number of meters you should raise the ceiling of some cave so that it is be possible to sort the miners into the caves and keep all miners happy with their working conditions or to determine that it is impossible to achieve by raising ceiling in exactly one cave.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 5·105) — the number of caves in the mine.

Then follows a line consisting of *n* positive integers *h*1, *h*2, ..., *h**n* (1 ≤ *h**i* ≤ 109), where *h**i* is the height of the ceiling in the *i*-th cave.

Next *n* - 1 lines contain the descriptions of transitions between the caves. Each line has the form *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*), where *a**i* and *b**i* are the numbers of the caves connected by a path.

The next line contains integer *k* (1 ≤ *k* ≤ *n*).

The last line contains *k* integers *s*1, *s*2, ..., *s**k* (1 ≤ *s**j* ≤ 109), where *s**j* is the *j*-th miner's height.

## Output

In the single line print the minimum number of meters that you need to raise the ceiling by in some cave so that all miners could be sorted into caves and be happy about the work conditions. If it is impossible to do, print  - 1. If it is initially possible and there's no need to raise any ceiling, print 0. 

## Examples

## Input


```
6  
5 8 4 6 3 12  
1 2  
1 3  
4 2  
2 5  
6 3  
6  
7 4 2 5 3 11  

```
## Output


```
6  

```
## Input


```
7  
10 14 7 12 4 50 1  
1 2  
2 3  
2 4  
5 1  
6 5  
1 7  
6  
7 3 4 8 8 10  

```
## Output


```
0  

```
## Input


```
3  
4 2 8  
1 2  
1 3  
2  
17 15  

```
## Output


```
-1  

```
## Note

In the first sample test we should increase ceiling height in the first cave from 5 to 11. After that we can distribute miners as following (first goes index of a miner, then index of a cave): ![](images/5d9b256bdaa3f5b0f9a3fc3b9f56256306a7a570.png).

In the second sample test there is no need to do anything since it is already possible to distribute miners as following: ![](images/ba4a2592a4bea5feafeae1ab8dec98663bf2c557.png).

In the third sample test it is impossible.



#### tags 

#3000 #binary_search #data_structures #dfs_and_similar #greedy #trees 