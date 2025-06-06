#!/bin/bash

# Enable nullglob so globbing fails gracefully if no match
shopt -s nullglob

# --- Check for directory argument ---
if [[ -z "$1" ]]; then
	echo "Error: No directory provided."
	echo "Usage: $0 <directory>"
	exit 1
fi

TARGET_DIR="$1"

# --- Check if it's a valid directory ---
if [[ ! -d "$TARGET_DIR" ]]; then
	echo "Error: '$TARGET_DIR' is not a valid directory."
	exit 1
fi

echo "Processing directory: $TARGET_DIR"

# --- Loop over all files except PNGs ---
for file in "$TARGET_DIR"/*; do
	# Skip if it's a directory
	[[ -d "$file" ]] && continue

	# Skip if it's already a PNG
	[[ "$file" == *.png ]] && continue

	# Extract base name without extension
	base="$(basename "${file%.*}")"
	output="$TARGET_DIR/${base}.png"

	echo "Converting: $file -> $output"

	# Attempt conversion
	if convert "$file" "$output"; then
		echo "Success: $file -> $output"
		rm -f "$file"
	else
		echo "Failed to convert: $file"
		rm -f "$output"
	fi
done

echo "Done. Only PNG files should remain in '$TARGET_DIR'."