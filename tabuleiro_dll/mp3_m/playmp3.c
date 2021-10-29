//Mon Apr 14 16:24:57 2014, by ricardo

#include <windows.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

int decode_mad_MP3(char *bufmp3, int len, char *out, int outlimit,
                   int *outsize, int *large);

int Exit_mad_MP3(void);

int Init_mad_MP3(void);

/*These are the informations that you can gather
   from an mp3 file using the madlib library
 */
extern int mad_force_exit; //do not use
extern int valid_xing;
extern int madsamplerate;  //sample rate
extern int madlayer;       //layer
extern int madchannel;     //channels
extern int numberofframes; //the number of frames
extern char madmode[];
extern int madsample_per_frame;
extern int madbitrate;        //the bitrate
extern double madmpegversion; //mpeg version
extern int mad_mp3_is_valid;
//Mon Apr 14 16:24:57 2014, by ricardo

////////////////////////////////////////////////////////////////////////////////////
static WAVEFORMATEX pwfx = {
    0,
};

static HWAVEOUT phwo = 0;

#define uint unsigned int

#define uchar unsigned char

#define TEST_1 5

int play(uchar *buf, uint len);
int play(uchar *buf, uint len)
{
     static int position = 0;
     static unsigned char copia_1[100000];
     static unsigned char copia_2_24_june_2011__14_12_PM[100000];
     static WAVEHDR WaveHdr;
     static WAVEHDR WaveHdr1;

     switch (position)
     {
     case 0:
     {

          while (WAVERR_STILLPLAYING == waveOutUnprepareHeader(phwo,
                                                               &WaveHdr,
                                                               sizeof(WAVEHDR)))
          {
               Sleep(TEST_1);
          }

          memcpy(copia_1, buf, len);
          WaveHdr.lpData = (void *)copia_1;
          WaveHdr.dwBufferLength = len;
          WaveHdr.dwUser = 1;
          WaveHdr.dwFlags = 0;
          waveOutPrepareHeader(phwo, &WaveHdr, sizeof(WAVEHDR));
          waveOutWrite(phwo, &WaveHdr, sizeof(WAVEHDR));
          position = 1;
          return 0;
     }
     break;
     case 1:
     {

          while (WAVERR_STILLPLAYING == waveOutUnprepareHeader(phwo,
                                                               &WaveHdr1,
                                                               sizeof(WAVEHDR)))
          {
               Sleep(TEST_1);
          }

          memcpy(copia_2_24_june_2011__14_12_PM, buf, len);
          WaveHdr1.lpData = (void *)copia_2_24_june_2011__14_12_PM;
          WaveHdr1.dwBufferLength = len;
          WaveHdr1.dwUser = 2;
          WaveHdr1.dwFlags = 0;
          waveOutPrepareHeader(phwo, &WaveHdr1, sizeof(WAVEHDR));
          waveOutWrite(phwo, &WaveHdr1, sizeof(WAVEHDR));
          position = 0;
          return 0;
     }
     break;
     }

     return 0;
}

static void CALLBACK
callback(HWAVEOUT handle, UINT message, DWORD data, DWORD param1,
         DWORD param2)
{
     (void)handle;
     (void)data;
     (void)param1;
     (void)param2;
     /*
                switch (intpriority)
                {

                case 0:
                        //idle
                        SetThreadPriority(
                                GetCurrentThread(),
                                -1
                                );
                        break;

                case 1:
                        //normal
                        SetThreadPriority(
                                GetCurrentThread(),
                                0
                                );
                        break;

                case 2:
                        //high
                        SetThreadPriority(
                                GetCurrentThread(),
                                2
                                );

                        break;
                default:
                        break;
        }
 */
     switch (message)
     {
     case WOM_DONE:

          break;
     case WOM_OPEN:

          break;
     case WOM_CLOSE:

          break;
     }
}

int initplayer(int intsamplerate);
int initplayer(int intsamplerate)
{
     uint ret = 0;
     //thinktwice1);

     {

          pwfx.wFormatTag = WAVE_FORMAT_PCM;
     }

     pwfx.nChannels = 2;
     {

          pwfx.nSamplesPerSec = intsamplerate;

          {
               pwfx.nAvgBytesPerSec =
                   (intsamplerate * ((2 * 16) / 8));
          }
     }

     {
          pwfx.nBlockAlign = 2 * 2;
          pwfx.wBitsPerSample = 16;
     }

     pwfx.cbSize = 0;

     if (phwo == 0)
     {

          ret = waveOutOpen(&phwo, -1, &pwfx,
                            (DWORD_PTR)callback, 0,
                            CALLBACK_FUNCTION);
     }

     switch (ret)
     {
     case MMSYSERR_NOERROR:
          printf("The wave out is open\n");
          return 0;

          break;

     case WAVERR_SYNC:
          printf("WAVERR_SYNC\n");
          exit(1);
          break;
     case WAVERR_BADFORMAT:
          printf("WAVERR_BADFORMAT\n");
          exit(1);
          break;
     case MMSYSERR_NOMEM:
          printf("MMSYSERR_NOMEM\n");
          exit(1);
          break;
     case MMSYSERR_NODRIVER:
          printf("MMSYSERR_NODRIVER\n");
          exit(1);
          break;
     case MMSYSERR_BADDEVICEID:
          printf("MMSYSERR_BADDEVICEID\n");
          exit(1);
          break;

     default:
          break;
     }

     return 1;
}

#include "id3_jump.c"

////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{

     FILE *myfile = NULL;
     static char bufmp3[100000];
     static char out[10000];
     int chaveador = 0;
     int len = 0;
     int large = 1;
     int isize = 0;
     int init = 0;
     int id3_tag_size_z;
     Init_mad_MP3();

     if (2 == argc)
     {

          myfile = fopen(argv[1], "rb");

          if (NULL == myfile)
          {
               printf("Error openning file %s\n", argv[1]);
               goto saida;
          }

          id3_tag_size_z = id3v2tag_check(argv[1]);

          if (id3_tag_size_z)
               printf("ID3 tag size %d\n\n", id3_tag_size_z);

          fseek(myfile, id3_tag_size_z, SEEK_SET);

     retornamp3:;

          len = fread(bufmp3,
                      sizeof(char),
                      large,
                      myfile);

          {
               static int size = 0;
               size += len;
               //printf("Reading...% d\n",size);
          }

          if (len <= 0 && 0 != large)
          {
               printf("End of stream\n");
               goto saida;
          }
     processa:;
          chaveador =
              decode_mad_MP3(bufmp3,
                             len,
                             out,
                             4608,
                             &isize,
                             &large);
     }
     if (0 != chaveador)
     {
          goto retornamp3;
     }
     //printf("Processing...\n");

     if (0 == init)
     {
          init++;

          assert(madchannel);
          assert(madsamplerate);

          initplayer(madsamplerate);

          //exit(1);
     }

     {

          //printf("isize %d\n", isize);

          static char buffer__[500000];
          static int deslocador = 0;
          static char *ptr = buffer__;

          if (deslocador < 90000)
          {
               memcpy(ptr, out, isize);
               deslocador += isize;
               ptr += isize;
          }
          else
          {
               //printf("size %d\n",deslocador);
               play((uchar *)buffer__, deslocador);
               ptr = buffer__;
               deslocador = 0;
          }
     }

     fflush(stdout);
     goto processa;

saida:;
     Exit_mad_MP3();
     if (myfile)
     {
          fclose(myfile);
     }

     printf("End of execution\n");
     return 0;
}
