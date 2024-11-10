@echo off
REM Python 스크립트를 실행하여 스니펫 파일 생성
python Etc/Script/_vscode_snippet_generator.py

REM 기존에 있던 스니펫을 old 폴더로 이동
IF EXIST "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\algo.code-snippets" (
    move /Y "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\algo.code-snippets" "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets\old"
)

REM 새로 만든 스니펫으로 교체
copy /Y "algo.code-snippets" "C:\Users\KyungmoKu\AppData\Roaming\Code\User\snippets"
