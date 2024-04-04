#!/bin/bash

i=`date "+%H:%M:%S"`
while [ $i ]
do
	echo $i
	sleep 1
	i=`date "+%H:%M:%S"`
done
