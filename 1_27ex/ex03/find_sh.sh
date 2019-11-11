#!/bin/bash
find . -name "*.sh" -execdir echo '{}' ';' | cut -d. -f1
