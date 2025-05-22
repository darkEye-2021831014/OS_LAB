#!/bin/bash
read -p "Please Enter The Exact File Name: " fileName
g++-13 -std=c++17 -o run $fileName && ./run
