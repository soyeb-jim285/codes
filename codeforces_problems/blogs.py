import os
import re
from pathlib import Path

import requests
from bs4 import BeautifulSoup as bsp
from markdownify import markdownify as md
from selenium import webdriver
from selenium.webdriver.chrome.options import Options as ChromeOptions
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

head = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:128.0) Gecko/20100101 Firefox/128.0",
    "Cookie": "JSESSIONID=C31EEEE78598FC1CFBFA524AB866831B",
}


def valid_name(text):
    text = "_".join(text.split(" "))
    text = "_".join(text.split("/"))
    text = "_".join(text.split("#"))
    text = "_".join(text.split("?"))
    text = "_".join(text.split("__"))
    return text


def check_folder_exists(folder_path):
    if os.path.exists(folder_path) and os.path.isdir(folder_path):
        return True
    else:
        return False


def create_markdown_with_file_links(directory, time, name):
    # Get all files in the directory and sort them alphabetically
    files = sorted(
        [
            f
            for f in os.listdir(f"{directory}/problems")
            if os.path.isfile(os.path.join(f"{directory}/problems", f))
        ]
    )

    with open(f"{directory}/{name}.md", "w") as md_file:
        md_file.write(f"# {name} \n\n")
        md_file.write(f"Time: {time} \n\n")

    # Create and write the Markdown document
    with open(f"{directory}/{name}.md", "a") as md_file:
        md_file.write("## Problems \n\n")
        for file in files:
            file_path = os.path.join("problems", file)
            md_file.write(f"- [{file}]({file_path})\n")
    files = sorted(
        [
            f
            for f in os.listdir(f"{directory}/blog")
            if os.path.isfile(os.path.join(f"{directory}/blog", f))
        ]
    )
    with open(f"{directory}/{name}.md", "a") as md_file:
        md_file.write("\n### Blogs \n\n")
        for file in files:
            file_path = os.path.join("blog", file)
            md_file.write(f"- [{file}]({file_path})\n")


def final_markdown():
    files = sorted(
        [
            f
            for f in os.listdir("With_rating")
            if os.path.isfile(os.path.join("With_rating", f))
        ]
    )
    files += sorted(
        [
            f
            for f in os.listdir("Without_rating")
            if os.path.isfile(os.path.join("Without_rating", f))
        ]
    )
    with open("final.md", "w") as md_file:
        md_file.write("# Final \n\n")
        for file in files:
            file_path = os.path.join("/", file)
            md_file.write(f"- [{file}]({file_path})\n")


def seconds_to_hms(total_seconds):
    hours = total_seconds // 3600
    minutes = (total_seconds % 3600) // 60
    return hours, minutes


def request_page(url):
    options = ChromeOptions()
    options.add_argument("--headless=new")
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-dev-shm-usage")
    options.add_argument(
        "user-agent=Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"
    )  # Add this line

    service = ChromeService(
        executable_path="/usr/bin/chromedriver")  # Update this path

    driver = webdriver.Chrome(service=service, options=options)

    try:
        driver.get(url)
        driver.add_cookie(
            {"name": "JSESSIONID", "value": "C31EEEE78598FC1CFBFA524AB866831B"}
        )
        # Wait until the page is fully loaded
        WebDriverWait(driver, 20).until(
            EC.presence_of_element_located((By.TAG_NAME, "body"))
        )
        page_content = driver.page_source
        return page_content
    except Exception as e:
        print(f"An error occurred: {e}")
        return None
    finally:
        driver.quit()


