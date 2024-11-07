import os
from bs4 import BeautifulSoup as bs
import requests

problem_url = "http://www.usaco.org/index.php?page=viewproblem2&cpid=663"

try:
    problem_page = requests.get(problem_url).text
except requests.exceptions.RequestException as e:
    raise SystemExit(e)

problem_soup = bs(problem_page, "html.parser")

inpt = problem_soup.find_all("pre", class_="in")
print(inpt.text.strip())
outpt = problem_soup.find_all("pre", class_="out")
print(outpt.text.strip())
