<h1 style='text-align: center;'> H. Pokermon League challenge</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Welcome to the world of Pokermon, yellow little mouse-like creatures, who absolutely love playing poker! 

Yeah, right… 

In the ensuing Pokermon League, there are *n* registered Pokermon trainers, and *t* existing trainer teams each of which belongs to one of two conferences. Since there is a lot of jealousy between trainers, there are *e* pairs of trainers who hate each other. Their hate is mutual, there are no identical pairs among these, and no trainer hates himself (the world of Pokermon is a joyful place!). Each trainer has a wish-list of length *l**i* of teams he’d like to join.

Your task is to divide players into teams and the teams into two conferences, so that: 

* each trainer belongs to exactly one team;
* no team is in both conferences;
* total hate between conferences is at least *e* / 2;
* every trainer is in a team from his wish-list.

Total hate between conferences is calculated as the number of pairs of trainers from teams from different conferences who hate each other. 

## Input

The first line of the input contains two integer *n* (4 ≤ *n* ≤ 50 000) and *e* (2 ≤ *e* ≤ 100 000) — the total number of Pokermon trainers and the number of pairs of trainers who hate each other.

Pokermon trainers are numbered from 1 to *n*. Next *e* lines contain two integers *a* and *b* (1 ≤ *a*, *b* ≤ *n*) indicating that Pokermon trainers *a* and *b* hate each other. Next 2*n* lines are in a following format. Starting with Pokermon trainer 1, for each trainer in consecutive order: first number *l**i* (16 ≤ *l**i* ≤ 20) — a size of Pokermon trainers wish list, then *l**i* positive integers *t**i*, *j* (1 ≤ *t**i*, *j* ≤ *T*), providing the teams the *i*-th trainer would like to be on.

Each trainers wish list will contain each team no more than once. Teams on the wish lists are numbered in such a way that the set of all teams that appear on at least 1 wish list is set of consecutive positive integers {1, 2, 3, …, *T*}. Here *T* might be up to 1 000 000.

## Output

Print two lines. The first line should contain *n* numbers, specifying for each trainer the team he is in.

The second line should contain *T* numbers, specifying the conference for each team (1 or 2).

## Example

## Input


```
4 3  
1 2  
2 3  
4 1  
16  
1 2 3 4 5 6 7 8 9 10 11 12 13 14 16 15  
16  
2 3 4 5 6 7 8 9 10 11 12 13 14 15 17 18  
16  
2 3 4 5 6 7 8 9 10 11 12 13 14 15 18 19  
16  
1 2 3 4 5 6 7 8 9 10 11 12 13 14 16 19  

```
## Output


```
16 15 19 14   
2 2 2 1 1 1 2 1 1 2 1 1 1 2 2 1 1 1 1 
```
## Note



#### tags 

#2400 #math #probabilities 