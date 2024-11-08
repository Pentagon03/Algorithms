import os, subprocess
# cpp 파일 일괄 컴파일
def compile_cpp_files():
    # 현재 디렉터리에서 모든 .cpp 파일 검색
    cpp_files = [f for f in os.listdir() if f.endswith(".cpp")]

    for cpp_file in cpp_files:
        # 파일 이름에서 확장자 제거
        file_name = os.path.splitext(cpp_file)[0]
        
        # g++ 컴파일 명령어
        command = ["g++", cpp_file, "-o", file_name]
        # command = ["g++", "-std=c++20", "-DLOCAL", cpp_file, "-o", file_name]
        print(f"Compiling {cpp_file}...")

        # 컴파일 명령어 실행
        result = subprocess.run(command, capture_output=True, text=True)
        
        # 컴파일 에러가 있을 경우 출력
        if result.returncode != 0:
            print(f"Error compiling {cpp_file}:\n{result.stderr}")
        else:
            print(f"{cpp_file} compiled successfully to {file_name}")

if __name__ == "__main__":
    compile_cpp_files()