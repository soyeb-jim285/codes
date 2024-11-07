# Tutorial


### [1315A - Dead Pixel](../problems/A._Dead_Pixel.md "Codeforces Round 623 (Div. 2, based on VK Cup 2019-2020 - Elimination Round, Engine)")

You can see that you should place the window in such a way so that the dead pixel is next to one of the borders of the screen: otherwise we can definitely increase the size of the window.

There are four possible ways to place the window right next to the dead pixel — you can place it below, above, to the left or to the right of the dead pixel. 

* if you place the window to the left to the pixel, the maximal size of the screen will be $x \cdot b$;
* if you place the window to the right to the pixel, the maximal size of the screen will be $(a - 1 - x) \cdot b$;
* if you place the window above the pixel, the maximal size of the screen will be $a \cdot y$;
* if you place the window above the pixel, the maximal size of the screen will be $a \cdot (b - 1 - y)$.

These four cases can be united to one formula like $\max(\max(x, a-1-x) \cdot b, a \cdot \max(y, b-1-y))$.

 
### [1315B - Homecoming](../problems/B._Homecoming.md "Codeforces Round 623 (Div. 2, based on VK Cup 2019-2020 - Elimination Round, Engine)")

The first thing you should do in this problem — you should understand the problem statement (which could be not very easy), and get the right answers to the sample test cases. 

Petya needs to find the minimal $i$ such that he has enough money to get from $i$ to $n$ (not $n+1$, he doesn't need to use the transport from the last crossroad. This was a rather common mistake in misunderstanding the statement) using only public transport. We can see that if Petya can get from $i$ to $n$ using only public transport, he can also get from any $j>i$ to $n$, using only public transport (because he will need fewer tickets).

Let's iterate the candidates for $i$ from $n$ to $1$ and try to find the minimal possible $i$. Of course, Petya can go from $n$ to $n$ using only public transport (he doesn't need to buy any ticket). Suppose Petya can get from $j$ to $n$ for some $j$, and it would cost him $t_j$ money. How much money he would need to get from $j-1$ to $n$? He definitely should be able to buy a ticket at station $j-1$. So, if it is the same ticket he should buy at station $j$, he will need the same amount of money, because he doesn't need to buy two consecutive equal tickets, it has no sense. Otherwise, he should buy one more ticket. 

So, a minimal amount of money $t_{j-1}$ to get from $j-1$ to $j$ is $t_j$, if $j<n$ and $s_{j-1}=s_j$, and $t_j+cost(s_{j-1})$ otherwise ($cost(s_{j-1})$ is $a$ if $s_{j-1} = \texttt{A}$, and $b$ otherwise). If this value is greater than $p$, he should go to $j$ by foot, otherwise, we should resume the process because he can go to $j-1$ or even some less-numbered crossroads.

 Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading...