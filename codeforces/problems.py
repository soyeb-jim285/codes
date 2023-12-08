import os
import pandas as pd
from bs4 import BeautifulSoup as bsp
import requests

loginurl = "https://codeforces.com/enter?back=%2F"
main = "https://codeforces.com/"
headers = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
    # "Cookie": "astOnlineTimeUpdaterInvocation=1702067027507; lastOnlineTimeUpdaterInvocation=1702061253074; lastOnlineTimeUpdaterInvocation=1702064499412; cf_clearance=US2zn7CZo81KrRdf5MOuqirSfKpbwVQIvbnKVPTMfDo-1702067283-0-1-f4783d3d.7f8ed50e.a37962dd-0.2.1702067283; X-User-Sha1=954e14f57531bc507e75b7ddecefaf203542627b; 39ce7=CFosg4y0; 70a7c28f3de=1s8qfy6d2hh7n6y2jh; lastOnlineTimeUpdaterInvocation=1701960555150; JSESSIONID=B2EBD99555EFFE522A8DC67F0064CC7B; evercookie_png=1s8qfy6d2hh7n6y2jh; evercookie_etag=1s8qfy6d2hh7n6y2jh; evercookie_cache=1s8qfy6d2hh7n6y2jh; X-User=; nocturne.language=en",
}
payload = {"handleOrEmail": "mathproblems.solve@gmail.com", "password": "My91sKhan&56"}
r = requests.post(loginurl, headers=headers, data=payload)

contest_number = 1902

contest_url = f"https://codeforces.com/contest/{contest_number}"
html_txt = requests.get(
    contest_url, headers=headers, allow_redirects=False, timeout=5
).text
soup = bsp(html_txt, "lxml")
problems = soup.find("table", class_="problems")
names = problems.find_all("tr")
for tr in names[1:]:
    tds = tr.find_all("td")
    indx = tds[0].text.strip()
    divs = tds[1].find_all("div")
    names = indx + ". " + divs[1].text.strip()
    print(names)
    problem_url = f"https://codeforces.com/contest/{contest_number}/problem/{indx}"
    problem_page = requests.get(
        problem_url, headers=headers, allow_redirects=False, timeout=5
    ).text
    page = bsp(problem_page, "html.parser")
    inpt = page.find_all(class_="input")
    outs = page.find_all(class_="output")
    for inp in inpt:
        input_div = inp.find_all("div")
        for inpput in input_div[1:]:
            print(inpput.text.strip())
        # print(inp.text.strip())
    # for inp in inpt:
    #     inps = inp.find_all("test-example-line")
    #     print(inps)
