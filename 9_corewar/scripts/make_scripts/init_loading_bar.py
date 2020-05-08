#!/usr/bin/env python3

import os
import sys
import json

def modified_headers():
	if not os.path.exists(sys.argv[4]):
		return False
	headers_files = sys.argv[3].split(" ")
	time_modified_bin = os.path.getmtime(sys.argv[4])
	amount_headers = len(headers_files)
	i = 0
	while i < amount_headers:
		if os.path.getmtime(headers_files[i]) > time_modified_bin:
			return True
		i += 1
	return False


def	files_to_recompiling(object_files, source_files):
	o_files_to_recompiling = 0
	len_source = len(source_files)
	if (modified_headers()):
		return len_source
	i = 0
	while i < len_source:
		if not os.path.exists(object_files[i]):
			o_files_to_recompiling += 1
		elif os.path.getmtime(object_files[i]) < os.path.getmtime(source_files[i]):
			o_files_to_recompiling += 1
		i += 1
	return o_files_to_recompiling

def run_init_loading_bar(files_to_compaling):
	loading_bar = {
		"size_one_step": 0.0,
		"progress": 0.0,
		"index_current_place": 2
	}
	length_bar = 50.0
	loading_bar["size_one_step"]= length_bar / files_to_compaling
	with open('.loading_bar.json', 'w') as json_file:
		json.dump(loading_bar, json_file)
		json_file.close()
	print('\x1b[?25l\x1b[?7l[\x1b[50C]', end='')
	print(' 0.0%', end='')

if __name__ == "__main__":
	object_files = sys.argv[1].split(" ")
	source_files = sys.argv[2].split(" ")
	files_to_recompiling = files_to_recompiling(object_files, source_files)
	if files_to_recompiling > 0:
		run_init_loading_bar(files_to_recompiling)
	
