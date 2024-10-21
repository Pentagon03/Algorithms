# Source: Coxie
import os
i = 1
while True:
    print(i)
    file_name = ""
    if os.system(f'.\{file_name}_gen {i} > {file_name}_in'): break
    if os.system(f'.\{file_name}_my < {file_name}_in > {file_name}_my'): break
    if os.system(f'.\{file_name}_you < {file_name}_in > {file_name}_you'): break
    if open(f'{file_name}_my').read() != open(f'{file_name}_you').read():
        break
    i += 1