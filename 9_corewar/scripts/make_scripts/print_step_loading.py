#!/usr/bin/env python3

import os
import sys
import json

if not os.path.exists('.loading_bar.json'):
	os.system('make init_loading --no-print-directory')

json_file = open(".loading_bar.json", "r")
loading_bar = json.load(json_file)
json_file.close()

loading_bar['progress'] += float(loading_bar['size_one_step'])
current_index = round(loading_bar['progress']) + 2
diff_index = int(current_index - loading_bar['index_current_place'])

if diff_index > 0:
	start_index = loading_bar['index_current_place']
	i = 0;
	print('\x1b[' + str(start_index) + 'G', end='')
	while i < diff_index:
		print('#', end='')
		i += 1

print('\x1b[53G\x1b[K', end='')
print('\x1b[54G' + str(round(loading_bar['progress'] * 2, 1)) + '%', end='')
print('\x1b[61G' + sys.argv[1], end='')

loading_bar['index_current_place'] = current_index

json_file = open(".loading_bar.json", "w")
json.dump(loading_bar, json_file)
json_file.close()
