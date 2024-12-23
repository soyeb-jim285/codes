<h1 style='text-align: center;'> E. Champions' League</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the autumn of this year, two Russian teams came into the group stage of the most prestigious football club competition in the world — the UEFA Champions League. Now, these teams have already started to play in the group stage and are fighting for advancing to the playoffs. In this problem we are interested in the draw stage, the process of sorting teams into groups.

The process of the draw goes as follows (the rules that are described in this problem, are somehow simplified compared to the real life). Suppose *n* teams will take part in the group stage (*n* is divisible by four). The teams should be divided into groups of four. Let's denote the number of groups as *m* (![](images/13019141edafe189dbacd60412f77f63699d44aa.png)). Each team has a rating — an integer characterizing the team's previous achievements. The teams are sorted by the rating's decreasing (no two teams have the same rating).

After that four "baskets" are formed, each of which will contain *m* teams: the first *m* teams with the highest rating go to the first basket, the following *m* teams go to the second one, and so on.

Then the following procedure repeats *m* - 1 times. A team is randomly taken from each basket, first from the first basket, then from the second, then from the third, and at last, from the fourth. The taken teams form another group. After that, they are removed from their baskets.

The four teams remaining in the baskets after (*m* - 1) such procedures are performed, form the last group.

In the real draw the random selection of teams from the basket is performed by people — as a rule, the well-known players of the past. As we have none, we will use a random number generator, which is constructed as follows. Its parameters are four positive integers *x*, *a*, *b*, *c*. Every time there is a call to the random number generator, it produces the following actions:

* calculates ![](images/44744603ac8523bac49217521d90f292153f5ac7.png);
* replaces parameter *x* by value *y* (assigns ![](images/810fe5b3c3f14483992c0349a68e310af9dc33a6.png));
* returns *x* as another random number.

Operation ![](images/aaf97e0135932f06441d41a3e2bc9a1eb624ba0b.png) means taking the remainder after division: ![](images/fdf2c6c9b006bda0fc4ecb27e3a247928900304f.png), ![](images/c7f45e6d2540ce9ce9c5f6930f24d24754ca4cd6.png).

A random number generator will be used in the draw as follows: each time we need to randomly choose a team from the basket, it will generate a random number *k*. The teams that yet remain in the basket are considered numbered with consecutive integers from 0 to *s* - 1, in the order of decreasing rating, where *s* is the current size of the basket. Then a team number ![](images/3d2af9d6ee6eb0c1d0c13528425cf2054334014f.png) is taken from the basket.

Given a list of teams and the parameters of the random number generator, determine the result of the draw. 

## Input

The first input line contains integer *n* (4 ≤ *n* ≤ 64, *n* is divisible by four) — the number of teams that take part in the sorting. The second line contains four space-separated integers *x*, *a*, *b*, *c* (1 ≤ *x*, *a*, *b*, *c* ≤ 1000) — the parameters of the random number generator. Each of the following *n* lines describes one team. The description consists of the name of the team and its rating, separated by a single space. The name of a team consists of uppercase and lowercase English letters and has length from 1 to 20 characters. A team's rating is an integer from 0 to 1000. All teams' names are distinct. All team's ratings are also distinct.

## Output

Print the way the teams must be sorted into groups. Print the groups in the order, in which they are formed in the sorting. Number the groups by consecutive uppercase English letters, starting from letter 'A'. Inside each group print the teams' names one per line, in the order of decreasing of the teams' rating. See samples for a better understanding of the output format.

## Examples

## Input


```
8  
1 3 1 7  
Barcelona 158  
Milan 90  
Spartak 46  
Anderlecht 48  
Celtic 32  
Benfica 87  
Zenit 79  
Malaga 16  

```
## Output


```
Group A:  
Barcelona  
Benfica  
Spartak  
Celtic  
Group B:  
Milan  
Zenit  
Anderlecht  
Malaga  

```
## Note

In the given sample the random number generator will be executed four times: 

* ![](images/2d76d911e7446d6db4b0be2679ce6e5ab930ab92.png),
* ![](images/cc339c0d810046d7adb9ef4339e48f5554842ae2.png),
* ![](images/74fb01e5b91f6c73ead806139c45f3e73fa1232d.png),
* ![](images/f8a9ac4805dfae22b7d7a65c5daa8f4cc5a21a5a.png).


#### tags 

#1600 #implementation 