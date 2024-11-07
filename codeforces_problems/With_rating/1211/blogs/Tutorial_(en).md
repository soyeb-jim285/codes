# Tutorial_(en)

Hello Codeforces!

I hope you enjoyed the problems. I forgot to mention the contribution of testers to the preparation of problems in the round announcement. I apologize and correct myself. Many thanks to the testers: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov"), [ashmelev](https://codeforces.com/profile/ashmelev "Grandmaster ashmelev"), [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN"), [arsijo](https://codeforces.com/profile/arsijo "International Grandmaster arsijo"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic") and [Roms](https://codeforces.com/profile/Roms "Master Roms"). Also many thanks to my co-authors: [300iq](https://codeforces.com/profile/300iq "International Grandmaster 300iq") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Expert geranazavr555"). Special thanks to [cannor147](https://codeforces.com/profile/cannor147 "Specialist cannor147") who helped with translations.

#### [1211A - Three Problems](../problems/A._Three_Problems.md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading...
#### [1211B - Traveling Around the Golden Ring of Berland](../problems/B._Traveling_Around_the_Golden_Ring_of_Berland.md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1211B - Traveling Around the Golden Ring of Berland](../problems/B._Traveling_Around_the_Golden_Ring_of_Berland.md "Kotlin Heroes: Episode 2")

The first solution is to find $w = \max a_i-1$. We need to make $w$ whole cycles plus some partial cycle. The last addend (partial cycle) is the index of the last occurrence of $\max a_i$.

Let's iterate through all possible $a_i$ and consider the length of the minimal path to make exactly $a_i$ selfie in the city $i$ in total (just do not consider other $a_j$ for other cities). If is exactly $i + (a_i - 1) \cdot n$ (or $0$ if $a_i=0$). The answer is the maximum value among all of them.

Here is the example of a solution in Kotlin:


```cpp
fun main() {  
    val n = readLine()!!.toLong()  
    val a = readLine()!!.split(" ").map { it.toInt() }  
    var ans = 0L  
    for ((i, k) in a.withIndex()) {  
        if (k == 0) continue  
        var visits = (i + 1).toLong()  
        if (k > 0) visits += (k - 1) * n  
        if (visits > ans) ans = visits  
    }  
    println(ans)  
}  

```
#### [1211C - Ice Cream](../problems/C._Ice_Cream.md "Kotlin Heroes: Episode 2")

Problem writers: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [geranazavr555](https://codeforces.com/profile/geranazavr555 "Expert geranazavr555")

 **Tutorial**Tutorial is loading...
#### [1211D - Teams](../problems/D._Teams.md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading...
#### [1211E - Double Permutation Inc.](../problems/E._Double_Permutation_Inc..md "Kotlin Heroes: Episode 2")

Problem writers: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [geranazavr555](https://codeforces.com/profile/geranazavr555 "Expert geranazavr555")

 **Tutorial**Tutorial is loading...
#### [1211F - kotlinkotlinkotlinkotlin...](../problems/F._kotlinkotlinkotlinkotlin....md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading...
#### [1211G - King's Path](../problems/G._King's_Path.md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1211G - King's Path](../problems/G._King's_Path.md "Kotlin Heroes: Episode 2")

It is easy to see that if for a leaf $u$ holds $c_u=d_u$, then the leaf $u$ is redundant (you can exclude it from any valid path). So while there is at least one such leaf in the tree, just erase any of them.

After it, the resulting tree should degenerate to be a path (or print No). Just test the path if it is valid with two possible directions.

#### [1211H - Road Repair in Treeland](../problems/H._Road_Repair_in_Treeland.md "Kotlin Heroes: Episode 2")

Problem writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading...
#### [1211I - Unusual Graph](../problems/I._Unusual_Graph.md "Kotlin Heroes: Episode 2")

Problem writer: [300iq](https://codeforces.com/profile/300iq "International Grandmaster 300iq")

 **Tutorial**
### [1211I - Unusual Graph](../problems/I._Unusual_Graph.md "Kotlin Heroes: Episode 2")

Key lemma

* If two vertices have the same set of adjacent vertices, we can set them equal numbers.

Because if two vertices with the same adjacent vertices have different numbers, we can change any one of them to the other, and it is easy to see that all constraints will be satisfied.

So, we can merge all vertices with the equal adjacency list into one vertex, and reduce the problem to following:

New problem

* Set different integers $0 \leq a_v \leq 15$ to vertices of the graph with $n \leq 16$ vertices, to satisfy the same condition as in the original problem.

Solution 1 (Found by participants) 

* You can use brute force with some prunings, and it will work fast enough. It can be proved that it will work fast enough. For example, it is quite clear that it will work fast enough if the number of edges is big because you can set $0,1,2,4,8$ arbitrary to vertex and its neighbors, and you will have $\leq 11$ remaining values to place, so it is quite clear that it is $\leq 11!$, and with further case analysis you can prove that it is way much faster.

Solution 2 (Intendend)

Now we can see that there are $\leq 2^{16}$ possible graphs, up to isomorphism.

So we can fix the set of values of vertices, and check that the given graph and the current graph are isomorphic.

Isomorphism problem

* You need to check that two graphs with $n \leq 16$ are isomorphic, note that these graphs are not arbitrary, so you can use some hacky way to check isomorphism.

Well, indeed, some hash-functions will work here! For example, you can fix some vertex as root, and calculate some hash of the graph with different coefficients of vertices, according to is it root or not. Also, you may fix more vertices, not only one root.

Any naive hash-function will reduce the number of candidate graphs to $\leq 300$.

For them, you can check with some smart, but slower to calculate hash-functions, as written earlier.

Bonus (maybe unsolvable?)

* Solve for $0 \leq a_v \leq 31$.
