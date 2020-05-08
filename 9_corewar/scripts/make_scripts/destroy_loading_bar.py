#!/usr/bin/env python3

import os

print('\x1b[?25h\x1b[?7h', end='')
print('\x1b[0G\x1b[K', end='')
loading_bar_json = "./.loading_bar.json"
if os.path.exists(loading_bar_json):
	os.remove(loading_bar_json)
