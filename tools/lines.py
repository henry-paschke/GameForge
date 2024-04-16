import os

def count_lines_of_code(directories):
    total_lines = 0
    for folder in directories:
        for root, dirs, files in os.walk(folder):
            for file in files:
                if file.endswith(('.hpp', '.cpp', '.h', '.c')):
                    file_path = os.path.join(root, file)
                    with open(file_path, 'r') as f:
                        lines = f.readlines()
                        print(file_path,"    ", len(lines))
                        total_lines += len(lines)

    return total_lines

src_directories = ['src', 'include\\private', 'include\\public\\GameForge']
lines_of_code = count_lines_of_code(src_directories)
print(f'Total lines of code: {lines_of_code}')