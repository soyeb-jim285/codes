<h1 style='text-align: center;'> D. Bishwock</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bishwock is a chess figure that consists of three squares resembling an "L-bar". This figure can be rotated by 90, 180 and 270 degrees so it can have four possible states:

 
```text
  
XX   XX   .X   X.  
X.   .X   XX   XX  

```
 Bishwocks don't attack any squares and can even occupy on the adjacent squares as long as they don't occupy the same square. 

Vasya has a board with $2\times n$ squares onto which he wants to put some bishwocks. To his dismay, several squares on this board are already occupied by pawns and Vasya can't put bishwocks there. However, pawns also don't attack bishwocks and they can occupy adjacent squares peacefully.

Knowing the positions of pawns on the board, help Vasya to determine the maximum amount of bishwocks he can put onto the board so that they wouldn't occupy the same squares and wouldn't occupy squares with pawns.

###### Input

The input contains two nonempty strings that describe Vasya's board. Those strings contain only symbols "0" (zero) that denote the empty squares and symbols "X" (uppercase English letter) that denote the squares occupied by pawns. Strings are nonempty and are of the same length that does not exceed $100$.

###### Output

###### Output

 a single integer — the maximum amount of bishwocks that can be placed onto the given board.

## Examples

###### Input


```text
00  
00  

```
###### Output


```text
1
```
###### Input


```text
00X00X0XXX0  
0XXX0X00X00  

```
###### Output


```text
4
```
###### Input


```text
0X0X0  
0X0X0  

```
###### Output


```text
0
```
###### Input


```text
0XXX0  
00000  

```
###### Output


```text
2
```


#### Tags 

#1500 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_491_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
