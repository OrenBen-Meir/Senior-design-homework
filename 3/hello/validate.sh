#!/bin/sh
#
# Usage: ./validate.sh <executable>

if test -z "$1"; then
	echo "Usage: ./validate.sh <executable>"
	exit 1
fi

INVALID=`$1 | sort | uniq | egrep -v "AAAAAAAAAA|BBBBBBBBBB|CCCCCCCCCC|DDDDDDDDDD"`

if test -z "$INVALID"; then
	echo "No invalid output, good job!"
	exit 0
fi

echo "Invalid output found, some examples below:"
echo $INVALID | tr " " "\n" | head -10
