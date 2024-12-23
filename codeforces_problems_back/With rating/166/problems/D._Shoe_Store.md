<h1 style='text-align: center;'> D. Shoe Store</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The warehouse in your shop has *n* shoe pairs. Each pair is characterized by two integers: its price *c**i* and its size *s**i*. We know that on this very day all numbers *s**i* are different, that is, there is no more than one pair of each size.

The shop has *m* customers who came at the same time. The customer number *i* has *d**i* money and the size of his feet equals *l**i*. The customer number *i* can buy the pair number *j*, if *c**j* ≤ *d**i*, and also if *l**i* = *s**j* or *l**i* = *s**j* - 1; that is, it is necessary that he has enough money to pay for the shoes. It is also necessary that the size of his feet equals to or is less by 1 than the size of the shoes he chooses.

Your task is to sell some customers pairs of shoes (a pair per person) so as to maximize the sum of the sold pairs *c**j* that is, the profit. It is guaranteed that each customer buys no more than one pair and each pair will be bought by no more than one customer.

## Input

The first input line contains the only integer *n* (1 ≤ *n* ≤ 105) — the number of shoe pairs in the warehouse. Then *n* lines contain the descriptions of pairs of shoes as two integers *c**i* and *s**i* (1 ≤ *c**i*, *s**i* ≤ 109), the numbers are separated by a space. It is guaranteed that all numbers *s**i* are different.

The next line contains an integer *m* (1 ≤ *m* ≤ 105) — the number of customers in the shop. Next *m* lines contain the customers' descriptions as two integers *d**i* and *l**i* (1 ≤ *d**i*, *l**i* ≤ 109), the numbers are separated by a space.

## Output

In the first line print the only integer — the maximum profit you can get from selling shoes. In the second line print an integer *k* — the number of shoe pairs you will sell. In the following *k* lines print the descriptions of the sold pairs — two space-separated integers where the first number is the customer's number and the second number is the number of the shoes the customer will buy.

You can print pairs of numbers "the customer's number and the shoes' number" in any order, the customers and the pairs of shoes are numbered starting from 1 in the order in which they are given in the input. If there are several optimal answers, you are allowed to print any of them.

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is preferred to use the cin, cout streams or the %I64d specificator instead.

## Examples

## Input


```
3  
10 1  
30 2  
20 3  
2  
20 1  
20 2  

```
## Output


```
30  
2  
2 3  
1 1  

```
## Input


```
3  
10 4  
20 5  
30 6  
2  
70 4  
50 5  

```
## Output


```
50  
2  
2 3  
1 2  

```


#### tags 

#2500 #dp #graph_matchings #greedy #sortings #two_pointers 