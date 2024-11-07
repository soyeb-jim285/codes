# Editorial

Thank you for participating!

 
### [1891A - Sorting with Twos](../problems/A._Sorting_with_Twos.md "Codeforces Round 907 (Div. 2)")

Look at the difference array b. bi = ai+1−ai for each i<n. 

If array is sorted, its difference array has all of its elements non-negative. 

And operation is adding 1 to bi if i is a power of 2. 

So look at difference array. If there is such i that i is not a power of 2 and bi<0 then answer is «NO». Else answer is «YES». 

Time complexity: O(n). 

 
### [1891B - Deja Vu](../problems/B._Deja_Vu.md "Codeforces Round 907 (Div. 2)")

Let a number be divisible by 2x. Then after applying the operation it is no longer divisible by 2x. From this we can conclude that if we apply the operation xi, and there is such an operation j<i that xj<xi, then the operation xi does not change the array. So, it is useless and can be simply not processed. 

Then we will maintain the minimum of the processed x. If the new operation is smaller than the minimum processed one, we will process the operation and update it. Otherwise we just won't do anything. Since the minimum processed will decrease at most 30 times, the time complexity is O(30⋅n). 

 
### [1891C - Smilo and Monsters](../problems/C._Smilo_and_Monsters.md "Codeforces Round 907 (Div. 2)")

Note that if the second operation were free, we would need ⌈sum2⌉ operations to get rid of all the monsters. Indeed, when we kill one monster, we can kill a second monster for free with a second operation. But the second operation is not free. So we need to use the second operation as little as possible.

To do this, we need to apply ultimates (second attack) on the current largest horde by number of monsters, when the combo counter reaches the size of the largest horde. And we apply the first attack on the smallest hordes. This is so because the combo counter allows us to defeat ⌈sum2⌉ monsters. But since we can't apply this operation on several hordes at once, we need to keep the number of hordes on which we apply these attacks of the second type as small as possible. Then we can use the greedy algorithm described above. Formally, we need to keep a sorted array and store two pointers: pointer i — to the smallest horde, j — to the largest horde. Until i is equal to j: if after destroying all horde i we can't kill horde j with ultimates, we destroy horde i, increase pointer i by 1 and increase combo counter x by a[i]. Otherwise, hit the horde i so many times that the combo counter x becomes a[j]. Then apply a second attack on horde j, reduce horde j's counter by 1, reduce a[i], and nullify the combo counter. When i becomes equal to j, you just need to apply the first attack the right number of times to finish with ultimates (or not if a[i] = 1). 

Total complexity O(nlogn).

 
### [1891D - Suspicious logarithms](../problems/D._Suspicious_logarithms.md "Codeforces Round 907 (Div. 2)")

First, let us estimate the number of such i that g(i)≠g(i+1). This can happen if f(i)≠f(i+1), but it happens rarely (about logn times). And if f(i) is equal, we can see that f(i)≥2 for any 4≤i, and on a segment with equal f(i) transitions will be O(logn), where n is the length of the segment. That is, there are O(logn) segments with equal f(i), and on each segment there are at most O(logn) transitions. Then there are a total of O(log2C) transitions, where C is the maximum value of i in the problem. In fact, in reality, there are even fewer transitions - something like 60. Now we can suppose all such i that g(i)≠g(i+1), and by passing over them we can consider the sum of g(i) for all i≤r. Or you can write a binary search and read the answer even faster. 

 
### [1891E - Brukhovich and Exams](../problems/E._Brukhovich_and_Exams.md "Codeforces Round 907 (Div. 2)")

Consider that every ai≠1. Then, we can split our array into blocks in which each adjacent element has gcd=1. For example, consider a=[2, 3, 4, 5, 5, 6, 7], then the array divides into two blocks: [2, 3, 4, 5] and [5, 6, 7]. Notice that if the lenght of a block is len, then it gives len−1 sadness to Smilo. Also notice that we can reduce sadness by two using only one operation: we can, for instance, nullify the second element in a block (if the length of the block is more than two). For illustration, if we nullify the second element in block [5, 6, 7], the sadness will decrease by two, and the block will be splitted into [5], [0], [7] with zero sadness in each block. If the size of a block is exactly two, we can decrease the sadness by one using one operation. Then notice that while we are having at least one block, which lenght is at least 3, we can decrease sadness by 2. Otherwise, we can decrease sadness at most by 1.

Unfortunately, we have ones in our array. In this case our algorithm won't work, since in order to make pair [1, 1] good, we will have to nullify both elements. Then let's slightly modify the algorithm: we will put consecutive ones in different blocks. For example, if a=[1, 1, 1, 3, 4, 4, 1], then our array will be splitted into 4 blocks: [1, 1, 1], [3, 4], [4], [1]. Now notice that if the block of ones is located at the edge of our array, then the sadness will decrease by len using len operations (len is the lenght of the block). Otherwise, sadness will decrease by len+1 using len operations. The final solution becomes obvious. Firstly, we should nullify the elements in non-ones blocks (if possible) in order to decrease sadness by 2 each operation. Then we need to nullify whole blocks of ones (which are not on the edge of the array) in ascending order of lenght. And finally, we need to use remaining operations to reduce sadness by one each operation.

The complexity is O(nlogn).

 
### [1891F - A Growing Tree](../problems/F._A_Growing_Tree.md "Codeforces Round 907 (Div. 2)")

Let's parse all the queries and build the tree. We can easily support subtree addition queries using segment tree on Euler tour of the tree. And when we add new vertex, we just need to set its value to zero. How to do it? You can get the value in this vertex now (by get query from the segment tree), let it be x. Then you add −x to its value. 

You can also use Fenwick tree to handle range add point get queries. 

Time complexity: O(qlogq).

Bonus: try to find a solution using sqrt decomposition. I hope it will get TLE, but still.

