# Tutorial_(en)


### [1099A - Snowball](https://codeforces.com/contest/1099/problem/A "Codeforces Round 530 (Div. 2)")

This problem can be solved in many ways, we will tell you one of them. Let's just iterate through all the heights of $i$ from $h$ to $1$. Inside the loop, we have to add $i$ to the weight of snowball, and then check whether there is a stone at this height. If there is, then you need to check whether weight of snowball is more than weight of the stone. If more — then subtract the weight of the stone from weight of snowball, if not — then assign the weight of snowball value 0. 

Code: ism_OK_tutorial

 Tutorial is loading... Tutorial is loading... 
### [1099D - Sum in the tree](https://codeforces.com/contest/1099/problem/D "Codeforces Round 530 (Div. 2)")

To achieve the minimum possible sum of values in the tree, for vertices with even depth we need to put 0 for leaves and the maximum value possible for other vertices, because increasing the value does not make the resulting sum worse — our children would compensate for it. Since av≥0, it's obvious that spv≤spv+av=sv. For every child u of vertex v it's also true that sv≤su, hence spv≤sv≤su. From this one can derive that the maximum possible av for vertices with even hv equals minu − child vsu−spv.

Given the values av in the vertices of even depth, we can restore the values in the vertices of odd depth using the formula av=sv−spv. This requires a simple DFS (which translated to a for-loop given the tree representation in the problem statement).

 Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading...