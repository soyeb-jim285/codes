import os
from bs4 import BeautifulSoup as BS
import requests

Contest_name = input("Input contest name: ")
contest_url = f"https://www.codechef.com/api/contests/{Contest_name}"

try:
    r = requests.get(contest_url)
except requests.exceptions.RequestException as e:
    raise SystemExit(e)

contest_data = r.json()

if not os.path.exists(Contest_name):
    os.makedirs(Contest_name)

for problem_name in contest_data["problems"]:
    problem_url = (
        f"https://www.codechef.com/api/contests/{Contest_name}/problems/{problem_name}"
    )
    print(problem_name)
    try:
        pr = requests.get(problem_url)
    except requests.exceptions.RequestException as e:
        raise SystemExit(e)
    problem_data = pr.json()
    with open(f"{Contest_name}/{problem_name}.cpp", "w") as f:
        if len(problem_data["problemComponents"]["sampleTestCases"]) == 1:
            with open("test.cpp", "r") as t:
                f.write(t.read())
        else:
            with open("notest.cpp", "r") as t:
                f.write(t.read())
    problem_path = f"{Contest_name}/{problem_name}/"
    input_path = f"{Contest_name}/{problem_name}/input/"
    output_path = f"{Contest_name}/{problem_name}/output/"
    answer_path = f"{Contest_name}/{problem_name}/answer/"
    if not os.path.exists(problem_path):
        os.makedirs(problem_path)
    if not os.path.exists(input_path):
        os.makedirs(input_path)
    if not os.path.exists(output_path):
        os.makedirs(output_path)
    if not os.path.exists(answer_path):
        os.makedirs(answer_path)
    for sample_test_case in problem_data["problemComponents"]["sampleTestCases"]:
        print(sample_test_case["input"])
        print(sample_test_case["output"])
        with open(f"{input_path}{sample_test_case['id']}.txt", "w") as f:
            f.write(sample_test_case["input"])
        with open(f"{answer_path}{sample_test_case['id']}.txt", "w") as f:
            f.write(sample_test_case["output"])
