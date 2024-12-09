@echo off
:: 커밋 메시지 인자 확인
if "%1"=="" (
    set COMMIT_MESSAGE=modify
) else (
    set COMMIT_MESSAGE=%*
)

:: 커밋 메시지 출력 (echo를 통해 출력)
echo Commit message: "%COMMIT_MESSAGE%"

call _make_snippet.bat

:: Git 명령어 실행
git pull
git add .
git commit -m "%COMMIT_MESSAGE%"
git push
