<h1 style='text-align: center;'> B. Checkout Assistant</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob came to a cash & carry store, put *n* items into his trolley, and went to the checkout counter to pay. Each item is described by its price *c**i* and time *t**i* in seconds that a checkout assistant spends on this item. While the checkout assistant is occupied with some item, Bob can steal some other items from his trolley. To steal one item Bob needs exactly 1 second. What is the minimum amount of money that Bob will have to pay to the checkout assistant? Remember, please, that it is Bob, who determines the order of items for the checkout assistant.

## Input

The first input line contains number *n* (1 ≤ *n* ≤ 2000). In each of the following *n* lines each item is described by a pair of numbers *t**i*, *c**i* (0 ≤ *t**i* ≤ 2000, 1 ≤ *c**i* ≤ 109). If *t**i* is 0, Bob won't be able to steal anything, while the checkout assistant is occupied with item *i*.

## Output

## Output

 one number — answer to the problem: what is the minimum amount of money that Bob will have to pay.

## Examples

## Input


```
4  
2 10  
0 20  
1 5  
1 3  

```
## Output


```
8  

```
## Input


```
3  
0 1  
0 10  
0 100  

```
## Output


```
111  

```


#### tags 

#1900 #dp 