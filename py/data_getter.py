#badger
import os
import sys

def is_gud_file(file:str,extensions:str)->bool:
	ans:bool=False
	for a in extensions:
		if file.endswith(a):
			ans=True
	return ans

def get_file_extensions(extensions):
	"""Returns a list of file extensions, ignoring any spaces."""
	extensions = extensions.replace(" ", "")
	return extensions.split(",")

def append_file_contents(folder_path, file_to_append, extensions, comment_token, token):
	"""Appends the contents of files in the folder to the given file."""
	for root, directories, files in os.walk(folder_path):
		for file in files:
			if is_gud_file(file,extensions):
				with open(os.path.join(root, file), "r") as f:
					contents = f.read()

				with open(file_to_append, "a") as f:
					f.write(5 * comment_token + "\n")
					f.write(comment_token + file + "\n")
					f.write(5 * comment_token + "\n\n")
					f.write(contents)
					f.write(f"{token}")

def main():
	"""The main function of the program."""
	folder_path = input("Enter the folder path: ")
	extensions = input("Enter the file extensions to look for (comma-separated): ")
	file_to_append = input("Enter the file to append the contents to: ")
	comment_token = input("Enter the comment token: ")
	token = input("Enter the token to append after each file: ").replace("\\n","\n")

	extensions = get_file_extensions(extensions)
	append_file_contents(folder_path, file_to_append, extensions, comment_token, token)

if __name__ == "__main__":
	main()
#use config. file for variables.
#determine when to append end token(after each file unless has README.md, then wait 'til last file in last subfolder to append end token).
#append README.md content in a multi-line comment after the comment token.
#comment the file dir. but only what's after the given path(just use replace to get rid of path name in dir. string).
	#-use instead of commenting just file name.