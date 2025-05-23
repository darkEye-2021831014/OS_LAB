#!/bin/bash
echo "Welcome To Shell Script"
echo -e "1)Factorial\n2)Parity Check\n3)File Metadata"
read -p "Option: " option

factorial(){
    val=$1
    ans=1
    for((i=1;i<=val;i++)){
        ((ans*=i))
    }
    echo $ans
}

parity(){
    val=$1
    if((val%2==0));then
        echo "$val: Even"
    else
        echo "$val: Odd"
    fi
}

case $option in
    1)
    read -p "Enter A Value: " fact
    if(($fact<0));then
        echo "Invallid Input"
    else
        factorial $fact
    fi
    ;;
    2)
    read -p "Enter A Value: " val
    parity $val
    ;;
    3)
    read -p "Enter File Name: " file
    echo "Current User: $(whoami)"
    echo "File Metadata: "
    ls -l $file
    ;;
    *)
    echo "Please Enter A Valid Option(1,2,3)"
    ;;
esac
