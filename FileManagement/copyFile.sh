#!/bin/bash
echo "Copy File"
read -p "Enter Source File Name: " oldFile
if [ -f $oldFile ];then
    read -p "Enter Destination File Name: " newFile
    cp $oldFile $newFile
    echo "Successfully Copied"
else
    echo "Source File Doesn't Exists"
fi