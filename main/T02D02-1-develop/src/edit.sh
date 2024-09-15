#!/bin/bash
echo  "Введите имя файла:"
read FileName
if [ -f "$FileName" ]

then
echo "Введите find строку: "
read str2
echo "Введите change строку: "
read str2


change=$(sed -i -e "s/$str2/$str2/g" "$FileName")

ShaSum=$(sha256sum "$FileName" |awk '{print $1}')
Var=$(stat --print "%s - %.16y - " "$FileName")
echo "src/$FileName $Var $ShaSum - sha256 " >> files.log

else echo "vi oshiblis"
fi
