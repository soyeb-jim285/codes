<h1 style='text-align: center;'> D. Leaving Auction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* people taking part in auction today. The rules of auction are classical. There were *n* bids made, though it's not guaranteed they were from different people. It might happen that some people made no bids at all.

Each bid is define by two integers (*a**i*, *b**i*), where *a**i* is the index of the person, who made this bid and *b**i* is its size. Bids are given in chronological order, meaning *b**i* < *b**i* + 1 for all *i* < *n*. Moreover, participant never makes two bids in a row (no one updates his own bid), i.e. *a**i* ≠ *a**i* + 1 for all *i* < *n*.

Now you are curious with the following question: who (and which bid) will win the auction if some participants were absent? Consider that if someone was absent, all his bids are just removed and no new bids are added.

## Note

, that if during this imaginary exclusion of some participants it happens that some of the remaining participants makes a bid twice (or more times) in a row, only first of these bids is counted. For better understanding take a look at the samples.

You have several questions in your mind, compute the answer for each of them.

## Input

The first line of the input contains an integer *n* (1 ≤ *n* ≤ 200 000) — the number of participants and bids.

Each of the following *n* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i* ≤ *n*, 1 ≤ *b**i* ≤ 109, *b**i* < *b**i* + 1) — the number of participant who made the *i*-th bid and the size of this bid.

Next line contains an integer *q* (1 ≤ *q* ≤ 200 000) — the number of question you have in mind.

Each of next *q* lines contains an integer *k* (1 ≤ *k* ≤ *n*), followed by *k* integers *l**j* (1 ≤ *l**j* ≤ *n*) — the number of people who are not coming in this question and their indices. It is guarenteed that *l**j* values are different for a single question.

It's guaranteed that the sum of *k* over all question won't exceed 200 000.

## Output

For each question print two integer — the index of the winner and the size of the winning bid. If there is no winner (there are no remaining bids at all), print two zeroes.

## Examples

## Input


```
6  
1 10  
2 100  
3 1000  
1 10000  
2 100000  
3 1000000  
3  
1 3  
2 2 3  
2 1 2  

```
## Output


```
2 100000  
1 10  
3 1000  

```
## Input


```
3  
1 10  
2 100  
1 1000  
2  
2 1 2  
2 2 3  

```
## Output


```
0 0  
1 10  

```
## Note

Consider the first sample: 

* In the first question participant number 3 is absent so the sequence of bids looks as follows:
	1. 1 10
	2. 2 100
	3. 1 10 000
	4. 2 100 000 Participant number 2 wins with the bid 100 000.
* In the second question participants 2 and 3 are absent, so the sequence of bids looks:
	1. 1 10
	2. 1 10 000 The winner is, of course, participant number 1 but the winning bid is 10 instead of 10 000 as no one will ever increase his own bid (in this problem).
* In the third question participants 1 and 2 are absent and the sequence is:
	1. 3 1 000
	2. 3 1 000 000 The winner is participant 3 with the bid 1 000.


#### tags 

#2000 #binary_search #data_structures 