import random

def generate_snare_beat(m, t, seed=None):
	# Initialize the random number generator
	if seed:
		random.seed(seed)
	else:
		random.seed()

	# Initialize the ASCII drum notation string
	ascii_notation = ''

	# Generate the number of measures specified
	for i in range(m):
		# Add a bar line to the notation to separate measures
		ascii_notation += '| '

		# Generate the number of beats specified by the time signature
		for j in range(t):
			# Roll a random number to decide whether to add a snare hit or a rest
			if random.random() > 0.5:
				ascii_notation += 'x '
			else:
				ascii_notation += '. '

	# Return the final ASCII drum notation
	return ascii_notation

# Generate a random snare beat lasting for 4 measures in 4/4 time
beat = generate_snare_beat(4, 4)
print(beat)