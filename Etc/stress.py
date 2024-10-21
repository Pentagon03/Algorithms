import os
import sys

def stress_test(file="sol", generator=False, start=1):
    i = start
    script_dir = os.path.dirname(os.path.abspath(__file__))  # Directory Path
    
    file_gen = os.path.join(script_dir, f"{file}_gen") # Generator
    file_ok = os.path.join(script_dir, f"{file}_ok") # Solution or Brute Force

    while True:
        print(f"Testcase No.{i}")
        input_file = os.path.join(script_dir, f"{i}.in") # Input File
        ans_out = os.path.join(script_dir, f"{i}.ans") # Answer File
        my_out = os.path.join(script_dir, f"{i}.my") # My Output File
        
        if generator:
            if os.system(f"{file_gen} {i} > {input_file}"):  # {i} is Seed (Use args)
                print(f"No {file}_gen")
                break
        
        if not os.path.exists(input_file):
            print(f"No Test, Stress Test Finished")
            break
        
        if not os.path.exists(ans_out):
            if os.system(f"{file_ok} < {input_file} > {ans_out}"):
                print(f"There should be {file}_ok file")
                break
        
        if os.system(f"{os.path.join(script_dir, file)} < {input_file} > {my_out}"): 
            break
        
        if open(my_out).read().rstrip() != open(ans_out).read().rstrip(): # change rstrip if needed
            print("Output is Different")
            break
        
        i += 1

if __name__ == "__main__":
    print(f"Usage: python {sys.argv[0]} <file_name> <generator_flag> [start_index]")
    file_name = sys.argv[1] if len(sys.argv) > 1 else "sol"
    generator_flag = sys.argv[2].lower()[0] == 't' if len(sys.argv) > 2 else False
    start_index = int(sys.argv[3]) if len(sys.argv) > 3 else 1
    
    stress_test(file=file_name, generator=generator_flag, start=start_index)
