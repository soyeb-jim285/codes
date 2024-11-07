<h1 style='text-align: center;'> B. Alternating Current</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mad scientist Mike has just finished constructing a new device to search for extraterrestrial intelligence! He was in such a hurry to launch it for the first time that he plugged in the power wires without giving it a proper glance and started experimenting right away. After a while Mike observed that the wires ended up entangled and now have to be untangled again.

The device is powered by two wires "plus" and "minus". The wires run along the floor from the wall (on the left) to the device (on the right). Both the wall and the device have two contacts in them on the same level, into which the wires are plugged in some order. The wires are considered entangled if there are one or more places where one wire runs above the other one. For example, the picture below has four such places (top view):

 ![](images/d9893064977f0a3ba06c4b18908f20c7ef488731.png) Mike knows the sequence in which the wires run above each other. Mike also noticed that on the left side, the "plus" wire is always plugged into the top contact (as seen on the picture). He would like to untangle the wires without unplugging them and without moving the device. Determine if it is possible to do that. A wire can be freely moved and stretched on the floor, but cannot be cut.

To understand the problem better please read the notes to the test samples.

## Input

The single line of the input contains a sequence of characters "+" and "-" of length *n* (1 ≤ *n* ≤ 100000). The *i*-th (1 ≤ *i* ≤ *n*) position of the sequence contains the character "+", if on the *i*-th step from the wall the "plus" wire runs above the "minus" wire, and the character "-" otherwise.

## Output

Print either "Yes" (without the quotes) if the wires can be untangled or "No" (without the quotes) if the wires cannot be untangled.

## Examples

## Input


```
-++-  

```
## Output


```
Yes  

```
## Input


```
+-  

```
## Output


```
No  

```
## Input


```
++  

```
## Output


```
Yes  

```
## Input


```
-  

```
## Output


```
No  

```
## Note

The first testcase corresponds to the picture in the statement. To untangle the wires, one can first move the "plus" wire lower, thus eliminating the two crosses in the middle, and then draw it under the "minus" wire, eliminating also the remaining two crosses.

In the second testcase the "plus" wire makes one full revolution around the "minus" wire. Thus the wires cannot be untangled: 

 ![](images/ab7cf5aedea609efdfcd91bf5ece433ff50d80fe.png) In the third testcase the "plus" wire simply runs above the "minus" wire twice in sequence. The wires can be untangled by lifting "plus" and moving it higher: 

 ![](images/c3d652f33419ce743e0f2e4e951b77f90915151b.png) In the fourth testcase the "minus" wire runs above the "plus" wire once. The wires cannot be untangled without moving the device itself: 

 ![](images/ca61897e6664278c14115d010a07b6023c28e833.png) 

#### tags 

#1600 #data_structures #greedy #implementation 