# Source: https://github.com/the-tourist/algo/blob/master/generate_snippets.py

# Generates algo.codesnippets with snippets for VSCode

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
    extension = extension[0]
    if extension != 'cpp' and os.path.basename(subdir[0]).lower() != 'template':
      continue

    if name in snippets and extension != 'py':
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r', encoding='UTF8') as f:
      snippet = {
        "prefix": name,
        "scope": extension,
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('algo.code-snippets', 'w') as f:
  f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)
