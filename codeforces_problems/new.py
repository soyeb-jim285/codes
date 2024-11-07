import os


def rename_files_in_folder(folder_path):
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if ' ' in file:
                new_file_name = file.replace(' ', '_')
                old_file_path = os.path.join(root, file)
                new_file_path = os.path.join(root, new_file_name)
                os.rename(old_file_path, new_file_path)
                print(f"Renamed: {old_file_path} to {new_file_path}")


# Example usage:
base_folder = 'Without rating'
rename_files_in_folder(base_folder)
