'''
# Stress Tester
원본: https://github.com/Pentagon03/Algorithms/blob/master/Etc/stress.py
사용법: https://github.com/Pentagon03/Algorithms/blob/master/Etc/stress_test_guide.md
'''
import os
import sys

def stress_test(file="sol", start=1, file_sol = "", file_gen = ""):
    i = start
    script_dir = os.path.dirname(os.path.abspath(__file__))  # Directory Path
    
    
    if not file_sol:
        file_sol = f"{file}_sol"
    file_sol = os.path.join(script_dir, file_sol) # Solution or Brute Force

    if not file_gen:
        file_gen = f"{file}_gen"
    file_gen = os.path.join(script_dir, file_gen) # Generator

    if not os.path.exists(file_sol):
        print("No Solution File")
    if not os.path.exists(file_gen):
        print("No Generator File")

    while True:
        input_file = os.path.join(script_dir, f"{i}.in") # Input File
        ans_out = os.path.join(script_dir, f"{i}.ans") # Answer File
        my_out = os.path.join(script_dir, f"{i}.my") # My Output File
            
        if not os.path.exists(input_file):
            if not os.path.exists(file_gen):
                print("Every Test Passed!")
                break
            elif os.system(f"{file_gen} {i} > {input_file}"):  # {i} is Seed (Use args)
                print(f"Generator Error Occurred")
                break
        if os.path.exists(file_sol):
            if os.system(f"{file_sol} < {input_file} > {ans_out}"):
                print(f"Solution Error Occurred")
                break
        if not os.path.exists(ans_out):
            print(f"No Output File")
            break
        
        print(f"Testcase {i}")
        if os.system(f"{os.path.join(script_dir, file)} < {input_file} > {my_out}"): 
            print(f"No {file} or Error Occurred")
            break
        if open(my_out).read().rstrip() != open(ans_out).read().rstrip(): # eliminate rstrip if needed
            print("Output is Different")
            break
        
        i += 1

if __name__ == "__main__":
    print(f"Usage: python {sys.argv[0]} <file_name> [start_index] [file_sol] [file_gen]")
    
    file_name = sys.argv[1] if len(sys.argv) > 1 else "sol"
    start_index = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    file_sol = sys.argv[3] if len(sys.argv) > 3 else ""
    file_gen = sys.argv[4] if len(sys.argv) > 4 else ""
    
    stress_test(file=file_name, start=start_index, file_sol=file_sol, file_gen=file_gen)
