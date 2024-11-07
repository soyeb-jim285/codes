<h1 style='text-align: center;'> E. Thwarting Demonstrations</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It is dark times in Berland. Berlyand opposition, funded from a neighboring state, has organized a demonstration in Berland capital Bertown. Through the work of intelligence we know that the demonstrations are planned to last for *k* days.

Fortunately, Berland has a special police unit, which can save the country. It has exactly *n* soldiers numbered from 1 to *n*. Berland general, the commander of the detachment, must schedule the detachment's work in these difficult *k* days. In each of these days, the general must send a certain number of police officers to disperse riots. Since the detachment is large and the general is not very smart, he can only select a set of all soldiers numbered from *l* to *r*, inclusive, where *l* and *r* are selected arbitrarily.

Now the general has exactly two problems. First, he cannot send the same group twice — then soldiers get bored and they rebel. Second, not all soldiers are equally reliable. Every soldier has a reliability of *a**i*. The reliability of the detachment is counted as the sum of reliabilities of soldiers in it. The reliability of a single soldier can be negative, then when you include him in the detachment, he will only spoil things. The general is distinguished by his great greed and shortsightedness, so each day he sends to the dissolution the most reliable group of soldiers possible (that is, of all the groups that have not been sent yet).

The Berland Government has decided to know what would be the minimum reliability of the detachment, sent to disperse the demonstrations during these *k* days. The general himself can not cope with such a difficult task. Help him to not embarrass himself in front of his superiors!

## Input

The first line contains two integers *n* and *k* ![](images/35fc76b4b94691643af90cb2d51781d51a7b2e04.png) — the number of soldiers in the detachment and the number of times somebody goes on duty.

The second line contains *n* space-separated integers *a**i*, their absolute value doesn't exceed 109 — the soldiers' reliabilities.

Please do not use the %lld specifier to read or write 64-bit integers in С++, it is preferred to use cin, cout streams of the %I64d specifier.

## Output

Print a single number — the sought minimum reliability of the groups that go on duty during these *k* days.

## Examples

## Input


```
3 4  
1 4 2  

```
## Output


```
4  

```
## Input


```
4 6  
2 -1 2 -1  

```
## Output


```
1  

```
## Input


```
8 10  
1 -2 3 -4 5 -6 7 -8  

```
## Output


```
2  

```


#### tags 

#2200 #binary_search #data_structures #trees 