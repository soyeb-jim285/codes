from telethon.sync import TelegramClient
from telethon.tl.functions.messages import GetHistoryRequest
from telethon.errors import SessionPasswordNeededError
from telethon.tl.types import (
    MessageMediaPhoto,
    PeerChannel,
    MessageMediaDocument,
    DocumentAttributeFilename,
    DocumentAttributeVideo,
)
from tqdm import tqdm
from rich.progress import Progress
from telethon.tl.types import MessageMediaDocument, MessageMediaPhoto
import os

api_id = 22138266
api_hash = "ec0b7ccc04be1c547f8dbc36563e7300"
phone = "+8801987490252"
download_directory = "/mood/5th semester/"

client = TelegramClient(phone, api_id, api_hash)

group_id = -1002034346377 # replace with your group ID, ensure it's an integer

client.connect()
if not client.is_user_authorized():
    client.send_code_request(phone)
    try:
        client.sign_in(phone, input("Enter the code: "))
    except SessionPasswordNeededError:
        client.sign_in(password=input("Enter the password: "))

group_entity = client.get_entity(PeerChannel(group_id))
downloaded_files = set()
last_message_id = 0
file_counter = 0
while True:
    posts = client(
        GetHistoryRequest(
            peer=group_entity,
            limit=1000,
            offset_date=None,
            offset_id=last_message_id,
            min_id=0,
            max_id=0,
            add_offset=0,
            hash=0,
        )
    )

    if not posts.messages:
        break
    
    progress = Progress()
    
    def download_progress(downloaded_bytes, total_bytes):
        if progress.tasks[0].total != total_bytes:
            progress.tasks[0].total = total_bytes
        progress.update(task, completed=downloaded_bytes)
    
    with progress:
        task = progress.add_task("[cyan]Downloading...", total=1)  # set initial total to 1
    
        for message in posts.messages:
            if message.media is not None:
                if isinstance(message.media, MessageMediaDocument):
                    file_name = f'{message.media.document.id}.mp4'
                elif isinstance(message.media, MessageMediaPhoto):
                    file_name = f'{message.media.photo.id}.jpg'
                else:
                    continue
                
                file_counter += 1
                
                if file_name in downloaded_files:
                    print(f"File already exists: {file_name}")
                    continue
                file_path = client.download_media(message=message, file=os.path.join(download_directory, file_name), progress_callback=download_progress)
                downloaded_files.add(file_name)
                _, file_extension = os.path.splitext(file_path)
                if file_extension == '.jpg':
                    os.remove(file_path)
                    print(f"Skipped file: {file_path}")
                else:
                    print(f"Downloaded file: {file_path}")

            progress.update(task, advance=1)

    last_message_id = posts.messages[-1].id

