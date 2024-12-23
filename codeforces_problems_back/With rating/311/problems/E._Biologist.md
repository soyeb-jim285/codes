<h1 style='text-align: center;'> E. Biologist</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

SmallR is a biologist. Her latest research finding is how to change the sex of dogs. In other words, she can change female dogs into male dogs and vice versa.

She is going to demonstrate this technique. Now SmallR has *n* dogs, the costs of each dog's change may be different. The dogs are numbered from 1 to *n*. The cost of change for dog *i* is *v**i* RMB. By the way, this technique needs a kind of medicine which can be valid for only one day. So the experiment should be taken in one day and each dog can be changed at most once.

This experiment has aroused extensive attention from all sectors of society. There are *m* rich folks which are suspicious of this experiment. They all want to bet with SmallR forcibly. If SmallR succeeds, the *i*-th rich folk will pay SmallR *w**i* RMB. But it's strange that they have a special method to determine whether SmallR succeeds. For *i*-th rich folk, in advance, he will appoint certain *k**i* dogs and certain one gender. He will think SmallR succeeds if and only if on some day the *k**i* appointed dogs are all of the appointed gender. Otherwise, he will think SmallR fails.

If SmallR can't satisfy some folk that isn't her friend, she need not pay him, but if someone she can't satisfy is her good friend, she must pay *g* RMB to him as apologies for her fail.

Then, SmallR hope to acquire money as much as possible by this experiment. Please figure out the maximum money SmallR can acquire. By the way, it is possible that she can't obtain any money, even will lose money. Then, please give out the minimum money she should lose.

## Input

The first line contains three integers *n*, *m*, *g* (1 ≤ *n* ≤ 104, 0 ≤ *m* ≤ 2000, 0 ≤ *g* ≤ 104). The second line contains *n* integers, each is 0 or 1, the sex of each dog, 0 represent the female and 1 represent the male. The third line contains *n* integers *v*1, *v*2, ..., *v**n* (0 ≤ *v**i* ≤ 104).

Each of the next *m* lines describes a rich folk. On the *i*-th line the first number is the appointed sex of *i*-th folk (0 or 1), the next two integers are *w**i* and *k**i* (0 ≤ *w**i* ≤ 104, 1 ≤ *k**i* ≤ 10), next *k**i* distinct integers are the indexes of appointed dogs (each index is between 1 and *n*). The last number of this line represents whether *i*-th folk is SmallR's good friend (0 — no or 1 — yes).

## Output

Print a single integer, the maximum money SmallR can gain. Note that the integer is negative if SmallR will lose money. 

## Examples

## Input


```
5 5 9  
0 1 1 1 0  
1 8 6 2 3  
0 7 3 3 2 1 1  
1 8 1 5 1  
1 0 3 2 1 4 1  
0 8 3 4 2 1 0  
1 7 2 4 1 1  

```
## Output


```
2  

```
## Input


```
5 5 8  
1 0 1 1 1  
6 5 4 2 8  
0 6 3 2 3 4 0  
0 8 3 3 2 4 0  
0 0 3 3 4 1 1  
0 10 3 4 3 1 1  
0 4 3 3 4 1 1  

```
## Output


```
16  

```


#### tags 

#2300 #flows 