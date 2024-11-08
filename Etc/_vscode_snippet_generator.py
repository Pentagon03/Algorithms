# Source: https://github.com/the-tourist/algo/blob/master/generate_snippets.py

# Generates cpp.json with snippets for VSCode

import os
import json
import sys

snippets = {}

for subdir in os.walk('.'):
  if subdir[0] == '.' or '.git' in subdir[0]:
    continue
  for filename in subdir[2]:
    print(filename)
    name, *extension = filename.split('.')
    if not name or name[0] == '_' or len(extension) != 1:
      continue
    if extension[0] != 'cpp':
      continue

    if name in snippets:
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r', encoding='UTF8') as f:
      snippet = {
        "prefix": name,
        "scope": "cpp",
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('algo.json', 'w') as f:
  f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)
