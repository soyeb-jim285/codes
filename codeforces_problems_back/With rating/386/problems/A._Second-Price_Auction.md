<h1 style='text-align: center;'> A. Second-Price Auction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In this problem we consider a special type of an auction, which is called the second-price auction. As in regular auction *n* bidders place a bid which is price a bidder ready to pay. The auction is closed, that is, each bidder secretly informs the organizer of the auction price he is willing to pay. After that, the auction winner is the participant who offered the highest price. However, he pay not the price he offers, but the highest price among the offers of other participants (hence the name: the second-price auction).

Write a program that reads prices offered by bidders and finds the winner and the price he will pay. Consider that all of the offered prices are different.

## Input

The first line of the input contains *n* (2 ≤ *n* ≤ 1000) — number of bidders. The second line contains *n* distinct integer numbers *p*1, *p*2, ... *p**n*, separated by single spaces (1 ≤ *p**i* ≤ 10000), where *p**i* stands for the price offered by the *i*-th bidder.

## Output

The single output line should contain two integers: index of the winner and the price he will pay. Indices are 1-based.

## Examples

## Input


```
2  
5 7  

```
## Output


```
2 5  

```
## Input


```
3  
10 2 8  

```
## Output


```
1 8  

```
## Input


```
6  
3 8 2 9 4 14  

```
## Output


```
6 9  

```


#### tags 

#800 #implementation 