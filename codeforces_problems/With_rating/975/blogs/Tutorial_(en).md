# Tutorial_(en)


### [975A - Aramic script](../problems/A._Aramic_script.md "Codeforces Round 478 (Div. 2)")

One can easily notice that we only differentiate between words when different letters exit, so one easy way to consider all the different words that belong to the same root as one, is to map every word to a mask of 26 bits; that is, for example, if letter 'b' exits in the ith word then we set the second bit in the ith mask to one, eventually, we insert all the masks in a set and the set size is the required answer.

[Solution](https://codeforces.com/https://pastebin.com/XUUxYdqB)

 
### [975B - Mancala](../problems/B._Mancala.md "Codeforces Round 478 (Div. 2)")

in this problem, we brute-force on the optimal hole to choose since there are only 14 holes, but how to calculate how many stones there will be after we start from the ith hole? the process of putting stones is repeating every 14 holes, suppose k is the number of stones in hand now so k/14 will be added to all holes and we simulate adding k mod 14 then we take the maximum answer from all the holes.

[Solution](https://codeforces.com/https://pastebin.com/zdD4NtdF)

 Tutorial is loading...[Solution](https://codeforces.com/https://pastebin.com/fcbXrqy4)

 
### [975D - Ghosts](../problems/D._Ghosts.md "Codeforces Round 478 (Div. 2)")

The condition for two points to meet in a moment of time T is for them to have the same X coordinates and the same Y coordinates. 

Time when they have the same X coordinates is 

X0i+VxiTx=X0j+VxjTx

So Tx should be

Tx=(X0i−X0j)/(Vxj−Vxi)

Time when they will meet on Y axis

Ty=(aX0i−aX0j+b−b)/(Vyj−Vyi)

In order for them to collide Ty=Tx so 

(X0i−X0j)/(Vxj−Vxi)=(aX0i−aX0j+b−b)/(Vyj−Vyi)

so

1/(Vxj−Vxi)=a/(Vyj−Vyi)

So 

aVxj−Vyj=aVxi−Vyi

Meaning that all ghosts with the same aVx−Vy will collide except if they were parallel.

the answer is two times the number of collisions.

[Solution](https://codeforces.com/https://pastebin.com/AKd4c5xt)

 
### [975E - Hag's Khashba](../problems/E._Hag's_Khashba.md "Codeforces Round 478 (Div. 2)")

In this problem, we calculate the center of mass of the polygon (ie its centroid) and then we make it our reference point. we maintain its coordinates after each and every rotation.

Now when the pin is taken out from a vertex it leaves the other pin as a pivot for rotation we calculate the angle of current rotation. calculate the new coordinates of the center of mass after rotation, we should also store the initial distances from the center of mass, and the angle that the polygon had rotated around itself.

from the angle, coordinates of the center of mass and the initial distances from the center of mass it is possible to calculate the coordinates of any point in the polygon.

Note: when calculating the center of mass we should shift the polygon to the (0,0) because in some algorithms it uses point (0,0) in triangulation the polygon. if the polygon is very far from (0,0) accuracy will be lost. so better to either shift the polygon to (0,0) or use the first point of the polygon to form the sub-triangles of the polygon when calculating the center of mass.

[Solution](https://codeforces.com/https://pastebin.com/4VmUcVUR)

