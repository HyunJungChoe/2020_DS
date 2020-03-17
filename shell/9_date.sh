#!/bin/bash

A=`date +%d`
B=`expr $A % 2`

echo "Today ? $A "

if [ $B -eq 0 ]
then
	echo "짝수날"

else 
	echo "홀수날"

fi 
