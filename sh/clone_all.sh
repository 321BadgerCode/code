#!/bin/bash

# Replace with the GitHub username
USERNAME=$1
if [ -z "$USERNAME" ]; then
	echo "Usage: $0 <github-username>"
	exit 1
fi

# Create a folder to store all repos
mkdir -p "$USERNAME-repos"
cd "$USERNAME-repos" || exit

# Fetch all public repos using GitHub API
curl -s "https://api.github.com/users/$USERNAME/repos?per_page=100" |
jq -r '.[].clone_url' |
while read -r repo; do
	git clone "$repo"
done