#!/bin/zsh
echo "Указать путь"
read path

 number=$(cat $path | wc -l)
 uniqNumber=$(cat $path | awk {'print $1'} | sort | uniq | wc -l)
 shaNumber=$(cat $path | awk {'print $8'} | uniq | wc -l)
 echo "$number $uniqNumber $shaNumber"
