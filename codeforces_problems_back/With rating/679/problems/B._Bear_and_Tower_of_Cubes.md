<h1 style='text-align: center;'> B. Bear and Tower of Cubes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Limak is a little polar bear. He plays by building towers from blocks. Every block is a cube with positive integer length of side. Limak has infinitely many blocks of each side length.

A block with side *a* has volume *a*3. A tower consisting of blocks with sides *a*1, *a*2, ..., *a**k* has the total volume *a*13 + *a*23 + ... + *a**k*3.

Limak is going to build a tower. First, he asks you to tell him a positive integer *X* — the required total volume of the tower. Then, Limak adds new blocks greedily, one by one. Each time he adds the biggest block such that the total volume doesn't exceed *X*.

Limak asks you to choose *X* not greater than *m*. Also, he wants to maximize the number of blocks in the tower at the end (however, he still behaves greedily). Secondarily, he wants to maximize *X*.

Can you help Limak? Find the maximum number of blocks his tower can have and the maximum *X* ≤ *m* that results this number of blocks.

## Input

The only line of the input contains one integer *m* (1 ≤ *m* ≤ 1015), meaning that Limak wants you to choose *X* between 1 and *m*, inclusive.

## Output

Print two integers — the maximum number of blocks in the tower and the maximum required total volume *X*, resulting in the maximum number of blocks.

## Examples

## Input


```
48  

```
## Output


```
9 42  

```
## Input


```
6  

```
## Output


```
6 6  

```
## Note

In the first sample test, there will be 9 blocks if you choose *X* = 23 or *X* = 42. Limak wants to maximize *X* secondarily so you should choose 42.

In more detail, after choosing *X* = 42 the process of building a tower is:

* Limak takes a block with side 3 because it's the biggest block with volume not greater than 42. The remaining volume is 42 - 27 = 15.
* The second added block has side 2, so the remaining volume is 15 - 8 = 7.
* Finally, Limak adds 7 blocks with side 1, one by one.

So, there are 9 blocks in the tower. The total volume is is 33 + 23 + 7·13 = 27 + 8 + 7 = 42.



#### tags 

#2200 #binary_search #dp #greedy 