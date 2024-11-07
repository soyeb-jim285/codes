<h1 style='text-align: center;'> B. T-shirt buying</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A new pack of *n* t-shirts came to a shop. Each of the t-shirts is characterized by three integers *p**i*, *a**i* and *b**i*, where *p**i* is the price of the *i*-th t-shirt, *a**i* is front color of the *i*-th t-shirt and *b**i* is back color of the *i*-th t-shirt. All values *p**i* are distinct, and values *a**i* and *b**i* are integers from 1 to 3.

*m* buyers will come to the shop. Each of them wants to buy exactly one t-shirt. For the *j*-th buyer we know his favorite color *c**j*.

A buyer agrees to buy a t-shirt, if at least one side (front or back) is painted in his favorite color. Among all t-shirts that have colors acceptable to this buyer he will choose the cheapest one. If there are no such t-shirts, the buyer won't buy anything. Assume that the buyers come one by one, and each buyer is served only after the previous one is served.

You are to compute the prices each buyer will pay for t-shirts.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 200 000) — the number of t-shirts.

The following line contains sequence of integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ 1 000 000 000), where *p**i* equals to the price of the *i*-th t-shirt.

The following line contains sequence of integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 3), where *a**i* equals to the front color of the *i*-th t-shirt.

The following line contains sequence of integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 3), where *b**i* equals to the back color of the *i*-th t-shirt.

The next line contains single integer *m* (1 ≤ *m* ≤ 200 000) — the number of buyers. 

The following line contains sequence *c*1, *c*2, ..., *c**m* (1 ≤ *c**j* ≤ 3), where *c**j* equals to the favorite color of the *j*-th buyer. The buyers will come to the shop in the order they are given in the input. Each buyer is served only after the previous one is served.

 

## Output

Print to the first line *m* integers — the *j*-th integer should be equal to the price of the t-shirt which the *j*-th buyer will buy. If the *j*-th buyer won't buy anything, print -1.

## Examples

## Input


```
5  
300 200 400 500 911  
1 2 1 2 3  
2 1 3 2 1  
6  
2 3 1 2 1 1  

```
## Output


```
200 400 300 500 911 -1   

```
## Input


```
2  
1000000000 1  
1 1  
1 2  
2  
2 1  

```
## Output


```
1 1000000000   

```


#### tags 

#1400 #data_structures #implementation 