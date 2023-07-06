import pyaudio
import struct
import numpy as np

# Set up the PyAudio stream
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1, rate=44100, input=True, frames_per_buffer=1024)

# Set up some variables to keep track of the state of the program
last_hit_time = 0
snare_interval = 0

while True:
  # Read some audio data from the microphone
  data = stream.read(1024)

  # Convert the audio data to a NumPy array
  audio_data = np.frombuffer(data, dtype=np.int16)

  # Calculate the root mean square (RMS) of the audio data
  rms = np.sqrt(np.mean(audio_data**2))

  # If the RMS value is above a certain threshold, assume that a snare hit has occurred
  if rms > 2000:
	# Calculate the interval between this snare hit and the last one
	snare_interval = time.time() - last_hit_time

	# Update the time of the last snare hit
	last_hit_time = time.time()

	# Print the interval between snare hits
	print(snare_interval)

# Close the PyAudio stream when you're finished
stream.stop_stream()
stream.close()
p.terminate()