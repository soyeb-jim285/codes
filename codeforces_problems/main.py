import glob
import json
import os.path as path
import time

from rich.progress import Progress

from api_calls import marged_data
from blogs import contest_page, seconds_to_hms, valid_name
from problems import problem_markdown


def is_file_older_than_x_days(file, days=1):
    file_time = path.getmtime(file)
    # Check against 24 hours
    return (time.time() - file_time) / 3600 > 24 * days


def epoch_to_date(epoch):
    # Ensure epoch is an integer or float
    epoch = float(epoch)
    return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(epoch))


def fetch_data(file):
    if path.exists(file):
        if is_file_older_than_x_days(file):
            marged_data()
    else:
        marged_data()


file = "data.json"
fetch_data(file)
f = open(file)

# returns JSON object as
data = json.load(f)
if data is not None:
    with open("Contests.md", "w") as f:
        f.write("# Codeforces Contests\n\n")
        f.write("|Start|Name|Length|Solved/Total|\n")
        f.write("|-----|----|------|------------|\n")
    done_elements = 0
    with Progress() as progress:
        task = progress.add_task("Processing...", total=len(data))
        for contestId in data:
            if data[contestId]["contests"]["phase"] != "FINISHED":
                continue
            if len(data[contestId]["problems"]) == 0:
                continue
            done_elements += 1
            progress.update(
                task,
                advance=1,
                description=f"[cyan]Processing.. {contestId} - {
                    done_elements}/{len(data)}",
            )
            problem_links = []
            for problem in data[contestId]["problems"]:
                problem_markdown(problem)
                problem_links.append(
                    (
                        f"https://codeforces.com/contest/{
                            problem['contestId']}/problem/{problem['index']}",
                        f"{valid_name(problem["index"] +
                                      ". " + problem['name'])}.md",
                    )
                )
                problem_links.append(
                    (
                        f"https://mirror.codeforces.com/contest/{
                            problem['contestId']}/problem/{problem['index']}",
                        f"{valid_name(problem["index"] +
                                      ". " + problem['name'])}.md",
                    )
                )
            # Finding the directory
            if "rating" in data[contestId]["problems"][0]:
                dir = f"With_rating/{contestId}"
            else:
                dir = f"Without_rating/{contestId}"
            problem_files = glob.glob(path.join(f"{dir}/problems", "*.md"))
            # Changing the links in the files
            for file in problem_files:
                with open(file, "r") as f:
                    content = f.read()
                for old_string, new_string in problem_links:
                    content = content.replace(old_string, new_string)
                with open(file, "w") as f:
                    f.write(content)
            result = contest_page(contestId)

            if result is None:
                print("Error: contest_page returned None")
                continue
            else:
                blogs, blog_strings = result
            blog_files = glob.glob(path.join(f"{dir}/blogs", "*.md"))
            for files in blog_files:
                with open(files, "r") as f:
                    content = f.read()
                if blog_strings is not None:
                    for old_string, new_string in blog_strings:
                        content = content.replace(old_string, new_string)
                    with open(files, "w") as f:
                        f.write(content)
            for files in problem_files:
                with open(files, "r") as f:
                    content = f.read()
                if blog_strings is not None:
                    for old_string, new_string in blog_strings:
                        content = content.replace(
                            old_string, f"../blogs/{new_string}")
                    with open(files, "w") as f:
                        f.write(content)
            for files in blog_files:
                with open(files, "r") as f:
                    content = f.read()
                if problem_links is not None:
                    for old_string, new_string in problem_links:
                        content = content.replace(
                            old_string, f"../problems/{new_string}"
                        )
                    with open(files, "w") as f:
                        f.write(content)
            for files in problem_files:
                with open(files, "r") as f:
                    content = f.read()
                if "## Blogs" not in content:
                    with open(files, "a") as f:
                        f.write("\n\n## Blogs\n")
                        f.write(
                            f"- [All Contest Problems](../{valid_name(
                                data[contestId]["contests"]["name"])}.md)\n"
                        )
                        for blog in blogs:
                            f.write(
                                f"- [{blog}](../blogs/{valid_name(blog)}.md)\n")
            contest = data[contestId]["contests"]
            solved = 0
            total_problems = len(data[contestId]["problems"])
            with open(f"{dir}/{valid_name(contest["name"])}.md", "w") as f:
                f.write(f"# {data[contestId]['contests']['name']}\n\n")
                f.write("## Problems\n\n")
                f.write("|Problem name|Status|\n")
                f.write("|------------|---------|\n")
                for problem in reversed(data[contestId]["problems"]):
                    if problem["verdict"] == "OK":
                        solved += 1
                    f.write(
                        f"| [{problem['index']}. {problem["name"]}](problems/{valid_name(
                            problem["index"] + ". " + problem["name"])}.md)|{problem["verdict"]}|\n"
                    )
                f.write("## Blogs\n\n")
                for blog in blogs:
                    f.write(f"- [{blog}](blogs/{valid_name(blog)}.md)\n")
            with open("Contests.md", "a") as f:
                time_str = contest["duration"]
                hour, minute = seconds_to_hms(int(time_str))
                time_str = f"{hour} hours"
                if minute != 0:
                    time_str = time_str + f" {minute} minutes"
                f.write(
                    f"|{epoch_to_date(contest["startTime"])}|[{contest["name"]}]({
                        dir}/{valid_name(contest["name"])}.md)|{time_str}|{solved}/{total_problems}|\n"
                )


else:
    print("Data is None")
