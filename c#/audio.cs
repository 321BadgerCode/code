//badger
using System;
using System.IO;
using System.Media;
using System.Runtime.InteropServices;

public static class audio{
	[DllImport("kernel32.dll", SetLastError = true)] private static extern bool Beep(uint A1, uint A2);

	public static void play(string A1) { SoundPlayer b1 = new SoundPlayer(A1 + ".wav"); b1.Play(); }
	public static void play(SystemSound A1) { A1.Play(); }
	public static void play(string file_name,double? A1, double? A2, double? A3, double? A4)
	{
		FileStream stream = new FileStream(file_name, FileMode.Create);
		BinaryWriter writer = new BinaryWriter(stream);
		int riff = 0x46464952;
		int wave = 0x45564157;
		int format_chunk_size = 16;
		int header_size = 8;
		int format = 0x20746D66;
		short format_type = 1;
		short tracks = 1;
		int samples_per_second = 44100;
		short bits_per_sample = 16;
		short frame_size = (short)(tracks * ((bits_per_sample + 7) / 8));
		int bytes_per_second = samples_per_second * frame_size;
		int wave_size = 4;
		int data = 0x61746164;
		int samples = 88200;
		int data_chunk_size = samples * frame_size;
		int file_size = wave_size + header_size + format_chunk_size + header_size + data_chunk_size;

		writer.Write(riff);
		writer.Write(file_size);
		writer.Write(wave);
		writer.Write(format);
		writer.Write(format_chunk_size);
		writer.Write(format_type);
		writer.Write(tracks);
		writer.Write(samples_per_second);
		writer.Write(bytes_per_second);
		writer.Write(frame_size);
		writer.Write(bits_per_sample);
		writer.Write(data);
		writer.Write(data_chunk_size);

		double volume = A1 ?? 10000;
		double a_natural = A2 ?? 220.0;
		double perfect = A3 ?? 1.5;
		double concert = A4 ?? 1.5;
		double frequency = a_natural * perfect;

		for (int a = 0; a < samples; a++)
		{
			double b1 = a / samples_per_second;
			short b2 = (short)(volume * (Math.Sin(b1 * frequency * 2 * Math.PI)));
			writer.Write(b2);
		}

		writer.Close();
		stream.Close();
	}
	public static void play(uint? A1, float? A2) { uint b1 = A1 ?? 100; uint b2 = (uint)(A2 * 1000 ?? 1000); Beep(b1, b2); }
};