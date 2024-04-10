import requests

def get_all_repositories(username):
    url = f'https://api.github.com/users/{username}/repos'
    response = requests.get(url)

    if response.status_code == 200:
        repositories = response.json()
        return repositories
    else:
        print(f"Error fetching repositories for {username}. Status code: {response.status_code}")
        return None

def get_commit_activity(username, repo):
    url = f'https://api.github.com/repos/{username}/{repo}/stats/commit_activity'
    response = requests.get(url)

    if response.status_code == 200:
        commit_activity = response.json()
        return commit_activity
    else:
        print(f"Error fetching commit activity for {username}/{repo}. Status code: {response.status_code}")
        return None

def calculate_typing_hours(commit_activity):
    total_lines = 0

    for week in commit_activity:
        total_lines += week['total']

    # Assuming one line of code takes 30 seconds to type
    typing_time_seconds = total_lines * 30

    # Convert seconds to hours
    typing_time_hours = typing_time_seconds / 3600

    return typing_time_hours

# Example usage
github_username = 'biniyam69'

repositories = get_all_repositories(github_username)

if repositories:
    total_typing_hours_all_repos = 0

    for repo in repositories:
        commit_activity = get_commit_activity(github_username, repo['name'])
        if commit_activity:
            total_typing_hours_all_repos += calculate_typing_hours(commit_activity)

    print(f"{github_username} spent {total_typing_hours_all_repos:.2f} hours typing code across all repositories.")
