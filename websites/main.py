import os
from urllib.parse import urljoin, urlparse

import requests
from bs4 import BeautifulSoup
from tqdm import tqdm


def download_resource(url, folder):
    response = requests.get(url, stream=True)
    if response.status_code == 200:
        filename = os.path.join(folder, os.path.basename(urlparse(url).path))
        total_size = int(response.headers.get('content-length', 0))
        with open(filename, 'wb') as file, tqdm(
            desc=filename,
            total=total_size,
            unit='B',
            unit_scale=True,
            unit_divisor=1024,
        ) as bar:
            for chunk in response.iter_content(1024):
                file.write(chunk)
                bar.update(len(chunk))
        return filename
    return None


def download_webpage(url, folder):
    if not os.path.exists(folder):
        os.makedirs(folder)

    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')

    resources = []
    for tag in soup.find_all(['img', 'link', 'script']):
        if tag.name == 'img' and tag.get('src'):
            resources.append((tag, 'src'))
        elif tag.name == 'link' and tag.get('href'):
            resources.append((tag, 'href'))
        elif tag.name == 'script' and tag.get('src'):
            resources.append((tag, 'src'))

    for tag, attr in tqdm(resources, desc="Downloading resources"):
        resource_url = urljoin(url, tag[attr])
        local_path = download_resource(resource_url, folder)
        if local_path:
            tag[attr] = os.path.basename(local_path)

    html_path = os.path.join(folder, 'index.html')
    with open(html_path, 'w', encoding='utf-8') as file:
        file.write(str(soup))

    print(f'Webpage downloaded and saved to {html_path}')


# Example usage
download_webpage(
    'https://codeforces.com/problemset/problem/1992/E', 'Problem E')
