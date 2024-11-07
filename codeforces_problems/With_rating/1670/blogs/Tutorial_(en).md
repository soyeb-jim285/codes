# Tutorial_(en)

Here is the editorial. Please provide your feedback on each problem so that we can improve upon them the next time.

### [1670A - Профессор Слим](../problems/A._Prof._Slim.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670A - Профессор Слим](../problems/A._Prof._Slim.md "Codeforces Round 788 (Div. 2)")

We can notice that to make the array sorted we must move all the negative signs to the beginning of the array. So let's say the number of negative elements is k. Then we must check that the first k elements are non-increasing and the remaining elements are non-decreasing.

Complexity is O(n).

 **Solution**
```cpp
import java.io.*;
import java.util.StringTokenizer;
 
public class A {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int tc = sc.nextInt();
        for (int test = 1; test <= tc; test++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();
            int i = 0, j = 0;
            while (i < n) {
                if (arr[i] < 0) {
                    arr[j++] *= -1;
                    arr[i] *= -1;
                }
                i++;
            }
            if (isSorted(arr)) {
                pw.println("YES");
            } else
                pw.println("NO");
        }
        pw.flush();
    }
 
    private static boolean isSorted(int[] arr) {
        for (int i = 1; i < arr.length; i++)
            if (arr[i] < arr[i - 1])
                return false;
        return true;
    }
 
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(FileReader f) {
            br = new BufferedReader(f);
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
 
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
 
        public int[] nextIntArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(next());
            }
            return arr;
        }
 
    }
}

```
### [1670B - Общажные войны](../problems/B._Dorms_War.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670B - Общажные войны](../problems/B._Dorms_War.md "Codeforces Round 788 (Div. 2)")

Let's consider the non-special characters as '0' and special characters as '1' since they are indistinguishable. So now the problem is that we have a binary string, where each '1' character removes the character before it each time the program is run.

The trivial case is when there is only one '1' character, the answer then is just the number of '0' characters before it.

But what if there is more than one '1' character? lets take for example when there are two '1' characters as follows: 00000010001→000001001→0000101→00011→001→01→1

The observation here is that when the first '1' character from the right reached the second '1', it acts as if it just replaced its place, so we can say that each '1' character replaces another '1' as soon as it reaches it.

So we can partition the binary string into small partitions where each partition contains only one '1' character that is the rightmost character in the partition.

For example, the string 00010000001011 can be partitioned into: (0001),(0000001),(01),(1)

We first calculate the amount of time each partition requires to remove all the '0' characters before it, which is basically the number of '0' characters before it. Each partition except for the first partition requires one more second to replace the '1' character in the previous partition.

So the answer is the maximum time required among all the partitions.

 **Solution**
```cpp
import java.io.*;
import java.util.StringTokenizer;
 
public class B{
 
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = sc.nextInt();
            char[] arr = sc.next().toCharArray();
            int k = sc.nextInt();
            boolean[] special = new boolean[26];
            for (int i = 0; i < k; i++)
                special[sc.next().charAt(0) - 'a'] = true;
            int idx = -1;
            for (int i = 0; i < n; i++)
                if (special[arr[i] - 'a'])
                    idx = i;
            int max=0;
            for(int i=idx-1;i>=0;i--){
                int j=i;
                while (j>0&&!special[arr[j]-'a'])
                    j--;
                max=Math.max(max,i+1-j);
                i=j;
            }
            pw.println(max);
        }
        pw.flush();
    }
 
 
    public static class Scanner {
        StringTokenizer st;
        BufferedReader br;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(String s) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(s)));
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}

```
### [1670C - Где пицца?](../problems/C._Where_is_the_Pizza_.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670C - Где пицца?](../problems/C._Where_is_the_Pizza_.md "Codeforces Round 788 (Div. 2)")

Let's first solve the version where the array d is filled with 0's (in other words there is no constrain on the permutation c that needs to be formed).

Let's say we have the permutation [1,2,3,4] as a and the permutation [3,1,2,4] as b.

