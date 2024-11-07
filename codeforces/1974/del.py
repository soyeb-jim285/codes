import os
import hashlib
from tqdm import tqdm

def calculate_hash(file_path):
    with open(file_path, "rb") as f:
        return hashlib.md5(f.read()).hexdigest()

video_dir = "/mood/downloaded_files/"
video_files = [
    os.path.join(video_dir, f)
    for f in os.listdir(video_dir)
    if os.path.isfile(os.path.join(video_dir, f))
]

hashes = {}
duplicate_count = 0
for video_file in tqdm(video_files):
    file_hash = calculate_hash(video_file)
    if file_hash in hashes:
        os.remove(video_file)
        duplicate_count += 1
    else:
        hashes[file_hash] = video_file

print(f"Number of duplicate files found and deleted: {duplicate_count}")