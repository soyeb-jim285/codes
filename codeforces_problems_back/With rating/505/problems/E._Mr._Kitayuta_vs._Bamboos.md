<h1 style='text-align: center;'> E. Mr. Kitayuta vs. Bamboos</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mr. Kitayuta's garden is planted with *n* bamboos. (Bamboos are tall, fast-growing tropical plants with hollow stems.) At the moment, the height of the *i*-th bamboo is *h**i* meters, and it grows *a**i* meters at the end of each day. 

Actually, Mr. Kitayuta hates these bamboos. He once attempted to cut them down, but failed because their stems are too hard. Mr. Kitayuta have not given up, however. He has crafted Magical Hammer with his intelligence to drive them into the ground.

He can use Magical Hammer at most *k* times during each day, due to his limited Magic Power. Each time he beat a bamboo with Magical Hammer, its height decreases by *p* meters. If the height would become negative by this change, it will become 0 meters instead (it does not disappear). In other words, if a bamboo whose height is *h* meters is beaten with Magical Hammer, its new height will be *max*(0, *h* - *p*) meters. It is possible to beat the same bamboo more than once in a day.

Mr. Kitayuta will fight the bamboos for *m* days, starting today. His purpose is to minimize the height of the tallest bamboo after *m* days (that is, *m* iterations of "Mr. Kitayuta beats the bamboos and then they grow"). Find the lowest possible height of the tallest bamboo after *m* days.

## Input

The first line of the input contains four space-separated integers *n*, *m*, *k* and *p* (1 ≤ *n* ≤ 105, 1 ≤ *m* ≤ 5000, 1 ≤ *k* ≤ 10, 1 ≤ *p* ≤ 109). They represent the number of the bamboos in Mr. Kitayuta's garden, the duration of Mr. Kitayuta's fight in days, the maximum number of times that Mr. Kitayuta beat the bamboos during each day, and the power of Magic Hammer, respectively.

The following *n* lines describe the properties of the bamboos. The *i*-th of them (1 ≤ *i* ≤ *n*) contains two space-separated integers *h**i* and *a**i* (0 ≤ *h**i* ≤ 109, 1 ≤ *a**i* ≤ 109), denoting the initial height and the growth rate of the *i*-th bamboo, respectively.

## Output

Print the lowest possible height of the tallest bamboo after *m* days.

## Examples

## Input


```
3 1 2 5  
10 10  
10 10  
15 2  

```
## Output


```
17  

```
## Input


```
2 10 10 1000000000  
0 10  
0 10  

```
## Output


```
10  

```
## Input


```
5 3 3 10  
9 5  
9 2  
4 7  
9 10  
3 8  

```
## Output


```
14  

```


#### tags 

#2900 #binary_search #greedy 