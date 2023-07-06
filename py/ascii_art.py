#badger
import sys
from PIL import Image

ASCII_CHARS = ['#', '?', '%', '.', 'S', '+', '.', '*', ':', ',', '@']

def scale_image(image, new_width=100):
	"""Resizes an image preserving the aspect ratio.
	"""
	(original_width, original_height) = image.size
	aspect_ratio = original_height/float(original_width)
	new_height = int(aspect_ratio * new_width)

	new_image = image.resize((new_width, new_height))
	return new_image

def convert_to_ascii(image, new_width=100):
	"""Converts an image to ASCII art.
	"""
	image = scale_image(image, new_width)
	ascii_image = []
	for pixel in image.getdata():
		# Convert pixel to grayscale
		grayscale = int(0.2989 * pixel[0] + 0.5870 * pixel[1] + 0.1140 * pixel[2])
		ascii_image.append(ASCII_CHARS[grayscale//25])
	return "".join(ascii_image)

def handle_image_conversion(image_file):
	image = None
	try:
		image = Image.open(image_file)
	except Exception as e:
		print(f"Unable to open image file {image_file}.")
		print(e)
		return

	image_ascii = convert_to_ascii(image)
	print(image_ascii)

if __name__=='__main__':
	if len(sys.argv) > 1:
		handle_image_conversion(sys.argv[1])
	else:
		print("missing image filename")