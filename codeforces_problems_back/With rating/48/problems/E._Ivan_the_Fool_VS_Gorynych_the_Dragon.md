<h1 style='text-align: center;'> E. Ivan the Fool VS Gorynych the Dragon</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time in a kingdom far, far away… Okay, let’s start at the point where Ivan the Fool met Gorynych the Dragon. Ivan took out his magic sword and the battle began. First Gorynych had *h* heads and *t* tails. With each strike of the sword Ivan can either cut off several heads (from 1 to *n*, but not more than Gorynych has at the moment), or several tails (from 1 to *m*, but not more than Gorynych has at the moment). At the same time, horrible though it seems, Gorynych the Dragon can also grow new heads and tails. And the number of growing heads and tails is determined uniquely by the number of heads or tails cut by the current strike. When the total number of heads and tails exceeds *R*, Gorynych the Dragon strikes its final blow and destroys Ivan the Fool. That’s why Ivan aims to cut off all the dragon’s heads and tails as quickly as possible and win. The events can also develop in a third way: neither of the opponents can win over the other one and they will continue fighting forever.

The tale goes like this; easy to say, hard to do. Your task is to write a program that will determine the battle’s outcome. Consider that Ivan strikes consecutively. After each blow Gorynych grows a number of new heads and tails depending on the number of cut ones. Gorynych the Dragon is defeated if after the blow he loses all his heads and tails and can’t grow new ones. Ivan fights in the optimal way (fools are lucky), i.e. 

* if Ivan can win, he wins having struck the least number of blows;
* if it is impossible to defeat Gorynych, but is possible to resist him for an infinitely long period of time, then that’s the strategy Ivan chooses;
* if Gorynych wins in any case, Ivan aims to resist him for as long as possible.
## Input

The first line contains three integers *h*, *t* and *R* (0 ≤ *h*, *t*, *R* ≤ 200, 0 < *h* + *t* ≤ *R*) which represent the initial numbers of Gorynych’s heads and tails and the largest total number of heads and tails with which Gorynych the Dragon does not yet attack. The next line contains integer *n* (1 ≤ *n* ≤ 200). The next *n* contain pairs of non-negative numbers "*h**i* *t**i*" which represent the number of heads and the number of tails correspondingly, that will grow if Gorynych has *i* heads (1 ≤ *i* ≤ *n*) cut. The next line contains an integer *m* (1 ≤ *m* ≤ 200) and then — the description of Gorynych’s behavior when his tails are cut off in the format identical to the one described above. All the numbers in the input file do not exceed 200. 

## Output

Print "Ivan" (without quotes) in the first line if Ivan wins, or "Zmey" (that means a dragon in Russian) if Gorynych the Dragon wins. In the second line print a single integer which represents the number of blows Ivan makes. If the battle will continue forever, print in the first line "Draw".

## Examples

## Input


```
2 2 4  
2  
1 0  
0 1  
3  
0 1  
0 1  
0 0  

```
## Output


```
Ivan  
2  

```
## Input


```
2 2 4  
1  
0 1  
1  
1 0  

```
## Output


```
Draw  

```
## Input


```
2 2 5  
1  
1 1  
1  
3 0  

```
## Output


```
Zmey  
2  

```


#### tags 

#2100 #dp #games #graphs 