import random
import subprocess


def generate_array(n):
    """Generate an array of size n with values 0, 1, 2, ensuring at least one 1."""
    array = [random.randint(0, 2) for _ in range(n)]
    if 1 not in array:
        array[random.randint(0, n - 1)] = 1  # Ensure at least one `1`
    return array


def is_sorted(array):
    """Check if the array is sorted."""
    return all(array[i] <= array[i + 1] for i in range(len(array) - 1))


def validate_solution(n, array, steps, swaps):
    """Validate the solution with 1-based indexing."""
    if len(swaps) > n:
        print("Error: Too many swaps!")
        return False

    for i, (a, b) in enumerate(swaps):
        # Convert 1-based to 0-based indices
        a -= 1
        b -= 1

        if not (0 <= a < n and 0 <= b < n):
            print(
                f"Error: Swap indices out of bounds at step {i + 1}, indices {a + 1}, {b + 1}."
            )
            return False

        if abs(array[a] - array[b]) != 1:
            print(f"Error: Invalid swap at step {i + 1}, indices {a + 1}, {b + 1}.")
            return False

        # Perform the swap
        array[a], array[b] = array[b], array[a]

    if not is_sorted(array):
        print("Error: Array is not sorted after swaps!")
        return False

    return True


def stress_test(program_path, test_count=100, max_n=10):
    """Stress test the C++ program."""
    for t in range(test_count):
        n = random.randint(2, max_n)
        array = generate_array(n)
        input_data = f"{n}\n" + " ".join(map(str, array)) + "\n"

        # Run the C++ program
        result = subprocess.run(
            program_path, input=input_data, text=True, capture_output=True
        )

        if result.returncode != 0:
            print(f"Error: Program crashed on test case {t + 1}")
            print(f"Input:\n{input_data}")
            print(f"Error Message:\n{result.stderr}")
            return

        output = result.stdout.strip().split("\n")
        try:
            st = int(output[0])
            swaps = [tuple(map(int, line.split())) for line in output[1:]]
        except Exception as e:
            print(f"Error: Malformed output on test case {t + 1}")
            print(f"Input:\n{input_data}")
            print(f"Output:\n{result.stdout}")
            return

        # Validate the solution
        print(f"Input:\n{input_data}")
        print(f"Output: \n {result.stdout}")
        if not validate_solution(n, array, st, swaps):
            print(f"Validation failed on test case {t + 1}")
            print(f"Input:\n{input_data}")
            print(f"Output:\n{result.stdout}")
            return

        print(f"Test case {t + 1} passed!")


if __name__ == "__main__":
    stress_test(["./main"])
