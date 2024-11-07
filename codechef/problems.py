import os
import requests

class CodeChefContest:
    def __init__(self, contest_name):
        self.contest_name = contest_name
        self.contest_url = f"https://www.codechef.com/api/contests/{contest_name}"

    def get_json(self, url):
        try:
            r = requests.get(url)
            return r.json()
        except requests.exceptions.RequestException as e:
            raise SystemExit(e)

    def create_directory(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

    def process_contest(self):
        contest_data = self.get_json(self.contest_url)
        self.create_directory(self.contest_name)

        for problem_name in contest_data["problems"]:
            self.process_problem(problem_name)

    def process_problem(self, problem_name):
        problem_url = f"https://www.codechef.com/api/contests/{self.contest_name}/problems/{problem_name}"
        print(problem_name)
        problem_data = self.get_json(problem_url)

        with open(f"{self.contest_name}/{problem_name}.cpp", "w") as f:
            if len(problem_data["problemComponents"]["sampleTestCases"]) == 1:
                with open("test.cpp", "r") as t:
                    f.write(t.read())
            else:
                with open("notest.cpp", "r") as t:
                    f.write(t.read())

        problem_path = f"{self.contest_name}/{problem_name}/"
        input_path = f"{problem_path}input/"
        output_path = f"{problem_path}output/"
        answer_path = f"{problem_path}answer/"

        self.create_directory(problem_path)
        self.create_directory(input_path)
        self.create_directory(output_path)
        self.create_directory(answer_path)

        for sample_test_case in problem_data["problemComponents"]["sampleTestCases"]:
            print(sample_test_case["input"])
            print(sample_test_case["output"])
            with open(f"{input_path}{sample_test_case['id']}.txt", "w") as f:
                f.write(sample_test_case["input"])
            with open(f"{answer_path}{sample_test_case['id']}.txt", "w") as f:
                f.write(sample_test_case["output"])

contest_name = input("Input contest name: ")
contest = CodeChefContest(contest_name)
contest.process_contest()