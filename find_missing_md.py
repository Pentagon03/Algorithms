import os

def find_files_without_md(root_dir):
    """
    주어진 루트 디렉토리에서 .cpp 또는 .py 파일이지만 같은 디렉토리에 .md 파일이 없는 파일의 전체 경로를 찾습니다.

    Args:
        root_dir (str): 탐색할 루트 디렉토리.

    Returns:
        list: 조건을 만족하는 파일의 전체 경로 리스트.
    """
    result = []
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith((".cpp", ".py")):
                base_name, _ = os.path.splitext(file)
                md_file = os.path.join(root, base_name + ".md")
                if not os.path.exists(md_file):
                    full_path = os.path.join(root, file)
                    result.append(full_path)
    return result

# 현재 작업 디렉토리
root_dir = "."  # 현재 디렉토리를 나타냅니다.

# 함수 호출 및 결과 출력
files_without_md = find_files_without_md(root_dir)
# 사용자가 직접 사용할 만한 함수 정보와 설명을 주석으로 추가
# ```python
# def find_files_without_md(root_dir):
#     """
#     .cpp 또는 .py 파일이지만 같은 디렉토리에 .md 파일이 없는 파일의 전체 경로를 찾습니다.
#     Args:
#         root_dir (str): 탐색할 루트 디렉토리.
#     Returns:
#         list: 조건을 만족하는 파일의 전체 경로 리스트.
#     """
# ```
for file_path in files_without_md:
    print(file_path)