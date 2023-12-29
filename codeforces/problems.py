import os
from bs4 import BeautifulSoup as bsp
import requests

headers = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
    "Cookie": "SESSIONID=EFA61D45CBC4A9E9D440B07F94D2C7EF; 39ce7=CFlGlyqs; _ga_K230KVN22K=GS1.1.1703773732.1.1.1703773822.0.0.0; _ga=GA1.2.1079810558.1703773732; _gid=GA1.2.1001151736.1703773732; evercookie_cache=wgbsx08emryk95lf9j; evercookie_etag=wgbsx08emryk95lf9j; cf_clearance=KlPEfllX1TyYZ8uuSMmYIUQMzQC9BIwFAfOGbZWqXF8-1703774306-0-2-25d9373f.85cc7e20.72d868df-160.2.1703773735; evercookie_png=wgbsx08emryk95lf9j; 70a7c28f3de=wgbsx08emryk95lf9j; X-User-Sha1=954e14f57531bc507e75b7ddecefaf203542627b; lastOnlineTimeUpdaterInvocation=1703773787752; cf_chl_2=de67e1b0a8fac15"
}
contest_number = input("Input contest number: ")

contest_url = f"https://codeforces.com/contest/{contest_number}"
html_txt = requests.get(
    contest_url, headers=headers, allow_redirects=False, timeout=5
).text
soup = bsp(html_txt, "lxml")
print(soup.text.strip())
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
