import subprocess, random


def generate_permutation(n):
    return random.sample(range(1, n + 1), n)


def handle_queries(hidden_permutation, n, max_queries=6666):
    process = subprocess.Popen(
        ["./solve"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True
    )
    process.stdin.write(f"{n}\n")
    process.stdin.flush()
    for query_count in range(max_queries):
        query = process.stdout.readline().strip().split()
        if query[0] == "1":
            guessed_perm = list(map(int, query[1:]))
            print("Correct!" if guessed_perm == hidden_permutation else "Wrong!")
            break

        matches = sum(p == h for p, h in zip(map(int, query[1:]), hidden_permutation))
        process.stdin.write(f"{matches}\n")
        process.stdin.flush()
    else:
        print("Query limit exceeded!")

    process.terminate()


n = 1000
hidden_permutation = generate_permutation(n)
print(f"Hidden permutation: {hidden_permutation}")
handle_queries(hidden_permutation, n)
