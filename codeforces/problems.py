import os
from bs4 import BeautifulSoup as bsp
import requests
import shutil
import JSESSIONID

headers = JSESSIONID.headers

contest_number = input("Input contest number: ")

contest_url = f"https://codeforces.com/contest/{contest_number}"
html_txt = requests.get(
    contest_url, headers=headers, allow_redirects=False, timeout=5
).text
soup = bsp(html_txt, "lxml")
print(soup.text.strip(" "))
problems = soup.find("table", class_="problems")
names = problems.find_all("tr")
for tr in names[1:]:
    tds = tr.find_all("td")
    indx = tds[0].text.strip()
    divs = tds[1].find_all("div")
    names = indx + ". " + divs[1].text.strip()
    print(names)
    input_name = names
    output_name = names
    problem_url = f"https://codeforces.com/contest/{contest_number}/problem/{indx}"
    problem_page = requests.get(
        problem_url, headers=headers, allow_redirects=False, timeout=5
    ).text
    page = bsp(problem_page, "html.parser")
    inpt = page.find_all(class_="input")
    outs = page.find_all(class_="output")
    print(len(inpt))
    print(len(outs))
    contest_path = f"{contest_number}/"
    if not os.path.exists(contest_path):
        os.mkdir(contest_path)
    with open(f"{contest_number}/{names}.cpp", "w") as file:
        if len(inpt) == 1:
            with open("test.cpp", "r") as test_file:
                file.write(test_file.read())
        else:
            with open("notest.cpp", "r") as notes_file:
                file.write(notes_file.read())
    shutil.copy2("compare.zh", f"{contest_number}")
    count = 1
    contest_folder = f"{contest_number}/{names}/"
    if not os.path.exists(contest_folder):
        os.mkdir(contest_folder)
    input_path = f"{contest_number}/{names}/input/"
    output_path = f"{contest_number}/{names}/output/"
    answer_path = f"{contest_number}/{names}/answer/"
    if not os.path.exists(input_path):
        os.mkdir(input_path)
    if not os.path.exists(output_path):
        os.mkdir(output_path)
    if not os.path.exists(answer_path):
        os.mkdir(answer_path)
    for inp in inpt:
        input_pre = inp.find("pre")
        input_d = input_pre.find_all("div")
        print("input " + str(count))
        with open(f"{contest_number}/{names}/input/{count}.txt", "w") as file:
            if len(input_d):
                for input_div in input_d:
                    file.write(input_div.text.strip())
                    file.write("\n")
                    print(input_div.text.strip())
            else:
                file.write(input_pre.text.strip())
                print(input_pre.text.strip())
            count += 1
    count = 1
    for out in outs:
        with open(f"{contest_number}/{names}/answer/{count}.txt", "w") as file:
            print("output " + str(count))
            count += 1
            output_div = out.find("pre")
            file.write(output_div.text.strip())
            print(output_div.text.strip())
