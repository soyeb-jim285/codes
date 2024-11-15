<h1 style='text-align: center;'> D. Help Monks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a far away kingdom is the famous Lio Shan monastery. Gods constructed three diamond pillars on the monastery's lawn long ago. Gods also placed on one pillar *n* golden disks of different diameters (in the order of the diameters' decreasing from the bottom to the top). Besides, gods commanded to carry all the disks from the first pillar to the third one according to the following rules:

* you can carry only one disk in one move;
* you cannot put a larger disk on a smaller one.

 There was no universal opinion concerning what is to happen after the gods' will is done: some people promised world peace and eternal happiness to everyone, whereas others predicted that the kingdom will face communi… (gee, what am I rambling about?) the Armageddon. However, as everybody knew that it was impossible to solve the problem in less than 2*n* - 1 moves and the lazy Lio Shan monks never even started to solve it, everyone lives peacefully even though the problem was never solved and nobody was afraid of the Armageddon.However, the monastery wasn't doing so well lately and the wise prior Ku Sean Sun had to cut some disks at the edges and use the gold for the greater good. Wouldn't you think that the prior is entitled to have an air conditioning system? Besides, staying in the monastery all year is sooo dull… One has to have a go at something new now and then, go skiing, for example… Ku Sean Sun realize how big a mistake he had made only after a while: after he cut the edges, the diameters of some disks got the same; that means that some moves that used to be impossible to make, were at last possible (why, gods never prohibited to put a disk on a disk of the same diameter). Thus, the possible Armageddon can come earlier than was initially planned by gods. Much earlier. So much earlier, in fact, that Ku Sean Sun won't even have time to ski all he wants or relax under the air conditioner.

The wise prior could never let that last thing happen and he asked one very old and very wise witch PikiWedia to help him. May be she can determine the least number of moves needed to solve the gods' problem. However, the witch laid out her cards and found no answer for the prior. Then he asked you to help him.

Can you find the shortest solution of the problem, given the number of disks and their diameters? Keep in mind that it is allowed to place disks of the same diameter one on the other one, however, the order in which the disks are positioned on the third pillar in the end should match the initial order of the disks on the first pillar.

## Input

The first line contains an integer *n* — the number of disks (1 ≤ *n* ≤ 20). The second line contains *n* integers *d**i* — the disks' diameters after Ku Sean Sun cut their edges. The diameters are given from the bottom to the top (1 ≤ *d**i* ≤ 20, besides, *d**i* ≥ *d**i* + 1 for any 1 ≤ *i* < *n*).

## Output

Print on the first line number *m* — the smallest number of moves to solve the gods' problem. Print on the next *m* lines the description of moves: two space-separated positive integers *s**i* and *t**i* that determine the number of the pillar from which the disk is moved and the number of pillar where the disk is moved, correspondingly (1 ≤ *s**i*, *t**i* ≤ 3, *s**i* ≠ *t**i*). 

## Examples

## Input


```
3  
3 2 1  

```
## Output


```
7  
1 3  
1 2  
3 2  
1 3  
2 1  
2 3  
1 3  

```
## Input


```
3  
3 1 1  

```
## Output


```
5  
1 2  
1 2  
1 3  
2 3  
2 3  

```
## Input


```
3  
3 3 3  

```
## Output


```
5  
1 2  
1 2  
1 3  
2 3  
2 3  

```
## Note

Pay attention to the third test demonstrating that the order of disks should remain the same in the end, even despite the disks' same radius. If this condition was not necessary to fulfill, the gods' task could have been solved within a smaller number of moves (three — simply moving the three disks from the first pillar on the third one).



#### tags 

#2500 #constructive_algorithms 