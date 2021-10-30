
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *

 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
  
/*
 * 
If you have time and want to contribute , just finish the documentation of:
mp3class.cs

The DLL is fully functional and can be used in GPL 3/LGPL 3 software.

Our software is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free software Foundation, either version 3 of
the License, or by (at your option) any later version.

This program is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public
License along with this program. If not, see
http://www.gnu.org/licenses/.

 */
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.Win32;

///This it the namespace for the project rsppmp3 (BW Player DLL)
namespace mp3dll
{
	static class Amanda_Constants
	{
		/// <summary>
		/// The windows max path plus 2 for safety...
		/// </summary>
		public const long MAX_PATH_k_p = 260 + 2;//for safety my love...
		public const double Pi = 3.879564;
		public const int SpeedOfLight = 325000; // km per sec.
	}
	
	public enum amanda_position
	{
		I_TOP__,
		I_CENTER,
		I_BOTTOM,
	};
	/// <summary>
	/// Some of the possible ratios, at least the most used
	/// </summary>
	public enum morcego_ratio
	{
		BE_AUTO_______,
		BE_5x4_______,
		BE_16x9_______,
		BE_16x10_______,
		BE_4x3_______,
		BE_2_21x1_______,
		BE_2_35x1_______,
		BE_2_39x1_______,
		BE_2_50x1_______,
		BE_1x1_______,
	};
	public class util_amanda
	{
		/// <summary>
		/// for your pleasure...
		/// </summary>
		internal const string amanda_pereira_empty_string_k_p = "";// ;-) ... 13-October-2020 11:06 AM
		
		/// <summary>
		/// Simple internal exit function...
		/// </summary>
		/// <param name="exit_value_k_p"></param>
		internal static void exit_ramses
			(
				long exit_value_k_p
			)
		{
			Environment.Exit
				(
					(int)exit_value_k_p
				);
			return;
		}
		public util_amanda ()
		{
			//constructor.
		}
	}
	/// <summary>
	/// The MP3 class is the class to play or decode Libav supported media files
	/// </summary>
	/// <remarks>
	/// remarks section
	/// </remarks>
	public class MP3
	{
		internal static sample sample_copy_i             = null;
		internal static amanda_search search_copy        = null;
		internal static sample sample_copy_ar            = null;
		internal static spectrum               k         = null;
		internal static normalize              k2        = null;
		internal static wave_effects           k3        = null;
		internal static equalizer              p         = null;
		internal static id3tag                 p4        = null;
		internal static DebugInformation       p2        = null;
		
		internal static int selected_track_i             =    1;
		internal static int selected_subtitle_track_i    =    1;
		
		internal static StringBuilder ricardo_koci_strb = new StringBuilder ((int)Amanda_Constants.MAX_PATH_k_p);
		internal static bool allow_create_new_instance_k_p = false;
		/// <summary>
		/// It will send debug information to the installed debugger
		/// Debugview by sysinternals in our case
		/// http://technet.microsoft.com/en-us/sysinternals/bb896647.aspx
		/// 
		/// 
		/// void WINAPI OutputDebugString(
		///__in_opt  LPCTSTR lpOutputString
		///);
		///
		/// </summary>
		/// <param name="lpOutputString"></param>
		[DllImport("kernel32.dll")]
		static extern void OutputDebugString(string lpOutputString);

		
		[DllImportAttribute("kernel32.dll", EntryPoint = "SetProcessWorkingSetSize", ExactSpelling = true, CharSet =
		                    CharSet.Ansi, SetLastError = true)]

		private static extern int SetProcessWorkingSetSize(IntPtr process, int minimumWorkingSetSize, int
		                                                   maximumWorkingSetSize);

		
		[DllImport("kernel32.dll")]
		public static extern int GetTickCount();
		
		/// <summary>
		/// Our internal debug function (arabcoder)
		/// </summary>
		/// <param name="data">the data to send</param>
		public static void dprintf(string data)
		{
			data = data + " _amanda_debug_";
			OutputDebugString(data);
		}
		/// <summary>
		/// 2020 new debug function, after the use just set 0 to -1
		/// </summary>
		/// <param name="position_k_p">0 to appear, -1 otherwise</param>
		/// <param name="data"></param>
		public static void pedro_dprintf
			(
				int position_k_p,
				string data)
		{
			
			if(-1 < position_k_p)
			{
				data = data + " _amanda_debug_";
				
				Console.WriteLine(data);
				data = data.Replace ("\n"," .. ");
				OutputDebugString(data);
			}
		}
		/// <summary>
		/// This is the function to play the media file
		///
		/// All media files suported by Libav can be played with this function
		///
		/// filename - The media file to play
		/// loop - Whether the playback will loop, if 1 it will loop forever
		///
		///  The playback will initialize as soon the function is called , and the function returns immediatelly also
		/// </summary>
		/// <param name="mv_instance">The instance of the player, for the moment only one instance is allowed, you get one with BE_CreateDecoder</param>
		/// <param name="utf8_filename">the media file to play, encoded from Unicode to UTF-8, see the sample project</param>
		/// <param name="loop">If it will loop or not</param>
		/// <param name="track">the track to play, for the moment need to be 1</param>
		/// <param name="hwnd_">the handle of the Picturebox that will be the background for the player, for the moment black</param>
		/// <param name="player_hwnd_">the handle of the Picturebox that will show the video</param>
		/// <param name="width_">the width of the desired video window</param>
		/// <param name="heigth_">the height of the desired video window</param>
		/// <param name="ratio_">the ratio of the video, at least the most used, use BE_AUTO_______ if unkown</param>
		/// <param name="left_">the position on the form of the video window</param>
		/// <param name="top_">the position on the form for the video window</param>
		/// <param name="subtitle_i">0 if no usage of subtitle or the subtitle to use, if the file have 3 subtitles the 1 is the first and so on</param>
		/// <returns>0 if ok, -1 if the decoder is not loaded</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Play(long mv_instance, string utf8_filename, int loop, int track,long hwnd_,
			     long player_hwnd_,
			     int width_,
			     int heigth_,
			     morcego_ratio ratio_,
			     int left_,
			     int top_,
			     int subtitle_i);

		
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			memory_usage__z(StringBuilder data_z);
		
		
		/// <summary>
		/// To know how many instances of the player are running, if two then it will exit and pass to the first instance the new file for playback
		/// </summary>
		/// <param name="path_k_p">the exe path to check if running</param>
		/// <returns>the count fo the running samples</returns>
		internal static int count_running_k_p(string path_k_p)
		{
			int num = 0;
			Process[] processes = Process.GetProcesses();
			path_k_p = path_k_p.ToLower();
			Process[] processArray = processes;
			for (int i = 0; i < (int)processArray.Length; i++)
			{
				Process process = processArray[i];
				try
				{
					if (path_k_p == process.MainModule.FileName.ToLower())
					{
						num++;
					}
				}
				catch
				{
				}
			}
			return num;
		}
		/// <summary>
		/// to enable the playback of stereo files as mono
		/// </summary>
		/// <param name="mv_instance">the player instance</param>
		/// <param name="enable">1 to enable...</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			BucaneiroPlayStereoAsMono(long mv_instance, int enable);

