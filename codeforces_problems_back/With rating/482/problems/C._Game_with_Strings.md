<h1 style='text-align: center;'> C. Game with Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You play the game with your friend. The description of this game is listed below. 

Your friend creates *n* distinct strings of the same length *m* and tells you all the strings. Then he randomly chooses one of them. He chooses strings equiprobably, i.e. the probability of choosing each of the *n* strings equals ![](images/68d6f939906e1ed93f58f66830326d540298fdfa.png). You want to guess which string was chosen by your friend. 

In order to guess what string your friend has chosen, you are allowed to ask him questions. Each question has the following form: «What character stands on position *pos* in the string you have chosen?» A string is considered guessed when the answers to the given questions uniquely identify the string. After the string is guessed, you stop asking questions. 

You do not have a particular strategy, so as each question you equiprobably ask about a position that hasn't been yet mentioned. Your task is to determine the expected number of questions needed to guess the string chosen by your friend.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 50) — the number of strings your friend came up with.

The next *n* lines contain the strings that your friend has created. It is guaranteed that all the strings are distinct and only consist of large and small English letters. Besides, the lengths of all strings are the same and are between 1 to 20 inclusive.

## Output

Print the single number — the expected value. Your answer will be considered correct if its absolute or relative error doesn't exceed 10- 9.

## Examples

## Input


```
2  
aab  
aac  

```
## Output


```
2.000000000000000  

```
## Input


```
3  
aaA  
aBa  
Caa  

```
## Output


```
1.666666666666667  

```
## Input


```
3  
aca  
vac  
wqq  

```
## Output


```
1.000000000000000  

```
## Note

In the first sample the strings only differ in the character in the third position. So only the following situations are possible: 

* you guess the string in one question. The event's probability is ![](images/adaad783a304f9e72218e6e79114c6551a112aad.png);
* you guess the string in two questions. The event's probability is ![](images/caddcdaf0d707d9e4ffa41e63e462a3c90474546.png) · ![](images/6bb1686dc4a3e6a10e00b92d434455668cb330a8.png) = ![](images/adaad783a304f9e72218e6e79114c6551a112aad.png) (as in this case the first question should ask about the position that is other than the third one);
* you guess the string in three questions. The event's probability is ![](images/caddcdaf0d707d9e4ffa41e63e462a3c90474546.png) · ![](images/6bb1686dc4a3e6a10e00b92d434455668cb330a8.png) · ![](images/a53d50910d43b79b6602f97f9fde950c9d1bdf77.png) = ![](images/adaad783a304f9e72218e6e79114c6551a112aad.png);

Thus, the expected value is equal to ![](images/5f789afab0601bacf9123c73584184ef358740fb.png)

In the second sample we need at most two questions as any pair of questions uniquely identifies the string. So the expected number of questions is ![](images/208df5d4b6316ba263eede5d4cf4b844075718f1.png).

In the third sample whatever position we ask about in the first question, we immediately identify the string.



#### tags 

#2600 #bitmasks #dp #probabilities 