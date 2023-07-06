import pygame
import time

# Set up the Pygame mixer
pygame.mixer.init()

# Load the drum samples
snare_sound = pygame.mixer.Sound('snare.wav')
bass_sound = pygame.mixer.Sound('bass.wav')

# Set the tempo (beats per minute) of the drumbeat
tempo = 120

# Calculate the length of a quarter note at the given tempo (in seconds)
quarter_note_length = 60.0 / tempo

# Read the ASCII drum notation from a file
with open('drums.txt', 'r') as f:
	ascii_notation = f.read()

# Split the ASCII notation into a list of measures
measures = ascii_notation.strip().split('|')

# Iterate over the measures
for measure in measures:
	# Split the measure into a list of individual drum symbols
	symbols = list(measure.strip())

	# Iterate over the symbols in the measure
	for symbol in symbols:
		# Play the corresponding drum sound
		if symbol == 'x':
			snare_sound.play()
		elif symbol == '|':
			bass_sound.play()

		# Sleep for the duration of a quarter note
		time.sleep(quarter_note_length)

# Wait until all the drum sounds have finished playing
while pygame.mixer.get_busy():
	time.sleep(0.1)

# Shutdown the Pygame mixer
pygame.mixer.quit()