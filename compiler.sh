#!/bin/bash

echo -e "\nCompiling all source files...\n"

FILES=$(find . -name "*.c")

size=$(find . -name "*.c" | wc -l | sed 's/ //g')

i=0
per=0
while (( i < $size ))
do
	(( i += 1 ))
	parsed=$(echo $FILES | cut -f "$i" -d ' ')
	object="$parsed"
	ok_=$(gcc -Wall -Wextra -Werror -O3 -c "$parsed")
	ok=$?
	if [ "$ok" != "0" ]
	then
		echo -e "\nCompilation failed for file $parsed. Stopping.\n"
		exit
	fi
	(( per = i * 100 / size ))
	echo -e "Compilation progress: \033[1m$per%\033[0m.\r\c"
done
echo ""

ok_=$(ar -rc libftprintf.a *.o)
ok=$?
if [ "$ok" != "0" ]
then
	echo -e "\nLibrary compilation failed. Stopping.\n"
	exit
fi
ranlib libftprintf.a
echo -e "\nCompilation done. libftprintf.a created.\n"
