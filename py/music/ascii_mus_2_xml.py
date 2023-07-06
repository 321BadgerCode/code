#badger
import sys
import xml.etree.ElementTree as ET

def ascii_to_music_xml(ascii_str):
	# Split the input string into a list of lines
	lines = ascii_str.strip().split('\n')

	# Create the root element of the MusicXML document
	root = ET.Element('music', {'version': '1.1'})

	# Create the score-partwise element and add it to the root
	score_partwise = ET.SubElement(root, 'score-partwise')

	# Create the part element and add it to the score-partwise element
	part = ET.SubElement(score_partwise, 'part')

	# Set the ID and name of the part
	part.set('id', 'P1')
	ET.SubElement(part, 'part-name').text = 'Drums'

	# Create the measure element and add it to the part
	measure = ET.SubElement(part, 'measure')
	measure.set('number', '1')

	# Set the time signature of the measure
	time = ET.SubElement(measure, 'attributes')
	ET.SubElement(time, 'time')
	ET.SubElement(time, 'beats').text = '4'
	ET.SubElement(time, 'beat-type').text = '4'

	# Set the tempo of the measure
	ET.SubElement(measure, 'direction', {'placement': 'above'}).text = '<sound tempo="120"/>'

	# Create a list of pitches corresponding to the drum sounds
	pitches = {
		'x': 'C5',	# Snare drum
		'|': 'G3',	# Bass drum
	}

	# Iterate over the lines of the ASCII notation
	for line in lines:
		# Split the line into individual drum symbols
		symbols = list(line)

		# Iterate over the symbols in the line
		for symbol in symbols:
			# If the symbol is a rest, skip it
			if symbol == '-':
				continue

			# Create a note element and add it to the measure
			note = ET.SubElement(measure, 'note')

			# Set the pitch of the note based on the symbol
			ET.SubElement(note, 'pitch').text = pitches[symbol]

			# Set the duration of the note to a quarter note
			ET.SubElement(note, 'duration').text = '4'
			ET.SubElement(note, 'type').text = 'quarter'

			# Add a stem element to the note
			ET.SubElement(note, 'stem').text = 'down'

			# Add a staff element to the note
			ET.SubElement(note, 'staff').text = '1'

	# Return the MusicXML document as a string
	return ET.tostring(root, encoding='unicode')

if __name__=="__main__":
	if len(sys.argv) > 1:
		# Generate the MusicXML string from the ASCII notation
		musicxml_str=ascii_to_music_xml(sys.argv[1])

		# Parse the MusicXML string into an ElementTree object
		root=ET.fromstring(musicxml_str)

		# Write the ElementTree object to a file
		ET.ElementTree(root).write("drum.xml",encoding="utf-8")
	else:
		print("usage: python "+str(sys.argv[0]+" <ASCII music>"))