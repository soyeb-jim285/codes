import asyncio
import http.client
import json
import os
import re
import shutil
import time
import urllib
import urllib.error
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import requests
from bs4 import BeautifulSoup as bsp
from markdownify import markdownify as md
from rich.progress import Progress

head = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:128.0) Gecko/20100101 Firefox/128.0",
    "Cookie": "JSESSIONID=C31EEEE78598FC1CFBFA524AB866831B",
}


def request_page(url, folder=None):
    max_retries = 5
    for attempt in range(max_retries):
        try:
            # Create a request object with headers
            req = urllib.request.Request(url, headers=head)
            # Get the page content
            with urllib.request.urlopen(req) as response:
                content_type = response.headers.get("Content-Type")
                content = b""
                while True:
                    try:
                        chunk = response.read()
                        if not chunk:
                            break
                        content += chunk
                    except http.client.IncompleteRead as e:
                        content += e.partial
            break  # Exit the loop if the request is successful
        except urllib.error.URLError as e:
            print(f"Attempt {attempt + 1} failed: {e}")
            if attempt < max_retries - 1:
                time.sleep(2)  # Wait for 2 seconds before retrying
            else:
                print("Failed to fetch the page after multiple attempts.")
                return

    if content_type in ["application/pdf", "application/pdf;charset=UTF-8"]:
        with open(f"{folder}.pdf", "wb") as pdf_file:
            pdf_file.write(content)
        print(f"Downloaded PDF: {folder}")
        return

    return content


def handle_img(img, folder, mark_down):
    img_url = img["src"]
    img_path = Path(f"{folder}/{img_url.split('/')[-1]}")
    if "codeforces" not in img_url:
        img_url_new = "https://codeforces.com/" + img_url.lstrip("/")
    elif not img_url.startswith("https"):
        img_url_new = "https://" + img_url.lstrip("/")
    else:
        img_url_new = img_url

    img_response = requests.get(img_url_new)
    with open(img_path, "wb") as img_file:
        img_file.write(img_response.content)
    mark_down = mark_down.replace(img_url, f"images/{img_url.split('/')[-1]}")
    return mark_down


def valid_name(text):
    text = "_".join(text.split(" "))
    text = "_".join(text.split("/"))
    text = "_".join(text.split("#"))
    text = "_".join(text.split("?"))
    text = "_".join(text.split("__"))
    return text


