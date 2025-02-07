#!/usr/bin/env bash

set -Eeuo pipefail
trap cleanup SIGINT SIGTERM ERR EXIT

cleanup() {
    trap - SIGINT SIGTERM ERR EXIT
    exit
}

# 사용자 입력 받기
read -p "Enter problem (e.g., '1800. Maximum Ascending Subarray Sum'): " input

# 문제 번호 추출 (예: "1800. Maximum Ascending Subarray Sum" → "1800")
problem_number=$(echo "$input" | awk -F'. ' '{print $1}')

# 문제 제목 추출 및 변환 (공백을 _로 변경)
problem_title=$(echo "$input" | awk -F'. ' '{print $2}' | tr ' ' '_')

# 디렉터리 생성
mkdir -p "$problem_number"

# Makefile 복사
cp ./configs/Makefile "$problem_number/"

# C++ 파일 생성
touch "$problem_number/${problem_number}_${problem_title}.cpp"

echo "Created directory: $problem_number"
echo "Copied Makefile to: $problem_number/"
echo "Created C++ file: $problem_number/${problem_number}_${problem_title}.cpp"
