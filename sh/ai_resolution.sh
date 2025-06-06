#!/bin/bash
resolutions=(512 768 1024 1280 1920)
for file in *; do
	if [ -f "$file" ]; then
		width=$(identify -format "%w" "$file" 2>/dev/null)
		height=$(identify -format "%h" "$file" 2>/dev/null)
		last_distance=(0 0)
		distance=(0 0)
		closest=(0 0)
		for res in "${resolutions[@]}"; do
			distance[0]=$((width - res))
			distance[1]=$((height - res))
			if [ ${distance[0]} -lt 0 ]; then
				distance[0]=$((0 - distance[0]))
			fi
			if [ ${distance[1]} -lt 0 ]; then
				distance[1]=$((0 - distance[1]))
			fi
			if [ ${last_distance[0]} -eq 0 ]; then
				last_distance[0]=${distance[0]}
			fi
			if [ ${last_distance[1]} -eq 0 ]; then
				last_distance[1]=${distance[1]}
			fi
			if [ ${distance[0]} -lt ${last_distance[0]} ]; then
				closest[0]=$res
				last_distance[0]=${distance[0]}
			fi
			if [ ${distance[1]} -lt ${last_distance[1]} ]; then
				closest[1]=$res
				last_distance[1]=${distance[1]}
			fi
		done
		if [ $closest -ne 0 ]; then
			convert "$file" -resize ${closest[0]}x${closest[1]}! "$file"
			echo "$file resized to ${closest[0]}x${closest[1]}"
		fi
	fi
done