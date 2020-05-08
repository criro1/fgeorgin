#!/usr/bin/env python3

# This script replaces the target file if the source file has changed.
# Accepts two arguments (argv[1] = "<source file>", argv[2] = "<target file>").

import os
import sys
import shutil

def need_move(bin_source, bin_root):
	if not os.path.exists(bin_root):
		return True
	if os.path.getmtime(bin_source) > os.path.getmtime(bin_root):
		return True
	return False

def	move_bin(bin_source, bin_root):
	shutil.copy(bin_source, bin_root)

if __name__ == "__main__":
	bin_source = sys.argv[1]
	bin_root = sys.argv[2]
	if os.path.exists(bin_source):
		if need_move(bin_source, bin_root):
			move_bin(bin_source, bin_root)
	else:
		print("Error: " + bin_source + " Not exists", file=sys.stderr)
