<h1 style='text-align: center;'> D. Lizards and Basements 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

This is simplified version of the problem used on the original contest. The original problem seems to have too difiicult solution. The constraints for input data have been reduced.

Polycarp likes to play computer role-playing game «Lizards and Basements». At the moment he is playing it as a magician. At one of the last levels he has to fight the line of archers. The only spell with which he can damage them is a fire ball. If Polycarp hits the *i*-th archer with his fire ball (they are numbered from left to right), the archer loses *a* health points. At the same time the spell damages the archers adjacent to the *i*-th (if any) — they lose *b* (1 ≤ *b* < *a* ≤ 10) health points each.

As the extreme archers (i.e. archers numbered 1 and *n*) are very far, the fire ball cannot reach them. Polycarp can hit any other archer with his fire ball.

The amount of health points for each archer is known. An archer will be killed when this amount is less than 0. What is the minimum amount of spells Polycarp can use to kill all the enemies?

Polycarp can throw his fire ball into an archer if the latter is already killed.

## Input

The first line of the input contains three integers *n*, *a*, *b* (3 ≤ *n* ≤ 10; 1 ≤ *b* < *a* ≤ 10). The second line contains a sequence of *n* integers — *h*1, *h*2, ..., *h**n* (1 ≤ *h**i* ≤ 15), where *h**i* is the amount of health points the *i*-th archer has.

## Output

In the first line print *t* — the required minimum amount of fire balls.

In the second line print *t* numbers — indexes of the archers that Polycarp should hit to kill all the archers in *t* shots. All these numbers should be between 2 and *n* - 1. Separate numbers with spaces. If there are several solutions, output any of them. Print numbers in any order.

## Examples

## Input


```
3 2 1  
2 2 2  

```
## Output


```
3  
2 2 2 
```
## Input


```
4 3 1  
1 4 1 1  

```
## Output


```
4  
2 2 3 3 
```


#### tags 

#2600 #brute_force #dp 