Suppose that we have chosen the first element of the array c to be the first element of array a, this way we can't choose the first element of array b. Since we want array c to be a permutation, we will have to get the first element of b from a (which is 3). If we search for 3 in array a and add it to array c, we wont be able to choose the element of b in the corresponding index (which is 2), so we again search for 2 in array a and add it to c. This time, the element in b at the corresponding index is 1, which is already included in the array c, so we are not obliged to select another element from array a.

We observe that the elements that we were obliged to choose from a along with the initial element we selected [1,2,3] are a permutation of the elements at the corresponding indices of b [3,1,2], and for each group that has a size bigger than one we have 2 options, either we select the whole group from a, or we select the whole group from b.

So the answer to this version is to just count the number of groups of size bigger than 1 (let's say the number of groups is p) and print 2p.

Now what if array d is not filled with 0's? We just have to make sure that each group we count has 0's in all the corresponding indices of the group we are considering, otherwise this group has only one option and we don't count it.

This solution can be implemented in many ways, but using DSU to union each group together is the most elegant way to implement it in my opinion.

 **Solution**
```cpp
import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;
 
public class C{
 
    static int mod = (int) 1e9 + 7;
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = sc.nextInt();
            int[] first = new int[n];
            int[] second = new int[n];
            int[] third=new int[n];
            for (int i = 0; i < n; i++)
                first[i] = sc.nextInt() - 1;
            for (int i = 0; i < n; i++)
                second[i] = sc.nextInt() - 1;
            for(int i=0;i<n;i++)
                third[i]= sc.nextInt()-1;
            UnionFind uf = new UnionFind(n);
            for (int i = 0; i < n; i++)
                uf.unionSet(first[i], second[i]);
            HashSet<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++)
                set.add(uf.findSet(i));
            for(int i=0;i<n;i++){
                if(third[i]==-1)
                    continue;
                set.remove(uf.findSet(third[i]));
            }
            int pow = 0;
            for (int x : set)
                if (uf.sizeOfSet(x) > 1)
                    pow++;
            int ans = 1;
            for (int i = 0; i < pow; i++)
                ans = (int) ((2L * ans) % mod);
            pw.println(ans);
        }
        pw.flush();
    }
    
    
    
     public static class UnionFind {
        int[] p, rank, setSize;
        int numSets;
 
        public UnionFind(int N) {
            p = new int[numSets = N];
            rank = new int[N];
            setSize = new int[N];
            for (int i = 0; i < N; i++) {
                p[i] = i;
                setSize[i] = 1;
            }
        }
 
        public int findSet(int i) {
            return p[i] == i ? i : (p[i] = findSet(p[i]));
        }
 
        public boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
 
        public void unionSet(int i, int j) {
            if (isSameSet(i, j))
                return;
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
 
        public int numDisjointSets() {
            return numSets;
        }
 
        public int sizeOfSet(int i) {
            return setSize[findSet(i)];
        }
    }
 
 
    public static class Scanner {
        StringTokenizer st;
        BufferedReader br;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(String s) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(s)));
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}

```
### [1670D - Очень подозрительно](../problems/D._Very_Suspicious.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670D - Очень подозрительно](../problems/D._Very_Suspicious.md "Codeforces Round 788 (Div. 2)")

We can notice that there are 3 different slopes in which we can draw a line, and we can also notice that drawing the lines exactly on the edges of the hexagons will result in the creation of 2 equilateral triangles at each intersection of 2 lines, so we can say that:

 Number of equilateral triangles = 2 *( number of intersections at center of some hexagon). 

Now we only need to find a way to draw the lines such that it maximizes the number of intersections. The best way to do that is to keep the number of lines on all 3 slopes as close as possible (the proof will be explained at the bottom). One way to do so is to add the lines once at each slope then repeat.

Let's say that slopes are numbered 1, 2, and 3, so we will add the lines as follows 1,2,3,1,2,3, and so on. The increase in the intersection will be the number of lines in the other two slopes added together. It will be as follows : +0,+1,+2,+2,+3,+4,+4,+5,+6,+6,+7,+8,…

If we separate that into groups of 3 we will get {0,1,2},{2,3,4},{4,5,6},…

The sum of the groups is 3,9,15,21,…

To get the sum of the first X groups it will be 3X2. So, to get the number of intersections using N lines we will first find the number of complete groups which is ⌊N3⌋ and then loop over the last group to find the total number of intersections.

Now that we have a way to find the number of equilateral triangles created by N lines we can find the number of lines needed to get X equilateral triangles by using binary search.

The proof that the best way to maximize the number of intersections is to keep the number of lines on all 3 slopes as close as possible:

Imagine a case in which the difference between the lines in two slops is more than 2 lines, now we can see that if we moved one line from the larger group to the smaller we will obtain more intersections because after moving, the intersections with the 3-rd line will be the same and will not be affected and the intersection between the slopes will decrease by the size of the smaller group and increased by the size of the larger group minus 1 so overall the intersections will increase by at least 1 so that proves that we can't have any difference more than 1 and the groups must be as close as possible.

 **Solution**
```cpp
import java.util.*;
import java.io.*;
 
public class D{
	public static void main(String[] args) throws Exception {
		int t=sc.nextInt();
		while(t-->0) {
			pw.println(sol(sc.nextInt()));
		}
		pw.close();
	}
	
	public static int sol(int n) {
		int low=0;
		int high=(int)1e9;
		int mid=(low+high)/2;
		while(low<=high) {
			if(calc(mid)<n) {
				low=mid+1;
			}else {
				high=mid-1;
			}
			mid=(low+high)/2;
		}
		return low;
	}
	
	public static long calc(long n) {
		n--;
		long ans=0;
		ans=(n/3)*(n/3)*3;
		for (int i = 0; i <= n % 3; i++)
			ans += (n / 3) * 2 + i;
		return ans*2;
	}
 
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
 
		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}
 
		public long[] nextlongArray(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public Long[] nextLongArray(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public int[] nextIntArray(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public Integer[] nextIntegerArray(int n) throws IOException {
			Integer[] a = new Integer[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
	}
 
	static Scanner sc = new Scanner(System.in);
	static PrintWriter pw = new PrintWriter(System.out);
}

```
### [1670E - Хемос на дереве](../problems/E._Hemose_on_the_Tree.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670E - Хемос на дереве](../problems/E._Hemose_on_the_Tree.md "Codeforces Round 788 (Div. 2)")

Let's look at the minimum maximum value that we can get if we have an array of numbers from [1,2(p+1)−1] and we are trying to get any prefix xor, the answer will be 2p because you can stop at the first integer that will have the bit p so the answer will be ≥2p. 

We can apply the same concept here, for any arrangement we can start at the root and stop at the first node/edge that has the bit p on. Let's try to find a construction that will make our answer always 2p. This is one of the valid ways. 

1. Select an arbitrary root.
2. Put 2p at the root.
3. Create 2p−1 pairs from the remaining numbers of the form (x,x+2p) where x<2p
4. For every node we will do the following:
	* If its parent has the bit p in its value the node will take the value x and the edge to the parent will take x+2p.
	* If its parent doesn't have the bit p in its value the node will take the value x+2p and the edge to the parent will take x.Using this construction you will find that the xor value form the root will alternate between 0 and 2p and x which is always ≤2p .
 **Solution**
```cpp
import java.util.*;
import java.io.*;
 
public class E{
    static ArrayList<int[]>[] adj;
    static int[] nodeval, edgeval;
    static int count, N;
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        while(t-->0){
        
            int n = sc.nextInt();
            N = 1 << n;
            adj = new ArrayList[N];
            for (int i = 0; i < N; i++)
                adj[i] = new ArrayList<>();
    
            for (int i = 0; i < N - 1; i++) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
    
                adj[u].add(new int[]{v, i});
                adj[v].add(new int[]{u, i});
            }
            nodeval = new int[N];
            edgeval = new int[N];
            nodeval[0] = N;
            count =0;
            dfs(0, -1);
    
            pw.println(1);
            for (int i = 0; i < N; i++)
                pw.print(nodeval[i] + " ");
            pw.println();
            for (int i = 0; i < N - 1; i++)
                pw.print(edgeval[i] + " ");
            pw.println();    
        }
        pw.close();
 
    }
 
    private static void dfs(int u, int p) {
 
        for (int[] nxt : adj[u]) {
            int v = nxt[0];
            int idx = nxt[1];
            if (v == p)
                continue;
            count++;
            edgeval[idx] = count + ((nodeval[u] & N) != 0 ? N : 0);
            nodeval[v] = count + ((nodeval[u] & N) != 0 ? 0 : N);
            dfs(v, u);
        }
    }
 
 
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(FileReader f) {
            br = new BufferedReader(f);
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
 
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
 
        public int[] nextIntArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(next());
            }
            return arr;
        }
 
    }
 
}

```
### [1670F - Джи, видишь?](../problems/F._Jee,_You_See_.md "Codeforces Round 788 (Div. 2)")

 **Tutorial**
### [1670F - Джи, видишь?](../problems/F._Jee,_You_See_.md "Codeforces Round 788 (Div. 2)")

Let's put aside the XOR constraint and only focus on the sum constraint.

let G(X) be the number of ways to construct n integers such that their sum is at most X.

We will construct each bit of the n integers at the same time, we want to guarantee that the contribution of the sum of the bits generated at each position plus the sum of the previous bits wont exceed X we only have to know the difference between the previous bits of X (add 1 if the current bit is on) and the sum of the generated bits.

However we know for sure that at each position we can generate at most n bits which will sum to n at most, so for the next position the difference will be the 2 * (current difference - the sum of the bits at the cur position). we can see that if the current difference has a value ≥ 2n we can place any number of bits at the remaining positions.

Let's define dp[m][k] as the number of ways to construct the first m bits of the n integers such that their sum doesn't exceed X, where k is min between (the difference between the previous bits and X) and 2n.

We can have count from 0 to min(k,n) ones placed at the current bit and for each count we have (ncount) ways to distribute them.

Formally dp[m][k]=∑min(n,k)count=0(ncount)⋅dp[m+1][2(k−count+currentBit)] where currentBit is one if the limit have the bit m on.

 

For the XOR constraint we only have to make sure that count is even if the current bit of Z is 0 or odd if the current bit is 1.

The answer of the problem will be G(R)−G(L−1).

 **Solution**
```cpp
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class F {
    static final int mod = (int) 1e9 + 7;
    static int n;
    static long l, r, z;
    static long[][] memo;
    static long[][] memo2;
 
    public static long nCr(int n, int r) {
        if (r == 0)
            return 1;
        if (n == 0)
            return 0;
        if (memo[n][r] != -1)
            return memo[n][r];
        return memo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
    }
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int tests = 1;
        memo = new long[1001][1001];
        for (long[] x : memo)
            Arrays.fill(x, -1);
        for (int test = 0; test < tests; test++) {
            n = sc.nextInt();
            l = sc.nextLong();
            r = sc.nextLong();
            z = sc.nextLong();
            long ans = (compute(r) - compute(l - 1) + mod) % mod;
            pw.println(ans);
        }
        pw.flush();
    }
 
    private static long compute(long val) {
        memo2 = new long[61][2001];
        for (long[] x : memo2)
            Arrays.fill(x, -1);
        return dp(60, 0, val);
    }
 
    private static long dp(int idx, int rem, long val) {
        if (rem > 2000)
            rem = 2000;
        if (rem < 0)
            return 0;
        if (idx == -1)
            return 1;
        if (memo2[idx][rem] != -1)
            return memo2[idx][rem];
        long ans = 0;
        int currentBitXor = (z & 1L << idx)== 0 ? 0 : 1;
        for (int i = currentBitXor == 1 ? 1 : 0; i <= n; i += 2) {
            int currentBitSum = (val & 1L << idx) == 0 ? 0 : 1;
            int nextRem = 2 * (rem + currentBitSum - i);
            long toAdd = (nCr(n, i) * dp(idx - 1, nextRem, val)) % mod;
            ans = (ans + toAdd) % mod;
        }
        return memo2[idx][rem] = ans;
    }
 
 
    public static class Scanner {
        StringTokenizer st;
        BufferedReader br;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(String s) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(s)));
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
```
