<h1 style='text-align: center;'> E. Piglet's Birthday</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Piglet has got a birthday today. His friend Winnie the Pooh wants to make the best present for him — a honey pot. Of course Winnie realizes that he won't manage to get the full pot to Piglet. In fact, he is likely to eat all the honey from the pot. And as soon as Winnie planned a snack on is way, the pot should initially have as much honey as possible. 

The day before Winnie the Pooh replenished his honey stocks. Winnie-the-Pooh has *n* shelves at home, each shelf contains some, perhaps zero number of honey pots. During the day Winnie came to the honey shelves *q* times; on the *i*-th time he came to some shelf *u**i*, took from it some pots *k**i*, tasted the honey from each pot and put all those pots on some shelf *v**i*. As Winnie chose the pots, he followed his intuition. And that means that among all sets of *k**i* pots on shelf *u**i*, he equiprobably chooses one.

Now Winnie remembers all actions he performed with the honey pots. He wants to take to the party the pot he didn't try the day before. For that he must know the mathematical expectation of the number *m* of shelves that don't have a single untasted pot. To evaluate his chances better, Winnie-the-Pooh wants to know the value *m* after each action he performs.

Your task is to write a program that will find those values for him.

## Input

The first line of the input contains a single number *n* (1 ≤ *n* ≤ 105) — the number of shelves at Winnie's place. The second line contains *n* integers *a**i* (1 ≤ *i* ≤ *n*, 0 ≤ *a**i* ≤ 100) — the number of honey pots on a shelf number *i*. 

The next line contains integer *q* (1 ≤ *q* ≤ 105) — the number of actions Winnie did the day before. Then follow *q* lines, the *i*-th of them describes an event that follows chronologically; the line contains three integers *u**i*, *v**i* and *k**i* (1 ≤ *u**i*, *v**i* ≤ *n*, 1 ≤ *k**i* ≤ 5) — the number of the shelf from which Winnie took pots, the number of the shelf on which Winnie put the pots after he tasted each of them, and the number of the pots Winnie tasted, correspondingly.

Consider the shelves with pots numbered with integers from 1 to *n*. It is guaranteed that Winnie-the-Pooh Never tried taking more pots from the shelf than it has.

## Output

For each Winnie's action print the value of the mathematical expectation *m* by the moment when this action is performed. The relative or absolute error of each value mustn't exceed 10- 9.

## Examples

## Input


```
3  
2 2 3  
5  
1 2 1  
2 1 2  
1 2 2  
3 1 1  
3 2 2  

```
## Output


```
0.000000000000  
0.333333333333  
1.000000000000  
1.000000000000  
2.000000000000  

```


#### tags 

#2600 #dp #math #probabilities 