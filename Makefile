all:
	read -p "Please Enter Exact FileName: " file && g++-13 -std=c++17 -o run "$$file" && ./run
