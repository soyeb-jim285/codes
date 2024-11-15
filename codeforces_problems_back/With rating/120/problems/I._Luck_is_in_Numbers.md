<h1 style='text-align: center;'> I. Luck is in Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has been collecting transport tickets for quite a while now. His collection contains several thousands of tram, trolleybus and bus tickets. Vasya is already fed up with the traditional definition of what a lucky ticket is. Thus, he's looking for new perspectives on that. Besides, Vasya cannot understand why all tickets are only divided into lucky and unlucky ones. He thinks that all tickets are lucky but in different degrees. Having given the matter some thought, Vasya worked out the definition of a ticket's degree of luckiness. Let a ticket consist of 2*n* digits. Let's regard each digit as written as is shown on the picture:

 ![](images/42b0c7b68e74c9ad27619d4229da35d43c605169.png) You have seen such digits on electronic clocks: seven segments are used to show digits. Each segment can either be colored or not. The colored segments form a digit. Vasya regards the digits as written in this very way and takes the right half of the ticket and puts it one the left one, so that the first digit coincides with the *n* + 1-th one, the second digit coincides with the *n* + 2-th one, ..., the *n*-th digit coincides with the 2*n*-th one. For each pair of digits, put one on another, he counts the number of segments colored in both digits and summarizes the resulting numbers. The resulting value is called the degree of luckiness of a ticket. For example, the degree of luckiness of ticket 03 equals four and the degree of luckiness of ticket 2345 equals six.

You are given the number of a ticket containing 2*n* digits. Your task is to find among the tickets whose number exceeds the number of this ticket but also consists of 2*n* digits such ticket, whose degree of luckiness exceeds the degrees of luckiness of the given ticket. Moreover, if there are several such tickets, you should only choose the one with the smallest number.

## Input

The first line contains the number of the ticket that consists of *k* characters (*k* = 2*n*, 1 ≤ *n* ≤ 105). 

## Output

Print the number of the sought ticket or "-1" (without the quotes) if no such ticket exists.

## Examples

## Input


```
13  

```
## Output


```
20  

```
## Input


```
2345  

```
## Output


```
2348  

```
## Input


```
88  

```
## Output


```
-1  

```


#### tags 

#2200 #greedy 