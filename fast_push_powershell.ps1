<#
.SYNOPSIS
    Pushes changes to a Git repository with a default commit message.
.DESCRIPTION
    This script adds all changes, commits them with a default message, and pushes them to the remote repository.
.PARAMETER CommitMessage
    The commit message to use. If not specified, "modify" is used.
#>
param (
    [string]$CommitMessage = "modify"
)

# 커밋 메시지 출력
Write-Host "Commit message: $CommitMessage"

& _make_snippet.bat

# Git 명령어 실행
git pull
git add .
git commit -m "$CommitMessage"
git push