#!/bin/bash
echo "Move File"
read -p "Enter File Name: " file
if [ -f $file ];then
    read -p "Enter Destination Path: " path
    mv $file $path
    echo "Successfully Moved"
else
    echo "File Doesnt Exists"
fi