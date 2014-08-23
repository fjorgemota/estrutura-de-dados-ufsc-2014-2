#!/bin/bash
INPUT_DIR=`pwd`
FILES=`ls -1 $INPUT_DIR | grep \..pp`
ERROR=0
for FILE in $FILES; do
	echo "Checking $FILE"
	CPPLINT_ERRORS=`./cpplint.py --root=$INPUT_DIR $FILE  2>&1 >/dev/null`
	NUM_COUNT=`echo $CPPLINT_ERRORS | grep -E -o "Total errors found: [0-9]+" | grep -E -o "[0-9]+"`
	if [ $NUM_COUNT == "0" ]; then
		echo "Zero errors detected! Congratulations!"
	else
		echo "$NUM_COUNT errors detected! Go fix it:"
		echo -e "$CPPLINT_ERRORS"
		ERROR=1
	fi;
	python -c "print '-'*100"
done;
DOXYGEN_PATH=`which doxygen`
if [ ! -z "$DOXYGEN_PATH" ]; then
	OLD=`pwd`
	cd $INPUT_DIR
	DOXYGEN_ERRORS=`echo 'OUTPUT_DIRECTORY = /tmp/' | $DOXYGEN_PATH - 2>&1 | grep -o '.*is not documented' | grep -v 'cpplint.py'`
	cd $OLD
	if [ -z "$DOXYGEN_ERRORS" ]; then
		echo "Doxygen seens to approved your code! Congratulations!"
	else
		echo "Documentation not found for some methods:"
		echo -e "$DOXYGEN_ERRORS"
		ERROR=1
	fi;
else
	echo "Doxygen not found. Documentation status not verified."
fi;
python -c "print '-'*100"

if [ $ERROR == 1 ]; then
	echo "Errors detected! Fix it!"
	exit 1
else
	echo "Errors not found. Congratulations!"
fi