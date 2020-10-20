#!/bin/bash

doLoop(){
		filetypes=("jpg" "jpeg")
		files=""
		for j in ${filetypes[@]}
		do
				files=$files" "`ls *|grep $j`
		done
		wd=`pwd`
		for k in ${files[@]}
		do
				f="file:"$wd"/"$k
				echo $f
				gsettings set org.gnome.desktop.background picture-uri "'"$f"'"
				sleep 10s
		done
}

while true
do
	doLoop
done
