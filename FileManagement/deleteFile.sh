#!/bin/bash
echo "Delete File"
read -p "Enter File Name: " file
if [ -f $file ];then
    rm $file
    echo "File Removed: $file"
else 
    echo "File Doesnt Exists"
fi