def blog_page(blog_url, folder):
    page_content = request_page(blog_url)
    if page_content is None:
        print(f"Failed to retrieve content from {blog_url}")
        return
    soup = bsp(page_content, "html.parser")
    blog_r = soup.find("div", class_="ttypography")

    if blog_r is None:
        print("The blog is none")
        return

    # Ensure all links contain 'codeforces'
    for link in blog_r.find_all("a", href=True):
        if "codeforces" not in link["href"]:
            link["href"] = "https://codeforces.com/" + link["href"].lstrip("/")

    # Handle spoilers
    for spoiler in blog_r.find_all("div", class_="spoiler"):
        spoiler_content = spoiler.find("div", class_="spoiler-title")
        if spoiler_content:
            spoiler.replace_with(spoiler_content)

    blog = str(blog_r)
    # Handle YouTube video links
    for iframe in blog_r.find_all("iframe"):
        src = iframe.get("src")
        if src is None:
            continue
        if "youtube.com" in src:
            video_id = src.split("/")[-1].split("?")[0]
            video_title = "Video"  # You might want to extract the title dynamically
            embed_code = f"[![{video_title}](https://img.youtube.com/vi/{
                video_id}/0.jpg)](https://www.youtube.com/watch?v={video_id})"
            # Replace the iframe with the markdown embed code
            new_tag = soup.new_tag("p")
            new_tag.string = embed_code
            iframe.replace_with(new_tag)
    blog = md(str(blog_r))
    blog = re.sub(r"\\(?!\\)", "", blog)
    # Handle double dollar signs
    # Replace double dollar signs with single dollar signs
    blog = re.sub(r"\$\$\$", "$", blog)

    # Add newlines before and after any kind of headings
    blog = re.sub(r"(\n)?(#+ .+)(\n)?", r"\n\2\n", blog)

    # Make all text boxes (usually inside divs) a cpp code block
    blog = re.sub(r"```(?!cpp)(.*?)```", r"```cpp\1```", blog, flags=re.DOTALL)

    imgs = blog_r.find_all("img")
    if len(imgs) > 0:
        os.makedirs(f"{folder}/images", exist_ok=True)
    for img in imgs:
        blog = handle_img(img, folder, blog)
    return blog


def handle_img(img, folder, blog):
    img_url = img["src"]
    img_path = Path(f"{folder}/images/{img_url.split('/')[-1]}")
    if "codeforces" not in img_url:
        img_url_new = "https://codeforces.com/" + img_url.lstrip("/")
    elif not img_url.startswith("https"):
        img_url_new = "https://" + img_url.lstrip("/")
    else:
        img_url_new = img_url

    img_response = requests.get(img_url_new)
    with open(img_path, "wb") as img_file:
        img_file.write(img_response.content)
    blog = blog.replace(img_url, f"images/{img_url.split('/')[-1]}")
    return blog


def save_blog(url, folder, name):
    name = valid_name(name)
    blog_path = Path(f"{folder}/{name}.md")
    if blog_path.exists():
        print(f"{name} already exists")
        return
    blog = blog_page(url, folder)
    if blog is None:
        return
    blog = f"# {name}\n\n" + blog

    os.makedirs(folder, exist_ok=True)
    with open(blog_path, "w") as blog_file:
        blog_file.write(blog)

    print(f"Saved blog to {blog_path}")


def contest_page(contestId):
    contest_url = f"https://codeforces.com/contest/{contestId}"
    page_content = request_page(contest_url)
    if page_content is None:
        print(f"Failed to retrieve page content for contest {contestId}")
        return
    soup = bsp(page_content, "html.parser")
    hrefs = soup.find_all("a", href=True)
    folder_path = f"With_rating/{contestId}"
    tmp = []
    blogs = []
    for href in hrefs:
        if check_folder_exists(folder_path):
            for href in hrefs:
                if "blog" in href["href"]:
                    if "codeforces" in href["href"]:
                        href_url = href["href"]
                    else:
                        href_url = f"https://codeforces.com{href['href']}"
                    save_blog(
                        href_url,
                        f"{folder_path}/blogs",
                        f"{valid_name(href.text)}",
                    )
                    tmp.append(
                        (
                            href_url,
                            f"{valid_name(href.text)}.md",
                        )
                    )
                    tmp.append(
                        (
                            f"{href["href"]}",
                            f"{valid_name(href.text)}.md",
                        )
                    )
                    blogs.append(href.text)
        folder_path = f"Without_rating/{contestId}"
        if check_folder_exists(folder_path):
            for href in hrefs:
                if "blog" in href["href"]:
                    if "codeforces" in href["href"]:
                        href_url = href["href"]
                    else:
                        href_url = f"https://codeforces.com{href['href']}"
                    save_blog(
                        href_url,
                        f"{folder_path}/blogs",
                        f"{valid_name(href.text)}",
                    )
                    tmp.append(
                        (
                            href_url,
                            f"{valid_name(href.text)}.md",
                        )
                    )
                    tmp.append(
                        (
                            f"{href["href"]}",
                            f"{valid_name(href.text)}.md",
                        )
                    )
                    blogs.append(href.text)
        return blogs, tmp


# contest_api_link = "https://codeforces.com/api/contest.list"
# response = requests.get(contest_api_link)
# data = response.json()['result']
# done_elements = 0
# with Progress() as progress:
#     task = progress.add_task("Processing...", total=len(data))
#     for contest in data:
#         done_elements += 1
#         progress.update(task, advance=1, description=f"[cyan]Processing.. {contest['id']} - {
#                         done_elements}/{len(data)}")
#         if contest['phase'] == 'FINISHED':
#             contest_page(
#                 contest['id'], contest['durationSeconds'], contest['name'])
#
# final_markdown()
# save_blog("https://codeforces.com/blog/entry/132018", "Without rating/1/blog", "Blog 1")
