#!/bin/bash
echo "Welcome To File Management"

while ((1));do
echo -e "1)createFile\n2)delteFile\n3)copyFile\n4)moveFile"
read -p "Option: " operation
case $operation in
    1)
    echo "Create File"
    read -p "Enter New File Name: " file
    if [ -f $file ];then
        echo "File Already Exists"
    else 
        touch $file
        echo "File Created: $file" 
    fi
    ;;
    2)
    echo "Delete File"
    read -p "Enter File Name: " file
    if [ -f $file ];then
        rm $file
        echo "File Removed: $file"
    else 
        echo "File Doesnt Exists"
    fi
    ;;
    3)
    echo "Copy File"
    read -p "Enter Source File Name: " oldFile
    if [ -f $oldFile ];then
        read -p "Enter Destination File Name: " newFile
        cp $oldFile $newFile
        echo "Successfully Copied"
    else
        echo "Source File Doesn't Exists"
    fi
    ;;
    4)
    echo "Move File"
    read -p "Enter File Name: " file
    if [ -f $file ];then
        read -p "Enter Destination Path: " path
        mv $file $path
        echo "Successfully Moved"
    else
        echo "File Doesnt Exists"
    fi
    ;;
    *)
    echo "Please Enter A Valid Option(1,2,3,4)"
    ;;
esac
echo ""
done