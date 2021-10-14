/********************************************************************************
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
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/
  
  The codenames in the changelog are very important GNU contributors...
  
First of all: thanks to the developers of:

Libav(ffmpeg)
SDL
Rabbit MP3 DLL
Dialog Medien MP3 OCX
Maplay 1.2, sorry Jeff...
Netshow 2.0

(NetShow was Microsoft's original framework for Internet network
broadcasting, intended to compete with RealNetworks RealMedia &
Vivo (acquired in 1998 by RealNetworks). It was later renamed
and marketed under the Windows Media umbrella.)

https://stackoverflow.com/
http://equ.sourceforge.net/

Second: in 01/01/2020 the license of our portions of the code have changed from GPL3
to LGPL, read the file:

https://www.gnu.org/licenses/gpl-3.0.txt

and:

https://www.gnu.org/licenses/lgpl-3.0.txt

for more information, then it can be used in open source projects or commercial
applications, ok?

Now back to the technical information...

			~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			
			mv_______->decoder_c___debug_flag=0;
			// if 1 it will simulate a delay in the audio, if 2 in the video
			
			test also to see if the return from hibernation and suspend state is
			working as expected, my tests passed, but we will test again in Win10
			
			~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~			

RSP MP3 OCX 1.0.2 project, sourceforge project rsppmp3
site   : https://sourceforge.net/projects/rsppmp3

GitHub : https://github.com/maria901/rsppmp3_v27

Win32(soon)/64 Dll to play all audio and video that are supported by the library Libav

If you need 32 bits version just now you need to use the release 5.2.3

Libav is provided as GPL and LGPL, soon our binary packages will have both methods, for the moment
it is only GPL

rspmp3ocx1.dll and interface2.dll compiled with gcc 11.1.0, SDL2 (mod) compiled
also with the same version.

The files are available in the following folders:
/bin              <- the compiled binaries, empty after 13.5.5
/c#_sample        <- the C# sample project ready to be compiled with SharpDevelop 5.1.0
/interface2       <- sources of the interface2.DLL, that is the interface for Libav
/morcego          <- sources for the morcego_interface.o obj file, some small functions
/mp3_dll          <- sources for the rspmp3ocx1.DLL, decoder.c and player.c are the main files
/sdl_2.0          <- the sources for our modified SDL 2.0 library, ready to be compiled again if needed
/sqlite           <- sources for the Amanda_27.DLL, it is just a wrapper for SQLite, recommended the latest SQLite library
/touch            <- sources for the C++ library SoundTouch that allows the change in playback speed in many modes

Documentation of the version 15.6.4 available online at:
https://arsoftware.net.br/binarywork/Amanda_Ava_Pereira/rsppmp3_doc_8.9.9/html/decoder_8c.html
                http://nomade.sf.net/Amanda_Ava_Pereira/rsppmp3_doc_8.9.9/html/decoder_8c.html
				
It says 8.9.9 but is the latest available

The documentation will be updated soon...				

Description

- Ability to play media files in the following formats:
All media formats supported by ffmpeg (new webm files (2021), flv avi mov rm ra including the new amazingly fast and
advanced rsp format (.ricardo4) (:-)) and many many more)
- It has a high quality (we supose) graphical equalizer (copied (as usual) from the XMMS project), as
far as we know it is optimized for 44100 (soon 48000) sample rate, we will be using the Shibatch version later,
because some people say that it is a real high quality version)
- It has a spectrum analyzer (now working) with 10 bands (but limited to 44100 sample rate)
- The decoder engine is loaded dynamically in the process(sic...)
- You can define what wave out device ( soundcard ) will play the MP3 file (in case you have twenty soundcards installed, 
but for BlueTooth phones it is handy, the sample project waits for your selection to return the playback if the Phone
is close (it was modified to work like Edge))
- Not support to next file playback in a playlist for EarPhones command, but
soon it will (code will be borrowed from Edge)
- The control has support to Xing and VBRI based VBR files (by Libav)
- The control can retrieve bitrate, samplerate, layer, stereo 
mode and the time of the media file as formatted string or milliseconds 
- Several wave effects, the Amanda wav effect can make a mono file play as stereo, give it a try
- ReplayGain and the new and recommended BENormalize normalization method
- Ability to extract to wav pcm in 16, 24 and 32 bits and FLOAT (soon to all formats too)
- Future versions will be able to play backwards. (in a few years from now)
- Future versions will have more features (at least this is what everyone is expecting we supose)

			~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Limitations:

All problems related to Libav are related also to this dll

If you want to see a Libav problem that can crash our DLL just try to play a flv file with an id3 v2 tag, soon we will
fix it or create a workaround (how Ricardo?)

Partial subtitles support for the moment (we need free time to add this, then wait)

Can select any audio track for playback (sic..., don't believe on it) but only the first video
track for the moment, it will be extended soon

            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Libav version information:

BEGIN:
{

  libavutil      57.  0.100 / 57.  0.100
  libavcodec     59.  3.100 / 59.  3.100
  libavformat    59.  3.101 / 59.  3.101
  libavdevice    59.  0.100 / 59.  0.100
  libavfilter     8.  0.103 /  8.  0.103
  libswscale      6.  0.100 /  6.  0.100
  libswresample   4.  0.100 /  4.  0.100
  libpostproc    56.  0.100 / 56.  0.100

  ffmpeg version N-102810-gda0abbbb01-20210702
  Copyright (c) 2000-2021 the FFmpeg developers

}
END:

You can replace the Libav dlls with different and updated versions, indeed it is
recommended
In a near future the Libav will be incorporated inside the rspmp3ocx1.dll(not sure,
but the sources are there for a long time now, just need to be compiled...) to
avoid too many dlls in the same path of the dll and avoid conflicts
with different copies of the Libav dlls in the same process running
(it is rare to occur but is possible)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Changelog: 

What is new in 16.0.9  build 667271  'Thu 14/October/2021 06:19:45' codename 'Daly'
Small modifications and added a new function to show the video bitrate,
if available of course, notice that some webm files don't report a video bitrate
but includes all in the audio bitrate, also a bug occurs sometimes when the 
media files are assiciated with the mp3dll.exe application, it is hard to occur 
and we will fix it when we figure out how to reproduce the problem, next release 
will use the new Libav libraries available 

What is new in 15.5.8  build 667220  'Terça(Tuesday) 10 Agosto 2021  12:06' codename 'Haible'
First release with full support to subtitles as SUBTITLE_BITMAP, missing
for the moment SUBTITLE_TEXT and SUBTITLE_ASS, will be added soon, minor
modifications.

What is new in 14.1.8  build 667080  'Terça(Tuesday)  03 Agosto 2021  10:51' codename 'Brabec'
First version capable of playing video in the Desktop window, minor modifications.

What is new in 13.6.5  build 667027  'Segunda(Monday) 02 Agosto 2021  15:39' codename 'Clark'
Now the DLL can detect and adjust the playback to a new Phone or new SoundCard
available on the system on the fly, before when a new Phone was detected by
Windows 10 the playback was paused, now it keep playing with the new attached
device, minor modifications.

What is new in 13.5.5  build 667017  'Sabado(Saturday) 31 Julho 2021  08:08' codename 'Kovalenko'
Updated and  uploaded the  latest rsppmp3 release, the sample was  enhanced and
some small  bugs got fixed, minor modifications.

What is new in 13.4.2  build 667004  'Sexta(Friday) 23 Julho 2021  09:03'  codename 'Krüger'
Fixed a weird bug in the new cache system, minor modifications.

What is new in 13.2.8  build 666990  Quarta 21 Julho 2021  11:42           codename 'Beebe'
The old packages may have up to 100 milliseconds of delay between
audio and video syc, new versions have less difference, anyway
you can calibrate it a little more yourself modifying the line 2082
of the libav_video.c file of the release 13.2.8 and above,
minor modifications.

What is new in 13.2.6  build 666988  Tue 20/July/2021 21:59:41    codename 'Huang'
Fixed two bugs related to  each other that can generate error in sync and
wrong duration information, the update is a must, also the .DB file
(the cache) need to be deleted because the bugs can save erroneus
information that need to be updated, minor modifications.

What is new in 13.1.1  build 666973  Tue 20/July/2021 14:43:57  codename 'Page and Mentré'
First release with full support to cache when loading normalization code
and new webm files that need to compute the duration from the audio wav extraction,
notice that the reported bug that was done yesterday at 00:00 was not fixed yet,
it only occurs with fast machines and will be fixed today, minor modifications.

What is new in 12.3.2  build 666894  Thu 15/July/2021 08:10:15  codename 'Dréo'
Rearranged the sources to small names and now the precompiled
binaries goes in another package name (bin), the first step for
cache usage is ready but not complete, support for egenration of
duration of new webm files is already working, minor modifications.

What is new in 11.5.4  build 666816   Thu 08/July/2021 06:08:35  codename Chéreau
Incomplete version, for debug purposes only, new version will be
available soon, tomorrow is my son's birthday, the name is Ricardo

What is new in 10.2.2  build 66684 Wed 16/June/2021 14:26:55  codename Rino
Adjusted the wav effect that was causing distortion when enabled
to work with all samplerates without problem, minor modifications.

What is new in 10.1.6  build 66678 Sat 29/May/2021 23:11:09   codename Hu
Fixed a bug that was causing distortion in the playback of files with
sample rate below 16000, it was caused by our own wav effect that is enabled
with the function BE_Special_Wav_Effect, now if the sample rate is below
16000 the effect will just be disabled during the playback, when we got
more time we will try to allow the use of this effect with these sample
rates, (sorry for the time missing at this moment), minor modifications.

What is new in 10.0.9  build 66671 Fri 28/May/2021 13:45:40   codename Weidendorfer
Fixed a abs call bug referred to the maximum negative value problem, older
versions could crash with an array bounds error due to this problem, minor
modifications.

What is new in 10.0.8  build 66670 Thu 27/May/2021 03:08:10   codename Breuer
Fixed weird bug when returning from floating window where a video window black
is positioned in the wrong position covering part of the form controls, now
the cursor don`t disappear in floating window mode, minor modifications.

What is new in 10.0.3  build 66665 Sat 08/May/2021 06:40:10   codename Shen
First release with a supported floating video window, minor
modifications.

What is new in 10.0.1  build 6664  Sat 01/May/2021 22:24:00   codename Joyez
Updated the Libav library to the latest version

What is new in 9.9.3  build 6656   Sat 01/May/2021 00:18:57   codename Lesourd
Removed the code that adjusted the memory usage report of the
application running the DLL, in the function 'clean_up_memory_p',
maybe this is the reason for the fullscreen playback crash of
two days ago, we will keep testing it

What is new in 9.9.1  build 6654   Tue 27/April/2021 19:41:24 codename Allouche
Fixed a bug in the fullscreen code that was occurring only
in some cases, in this case the taskbar was appearing during
the playback, now it is always hidden, minor modifications

What is new in 9.8.3  build 6646   Thu 08/April/2021 12:23:34 codename Raux
Replaced the old ini file with a xml file (.mis), enhanced the
appearence of the progress bar (slider), minor modifications

What is new in 9.7.4  build 6637 b Wed 07/April/2021 17:24:02 codename Lecerf
Fixed a weird bug on returning from fullscreen, minor
modifications

What is new in 9.7.4  build 6637 Sat 03/April/2021 08:26:25
Fixed a weird memory leak that can make the memory usage go
to more than 2 GB when used to play a large playlist, the
problem occurred because the informations about the intrinsics
of some Libav usage is difficult to find, and some informations
are not just incomplete but wrong, fixed in this version, minor
sample modifications.

What is new in 8.9.7  build 6560 Sat 27/March/2021 19:32:35
Fixed a few memory leaks in the Libav interface to decode
audio, added memory usage code to quickly see whether a memory
leak is occurring.

What is new in 8.9.6  build 6559 Fri 19/March/2021 14:15:10
Fixed small bugs, minor modifications.

What is new in 8.7.2  build 6535 Sat 06/March/2021 02:46:24
Updated the Libav library to the version compiled at 05-March-2021,
minor modifications.

What is new in 8.7.2  build 6535  date - Wed 10/February/2021 23:43:37
Fixed a weird bug that was causing the last 3 frames to appear again
after the end of the playback, minor modifications.

What is new in 8.7.1  build 6534  date - Wed 10/February/2021 23:43:37
Recompiled the libav interface DLL to use the latest ffmpeg files version,
minor modifications.

What is new in 8.7.0  build 6533  date - Sun 10/January/2021 08:01:10
Recompiled the libav interface DLL to use the latest ffmpeg files version,
minor modifications.

What is new in 8.6.9  build 6532  date - Sun 10/January/2021 08:01:10
Fixed a bug that was not closing the media file, then all files loaded
was always in the memory and cannot be renamed or deleted, fixed now,
updated the Libav library to the latest version available, added a new function
to fix a bug that was causing a crash at the Playback button on
fullscreen, now it will wait for a valid value for the wavout before
calling 'PlaybackResume', minor modifications.

What is new in 8.6.3  build 6526  date - Fri 04/December/2020 17:40:45
As Microsoft stated a Direct3D device can be in either an operational
state or a lost state. The operational state is the normal state of
the device in which the device runs and presents all rendering as
expected. The device makes a transition to the lost state when an
event, such as the loss of keyboard focus in a full-screen application,
causes rendering to become impossible. The lost state is characterized
by the silent failure of all rendering operations, which means that the
rendering methods can return success codes even though the rendering
operations fail. In this situation, the error code D3DERR_DEVICELOST
is returned by IDirect3DDevice9::Present.
This problem was affecting our version of the DLL that was using SDL
version 2.0.12, we already did some modifications to the SDL code to
fix a problems that was affecting SDL_CreateWindowFrom and now we have added
the function get_device_lost_state_k() to SDL to make it possible to
know after a call to SDL_RenderPresent whether the Direct3D device was
in lost state, if this is the case the code will try to acquire the
operational state again and again, without it the code will only
show the updated window if the user restart the player, the d3d11
mode was not tested because I don't have a machine with windows 10
at this moment but support to it will also be added in the future,
we have yet a lot of improvements to add to this DLL and speed of playback
is one of the concerns, minor bugs fixed.

What is new in 8.6.2  build 6525  date - Thu 03/December/2020 17:00:44
Added a workaround to avoid the equalizer silence bug, just to clarify
that the silence bug happens in all x86 processors using the standard
i387 FP (including SSE) code (because of the way underflow exceptions
are handled), to solve the problem we have added a call to:
_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON); before calls to code that
can cause a Flush-to-zero floating point problem, without it if your
media file have a few seconds of silence the processor usage will go to 100%, this
problem affects all prior versions that have the equalizer as far as I remeber
it was part of the DLL since 2002 but I only become aware of this problem in the
past week, if the Flush-to-zero workaround may cause problems to your
code make a call to _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_OFF); at the end of the playback
to return to the standard floating point mode, fixed a memory leak
in the video decoder thread (missing call to av_packet_unref to unused
packets and missing calls to the packets allocated in the video player
thread) sample project updated a lot, modified the sources to allow the
compilation with gcc 10.2.0 (I know that this is weird but is true, if 
you want to see the problem try to compile with 10.2.0 any prior version), 
not fixed yet a bug that occurs during the first execution 
of ctrl+alt+del, as soon you do it the player window will
freeze until you restart the player, notice that a second
ctrl+alt+del will not generate the problem until you reboot, it is
hard to track down the bug because it needs a reboot to reproduce the problem again
but I promise that the SDL2 code will be fixed very soon, fixed a bug in the
voice removal code, it was clipping, minor modifications and due to multi-thread
support of Libav now enabled (disabled in the past because it is the default) increased the decoding
speed a lot, and now also  we are using SWS_FAST_BILINEAR for fast video
resize and convert code, in the past we was using SWS_BICUBIC, notice
that yet our DLL cannot play as fast as Media Player Classic Home Cinema 1.7.13
or Windows Media Player but we are working on it..., also for the moment
the equalizer is optimized for 44100 sample rate, future versions will have also
48000 and 32000 full support, have a great day.

What is new in 7.7.7  build 6440  date - Sun 29/November/2020 15:50:57
Replaced the SDL library 1.2.14 with SDL 2-2.0.12 with some customizations
to fit our needs, like the old version, if you replace our modified
SDL with the standard SDL2.dll you will see that the sample application
just crash, examine the sources to see where is the problem, if you are
curious, despite this new version the performance is almost the same
as 1.2.14, at least in my 1ghz windows 7 machine, maybe in windows
10 the performance is better, anyway you will see that the bottleneck
is in the Libav function calls to decode and convert the video data,
we are yet researching on it to enhance the playback speed, minor
modifications.

What is new in 7.6.8  build 6431  date - Fri 20/November/2020 21:13:32
Fixed a bug that was causing the finished event to don't be raised,
and this was causing the playback of wpl playlists to just stop as soon a
mp3 file with a video frame on it was found, also the loop was not
working, minor modifications

What is new in 7.6.2  build 6425  date - Sun 25/October/2020 10:28:01
Replaced the 5.1 and 7.1 channels downmix code that we are using in
the release 7.6.1 with a code that comes from Android sources that
some developers agree that is a better solution, minor
modifications.

What is new in 7.6.1  build 6424  date - Sat 17/October/2020 07:22:55
Added full 5.1 and 7.1 channels support in systems that have only stereo
output, notice that for the moment in a real 5.1 and 7.1 system all the
channels will be mixed and sent to the front speakers, this limitation will
be solved in the next week.
Solved a weird memory leak on libav.c related to the AVCodecContext
variable of the video decoder, minor modifications.

What is new in 7.5.2  build 6415  date - Wed 14/October/2020 07:42:41

Fixed a bug that was making the last slice of pcm data to don't
play at the end of the audio playback, this bug was introduced
during a creation of a workaround to a Windows 7 problem in the
Windows API function waveOutClose that was causing a
memory error crash when this function was called at the end of
the playback, to avoid this Microsoft original bug the function
finalizeplayer at the end of playback was not calling waveOutClose
but the handle was remaining open until a next playback start where
the function initplayer was being called and where the function
waveOutClose is being called to close the handle and start a new
player process, at that time it was the only way to don't generate
a memory access error at the end of playback, notice that Windows 95
up to Windows XP don't have this weird waveOutClose problem and we
almost pulled our hair out to understand what was wrong with the
Windows APIs, if you are new to the wav APIs take a look in
initplayer and finalizeplayer to see how to handle it correctly at
least until Microsoft introduce modifications on these APIs again.
Added support to the following sample formats:

AV_SAMPLE_FMT_U8,          ///< unsigned 8 bits
AV_SAMPLE_FMT_S16,         ///< signed 16 bits
AV_SAMPLE_FMT_S32,         ///< signed 32 bits
AV_SAMPLE_FMT_FLT,         ///< float
AV_SAMPLE_FMT_DBL,         ///< double

AV_SAMPLE_FMT_U8P,         ///< unsigned 8 bits, planar
AV_SAMPLE_FMT_S16P,        ///< signed 16 bits, planar
AV_SAMPLE_FMT_S32P,        ///< signed 32 bits, planar
AV_SAMPLE_FMT_FLTP,        ///< float, planar
AV_SAMPLE_FMT_DBLP,        ///< double, planar
AV_SAMPLE_FMT_S64,         ///< signed 64 bits
AV_SAMPLE_FMT_S64P,        ///< signed 64 bits, planar

Feel free to make your tests, the multichannel support for the
moment is the hability to handle the multichannel and play only
the front right and left channels while older versions cannot do
this, minor modifications.

What is new in 7.2.2  build 6385  date - Mon 12/October/2020 16:48:39
Added two new functions, SlowComputersCommand_k_p and
GetOriginalNumberofChannels.
Information about the function SlowComputersCommand_k_p:
When the computer is old the time required to decompress
and draw the video can be more than the processing time
available, without this the audio and video will just lose sync and
the audio will finish before the playback of all the video frames.
Using this option will adjust the audio and video sync as soon the 
sync is lost, but it is not perfect, frames will be dropped a lot,
it is optional because some users may want to see all the frames
without drop, make your tests...
Information about the GetOriginalNumberofChannels:
It will retrieve the number of channels in the media file.
It is required because internally any number of channels
above two are converted to two at this moment, this
is just informative, maybe in the future the DLL will be able
to access and use the additional channels and play it using
WaveOutWrite api.
Minor modifications, and only above version 7.1.4 the DLL
is capable of playing multichannel media files(5.1 e 7.1), the update
to these new versions is very important.


What is new in 7.1.4  build 6377  date - Sun 11/October/2020 12:33:16
Updated the Libav library with the release compiled by BtbN at
https://github.com/BtbN/FFmpeg-Builds/releases it is the release
[Auto-Build 2020-10-10 12:30], minor bugs fixed.

What is new in 7.0.9  build 63702 date - Sun 04/October/2020 15:33:16
Added code to drop frames when the time required to decode and show
the media file is less than required, it now allows to see a video
(even without some frames) with a better quality, the old releases
will just lose sync, minor bugs fixed.

What is new in 7.0.7  build 6370 date - Sun 27/September/2020 18:12:06
Modified the audio and video sync code, now it is more accurate, it can
have up to 12 milliseconds difference when compared with the real
playback position of the video, from my point of view it is ok, nobody
will be able to detect the absence of sync, minor bugs fixed.

What is new in 7.0.5  build 6368 date - Sun 27/September/2020 10:48:51
Due to the modifications added to the video playback thread to make it
possible to show the remaining frames after the end of the video playback
a bug was introduced that will appear when a mp3 file with a video frame
is played, (and this kind of mp3 file is common these days),
minor bugs fixed (as usual...).

What is new in 7.0.0  build 6363 date - Sun 20/September/2020 12:56:06
Replaced the Libav dlls with the release from Zeranoe compiled in
31/August/2020, fixed some problems in the sample project in the
SoundTouch control, removed some debug infrmation that was sent
to the installed debugger or DebugView, this version yet is not as
fast as Windows Media Player and Media Player Classic Home Cinema,
the delays occur on the Libav decoding functions and in the SDL
video handling routines, we need to figure out what kind of magic
Media Player Classic was doing to play 5 times faster than this DLL
when the library is the same, minor bugs fixed, next week we will
be fixing finally the weird audio and video sync code that we have
created ourselves, it works but can be improved.

What is new in 6.8.8  build 6351 date - Tue 08/September/2020 03:23:18
Added a new thread to help to speed up the decoding process but yet
this decoder and player is not as fast as Media Player Classic Home
Cinema and Windows Media Player, the problem is in the compiled
version of Libav that apparently was compiled wthout optimization
because MPC is also using Libav.
Next version will use the audio and video sync that I stole from
Chrome, the problem is that it need to be very well tested and debugged,
for the moment we will keep using our old weird method that is not
perfect but works.

What is new in 5.5.6  build 6219 date - Mon 31/August/2020 10:02:06
Fixed a few memory leaks, minor modifications, more changes will be
added in the next sunday.

What is new in 5.5.2  build 6194 date - Sun 30/August/2020 20:01:52
Fixed a few bugs that was causing the DLL to crash, yet the playback of HD
videos is slow, apparently the Libav libraries was compiled without
optimization, the delay to decode the media files come from the Libav
function avcodec_send_packet but we need to research a little more
on it, if you have a fast machine you will not notice the problem,
and was detected also a few memory leaks that will be fixed if the
problem is in our code, because if it come from the Libav only a new
release will solve the problem, this is what we have to say for the
moment, and it was an amazing hacking day.

What is new in 5.4.29 build 6157 date - Sun 30/August/2020 02:52:49
It is there, the first 64 bits release of the rsppmp3 project, it
now not only start but plays audio and video, but notice that despite
being using the latest Libav llbrary the playback of HD videos is
slower than other players like Windows Media Player and Media Player
Classic Home Cinema, I will investigate this problem in the rest of 
the sunday, feel free to download and test it in your own system and 
send some feedback, notice that Win32 versions using this release of
Libav will only be provided if someone request, a hug and thanks for
using our software.

What is new in 5.4.1  build 6129 date - Sun 23/August/2020 21:00:00
First version compiled correctly for win64, but the sample is
not able to play yet, we only need to debug a little more to
make it usable, or maybe you can hack on it and fix what is
making it unable to play at this moment
Next sunday we will work more on it.

What is new in 5.3.1  build 6113 date - Sun 16/August/2020 17:54:33
The conversion is almost done, only needs a few more hours, but
I will have this hours available to do it in the next sunday.
Notice that no bugs will be fixed during the conversion, only after.
The delay of this conversion comes from my unability to work
perfectly with Emacs until I learn the basics (again) and the APIs
removed from the old version of Libav of 2011.
A hug to you...

What is new in 5.2.12 build 6105 date - Sun 16/August/2020 10:11:52
First pass of the conversion to x64 is ready, now
we are working on the second step, this release
don't play at this moment, maybe in the
end of the day, just wait.

			Changelog
What is new in 5.2.3  build 6039
Only the modifications was the addition
of a new partner, new e-mail to support
, new primary homepage and we are using
again the name BinaryWork Corp., we hope to
never change it again in the future, about
e-mails e phone number it is checked 
instantly because now I have a decent 
smart phone and good friends are paying
the bills of our company, then we can
answer your questions very fast, another
important thing: the decoder from this
release of libav is very slow and it can
lose sync during the playback of full
hd webm and flv files, this don't occur
with new releases of libav, we have an
audio only player based in libav that is already
64 bits and the video decoder have been enhanced a lot
by the original libav maintainers the name is
arplayer and it is available also on sourceforge, as
soon we got more time we will replace this 2011
version of the libav with a 2020 release
both 32 and 64 bits, ok? the whatsapp
number can be found on the botton of this page
fell free to contact us 24x7 365 days of the year,
minor modifications, a hug to you for using our 
lovely software.

What is new in 5.1.15 build 6090
Debug version, have a bug in the
libav library, that is slow, do not
use this version in your products 
at least untill the fixes,
, fixed a bug that was causing an
error when a wpl playlist was loaded,
in this case the next call to the
Is_WPL_Playlist function was failing, 
added sort routines from Microsoft
in the listview code, fixed a weird problem
that was causing an error during the 
second call to the
load of the wpl file, thanks to the,
https://stackoverflow site for the help.


What is new in 5.1.14 build 6089
Debug version, have a bug in the
libav library, that is slow, and
in the sort of the listview when
playing a wpl playlist file, do not
use this version in your products
, at least untill the fixes.

What is new in 5.1.9 build 6084
Added code to the sample project
to disable the standby mode
and the monitor to turning off,
minor changes.

What is new in 5.1.5 build 6080
Fixed a weird bug that could cause
an access violation in the DLL,
minor bugs fixed.

What is new in 5.1.2 build 6077
Added documentation on the package,
it is in the folder
<extracted folder>\rsppmp3 sources\doxygen docs\html\index.html
no new modifications.

What is new in 5.1.1 build 6076
Fixed a bug in the initplayer
function that caused the call
to waveOutClose to occur with
the wrong parameters, minor
bugs fixed.

What is new in  5.0.35 build 6000
Changed the sample project to target
the .net framework 4.5 then
the Microsoft .NET Framework 4.5.1 must 
be installed on your machine, 
download link:
http://www.microsoft.com/en-us/download/details.aspx?id=40779
or you need to have the Visual Studio 17,
I am using sharpdevelop 5, in this version
if the decode and playback requires too
much processor time more than what is 
available the sync between audio and 
video can be lost, future versions
maybe will avoid it, minor bugs fixed.


What is new in 5.0.26 build 5991
The function that detect the frame
rate during the playback need fixes, it is
disabled for the moment, fixed a bug that
created crashes when you click cancel or
exit the application during playback,
the error was reported in the function 
PlaybackCancel, for the moment the 
playback of some media files requires
fast machines to avoid frames being dropped,
fixed a bug that only occurs when the
Soundtouch feature was enabled, it
was making the absence of sync
when frames need to be dropped
when the playback was above normal speed,
the problem only appeared in slow machines.

What is new in bw_4.0.12_build_5899.rar
Added update of the frame rate dinamicaly, now
the player can detect and adjust the frame rate
at runtime, this feature was missing.
			
What is new in bw_4.0.10_build_5897.rar
			
What is new in bw_4.0.5_build_5892.rar	
Fixed weird bug in the video section that
only appears in windows 8, the bug was causing
a crash during resize of the video window		
			
What is new in sr_3.3.607_build_000C00005877_.rar
Win7 problems not fixed completely yet, now basic win7
resize of the window is possible, fullscreen not working yet,
don't occur with all win7 machines, this is weird

What is new in sr_3.3.603_build_000C00005873_.rar
Due to a crash during the resize of the main video player window in win7 now the dll 
can be used for the moment to create an audio only player, the video player will be 
fixed soon.			
			
			
What is new in be_arabian_mp3_dll_3.3.568_build_000C00005838_.rar
Update of the company info.
			
What is new in be_arabian_mp3_dll_3.3.566_build_000C00005833_.rar
Small modifications.
			
What is new in be_arabian_mp3_dll_3.3.499_build_000C00005776_.7z
Enhanced the audio and video sync, now it is close to the perfect mode,
and the hability to keep playing audio and video after a suspend or
hibernate state is not working very weel yet, please fix it if you
have interest in this feature, to me it is useless and I think that
the playback need to stop when entering these states a la Windows
Media Player.

What is new in be_arabian_mp3_dll_3.3.471_build_000C00005748_.7z
To avoid possible problems now the framerate is always detected based
up to the first 500 seconds of playback for any file.

			What is new in be_arabian_mp3_dll_3.3.464_build_000C00005741_.7z
Added code to detect the correct framerate for some flv files
that Libav report erroneous values, now old flv files will play
perfectly.

What is new in be_arabian_mp3_dll_3.3.186_build_000C00005463_.7z
SoundTouch now when used will sinchronize the modified audio with
the video perfectly, modofied the Open and Play functions to avoid
a nasty bug that could cause these functions to don't return, now
the window information is passed on these functions.

What is new in the version 3.3.118 build 5395
Added a function to enhance the fullscreen modes,
minor modifications.

What is new in the version 3.3.86 build 5363
Large enhancements on the audio and video sinchronization
, now when returning from suspend and hibernation state
the sinchronization will recover perfectly, many other
modifications.
			
What is new in the version 3.2.928 build 5205
Fixed a small problem in the audio and video
sinchronization, the value of the time required to
draw the image was in seconds and not milliseconds,
now the milliseconds will be diminished of the
requested sleep time making it more accurate, anyway
you will not perceive the difference because the method
that I was using to sinchronize already was able to compensate 
for this problem, the variable in question was 'timespent'.
			
What is new in the version 3.2.918 build 5195
Due to some flaws on the ReplayGain we developed the new
BENormalize normalization method, it s based on the peak value
of the samples, believe me it gives better results than ReplayGain,
just make some tests and you will see.

What is new in the version 3.2.886 build 5163
Now the apllication running the DLL will not hijack
the focus when the video is loaded, then you can do
other works while the player is running in the background
, you can test it if you set the loop mode.
			
What is new in the version 3.2.878 build 5155
Modified the sample project to avoid some problems, next
release will adjust the size of the player window without a reload
of the media file as expected, the modified sources of SDL
was included and if you don't have the whole DirecX SDK installed
(like me) you will find the file dxguid.lib handy, it is in the
SDL sources folder, and now with all the sources available anyone
can compile this to 64 bits, at least my portions of the sources
are win64 ready for a long time now.

What is new in the version 3.2.874 build 5151
Fixed problem that occurs when the DirectX surface is lost
, now it will recover from this situation without any problem,
and I don't supose that modifications to SDL more than we did
are necessary.

What is new in the version 3.2.816 build 5093
	Modified the behavior of the Open and Play functions now it
	will return -1 if you are calling these while the last call 
	was not finished loading the media file, without it the DLL
	can enter in an infinite loop waiting for something that never
	will occur, if you receive a -1 from this call you only need
	to add a Sleep(3000) and call the open or play function again
	with the same media file, it sounds strange
	but it is very weird to track where the loading processing is
	to stop it immediately at anytime, maybe in the future this
	behavour will be modified but for the moment this is the best
	thing to do, many small bugs removed.
	
	What is new in the version 3.2.766 build 5043
		Now we are using DirectX for drawing because it
		is faster, some apis modified for DirecX
		support, the SDL version embedded on our
		code is a lot different than the original
		version, and it depends on the msvcr90.dll,
		I will not remove this dependency without
		a good reason, it would be great to keep msvcr90.dll
		with us to remember how important the MSVC
		compilers was in the past
		, but if someone ask I will make it compile
		with mingw, indeed I love to convert projects
		to mingw because they run faster and no 
		dependency of any kind and easy port to 64
		with Cygwin, another thing, the audio and video
		sinchronization has several different modes
		to avoid problems, but yet I don't know if it
		is perfect, take a look, and yet
		the seek on webm files don't occurs as expected,
		this is a Libav problem, the only solution that
		I have to this problem is slow, then it is not
		a solution at all.
		
			What is new in the version 3.2.9 build 4286
		First release capable of playing video, it will
		skip some frames it the processor time is not 
		enough to process the video draw request (as
		expected), the video is outside of the form for
		the moment, next release will show the video
		inside the form as a picturebox, many modifications
		and bug fixes, the spectrum analizer now is a real
		FFT based spectrum analizer and work very well.			
		
			What is new in the version 3.1.238 build 3515
		The seek on webm files is not working as expected
		, we are thinking about what is the best workaround
		to this problem, a slow solution is ready but since it
		is slow it is not a real fix to the problem, we need
		code to handle webm outside the Libav, this appears
		to be the best solution or hook on the Libav apis and
		replace the webm functions with another fixed
		implementation.

			What is new in the version 3.1.169 build 3446
Fixed weird memory access problem on the
id3 v1 tag implementation that was there
since 2001.
		
		What is new in the version 2.5.68 build 2745
Removed the ffms2.dll because it is slow, and now we
are using directly the Libav dlls (included), many
other modifications, and no change in the external
apis, fixed many bugs too, this is a stable release.
		
		What is new in the version 2.2.83 build 2460
Many bugs fixed, added also many enhancements.
		
		What is new in the version 2.1.40 build 2317
First release with Libav support(ffmsi2.dll)
Now the dll can play all media formats, video
support will follow
Many modifications when compared with older releases,
Some functions was renamed and removed too.

Check the sources to see what is different.

			What is new in the version 1.9.2 build 2072
An unexpected problem started on version 1.8.1 fixed in 
this version, in this case an AAC or MP4 would just not 
play, fixed.

			What is new in the version 1.8.8 build 2068
After now the DLL can only play perfect MPEG data,
if it is a problem to you comment out the lines 
233, 234 and 235 of the player.c source file.

What is new in the version 1.8.4 build 2067
Detected a bug on the mp3 decoder (it is not a joke)
it may cause the DLL to become in an instable state
and crash the application, it only occurs if you
pass an invalid media file that is not a perfect
mp3, the chances of this occur is small but will
be fixed as soon as I got time, sorry for this problem
, I have removed the mpeglib as the decoder just due
to these problems, and I was not expecting this
problem also with madlib.

What is new in the version 1.8.1 build 2066
Important information: after 11 years the spectrum 
analizer is finally working.

What is new in the version 1.8.1 build 2066
Too many modifications to be listed here,
now the win64 version need to be compiled, you only
need to adjust the makefile to do it, many many
modifications, replace older versions of this
dll with this release for fixes.
Another important information: after now the
additional media formats supported will only be 
able to seek after 2 seconds of playback, for 
wav and mpeg (mp3) it is not affected, maybe in 
a near future when I gathering the Standard C 
sources of all the media formats directly it 
will be able to seek like mp3 and wav.

What is new in the version 1.5.8 build 2043
Small modifications, the API ConvertMP3ToWav
has changed their arguments, please check
your code if you will just replace an older
version of the DLL with the new version,
both win32 and win64 binaries of the latest
release is available.

What is new in the version 1.5.7 build 2042
Fixed a weird bug in the playback of mono files
that will play it slowly, sorry for not figuring
it out before.

What is new in the version 1.5.6 build 2041
Removed mpeglib, it has severallimitations
to decode a damaged mp3 file then it was just removed
nowonly madlib decodes mp3, several modofocations
and enhancements, the 64 bits release is the same as the
version 1.5.5,if you need compile the 64 bits
to update, the win32 version dll is real version
1.5.6, in the next release both binaries will
be exactly the same, absence of time at this moment,
sorry, the sample project in C# was modified
and the 64 bits version is old,it will be
updated also on the next release.
 
What is new in the version 1.5.5 build 2040
Added possibility to convert the mp3 data to various
wav modes, PCM 16 24 32 and FLOAT, minor modifications.

What is new in the version 1.5.2 build 2037
(Tue May 17 GMT 13:42:28 2011 , by arab)
Fixed a bug on the equalizer when running
on 64 bits systems, minor modifications.

What is new in the version 1.5.0 build 2034
(Mon May 16 GMT 17:10:29 2011 , by arab)
Now the win32 and win64 dlls compiles only
with mingw and mingw64, first release with
both 32 and 64 bits of the dlls and sample
project, many modifications on the sources,
and now the playback is always madlib.
			~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Installation and Usage:

Install : Extract the files to an empty folder
Uninstall: Delete the folder

Important: 
1-No access to the registry from the DLL (maybe from Libav or SDL, please check
if it is a problem to you),
it is Windows 7/8/10 safe at least my portions of the code

			~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Valquiria says thanks for using our software.

Melhorado no Brasil - whats +55 41 9627-1708