		/// <summary>
		/// This is the function to play the media file
		///
		/// All media files suported by Libav can be played with this function
		///
		/// filename - The media file to play
		/// loop - Whether the playback will loop, if 1 it will loop forever
		///
		///  The playback will initialize as soon the function is called , and the function returns immediatelly also
		/// </summary>
		/// <param name="mv_instance">The instance of the player, for the moment only one instance is allowed, you get one with BE_CreateDecoder</param>
		/// <param name="utf8_filename">the media file to play, encoded from Unicode to UTF-8, see the sample project</param>
		/// <param name="loop">If it will loop or not</param>
		/// <param name="track">the track to play, for the moment need to be 1</param>
		/// <param name="hwnd_">the handle of the Picturebox that will be the background for the player, for the moment black</param>
		/// <param name="player_hwnd_">the handle of the Picturebox that will show the video</param>
		/// <param name="width_">the width of the desired video window</param>
		/// <param name="heigth_">the height of the desired video window</param>
		/// <param name="ratio_">the ratio of the video, at least the most used, use BE_AUTO_______ if unkown</param>
		/// <param name="left_">the position on the form of the video window</param>
		/// <param name="top_">the position on the form for the video window</param>
		/// <param name="subtitle_i">0 if no usage of subtitle or the subtitle to use, if the file have 3 subtitles the 1 is the first and so on</param>
		/// <returns>0 if ok, -1 if the decoder is not loaded</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Open(long mv_instance, string utf8_filename, int loop, int track,long hwnd_,
			     long player_hwnd_,
			     int width_,
			     int heigth_,
			     morcego_ratio ratio_,
			     int left_,
			     int top_,
			     int subtitle_i);

		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetWaveOutStatus_arp
			(
				long mv_instance
			);
		
		
		/// <summary>
		/// This function will return the status of the playback , if > 999 then it is playing
		/// It is required to control the playback
		
		///Since this is the most important function to control the end of the playback you need to understand how it work correctly
		///  The return value can be passed to GetErrorString to retrieve a string with the result of the playback
		/// Values:<br><br>
		/// 0-"No error"<br>
		/// 2-"Error opening waveout"<br>
		/// 3-"Input does not appear to be a wav file"<br>
		/// 4-"Error reading first page of Ogg bitstream data"<br>
		/// 5-"Error reading initial header packet"<br>
		/// 6-"This Ogg bitstream does not contain Vorbis"<br>
		/// 7-"Corrupt secondary header"<br>
		/// 8-"End of file before finding all Vorbis headers!"<br>
		/// 9-"No valid devices in the system"<br>
		/// 10-"Cannot open media file"<br>
		/// 20-"Input does not appear to be a wav file"<br>
		/// 21-"Only PCM wav files can play"<br>
		/// 22-"Invalid number of bits per sample"<br>
		/// 24-"Invalid MPEG file"<br>
		/// 25-"Invalid number of channels"<br>
		/// 26-"Invalid sample rate"<br>
		/// 300-"Tampering detected , please reinstall the component"<br>
		/// 1000-"Playing..."<br>
		/// 1001-"Playback paused" <br>
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			IntReturn(long mv_instance);


		/// <summary>
		///It is used to pause the playback
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PlaybackPause(long mv_instance);

		/// <summary>
		///It is used to resume the playback or initiate the playback if the function Open was used
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PlaybackResume(long mv_instance);

		/// <summary>
		///It is used to cancel the playback, and unload the mefia file
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PlaybackCancel(long mv_instance);

		/// <summary>
		///It is used to retrieve the samplerate of the media file
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			SampleRate(long mv_instance);

		/// <summary>
		///It will retrieve the number of channels of the media file, 1 or 2 always for the moment (24/November/2020)
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Channels(long mv_instance);

		/// <summary>
		/// It is the media bits per sample, but notice that the player will convert it to 16 bits to play (at least at 24/November/2020), if it is a problem send me an email and I will extend it to play in the real number of bits
		/// </summary>
		/// <param name="number">the player instance</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Bits_per_Sample(long mv_instance);

		/// <summary>
		///To retrieve the playback position in milliseconds
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetTimeMilliseconds(long mv_instance);

		/// <summary>
		///To retrieve the playback time in seconds
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetTime(long mv_instance);

		/// <summary>
		///It will retrieve the playback time in a formatted string
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetTimeString(long mv_instance, StringBuilder time);

		/// <summary>
		///It will retrieve the length of the media file as a formatted string
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetLengthString(long mv_instance, StringBuilder time);

		/// <summary>
		///It will retrieve the length of the media file as milliseconds
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetLengthMilliseconds(long mv_instance);

		/// <summary>
		///It will retrieve the length of the media file as seconds
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetLength(long mv_instance);

		/// <summary>
		///It will finish the playback and close the player
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			ClosePlayer(long mv_instance);

		/// <summary>
		///It will seek on the media playback
		///seek - The value to seek in percentage (0 to 100)
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			SeekTo(long mv_instance, double seek);
		/// <summary>
		/// It will seek based on a 10000 slice of the whole media playback time, for a good granularity of the slider, now each pixel can select a different media playback position, at least until the size of the width of the screen reach a value larger than 10000 pixels
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="seek"></param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			SeekTo_10000(long mv_instance, double seek);

		/// <summary>
		/// It will seek based on a AV_TIME_BASE value , it is 1000000 for each second
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="seek"></param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			SeekTo_AV_TIME_BASE(long mv_instance, double seek);

		/// <summary>
		///It will get the progress position as percentage (0 to 100)
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PlayBackPosition(long mv_instance);
		/// <summary>
		/// it will return the playback position as a slice of 10000, 5000 means the middle of the media file
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PlayBackPosition_10000(long mv_instance);

		/// <summary>
		/// to show or hide the cursor
		/// </summary>
		/// <param name="enable">1 to show</param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			ShowCursor_(int enable);

		/// <summary>
		/// it will return the AV_TIME_BASE position of the playback, it is 1000000 for each second
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern
			double
			PlayBackPosition_AV_TIME_BASE(long mv_instance);

		/// <summary>
		///It will set the priority of the playback
		///0 - Idle processor time
		///1 - Normal processor time
		///2 - High processor time
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			SetPriority(long mv_instance, int priority);

		/// <summary>
		/// This function will change the volume of the playback
		/// In the version 2.5.0 this function was modified, now it range from 0 to 100 and not from 0 to 10 anymore
		/// Notice that this function access the system mixer , then it affect the volume of any file playing, if you want to change only the playback of the file playing in the control, then use the InternalVolume function, now the InternalVolume function is the preferred way to change volume playback
		/// A value of 0 will mute the playback, a value of 100 to maximum volume
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			SetVolumeGain(long mv_instance, int value);

		/// <summary>
		///It will define the wave out device that will play the media file, it range from 0 to the number of wave out devices less 1, use GetNumberofWaveOutDevices to retrieve the number of wave out devices
		///
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			SetWaveOutDevice(long mv_instance, int device);

		/// <summary>
		///It will return the name of the selected wave out device in the data variable
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetWaveOutDevicesName(long mv_instance, int device, StringBuilder data);

		/// <summary>
		///After release 1.9.38 this function has no effect
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetVBR(long mv_instance);

		/// <summary>
		///It will retrieve the bitrate of the media file (if applicable)
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetBitrate(long mv_instance);
		
		/// <summary>
		///It will retrieve the bitrate of the media file (if applicable)
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetBitrate_Video(long mv_instance);

		/// <summary>
		/// After release 1.9.38 this function has no effect
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetMpegVersion(long mv_instance, StringBuilder version);

		/// <summary>
		///It will retrieve the media information, about the audio and also the video if this is the case
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetMediaInformation(long mv_instance, StringBuilder layer);

		/// <summary>
		///It will retrieve the stereo mode
		///
		/// 
		///  It can be:
		/// "Stereo", "Joint-Stereo", "Dual-Channel" or "Single-Channel"
		///
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetMpegMode(long mv_instance, StringBuilder mode);

		/// <summary>
		/// It will retrieve the information about the sample format with description, but
		/// notice that internally it will be always converted to signed
		/// 16 bits two channels (for the moment...)
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="sample_format_string_k_p"></param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			GetSampleFormatInfo
			(
				long mv_instance,
				StringBuilder sample_format_string_k_p
			);
		
		/// <summary>
		///It will convert any media file to wav pcm
		///
		///input - any media file file
		///output - the output wav file
		///Notice that the function will only return after the end of the conversion
		/// 
		///error_msg - The error message as a string
		/// 
		///Return values
		///
		///01 - Invalid input file
		///02 - Invalid output
		///03 - Error during decode
		///04 - Error in the wav write function
		///
		/// possible values for wavmode
		///   #define  1 - 16 bits wav pcm
		///  #define  2 - 24 bits wav pcm
		///  #define  3 - 32 bits wav pcm
		///  #define  4 - 32 bits IEEE float wav (IEEE 754)
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			ConvertMP3ToWav(long mv_instance, string input, string output,
			                int wav_mode, StringBuilder error_msg,
			                int track);
		/// <summary>
		/// It will extract the media file to wav, and soon to mp3 or aac
		/// </summary>
		/// <param name="number"></param>
		/// <param name="input"></param>
		/// <param name="output"></param>
		/// <param name="wav_mode"></param>
		/// <param name="track">what is the track to encode to wav, only valid if the media file has multiples different tracks (need to be updated at least at 24/November/2020)</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			ConvertMP3ToWavExtended(long mv_instance, string input,
			                        string output, int wav_mode,
			                        int track);
		/// <summary>
		/// to be used to return progress information of the media to wav conversion function
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="percent">the progress percent</param>
		/// <param name="finished">1 if finished</param>
		/// <param name="returnvalue_">the return value for the conversion</param>
		/// <param name="message_____________oi___">the message if applicable</param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern
			void
			GetConversionInfo(long mv_instance, out int percent,
			                  out int finished, out int returnvalue_,
			                  StringBuilder message_____________oi___);

		/// <summary>
		/// This function will enable or disable the equalizer
		/// When enabled, it will use the values passed to the function EqualizerSettings
		///
		/// If the call to the function EqualizerSettings was not done yet, then it will define the values as the initial position of the equalizer, it will be 50 for each argument to the EqualizerSettings function
		/// The equalizer provide +-12 db of gain (correct me if I am wrong), ranging from value 0 to 100, 50 is the middle or no gain, when the DoubleBuffer is enabled the gain is enhanced a little more, but it can introduce a little noise or distortion
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="enable">1 to enable</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableEqualizer(long mv_instance, int enable);
		
		/// <summary>
		/// This function will change the settings of the equalizer
		///  The value to be passed to each argument range from 0 to 100, 50 is the middle or no gain in equalization
		///   Band60 = 60 hertz
		///   Band170 = 170 hertz
		///   Band310 = 310 hertz
		///   Band600 = 600 hertz
		///   Band1000 = 1 kilohertz
		///   Band3000 = 3 kilohertz
		///   Band6000 = 6 kilohertz
		///   Band12000 = 12 kilohertz
		///   Band14000 = 14 kilohertz
		///   Band16000 = 16 kilohertz
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="Band60"></param>
		/// <param name="Band170"></param>
		/// <param name="Band310"></param>
		/// <param name="Band600"></param>
		/// <param name="Band1000"></param>
		/// <param name="Band3000"></param>
		/// <param name="Band6000"></param>
		/// <param name="Band12000"></param>
		/// <param name="Band14000"></param>
		/// <param name="Band16000"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EqualizerSettings(long mv_instance, int Band60, int Band170, int
			                  Band310, int Band600, int Band1000, int
			                  Band3000, int Band6000, int Band12000, int
			                  Band14000, int Band16000);

		/// <summary>
		/// This function will enable or disable the preamplifier
		/// 
		/// To control the preamplifier call the function PreamplifierValue
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="enable">1 to enable</param>
		/// <returns>irrelevant...in the future we will convert it to void</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnablePreamplifier(long mv_instance, int enable);
		
		
		/// <summary>
		///  This function will set the preamplifier value to be used,
		///  a value of 50 means no preamplifier gain, a value of 0 mean
		///  no sound, a value of 100 means the double of the value of
		///  each sample playing, then if the value of the sample is 5000
		///  and this function receive a value 100 the sample will be
		///  modified to 10000, it can be used to increase the volume
		///  of mp3 files generated with very low volume
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PreamplifierValue(long mv_instance, int value);
		
		/// <summary>
		/// This function will change the internal volume of the file playing, it work in a similar mode as the SetVolumeGain function but it don't affect the other files playing, since it is internal to each control, then this is the preferred mode to change the volume of the playback now, it was introduced in the version 2.5.0 of the mp3 control, the SetVolumeGain function only need to be used when you really want to change the volume of the system mixer
		/// notice that you can pass 200 as the volume value, it will increase the internal stream playing to 200%, it is usefull if the recorded mp3 have low playback volume level, but if this is the case just use the Volume Normalization function EnableOnTheFlyVolumeNormalization
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			InternalVolume(long mv_instance, int value);
		
		/// <summary>
		/// This function will enable or disable the on the fly volume normalization
		/// 
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="mode">If mode is 0 then no normalization, if 1 the normalization will be based on the whole file, if 2 then only 30 seconds will be used to generate the normalization value, if 3 the new recommended method BENormalize will be used</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableOnTheFlyVolumeNormalization(long mv_instance, int mode);
		
		/// <summary>
		/// This function will make the equalizer to provide the double of the gain
		/// It was added because some users have reported that the response of the equalizer was not enough
		/// Now it provides more gain than Winamp or Media Player equalizer, indeed, it can even introduce a little noise or distortion when the gain is set to the maximum
		///
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="enable">1 to enable</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			DoubleBuffer(long mv_instance, int enable);
		
		/// <summary>
		/// It will return the paused state of the player
		/// 
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <returns>Return 1 if paused</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PauseState(long mv_instance);

		/// <summary>
		/// This function will inform whether volume normalization is being used
		/// </summary>
		/// <returns>0 - if no normalization is being used, 1 if normalization is being used</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			IsUsingNormalization(long mv_instance);

		/// <summary>
		/// This function will retrieve the normalization factor being used,
		/// this information has no useful value other than showing the
		/// multiplication factor in the media file, then  if it show 1.000,
		/// it means that each sample is
		/// being multiplied by 1.0 and sent to the soundcard, soon you will be able to see the value in Decibels too (after 2025)
		/// </summary>
		/// <param name="value">The string with the information returns here</param>
		/// <returns>Always 0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			NormalizationFactor(long mv_instance, StringBuilder value);

		/// <summary>
		/// The audio peak value for both channels
		/// </summary>
		/// <param name="number"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetPeak(long mv_instance);

		/// <summary>
		/// This function will read the id3 v1/1.1 tag
		/// </summary>
		/// <param name="filename">The mp3 file (not utf-8 encoded)</param>
		/// <param name="Track">The track</param>
		/// <param name="Title">The title</param>
		/// <param name="Artist">The artist</param>
		/// <param name="Album">The album</param>
		/// <param name="Year">The year</param>
		/// <param name="Genre">The genre</param>
		/// <param name="Comment">The comment</param>
		/// <returns>0 - no error
		/// 1 - cannot open file
		/// 2 - id3 tag not found
		/// 3 - invalid file
		/// </returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Read_ID3_v1_tag(long mv_instance, String filename, ref int Track,
			                StringBuilder Title, StringBuilder Artist,
			                StringBuilder Album, StringBuilder Year, ref int Genre,
			                StringBuilder Comment);

		/// <summary>
		/// It will return the genre names based on the number 'pos', it range from 0 to 148
		/// The genre list is the same genre list supported by Winamp, indeed the whole ID3 tag support on this control was based exactly in the same way it is support and implemented in Winamp
		/// </summary>
		/// <param name="pos">array position, from 0 to 148</param>
		/// <param name="data">Where the string returns</param>
		/// <returns>Always 0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Generate_ID3v1Genre(long mv_instance, int pos, StringBuilder data);

		/// <summary>
		/// This fuction will write the id3 v1 tag on the file
		/// </summary>
		/// <param name="filename">The MP3 file (not utf-8 encoded)</param>
		/// <param name="Track">Track</param>
		/// <param name="Title">Title</param>
		/// <param name="Artist">Artist</param>
		/// <param name="Album">Album</param>
		/// <param name="Year">Year</param>
		/// <param name="Genre">Genre</param>
		/// <param name="Comment">Comment</param>
		/// <returns>0 - no error
		/// 1 - cannot open mp3 file
		/// 2 - file is too small
		/// 3 - invalid file
		/// 4 - file is read only
		/// </returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Write_ID3_v1_tag(long mv_instance, string filename, int Track,
			                 string Title, string Artist, string Album, string Year,
			                 int Genre, string Comment);

		/// <summary>
		/// This function will remove the ID3 tag, if it is available on the file, of course
		/// </summary>
		/// <param name="filename">The mp3 file as a utf-8 encoded string</param>
		/// <returns>0 - no error
		/// 1 - unable to remove id3 tag
		/// 3 - read only file </returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Remove_ID3V1_tag(long mv_instance, string filename);

		/// <summary>
		/// This function will read the id3 v2 tag (support only for 2.3 version and not 2.4 version like the support available in the Libav for October/2020)
		/// </summary>
		/// <param name="filename">The mp3 file (not utf-8 encoded)</param>
		/// <param name="Track">Track</param>
		/// <param name="Title">Title</param>
		/// <param name="Artist">Artist</param>
		/// <param name="Album">Album</param>
		/// <param name="Year">Year</param>
		/// <param name="Genre">Genre</param>
		/// <param name="Comment">Comment</param>
		/// <param name="EncodedBy">Encoded by</param>
		/// <param name="URL">URL</param>
		/// <param name="Copyright">Copyright</param>
		/// <param name="OriginalArtist">Original Artist</param>
		/// <param name="Composer">Composer</param>
		/// <returns>0 - no error
		/// 1 - no v2 tag on the file
		/// 2 - cannot load data from file
		/// </returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Read_ID3_v2_tag(long mv_instance, String utf8_filename,
			                StringBuilder Track, StringBuilder Title,
			                StringBuilder Artist,
			                StringBuilder Album, StringBuilder Year,
			                StringBuilder Genre, StringBuilder Comment,
			                StringBuilder EncodedBy, StringBuilder URL,
			                StringBuilder Copyright,
			                StringBuilder OriginalArtist,
			                StringBuilder Composer);


		

		/// <summary>
		/// This fuction will write the id3 v2 tag on the file (support only to version 2.3 for the moment)
		/// </summary>
		/// <param name="utf8_filename">The mp3 file, (not utf-8 encoded)</param>
		/// <returns>0 - no error
		/// 1 - read only
		/// 2 - unable to create temp file
		/// 3 - cannot load data from file
		/// 4 - cannot open temp file to write (mode 1)
		/// 5 - cannot open input file to read
		/// 6 - cannot open temp file to write (mode 2)
		/// 7 - cannot replace original file
		/// 8 - ? ( I supose tampered id3v2 that may crash due to too large memory requirements )</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Write_ID3_v2_tag
			(
				long mv_instance, string utf8_filename, string Track,
				string Title, string Artist, string Album,
				string Year, string Genre, string Comment,
				string EncodedBy, string URL, string Copyright,
				string OriginalArtist, string Composer
			)
			;

		/// <summary>
		/// It will remove the ID3 v2 tag from the file (only support for version 2.3), after the removal it will adjust the size of the file
		/// </summary>
		/// <param name="filename">The mp3 file</param>
		/// <returns>0 - no error
		/// 1 - read only
		/// 2 - unable to create temp file
		/// 3 - cannot open input file to read
		/// 4 - cannot open temp file to write
		/// 5 - cannot replace original file </returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Remove_ID3V2_tag(long mv_instance, string filename);

		/// <summary>
		/// It will retrieve the spectrum analizer information
		/// </summary>
		/// <param name="f60">60 hertz</param>
		/// <param name="f170">170 hertz</param>
		/// <param name="f310">310 hertz</param>
		/// <param name="f600">600 hertz</param>
		/// <param name="f1000">1000 hertz</param>
		/// <param name="f3000">3000 hertz</param>
		/// <param name="f6000">6000 hertz</param>
		/// <param name="f12000">12 kilohertz</param>
		/// <param name="f14000">14 kilohertz</param>
		/// <param name="f16000">16 kilohertz</param>
		/// <param name="fpeak">Peak value</param>
		/// <returns>Always 0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetSpectrumAnalyzer(long mv_instance, ref int f60, ref int f170, ref int f310, ref int f600
			                    , ref int f1000, ref int f3000, ref int f6000, ref int f12000, ref int f14000, ref int f16000, ref int fpeak);

		/// <summary>
		/// To check whether the path information is a file
		/// </summary>
		/// <param name="filename">The file (not utf-8 encoded for the moment), I recomend you to use the System.IO methods</param>
		/// <returns>0 if path is invalid or folder, 1 if it is a file</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			IsPathFile(long mv_instance, string filename);

		/// <summary>
		/// To check whether the path information is a folder
		/// </summary>
		/// <param name="filename">The file (not utf-8 encoded for the moment), I recomend you to use the System.IO methods</param>
		/// <returns>0 if path is invalid or file, 1 if it is a folder</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			IsPathFolder(long mv_instance, string filename);

		/// <summary>
		/// Only for internal use...
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="debug"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			DebugInformation(long mv_instance, StringBuilder debug);

		/// <summary>
		///It will enable or disable the voice removal wave effect
		/// 
		///It is disabled by default
		///The voice removal code will try to remove information from the
		///samples based on what is the same in both channels
		///Then if the same information is available in both channels
		///it will be just removed, and the remaining information
		///is only the information that are different in both channels
		///Since the voice is equal in both channels  in any normal stereo file
		///it will just disappear after passing this filter
		///Notice that a mono file will just become pure silence
		///since both channels will be canceled
		///The capacity of this code to work will depend on the
		///file, then it is not a 100 percent working solution
		///Several new wave effects will be added to future releases (after 2025)
		/// </summary>
		/// <param name="enable">0 will disable</param>
		/// <returns>nothing but 0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableVoiceRemoval(long mv_instance, int enable);

		/// <summary>
		/// The EnableEcho function will enable or disable the echo
		/// 
		///The argument Delay range from 0 to 100 , 0 means 1
		///second of delay of the echo, 100 means no delay at
		///all, then it means no echo
		///It initiate at 50
		///This echo effect will copy portions of the file already
		///played in a buffer that later is added again to the next chunk
		///to play, giving an echo effect
		///It can be used also to generate a reverberation effect, just
		///adjust the value of the Delay argument
		///The Enable argument will define whether the echo effect is
		///enabled or not
		///Several new wave effects will be added to future releases
		/// </summary>
		/// <param name="enable">it will enable with a 1 or disable with a 0</param>
		/// <param name="delay">the delay value</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableEcho(long mv_instance, int enable, int delay);

		/// <summary>
		/// Superseded by EnableSoundTouch, the PitchControl will change the playback speed
		///of the player
		///It means that the playback will be faster or slower
		///It range from 0 to 100, and initiate at 50
		///50 means no speed change
		///More close to 0 and it slow down the playback
		///More close to 100 and it become faster
		///The Control argument is where the speed is defined
		///The Enable argument will enable or disable this
		///effect
		///Several new wave effects will be added to future releases
		/// </summary>
		/// <param name="enable">0 to no, 1 to yes</param>
		/// <param name="control">the value to pass</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			PitchControl(long mv_instance, int enable, int control);

		/// <summary>
		/// This function will enable or disable a surround like wave effect in the playback, requires a soundcard and fones de ouvido
		/// </summary>
		/// <param name="enable">0 to no or 1</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableSurround(long mv_instance, int enable);

		/// <summary>
		/// This function will enable or disable a surround like wave effect in the playback, this effect is very interesting, take a look in the source, the argument range from 0 to 100, requires a soundcard and fones de ouvido
		/// </summary>
		/// <param name="enable">0 to no or 1</param>
		/// <param name="range">the range</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			BE_Special_Wav_Effect(long mv_instance, int enable, int range);

		/// <summary>
		/// (Without use after the Libav as the decoder) It will enable or disable the playback of encrypted files, the password will define the password to be used, in order to play the file it need to be encrypted with the function Encrypt_File
		/// </summary>
		/// <param name="mv_instance">the instance</param>
		/// <param name="enable">0 to no or 1</param>
		/// <param name="pass">the password</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			UseEncryption(long mv_instance, int enable, string pass);

		/// <summary>
		/// (Without use after the Libav as the decoder) It will encrypt the file in order to be played by the control , to play it you need to use the function UseEncryption
		/// In order to unencrypt the file just encrypt it again with the same password, it is RC4, yes it is weak but works, AES CTR will be used later
		/// </summary>
		/// <param name="input">input file</param>
		/// <param name="output">output file</param>
		/// <param name="pass">password</param>
		/// <returns>0 ? bug here, will be fixed in the next release</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Encrypt_File(long mv_instance, string input, string output, string pass);

		/// <summary>
		/// It will enable or disable the Freeverb, Freeverb is a very good reverberation, ffdshow has it also and also settings to modify it.
		/// </summary>
		/// <param name="enable">0 to no or 1</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableFreeverb(long mv_instance, int enable);

		/// <summary>
		/// It will enable SoundTouch by http://www.surina.net/soundtouch, then you can change the tempo, pitch and rate, the quality of this code is amazing only testing you will see the very good precision, the original developer of SoundTouch know what he is doing
		/// </summary>
		/// <param name="enable">0 to no or 1</param>
		/// <param name="tempo">range from -95 to +95</param>
		/// <param name="pitch">range from -60 to +60</param>
		/// <param name="rate">range from -95 to +95</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			EnableSoundTouch(long mv_instance, int enable, int tempo, int pitch, int rate);

		/// <summary>
		/// It will retrieve information from an impxmlv2 ini file that is in the same path of the mp3 dll
		/// </summary>
		/// <param name="key">the key</param>
		/// <param name="data">the data</param>
		/// <param name="defaulT">default value, must be from my point of view ""</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetSettings(string key, StringBuilder data, string defaulT);

		/// <summary>
		/// It will save information in an impxmlv2 ini file that is in the same path of the mp3 dll
		/// </summary>
		/// <param name="key">the key</param>
		/// <param name="data">the data</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			SaveSettings(string key, string data);

		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			Amanda_s_Smart_Ape_Use_Cache(long mv_instance,
			                                  int enable_amanda_s_smart_ape_enable);
		
		/// <summary>
		/// to show um aboutbox of the dll, very simple
		/// </summary>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			About();

		/// <summary>
		/// To return the information and version number of the dll
		/// </summary>
		/// <param name="data">the data</param>
		/// <returns>0xbadc0da :-)</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			ControlName(StringBuilder data);

		/// <summary>
		/// It will retrieve the number of wave out devices ( soundcards ) you have installed in the system
		/// Notice that a value of 0 means that you don't have an installed soundcard, so, you cannot play using this control, but you can extract to wav
		/// </summary>
		/// <returns>the number of wave out devices</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetNumberofWaveOutDevices(long mv_instance);

		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			DetectChangeInSoundCards_i(long mv_instance);
		
		/// <summary>
		/// When the computer is old the time required to decompress
		/// and draw the video can be more than the processing time
		/// available, without this the audio and video will just lose sync and
		/// the audio will finish before the playback of all the video frames.
		/// Using this option will adjust the audio and video sync as soon the
		/// sync is lost, but it is not perfect, frames will be dropped a lot,
		/// it is optional because some users may want to see all the frames
		/// without drop, make your tests...
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="enable_slow_computers_hack">1 to enable</param>
		[DllImport("rspmp3ocx1.dll")]
		public static extern void
			SlowComputersCommand_k_p
			(
				long mv_instance,
				int enable_slow_computers_hack
			);
		
		/// <summary>
		/// It will retrieve the number of channels in the media file.
		/// It is required because internally any number of channels
		/// above two are converted to two at this moment, this
		/// is just informative, maybe in the future the DLL will be able
		/// to access and use the additional channels and play it using
		/// WaveOutWrite api (we already have sample code to do it,
		/// soon it will be available)
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetOriginalNumberofChannels
			(
				long mv_instance
			);
		
		/// <summary>
		/// It will receive a string with the description of the error passed, possible error values are available in the file mp3class.cs in the line 1300, file mp3class.cs is vailable on folder .\win32\mp3dll\mp3dll </summary>
		/// <param name="value">the error</param>
		/// <param name="data">the string</param>
		/// <returns>0</returns>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			GetErrorString(long mv_instance, int value, StringBuilder data);
		
		/// <summary>
		/// It will retrieve the remaining time of the playback
		/// , it can be useful
		/// </summary>
		[DllImport("rspmp3ocx1.dll")]
		public static extern int
			Alladin_GetRemainingTime(long mv_instance, StringBuilder data);
		[DllImport("rspmp3ocx1.dll")]
		extern static IntPtr utf8towide(string utf8_filename);
		public static string utf82wide(string utf8_filename)
		{
			IntPtr retVal = utf8towide(utf8_filename);

			var val = Marshal.PtrToStringUni(retVal);
			return val;
		}
		[DllImport("rspmp3ocx1.dll", CharSet = CharSet.Unicode)]
		extern static IntPtr widetoutf8(string unicode_filename);
		
		/// <summary>
		/// It will convert an Unicode string to the Unicode representation of a utf-8 encoded string
		/// </summary>
		/// <param name="unicode_filename"></param>
		/// <returns></returns>
		public static string wide2utf8(string unicode_filename)
		{
			IntPtr retVal = widetoutf8(unicode_filename);

			string val = Marshal.PtrToStringAnsi(retVal);
			return val;
		}
		/// <summary>
		/// Retrieve the number of audio tracks
		/// </summary>
		/// <param name="number"></param>
		/// <param name="utf8_filename"></param>
		/// <param name="error_message"></param>
		/// <returns>negative in case of error, see the message for explanation of the error</returns>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			int
			GetNumberOfAudioTracks(long mv_instance, string utf8_filename,
			                       StringBuilder error_message);
		
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			int
			GetNumberOfSubtitles(long mv_instance, string utf8_filename,
			                       StringBuilder error_message);

		/// <summary>
		/// it will create a decoder, this is the first function that need to be called
		/// </summary>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			long BE_CreateDecoder();

		/// <summary>
		/// this is the last function that need to be called, it will free all the memory allocated and close the decoder
		/// </summary>
		/// <param name="instance_64"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void BE_CloseDecoder(ref long instance_64);

		/// <summary>
		/// It will pass the window handles required and the arguments for the video playback, the hwnd of the window need to be from a picturebox
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="hwnd">the first window that will be the background of the player</param>
		/// <param name="player_hwnd">the player window, will be adjusted based on the size of the media file</param>
		/// <param name="width">the width of the background window</param>
		/// <param name="heigth">the heigth</param>
		/// <param name="ratio">the ratio to be used</param>
		/// <param name="left">the X position of the window</param>
		/// <param name="top">the Y position of the window</param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void PassWindowInformation
			(
				long mv_instance,
				long hwnd,
				long player_hwnd,
				int width,
				int heigth,
				morcego_ratio ratio,
				int left,
				int top
			)
			;
		
		/// <summary>
		/// Function to enable or disable the playback in Desktop
		/// </summary>
		/// <param name="mv_instance">the DLL instance (the whole internal struct address)</param>
		/// <param name="enable">to enable or disable</param>
		/// <param name="system_screen_w">the system screen width</param>
		/// <param name="system_screen_h">the system screen height</param>
		/// <param name="desired_w">the width of the video to play</param>
		/// <param name="desired_h">the height of the video to play</param>
		/// <param name="position_i">the values to position the screen on the desktop window</param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			int
			PlayInDesktop(long mv_instance, int enable, int system_screen_w, int system_screen_h, int desired_w, int desired_h, amanda_position position_i);
		/// <summary>
		/// returns a string with the description of the media file about the video if applicable
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="data"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void GetVideoInfo
			(
				long mv_instance,
				StringBuilder data
			);

		/// <summary>
		/// To don't decode and play the video, only the audio
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="enable"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void DisableVideo
			(
				long mv_instance,
				int enable
			);
		/// <summary>
		/// To stop drawing the video
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="do_not_draw"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void Don_t_Draw_Video
			(
				long mv_instance,
				int do_not_draw
			);
		/// <summary>
		/// To return the width and height of the media file that was loaded, need to be called only after the Play or Open funcation are called
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="w"></param>
		/// <param name="h"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void GetWindowSize
			(
				long mv_instance,
				out int w,
				out int h
			)
			;
		/// <summary>
		/// It will return a string with the pixel format of the video file (need to be updated...), also it will return the audio and video sinchronization values
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="format"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void GetPixelFormat____
			(
				long mv_instance,
				StringBuilder format
			)
			;
		
		/// <summary>
		/// It can be used to modify the ratio, take a look in the sample project
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="adjust"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void AdjustRatio
			(
				long mv_instance,
				double adjust
			)
			;
		/// <summary>
		/// To know whether the file is a Windows Media Player playlist (.wpl)
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="filename_utf8"></param>
		/// <returns>0 if not</returns>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			int  Is_WPL_Playlist
			(
				long mv_instance,
				string filename_utf8
			)
			;

		
		/// <summary>
		/// to retrieve the files that are expressed in the .wpl file
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="filename">the filename returned</param>
		/// <returns>1 if have more</returns>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			int  GetPlaylistFiles(long mv_instance,
			                      StringBuilder filename);

		/// <summary>
		/// Without it the width of the window never will be larger than the width of the player window, then after calling this function it can be larger, this is usefull for the fullscreen options, take a look in the sample project
		/// </summary>
		/// <param name="mv_instance"></param>
		[DllImport("rspmp3ocx1.dll")]
		public extern static
			void DisableWidthLimit(long mv_instance);

		public static int wave_mode = 1;
		public static long number = MP3.BE_CreateDecoder();
		
		public static double full_screen_player_position;
		public static morcego_ratio f_ratio;
		public static string filename;
		public static bool is_full_screen = false;

		public static bool disabled = false;
		public static bool loading_file = false;
		public static double adjusted_ratio=0;
		public static bool is_playlist = false;
		public static int playlist_index = 0;
		public static string the_filename = "";
		public static bool is_shuffle = false;

		/// <summary>
		/// to retrieve a randomic number that range from min to max inclusive
		/// </summary>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int get_rand(int min, int max);
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern void add_more_one_z();
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int  init_playlist_z();
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int set_played_item_z(long item_z);
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int get_next_item_z(
			ref long item_got_z, ref long item_number_z);
		
		/// <summary>
		/// It will retrieve the filename from the path
		/// </summary>
		/// <param name="filename">The mp3 file (not utf-8 encoded)</param>
		/// <param name="path">The path</param>
		[DllImport("rspmp3ocx1.DLL")]
		public static extern void get_filename
			(
				string path,
				StringBuilder filename
			)
			;

		/// <summary>
		/// To change the position of the playback of audio and video,
		/// default to 0 for total sync between audio and video, 500
		/// to a half second difference of sync
		/// </summary>
		/// <param name="mv_instance"></param>
		/// <param name="value"></param>
		[DllImport("rspmp3ocx1.DLL")]
		public static extern
			void
			AdjustSync(long mv_instance, double value);

		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int
			init_jun_playlist_z(string jun_playlist_z);
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern int
			add_to_jun_playlist_z(string jun_playlist_z);
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern void
			add_item_to_playlist_z(string entry_z);
		
		[DllImport("rspmp3ocx1.DLL")]
		public static extern void
			close_playlist_z();
		
		/// <summary>
		///          * 
		///  If sync is lost this function will return 1
		///  Sync can be lost on slow machines or when soundtouch
		///  changes the playback speed to more than the normal
		/// </summary>
		/// <param name="mv_instance">the instance</param>
		[DllImport("rspmp3ocx1.DLL")]
		public static extern
			int
			GetSyncStatus(long mv_instance);

		internal static void clean_up_memory_p()
		{
			return; //disable because of an unexpected bug on
			/*
			GC.Collect();
			GC.WaitForPendingFinalizers();
			if (Environment.OSVersion.Platform == PlatformID.Win32NT)
			{
				SetProcessWorkingSetSize(System.Diagnostics.Process.
				                         GetCurrentProcess().Handle, -1, -1);
			}
			*/
		}
	}
}