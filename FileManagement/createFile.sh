#!/bin/bash
echo "Create File"
read -p "Enter New File Name: " file
if [ -f $file ];then
    echo "File Already Exists"
else 
    touch $file
    echo "File Created: $file" 
fi