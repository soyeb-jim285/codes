<h1 style='text-align: center;'> D. My pretty girl Noora</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Pavlopolis University where Noora studies it was decided to hold beauty contest "Miss Pavlopolis University". Let's describe the process of choosing the most beautiful girl in the university in more detail.

The contest is held in several stages. Suppose that exactly *n* girls participate in the competition initially. All the participants are divided into equal groups, *x* participants in each group. Furthermore the number *x* is chosen arbitrarily, i. e. on every stage number *x* can be different. Within each group the jury of the contest compares beauty of the girls in the format "each with each". In this way, if group consists of *x* girls, then ![](images/90eda7186d150a31a8a1f356c79097a0591eb8c0.png) comparisons occur. Then, from each group, the most beautiful participant is selected. Selected girls enter the next stage of the competition. Thus if *n* girls were divided into groups, *x* participants in each group, then exactly ![](images/73ee00e56876de3fc3efc21fb6d81038dff5ed20.png) participants will enter the next stage. The contest continues until there is exactly one girl left who will be "Miss Pavlopolis University"

But for the jury this contest is a very tedious task. They would like to divide the girls into groups in each stage so that the total number of pairwise comparisons of the girls is as few as possible. Let *f*(*n*) be the minimal total number of comparisons that should be made to select the most beautiful participant, if we admit *n* girls to the first stage.

The organizers of the competition are insane. They give Noora three integers *t*, *l* and *r* and ask the poor girl to calculate the value of the following expression: *t*0·*f*(*l*) + *t*1·*f*(*l* + 1) + ... + *t**r* - *l*·*f*(*r*). However, since the value of this expression can be quite large the organizers ask her to calculate it modulo 109 + 7. If Noora can calculate the value of this expression the organizers promise her to help during the beauty contest. But the poor girl is not strong in mathematics, so she turned for help to Leha and he turned to you.

## Input

The first and single line contains three integers *t*, *l* and *r* (1 ≤ *t* < 109 + 7, 2 ≤ *l* ≤ *r* ≤ 5·106).

## Output

In the first line print single integer — the value of the expression modulo 109 + 7.

## Example

## Input


```
2 2 4  

```
## Output


```
19  

```
## Note

Consider the sample.

It is necessary to find the value of ![](images/3ecc798906ae9e9852061ba2dd5cf6b8fce7753b.png).

*f*(2) = 1. From two girls you can form only one group of two people, in which there will be one comparison.

*f*(3) = 3. From three girls you can form only one group of three people, in which there will be three comparisons.

*f*(4) = 3. From four girls you can form two groups of two girls each. Then at the first stage there will be two comparisons, one in each of the two groups. In the second stage there will be two girls and there will be one comparison between them. Total 2 + 1 = 3 comparisons. You can also leave all girls in same group in the first stage. Then ![](images/fcc6c9e72a1525cc01abbfb89094669a9d37d3b1.png) comparisons will occur. Obviously, it's better to split girls into groups in the first way.

Then the value of the expression is ![](images/2c5a0f75c9d910ec77b2fe675e690de453060631.png).



#### tags 

#1800 #brute_force #dp #greedy #math #number_theory 