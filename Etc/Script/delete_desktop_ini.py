import os
'''
For the directory of the script being run:
```python
import pathlib
pathlib.Path(__file__).parent.resolve()
```
For the current working directory:
```python
import pathlib
pathlib.Path().resolve()
```
'''
# Whatever, just copy and paste
folder_path = r"C:\Users\KyungmoKu\Desktop\Githubs\Trading_Github"

for root, dirs, files in os.walk(folder_path):
    for filename in files:
        if filename.lower() == "desktop.ini":
            file_path = os.path.join(root, filename)
            try:
                os.remove(file_path)
                print(f"Deleted {file_path}")
            except Exception as e:
                print(f"Error deleting {file_path}: {e}")