<h1 style='text-align: center;'> E. Let's Go Rolling!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On a number axis directed from the left rightwards, *n* marbles with coordinates *x*1, *x*2, ..., *x**n* are situated. Let's assume that the sizes of the marbles are infinitely small, that is in this task each of them is assumed to be a material point. You can stick pins in some of them and the cost of sticking in the marble number *i* is equal to *c**i*, number *c**i* may be negative. After you choose and stick the pins you need, the marbles will start to roll left according to the rule: if a marble has a pin stuck in it, then the marble doesn't move, otherwise the marble rolls all the way up to the next marble which has a pin stuck in it and stops moving there. If there is no pinned marble on the left to the given unpinned one, it is concluded that the marble rolls to the left to infinity and you will pay an infinitely large fine for it. If no marble rolled infinitely to the left, then the fine will consist of two summands: 

* the sum of the costs of stuck pins;
* the sum of the lengths of the paths of each of the marbles, that is the sum of absolute values of differences between their initial and final positions.

Your task is to choose and pin some marbles in the way that will make the fine for you to pay as little as possible.

## Input

The first input line contains an integer *n* (1 ≤ *n* ≤ 3000) which is the number of marbles. The next *n* lines contain the descriptions of the marbles in pairs of integers *x**i*, *c**i* ( - 109 ≤ *x**i*, *c**i* ≤ 109). The numbers are space-separated. Each description is given on a separate line. No two marbles have identical initial positions.

## Output

## Output

 the single number — the least fine you will have to pay.

## Examples

## Input


```
3  
2 3  
3 4  
1 2  

```
## Output


```
5  

```
## Input


```
4  
1 7  
3 1  
5 10  
6 1  

```
## Output


```
11  

```


#### tags 

#1800 #dp #sortings 