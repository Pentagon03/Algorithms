@echo off

REM Change Folder1, Folder2 to your own snippet folders

REM Python 스크립트를 실행하여 스니펫 파일 생성
python Etc/Script/vscode_snippet_generator.py

REM Set your snippet folders
set Folder1=C:\Users\$USER\AppData\Roaming\Code\User\snippets

REM 기존에 있던 스니펫을 old 폴더로 이동
IF EXIST "%Folder1%\algo.code-snippets" (
    move /Y "%Folder1%\algo.code-snippets" "%Folder1%\old"
)

REM 새로 만든 스니펫으로 교체
copy /Y "algo.code-snippets" "%Folder1%"


REM Erase below lines if you don't use other ides
set Folder2=C:\Users\$USER\AppData\Roaming\Cursor\User\snippets

REM 기존에 있던 스니펫을 old 폴더로 이동
IF EXIST "%Folder2%\algo.code-snippets" (
    move /Y "%Folder2%\algo.code-snippets" "%Folder2%\old"
)

REM 새로 만든 스니펫으로 교체
copy /Y "algo.code-snippets" "%Folder2%"