def statement_markdown(problem_statement):
    title = problem_statement.find("div", class_="title").text
    markdown_content = f"<h1 style='text-align: center;'> {title}</h1>\n\n"
    problem_markdown = md(str(problem_statement))

    # Print texts in `class=section-title` as h2 headers
    headers = problem_statement.find("div", class_="header")
    headers_md = md(str(headers))
    problem_markdown = problem_markdown.replace(headers_md, "")

    time_divs = headers.find("div", class_="time-limit")
    time_1 = time_divs.find("div", class_="property-title")
    time_md = (
        "<h5 style='text-align: center;'>"
        + time_1.text
        + ": "
        + time_divs.contents[1].strip()
        + "</h5>\n"
    )
    memory = headers.find("div", class_="memory-limit")
    memory_1 = memory.find("div", class_="property-title")
    memory_md = (
        "<h5 style='text-align: center;'>"
        + memory_1.text
        + ": "
        + memory.contents[1].text
        + "</h5>\n\n"
    )

    headers_md = markdown_content + time_md + memory_md

    section_titles = problem_statement.find_all("div", class_="input")
    for section_title in section_titles:
        section_title_md = md(str(section_title.find("div", class_="title")))
        section_title_h2 = section_title_md.replace(
            section_title_md,
            f"#{section_title.find("div", class_="title").text.strip()}",
        )
        problem_markdown = problem_markdown.replace(section_title_md, section_title_h2)

    section_titles = problem_statement.find_all("div", class_="output")
    for section_title in section_titles:
        section_title_md = md(str(section_title.find("div", class_="title")))
        section_title_h2 = section_title_md.replace(
            section_title_md,
            f"#{section_title.find("div", class_="title").text.strip()}",
        )
        problem_markdown = problem_markdown.replace(section_title_md, section_title_h2)

    section_titles = problem_statement.find_all("div", class_="section-title")
    for section_title in section_titles:
        section_title_md = md(str(section_title))
        section_title_h2 = section_title_md.replace(
            section_title_md, f"## {section_title.text.strip()}\n\n"
        )
        problem_markdown = problem_markdown.replace(section_title_md, section_title_h2)

    # Handle backslashes
    # Remove single backslash if followed by any character other than a backslash
    problem_markdown = re.sub(r"\\(?!\\)", "", problem_markdown)
    # Handle double dollar signs
    # Replace double dollar signs with single dollar signs
    problem_markdown = re.sub(r"\$\$\$", "$", problem_markdown)

    # Add newlines before and after any kind of headings
    problem_markdown = re.sub(r"(\n)?(#+ .+)(\n)?", r"\n\2\n", problem_markdown)

    # Make all text boxes (usually inside divs) a cpp code block
    problem_markdown = re.sub(
        r"```(?!text)(.*?)```", r"```text\1```", problem_markdown, flags=re.DOTALL
    )
    problem_markdown = re.sub(
        r"```text\n\n(.*?)\n\n```",
        r"```text\n\1\n```",
        problem_markdown,
        flags=re.DOTALL,
    )
    # Combine the title and problem markdown
    markdown_content = headers_md + problem_markdown + "\n\n#### Tags \n\n"
    return markdown_content


def problem_markdown(problem):
    name = problem["index"] + ". " + problem["name"]
    contestid = problem["contestId"]
    index = problem["index"]
    tags = problem["tags"]
    url = f"https://codeforces.com/contest/{contestid}/problem/{index}"
    if "rating" in problem:
        rating = problem["rating"]
        folder = f"With_rating/{contestid}/problems"
        bad_folder = f"Without_rating/{contestid}"
        if os.path.exists(bad_folder):
            shutil.rmtree(bad_folder)
    else:
        rating = 0
        folder = f"Without_rating/{contestid}/problems"

    file_name = valid_name(name)
    path = Path(f"{folder}/{file_name}.pdf")
    if path.exists():
        print(f"{name} already exists")
        return
    path = Path(f"{folder}/{file_name}.md")
    if path.exists():
        print(f"{name} already exists")
        return
    if not os.path.exists(folder):
        os.makedirs(folder, exist_ok=True)

    print("Fetching problem", end="\r")
    page_content = request_page(url, f"{folder}/{file_name}")
    if page_content is None:
        print("Page is none", end="\r")
        return None
    print("Fetched problem", end="\r")
    soup = bsp(page_content, "html.parser")

    # Extract the problem statement
    problem_statement = soup.find("div", class_="problem-statement")
    # Extract the title and add it to the top of the markdown
    soup_title = soup.find("div", class_="title")
    if not soup_title:
        markdown_content = "Problem is not available"
        with open(path, "w", encoding="utf-8") as file:
            file.write(markdown_content)
        print("Problem statement is not available")
        return
    markdown_content = statement_markdown(problem_statement)
    if rating != 0:
        markdown_content += f"#{rating} "
    markdown_content += f"#{problem["verdict"]} "
    for tag in tags:
        markdown_content += f"#{valid_name(tag)} "
    # Download and save images
    image_tags = problem_statement.find_all("img")

    image_folder = f"{folder}/images"

    if len(image_tags) > 0:
        os.makedirs(image_folder, exist_ok=True)
    imgs = problem_statement.find_all("img")
    for img in imgs:
        markdown_content = handle_img(img, image_folder, markdown_content)
    # Save the updated Markdown to a file
    with open(path, "w", encoding="utf-8") as file:
        file.write(markdown_content)
    print(f"Saved problem to {path}", end="\r")
