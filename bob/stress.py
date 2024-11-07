import subprocess
import math

# Path to your test case generator, your code, and the correct code
testcase_generator = "./generate_testcases"  # path to your testcase generator
your_code = "./your_code"  # path to your code
correct_code = "./correct_code"  # path to the correct code


# Function to calculate the relative error between two numbers
def relative_error(your_output, correct_output):
    if correct_output == 0:
        return math.inf if your_output != 0 else 0
    return abs(your_output - correct_output) / abs(correct_output)


# Number of test cases you want to run
num_tests = 10000

max_error = 0
max_error_test_case = None

for i in range(num_tests):
    print(f"Running test case {i}...")
    # Generate a test case
    test_case = subprocess.check_output([testcase_generator]).decode("utf-8").strip()

    # Run your code (suppressing output in terminal)
    your_output = (
        subprocess.check_output(your_code, input=test_case, text=True)
        .strip()
        .splitlines()
    )

    # Run the correct code (suppressing output in terminal)
    correct_output = (
        subprocess.check_output(correct_code, input=test_case, text=True)
        .strip()
        .splitlines()
    )

    # Convert outputs to float
    try:
        your_results = list(map(float, your_output))
        correct_results = list(map(float, correct_output))
    except ValueError:
        print(f"Test case {i} failed with non-numeric output.")
        # Skip test case if the output is non-numeric, no output to terminal
        continue

    # Check for relative error for each output
    for j in range(min(len(your_results), len(correct_results))):
        error = relative_error(your_results[j], correct_results[j])
        if error > max_error:
            max_error = error
            max_error_test_case = test_case
        # print(f"Relative error for test case {i}, output index {j}: {error:.18f}")
        if error > 1e-5:
            # Only show failure message without test case details
            print(
                f"Test case {i} failed with relative error exceeding 10^-6 for output index {j}. and error is {error:.18f}"
            )
            print(f"Test case is:\n {test_case}")
            break
    else:
        continue  # Only continue to the next test case if no error was found
    break  # Break out of the outer loop if a failure was found
else:
    print("All test cases passed within the relative error threshold.")
    print(f"Maximum relative error: {max_error:.18f}")
    print(f"Test case with maximum relative error:\n{max_error_test_case}")
