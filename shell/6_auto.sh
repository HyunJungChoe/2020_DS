#!/bin/bash

for i in ./*.sh ; do
	if [ -e 2_if.sh ] ; then 
		.  2_if.sh
	fi
done

echo "complete" 
 

