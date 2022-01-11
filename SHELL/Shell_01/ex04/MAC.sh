for i in $(ifconfig |grep 'ether' |awk '{print $2}'); do printf "$i\n"; done
