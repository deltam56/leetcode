#!/bin/bash

# 사용자 입력 받기
read -p "Enter problem (e.g., '1800. Maximum Ascending Subarray Sum'): " input

# 문제 번호 추출 (정수 부분만 추출)
problem_number=$(echo "$input" | awk -F'. ' '{print $1}')

# 문제 제목 추출 및 변환 (공백을 _로 변경, 특수문자 제거)
problem_title=$(echo "$input" | cut -d' ' -f2- | tr ' ' '_' | tr -cd '[:alnum:]_')

dirname=${problem_number}_unsolved
# 디렉터리 생성
mkdir -p "$dirname"

# Makefile 복사 (존재하는 경우에만 복사)
if [ -f ./configs/Makefile ]; then
    cp ./configs/Makefile "$dirname/"
    echo "Copied Makefile to: $dirname/"
else
    echo "Warning: Makefile not found in ./configs/"
fi

# C++ 파일 생성
cpp_file="$dirname/${problem_number}_${problem_title}.cpp"
touch "$cpp_file"

# 기본 C++ 코드 추가
cat <<EOL > "$cpp_file"
/**
*
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

int main() {
	Solution sol;	

	cout << "Accepted!" <<endl;
    return 0;
}
EOL

echo "Created directory: $dirname"
echo "Created C++ file: $cpp_file"
