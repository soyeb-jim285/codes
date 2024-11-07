<h1 style='text-align: center;'> C. Logistical Questions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Some country consists of *n* cities, connected by a railroad network. The transport communication of the country is so advanced that the network consists of a minimum required number of (*n* - 1) bidirectional roads (in the other words, the graph of roads is a tree). The *i*-th road that directly connects cities *a**i* and *b**i*, has the length of *l**i* kilometers.

The transport network is served by a state transporting company FRR (Fabulous Rail Roads). In order to simplify the price policy, it offers a single ride fare on the train. In order to follow the route of length *t* kilometers, you need to pay ![](images/d859317482668da17f2b69b7470d5fc143216fb4.png) burles. ## Note

 that it is forbidden to split a long route into short segments and pay them separately (a special railroad police, or RRP, controls that the law doesn't get violated).

A Large Software Company decided to organize a programming tournament. Having conducted several online rounds, the company employees determined a list of finalists and sent it to the logistical department to find a place where to conduct finals. The Large Software Company can easily organize the tournament finals in any of the *n* cities of the country, so the the main factor in choosing the city for the last stage of the tournament is the total cost of buying tickets for all the finalists. We know that the *i*-th city of the country has *w**i* cup finalists living there.

Help the company employees find the city such that the total cost of travel of all the participants to it is minimum.

## Input

The first line of the input contains number *n* (1 ≤ *n* ≤ 200 000) — the number of cities in the country.

The next line contains *n* integers *w*1, *w*2, ..., *w**n* (0 ≤ *w**i* ≤ 108) — the number of finalists living in each city of the country.

Next (*n* - 1) lines contain the descriptions of the railroad, the *i*-th line contains three integers, *a**i*, *b**i*, *l**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*, 1 ≤ *l**i* ≤ 1000).

## Output

Print two numbers — an integer *f* that is the number of the optimal city to conduct the competition, and the real number *c*, equal to the minimum total cost of transporting all the finalists to the competition. Your answer will be considered correct if two conditions are fulfilled at the same time: 

1. The absolute or relative error of the printed number *c* in comparison with the cost of setting up a final in city *f* doesn't exceed 10- 6;
2. Absolute or relative error of the printed number *c* in comparison to the answer of the jury doesn't exceed 10- 6.

If there are multiple answers, you are allowed to print any of them.

## Examples

## Input


```
5  
3 1 2 6 5  
1 2 3  
2 3 1  
4 3 9  
5 3 1  

```
## Output


```
3 192.0
```
## Input


```
2  
5 5  
1 2 2  

```
## Output


```
1 14.142135623730951000  

```
## Note

In the sample test an optimal variant of choosing a city to conduct the finals of the competition is 3. At such choice the cost of conducting is ![](images/4219dfaeaed77b348dc7ca0c500739d1c0ff9e3f.png) burles.

In the second sample test, whatever city you would choose, you will need to pay for the transport for five participants, so you will need to pay ![](images/bec9396b77dab4487d19f32c85b0edb26924da8c.png) burles for each one of them.



#### tags 

#3000 #dfs_and_similar #divide_and_conquer #trees 