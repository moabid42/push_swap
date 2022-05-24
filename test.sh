#!/bin/bash

# RANDOM=$$
# for i in `seq 50`
# do
# 	echo $[$RANDOM % 117 + 1 ]
# done

# jot -r 1  2000 65000
# entries=($(shuf -i 0-149 -n 15))
# echo "${entries[@]}"

NBR=$(seq -500 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)