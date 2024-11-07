import requests
from bs4 import BeautifulSoup
import re
import html2text
import os


def process_math_spans(soup):
    # Inline math spans
    for span in soup.find_all("span", class_="math inline"):
        span.replace_with(f"${span.get_text()}$")

    # Display math spans with new lines before and after
    for span in soup.find_all("span", class_="math display"):
        math_text = span.get_text()
        span.replace_with(f"\n$$\n{math_text}\n$$\n")

    return soup


def process_pre_tags(soup):
    # Preformatted text
    for pre in soup.find_all("pre"):
        pre_text = pre.get_text()
        pre.replace_with(f"```\n{pre_text}\n```")

    return soup


def download_and_convert_to_markdown(url, base_url="https://cses.fi"):
    # Send a GET request to the page
    response = requests.get(url)

    if response.status_code == 200:
        # Parse the page content
        soup = BeautifulSoup(response.content, "html.parser")

        # Process math spans
        soup = process_math_spans(soup)

        # Process pre tags
        soup = process_pre_tags(soup)

        # Convert the page to Markdown
        html_content = str(soup)
        text_maker = html2text.HTML2Text()
        text_maker.ignore_links = True
        markdown_content = text_maker.handle(html_content)

        return markdown_content, soup
    else:
        print(f"Failed to download page: {url}")
        return None, None


# URL of the CSES Problem Set page
main_url = "https://cses.fi/problemset/"

# Download and convert the main page
main_markdown_content, main_soup = download_and_convert_to_markdown(main_url)

if main_markdown_content and main_soup:
    # Find all problem links
    problems = main_soup.find_all("a", href=True)

    # Pattern to match URLs of the form 'https://cses.fi/problemset/task/' followed by a number
    pattern = re.compile(r"^/problemset/task/\d+$")

    # Directory to save the task markdown files
    os.makedirs("cses_tasks", exist_ok=True)

    for problem in problems:
        href = problem["href"]

        if pattern.match(href):
            problem_url = "https://cses.fi" + href
            problem_name = problem.get_text().strip()
            task_file_name = problem_name.replace(" ", "_").replace("/", "_") + ".md"
            task_file_path = os.path.join("cses_tasks", task_file_name)

            # Print problem details
            print(f"Downloading problem: {problem_name}")
            print(f"URL: {problem_url}")

            # Download and convert the problem page to Markdown
            task_markdown_content, _ = download_and_convert_to_markdown(problem_url)

            if task_markdown_content:
                # Save the problem as a Markdown file
                with open(task_file_path, "w", encoding="utf-8") as file:
                    file.write(task_markdown_content)

                # Replace the original link with a link to the markdown file
                problem["href"] = f"cses_tasks/{task_file_name}"
            else:
                print(f"Failed to download problem: {problem_name}")

    # Convert the updated main page to Markdown again to include the correct links
    updated_main_html_content = str(main_soup)
    main_text_maker = html2text.HTML2Text()
    main_text_maker.ignore_links = False
    updated_main_markdown_content = main_text_maker.handle(updated_main_html_content)

    # Save the main page as a Markdown file
    with open("CSES_Problem_Set.md", "w", encoding="utf-8") as file:
        file.write(updated_main_markdown_content)

else:
    print("Failed to retrieve the main problem set page")
