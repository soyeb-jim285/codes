<h1 style='text-align: center;'> B. Game of Robots</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In late autumn evening *n* robots gathered in the cheerful company of friends. Each robot has a unique identifier — an integer from 1 to 109.

At some moment, robots decided to play the game "Snowball". Below there are the rules of this game. First, all robots stand in a row. Then the first robot says his identifier. After that the second robot says the identifier of the first robot and then says his own identifier. Then the third robot says the identifier of the first robot, then says the identifier of the second robot and after that says his own. This process continues from left to right until the *n*-th robot says his identifier.

Your task is to determine the *k*-th identifier to be pronounced.

## Input

The first line contains two positive integers *n* and *k* (1 ≤ *n* ≤ 100 000, 1 ≤ *k* ≤ *min*(2·109, *n*·(*n* + 1) / 2).

The second line contains the sequence *id*1, *id*2, ..., *id**n* (1 ≤ *id**i* ≤ 109) — identifiers of roborts. It is guaranteed that all identifiers are different.

## Output

Print the *k*-th pronounced identifier (assume that the numeration starts from 1).

## Examples

## Input


```
2 2  
1 2  

```
## Output


```
1  

```
## Input


```
4 5  
10 4 18 3  

```
## Output


```
4  

```
## Note

In the first sample identifiers of robots will be pronounced in the following order: 1, 1, 2. As *k* = 2, the answer equals to 1.

In the second test case identifiers of robots will be pronounced in the following order: 10, 10, 4, 10, 4, 18, 10, 4, 18, 3. As *k* = 5, the answer equals to 4.



#### tags 

#1000 #implementation 