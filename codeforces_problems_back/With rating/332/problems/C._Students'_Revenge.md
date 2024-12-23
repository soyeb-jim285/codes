<h1 style='text-align: center;'> C. Students' Revenge</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A student's life is fraught with complications. Some Berland University students know this only too well. Having studied for two years, they contracted strong antipathy towards the chairperson of some department. Indeed, the person in question wasn't the kindest of ladies to begin with: prone to reforming groups, banning automatic passes and other mean deeds. At last the students decided that she just can't get away with all this anymore...

The students pulled some strings on the higher levels and learned that the next University directors' meeting is going to discuss *n* orders about the chairperson and accept exactly *p* of them. There are two values assigned to each order: *a**i* is the number of the chairperson's hairs that turn grey if she obeys the order and *b**i* — the displeasement of the directors if the order isn't obeyed. The students may make the directors pass any *p* orders chosen by them. The students know that the chairperson will obey exactly *k* out of these *p* orders. She will pick the orders to obey in the way that minimizes first, the directors' displeasement and second, the number of hairs on her head that turn grey.

The students want to choose *p* orders in the way that maximizes the number of hairs on the chairperson's head that turn grey. If there are multiple ways to accept the orders, then the students are keen on maximizing the directors' displeasement with the chairperson's actions. Help them.

## Input

The first line contains three integers *n* (1 ≤ *n* ≤ 105), *p* (1 ≤ *p* ≤ *n*), *k* (1 ≤ *k* ≤ *p*) — the number of orders the directors are going to discuss, the number of orders to pass and the number of orders to be obeyed by the chairperson, correspondingly. Each of the following *n* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ 109), describing the corresponding order.

## Output

Print in an arbitrary order *p* distinct integers — the numbers of the orders to accept so that the students could carry out the revenge. The orders are indexed from 1 to *n* in the order they occur in the input. If there are multiple solutions, you can print any of them.

## Examples

## Input


```
5 3 2  
5 6  
5 8  
1 3  
4 3  
4 11  

```
## Output


```
3 1 2 
```
## Input


```
5 3 3  
10 18  
18 17  
10 20  
20 18  
20 18  

```
## Output


```
2 4 5 
```
## Note

In the first sample one of optimal solutions is to pass orders 1, 2, 3. In this case the chairperson obeys orders number 1 and 2. She gets 10 new grey hairs in the head and the directors' displeasement will equal 3. ## Note

 that the same result can be achieved with order 4 instead of order 3.

In the second sample, the chairperson can obey all the orders, so the best strategy for the students is to pick the orders with the maximum sum of *a**i* values. The chairperson gets 58 new gray hairs and the directors' displeasement will equal 0.



#### tags 

#2200 #data_structures #greedy #sortings 