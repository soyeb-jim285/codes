<h1 style='text-align: center;'> C. Constanze's Machine</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Constanze is the smartest girl in her village but she has bad eyesight.

One day, she was able to invent an incredible machine! When you pronounce letters, the machine will inscribe them onto a piece of paper. For example, if you pronounce 'c', 'o', 'd', and 'e' in that order, then the machine will inscribe "code" onto the paper. Thanks to this machine, she can finally write messages without using her glasses.

However, her dumb friend Akko decided to play a prank on her. Akko tinkered with the machine so that if you pronounce 'w', it will inscribe "uu" instead of "w", and if you pronounce 'm', it will inscribe "nn" instead of "m"! Since Constanze had bad eyesight, she was not able to realize what Akko did.

The rest of the letters behave the same as before: if you pronounce any letter besides 'w' and 'm', the machine will just inscribe it onto a piece of paper.

The next day, I received a letter in my mailbox. I can't understand it so I think it's either just some gibberish from Akko, or Constanze made it using her machine. But since I know what Akko did, I can just list down all possible strings that Constanze's machine would have turned into the message I got and see if anything makes sense.

But I need to know how much paper I will need, and that's why I'm asking you for help. Tell me the number of strings that Constanze's machine would've turned into the message I got.

But since this number can be quite large, tell me instead its remainder when divided by $10^9+7$.

If there are no strings that Constanze's machine would've turned into the message I got, then print $0$.

###### Input

###### Input

 consists of a single line containing a string $s$ ($1 \leq |s| \leq 10^5$) — the received message. $s$ contains only lowercase Latin letters.

###### Output

Print a single integer — the number of strings that Constanze's machine would've turned into the message $s$, modulo $10^9+7$.

## Examples

###### Input


```text
ouuokarinn
```
###### Output


```text
4
```
###### Input


```text
banana
```
###### Output


```text
1
```
###### Input


```text
nnn
```
###### Output


```text
3
```
###### Input


```text
amanda
```
###### Output


```text
0
```
## Note

For the first example, the candidate strings are the following: "ouuokarinn", "ouuokarim", "owokarim", and "owokarinn".

For the second example, there is only one: "banana".

For the third example, the candidate strings are the following: "nm", "mn" and "nnn".

For the last example, there are no candidate strings that the machine can turn into "amanda", since the machine won't inscribe 'm'.



#### Tags 

#1400 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_597_(Div._2).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [Announcement #2 (en)](../blogs/Announcement_2_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
