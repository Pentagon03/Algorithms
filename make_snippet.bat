@echo off
REM Python 스크립트를 실행하여 스니펫 파일 생성
python Etc/_vscode_snippet_generator.py

IF EXIST "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\algo.code-snippets" (
    move /Y "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\algo.code-snippets" "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\old"
)

copy /Y "algo.code-snippets" "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets"
