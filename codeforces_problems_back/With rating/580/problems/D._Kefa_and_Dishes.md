<h1 style='text-align: center;'> D. Kefa and Dishes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

When Kefa came to the restaurant and sat at a table, the waiter immediately brought him the menu. There were *n* dishes. Kefa knows that he needs exactly *m* dishes. But at that, he doesn't want to order the same dish twice to taste as many dishes as possible. 

Kefa knows that the *i*-th dish gives him *a**i* units of satisfaction. But some dishes do not go well together and some dishes go very well together. Kefa set to himself *k* rules of eating food of the following type — if he eats dish *x* exactly before dish *y* (there should be no other dishes between *x* and *y*), then his satisfaction level raises by *c*. 

Of course, our parrot wants to get some maximal possible satisfaction from going to the restaurant. Help him in this hard task!

## Input

The first line of the input contains three space-separated numbers, *n*, *m* and *k* (1 ≤ *m* ≤ *n* ≤ 18, 0 ≤ *k* ≤ *n* * (*n* - 1)) — the number of dishes on the menu, the number of portions Kefa needs to eat to get full and the number of eating rules.

The second line contains *n* space-separated numbers *a**i*, (0 ≤ *a**i* ≤ 109) — the satisfaction he gets from the *i*-th dish.

Next *k* lines contain the rules. The *i*-th rule is described by the three numbers *x**i*, *y**i* and *c**i* (1 ≤ *x**i*, *y**i* ≤ *n*, 0 ≤ *c**i* ≤ 109). That means that if you eat dish *x**i* right before dish *y**i*, then the Kefa's satisfaction increases by *c**i*. It is guaranteed that there are no such pairs of indexes *i* and *j* (1 ≤ *i* < *j* ≤ *k*), that *x**i* = *x**j* and *y**i* = *y**j*.

## Output

In the single line of the output print the maximum satisfaction that Kefa can get from going to the restaurant.

## Examples

## Input


```
2 2 1  
1 1  
2 1 1  

```
## Output


```
3  

```
## Input


```
4 3 2  
1 2 3 4  
2 1 5  
3 4 2  

```
## Output


```
12  

```
## Note

In the first sample it is best to first eat the second dish, then the first one. Then we get one unit of satisfaction for each dish and plus one more for the rule.

In the second test the fitting sequences of choice are 4 2 1 or 2 1 4. In both cases we get satisfaction 7 for dishes and also, if we fulfill rule 1, we get an additional satisfaction 5.



#### tags 

#1800 #bitmasks #dp 