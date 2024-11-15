<h1 style='text-align: center;'> B. Growing Mushrooms</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Each year in the castle of Dwarven King there is a competition in growing mushrooms among the dwarves. The competition is one of the most prestigious ones, and the winner gets a wooden salad bowl. This year's event brought together the best mushroom growers from around the world, so we had to slightly change the rules so that the event gets more interesting to watch.

Each mushroom grower has a mushroom that he will grow on the competition. Under the new rules, the competition consists of two parts. The first part lasts *t*1 seconds and the second part lasts *t*2 seconds. The first and the second part are separated by a little break.

After the starting whistle the first part of the contest starts, and all mushroom growers start growing mushrooms at once, each at his individual speed of *v**i* meters per second. After *t*1 seconds, the mushroom growers stop growing mushrooms and go to have a break. During the break, for unexplained reasons, the growth of all mushrooms is reduced by *k* percent. After the break the second part of the contest starts and all mushrooms growers at the same time continue to grow mushrooms, each at his individual speed of *u**i* meters per second. After a *t*2 seconds after the end of the break, the competition ends. ## Note

 that the speeds before and after the break may vary.

Before the match dwarf Pasha learned from all participants, what two speeds they have chosen. However, the participants did not want to disclose to him all their strategy and therefore, did not say in what order they will be using these speeds. That is, if a participant chose speeds *a**i* and *b**i*, then there are two strategies: he either uses speed *a**i* before the break and speed *b**i* after it, or vice versa.

Dwarf Pasha really wants to win the totalizer. He knows that each participant chooses the strategy that maximizes the height of the mushroom. Help Dwarf Pasha make the final table of competition results.

The participants are sorted in the result table by the mushroom height (the participants with higher mushrooms follow earlier in the table). In case of equal mushroom heights, the participants are sorted by their numbers (the participants with a smaller number follow earlier).

## Input

The first input line contains four integer numbers *n*, *t*1, *t*2, *k* (1 ≤ *n*, *t*1, *t*2 ≤ 1000; 1 ≤ *k* ≤ 100) — the number of participants, the time before the break, the time after the break and the percentage, by which the mushroom growth drops during the break, correspondingly.

Each of the following *n* lines contains two integers. The *i*-th (1 ≤ *i* ≤ *n*) line contains space-separated integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ 1000) — the speeds which the participant number *i* chose.

## Output

Print the final results' table: *n* lines, each line should contain the number of the corresponding dwarf and the final maximum height of his mushroom with exactly two digits after the decimal point. The answer will be considered correct if it is absolutely accurate.

## Examples

## Input


```
2 3 3 50  
2 4  
4 2  

```
## Output


```
1 15.00  
2 15.00  

```
## Input


```
4 1 1 1  
544 397  
280 101  
280 101  
693 970  

```
## Output


```
4 1656.07  
1 937.03  
2 379.99  
3 379.99  

```
## Note

* First example: for each contestant it is optimal to use firstly speed 2 and afterwards speed 4, because 2·3·0.5 + 4·3 > 4·3·0.5 + 2·3.


#### tags 

#1200 #greedy #sortings 