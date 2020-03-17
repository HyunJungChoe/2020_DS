#!/bin/bash

if [ -f file1 ]
then
	echo "file r/w"
else 
	echo "file not found"

fi

if [ -r file1 -a -w file1 ]
then
	echo "file r/w"
else 
	echo "file not found"

fi
