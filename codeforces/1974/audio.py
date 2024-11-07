import os
from moviepy.editor import VideoFileClip
from tqdm import tqdm

video_dir = '/mood/downloaded_files/'
output_dir = '/mood/downloaded_files/audio/'
video_files = [os.path.join(video_dir, f) for f in os.listdir(
    video_dir) if os.path.isfile(os.path.join(video_dir, f))]

audio_count = 0
for video_file in tqdm(video_files):
    video = VideoFileClip(video_file)
    if video.audio is not None:
        os.rename(video_file, os.path.join(
            output_dir, os.path.basename(video_file)))
        audio_count += 1

print(f"Number of videos with audio found: {audio_count}")
