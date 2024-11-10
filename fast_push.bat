@echo off
chcp 65001 >nul
setlocal
call make_snippet.bat
git pull
git add .

rem 사용자에게 간단한 수정 내용을 입력받기
set /p commit_message="Enter commit message (description of changes): "

git commit -m "%commit_message%"
git push
endlocal