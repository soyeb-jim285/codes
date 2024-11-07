import requests
import json

problem_api = "https://codeforces.com/api/problemset.problems?"
constest_api = "https://codeforces.com/api/contest.list?"
user_api = "https://codeforces.com/api/user.status?handle=soyeb_p_jim"


def api_response(url):
    try:
        response = requests.get(url=url)
        data = response.json()
        return data
    except Exception as e:
        print(f"An error occurred: {e}")
        return None


def marged_data():
    user_data = api_response(user_api)
    if user_data is None:
        return None
    print("Successfully fetched user data", end="\r")
    ok_verdicts = []
    for submission in user_data["result"]:
        if submission["verdict"] == "OK":
            ok_verdicts.append(
                str(submission["problem"]["contestId"]) + submission["problem"]["index"]
            )
    problems_data = api_response(problem_api)
    if problems_data is None:
        return None
    print("Successfully fetched problems data", end="\r")
    problems_data = problems_data["result"]["problems"]
    contests_data = api_response(constest_api)
    if contests_data is None:
        return None
    print("Successfully fetched contests data", end="\r")
    contests_data = contests_data["result"]
    data = {}
    done = 0
    for contest in contests_data:
        contest_id = contest["id"]
        contest_dic = {
            "name": contest["name"],
            "phase": contest["phase"],
            "startTime": contest["startTimeSeconds"],
            "duration": contest["durationSeconds"],
        }
        problem_dic = []
        data[contest_id] = {"contests": contest_dic, "problems": problem_dic}
        done += 1
        print(done)
        for problem in problems_data:
            if str(problem["contestId"]) + problem["index"] in ok_verdicts:
                problem["verdict"] = "OK"
            else:
                problem["verdict"] = "NOT OK"
            if "contestId" in problem and problem["contestId"] == contest_id:
                data[contest_id]["problems"].append(problem)
    print("Successfully merged data", end="\r")
    with open("data.json", "w") as f:
        json.dump(data, f)
    return data
