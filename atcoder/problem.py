import os
from bs4 import BeautifulSoup as BS
import requests

contest_name = input("Input contest name: ")
# contest_name = "arc169"
headrs = {
    "Accept-Language": "en-US,en;q=0.5",
    "Accept-Encoding": "gzip, deflate, br",
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
}
contest_url = f"https://atcoder.jp/contests/{contest_name}/tasks"

try:
    contest_data = requests.get(contest_url, headers=headrs).text
except requests.exceptions.RequestException as e:
    raise SystemExit(e)
contest_path = f"{contest_name}/"
if not os.path.exists(contest_path):
    os.mkdir(contest_path)
contest_soup = BS(contest_data, "html.parser")
Table = contest_soup.find("tbody")
Trs = Table.find_all("tr")
for tr in Trs:
    tds = tr.find_all("td")
    problem_name = tds[0].text.strip() + ". " + tds[1].text.strip()
    problem_path = f"{contest_name}/{problem_name}/"
    print(problem_name)
    with open(f"{contest_name}/{problem_name}.cpp", "w") as f:
        with open("notest.cpp", "r") as t:
            f.write(t.read())
    if not os.path.exists(problem_path):
        os.mkdir(problem_path)
    problem_url = "https://atcoder.jp" + tds[1].find("a")["href"]
    try:
        problem_data = requests.get(problem_url, headers=headrs).text
    except requests.exceptions.RequestException as e:
        raise SystemExit(e)
    problem_soup = BS(problem_data, "html.parser")
    pres = problem_soup.find_all("pre")
    count = 0
    input_path = f"{contest_name}/{problem_name}/input"
    output_path = f"{contest_name}/{problem_name}/output"
    answer_path = f"{contest_name}/{problem_name}/answer"
    if not os.path.exists(input_path):
        os.mkdir(input_path)
    if not os.path.exists(output_path):
        os.mkdir(output_path)
    if not os.path.exists(answer_path):
        os.mkdir(answer_path)
    for pre in pres:
        if len(pre) == 1:
            if count % 2 == 0:
                print(f"input {count//2+1}")
                with open(f"{input_path}/{count//2+1}.txt", "w") as f:
                    f.write(pre.text.strip())
            else:
                print(f"output {count//2+1}")
                with open(f"{answer_path}/{count//2+1}.txt", "w") as f:
                    f.write(pre.text.strip())
            print(pre.text.strip())
            count += 1
