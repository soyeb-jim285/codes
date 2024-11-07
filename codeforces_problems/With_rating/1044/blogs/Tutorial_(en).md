# Tutorial_(en)


### [1075A - The King's Race](https://codeforces.com/contest/1075/problem/A "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)")

Let's find the minimum time needed for the white king to reach the coin.

It is obvious that it is always optimal to move only towards the coin. In case of white king it means that we should move only up, right or up-right diagonally. During one move we can only add $1$ or $0$ to any of our coordinates (or to both of them), it means that the length of the optimal path can not be smaller than $max(x-1,y-1)$.

Let's show that we can reach the coin with $max(x-1,y-1)$ moves.

First step. Let $z$ be equal to $min(x,y)$. The king does $z-1$ up-right moves, so after that the king will be in the cell $(z,z)$. 

Second step. Let's assume that $x \le y$ (the case when $x > y$ is proved in a similar way). So $z = x$. It means that the king is in the cell $(x,x)$. Now the king can do $y-x$ up moves, after which he would be in the cell $(x,y)$. 

It took him $(x-1)+(y-x)=y-1$ moves to reach the coin. If $x$ was greater than $y$ he would need $x-1$ moves (could be proved the same way). 

So now we proved that it takes $max(x-1,y-1)$ moves for the white king to reach the coin.

In the same way we can prove that it takes $max(n-x,n-y)$ steps for the black king to reach the coin.

The king, which is closer to the coin, wins. If the distances is equal, than the white king wins, because he moves first.

Final description of the algorithm:

If $max(n-x,n-y)<max(x-1,y-1)$ then the answer is "Black", otherwise the answer is "White".

It is also can be proven that instead of comparing minimal distances between the coin and the kings we can compare manhattan distances between them. I will leave the proof as homework task.

Author: [arsijo](https://codeforces.com/profile/arsijo "International Grandmaster arsijo")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 
### [1075B - Taxi drivers and Lyft](https://codeforces.com/contest/1075/problem/B "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)")

Let's find for each rider the taxi driver that will get his call.

To do this we can find for each rider the nearest taxi driver at right and the nearest taxi driver at left. Let's define the nearest taxi driver at left for $i$-th citizen as $l_i$ and at the right as $r_i$.

The computations can be done with the following algorithm:

Let's define $l_0=0$ and $r_{n+m+1}=n+m+1$. And $x_0=-2*10^9$, $x_{n+m+1} = 2*10^{9}$.

In order to find $l_i$ for each $i$ we should iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a taxi driver, then he/she is obviously the nearest taxi driver to himself/herself. If the $i$-th citizen is a rider, then $l_i=l_{i-1}$

In order to find $r_i$ for each $i$ we should iterate through the citizens from $n+m$ to $1$. If the $i$-th citizen is a taxi driver, then $r_i=i$, else $r_i=r_{i+1}$.

Now it's time to compute the answer.

Let's denote $b_i$ as the number of citizens, whose calls the $i$-th citizen will get (if the $i$-th citizen is a rider, then $b_i=0$).

In order to do compute the values of array $b$ we should iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a rider, then if the $x_{r_i}-x_i<x_i-x_{l_i}$ (distance between the nearest taxi driver at right and the $i$-th citizen is smaller than distance between the nearest taxi driver at the left and the citizen), then taxi driver $r_i$ will get the call, otherwise the taxi driver $l_i$ will get the call. So if $x_{r_i}-x_i<x_i-x_{l_i}$, then $b_{r_i}:=b_{r_i}+1$, else $b_{l_i}:=b_{l_i}+1$. 

In order to print out the answer we iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a taxi driver, than we should print $b_i$.

The algorithm iterates through the array four times, so overall complexity is $O(n+m)$

Author: [arsijo](https://codeforces.com/profile/arsijo "International Grandmaster arsijo")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 Tutorial is loading...Author: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 Tutorial is loading...Author: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

Developer: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

 Tutorial is loading...Author: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

Developer: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

 Tutorial is loading...Author: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

Developer: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

 Tutorial is loading...Author: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

Developer: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

 Tutorial is loading...Author: [_h_](https://codeforces.com/profile/_h_ "International Grandmaster _h_")

Developers: [_h_](https://codeforces.com/profile/_h_ "International Grandmaster _h_") and [majk](https://codeforces.com/profile/majk "International Grandmaster majk")

