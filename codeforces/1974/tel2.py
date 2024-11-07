from telethon.sync import TelegramClient
from telethon.tl.functions.messages import GetHistoryRequest
from telethon.errors import SessionPasswordNeededError
from telethon.tl.types import MessageMediaPhoto
api_id = '22138266'
api_hash = 'ec0b7ccc04be1c547f8dbc36563e7300'
phone = '+8801987490252'

client = TelegramClient(phone, api_id, api_hash)

client.connect()
if not client.is_user_authorized():
    client.send_code_request(phone)
    try:
        client.sign_in(phone, input('Enter the code: '))
    except SessionPasswordNeededError:
        client.sign_in(password=input('Enter the password: '))

dialogs = client.get_dialogs()

for dialog in dialogs:
    print(dialog.name, dialog.id)