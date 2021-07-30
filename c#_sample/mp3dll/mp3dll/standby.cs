
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

using System;
using System.Runtime.InteropServices;

namespace mp3dll
{
	/// <summary>
	/// this class will avoid the system entering standby mode and turning off the monitor
	/// </summary>
	public class avoid_standby
	{
		

		#region prevent screensaver, display dimming and automatically sleeping
		POWER_REQUEST_CONTEXT _PowerRequestContext;
		IntPtr _PowerRequest; //HANDLE
		bool  can_close_z = false;
		// Availability Request Functions
		[DllImport("kernel32.dll")]
		static extern IntPtr PowerCreateRequest(ref POWER_REQUEST_CONTEXT Context);

		[DllImport("kernel32.dll")]
		static extern bool PowerSetRequest(IntPtr PowerRequestHandle, PowerRequestType RequestType);

		[DllImport("kernel32.dll")]
		static extern bool PowerClearRequest(IntPtr PowerRequestHandle, PowerRequestType RequestType);

		[DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
		internal static extern int CloseHandle(IntPtr hObject);

		// Availablity Request Enumerations and Constants
		enum PowerRequestType
		{
			PowerRequestDisplayRequired = 0,
			PowerRequestSystemRequired,
			PowerRequestAwayModeRequired,
			PowerRequestMaximum
		}

		const int POWER_REQUEST_CONTEXT_VERSION = 0;
		const int POWER_REQUEST_CONTEXT_SIMPLE_STRING = 0x1;
		const int POWER_REQUEST_CONTEXT_DETAILED_STRING = 0x2;

		// Availablity Request Structures
		// Note:  Windows defines the POWER_REQUEST_CONTEXT structure with an
		// internal union of SimpleReasonString and Detailed information.
		// To avoid runtime interop issues, this version of
		// POWER_REQUEST_CONTEXT only supports SimpleReasonString.
		// To use the detailed information,
		// define the PowerCreateRequest function with the first
		// parameter of type POWER_REQUEST_CONTEXT_DETAILED.
		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
		public struct POWER_REQUEST_CONTEXT
		{
			public UInt32 Version;
			public UInt32 Flags;
			[MarshalAs(UnmanagedType.LPWStr)]
			public string
				SimpleReasonString;
		}

		[StructLayout(LayoutKind.Sequential)]
		public struct PowerRequestContextDetailedInformation
		{
			public IntPtr LocalizedReasonModule;
			public UInt32 LocalizedReasonId;
			public UInt32 ReasonStringCount;
			[MarshalAs(UnmanagedType.LPWStr)]
			public string[] ReasonStrings;
		}

		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
		public struct POWER_REQUEST_CONTEXT_DETAILED
		{
			public UInt32 Version;
			public UInt32 Flags;
			public PowerRequestContextDetailedInformation DetailedInformation;
		}
		#endregion



		/// <summary>
		/// Prevent screensaver, display dimming and power saving. This function wraps PInvokes on Win32 API.
		/// </summary>
		/// <param name="enableConstantDisplayAndPower">True to get a constant display and power - False to clear the settings</param>
		public void EnableConstantDisplayAndPower(bool enableConstantDisplayAndPower)
		{
			
			//MP3.dprintf("enable or disable screensaver " +enableConstantDisplayAndPower);
			
			if (enableConstantDisplayAndPower)
			{
				// Set up the diagnostic string
				_PowerRequestContext.Version = POWER_REQUEST_CONTEXT_VERSION;
				_PowerRequestContext.Flags = POWER_REQUEST_CONTEXT_SIMPLE_STRING;
				_PowerRequestContext.SimpleReasonString = "Continuous measurement"; // your reason for changing the power settings;

				MP3.pedro_dprintf(-1, "Will try to request the new power state");
				// Create the request, get a handle
				_PowerRequest = PowerCreateRequest(ref _PowerRequestContext);
				can_close_z = true;
				// Set the request
				PowerSetRequest(_PowerRequest, PowerRequestType.PowerRequestSystemRequired);
				PowerSetRequest(_PowerRequest, PowerRequestType.PowerRequestDisplayRequired);
				MP3.pedro_dprintf(-1, "Requested");
			}
			else
			{
				if(can_close_z)
				{
					MP3.pedro_dprintf(-1, "Will try to close");
					// Clear the request
					PowerClearRequest(_PowerRequest, PowerRequestType.PowerRequestSystemRequired);
					PowerClearRequest(_PowerRequest, PowerRequestType.PowerRequestDisplayRequired);

					CloseHandle(_PowerRequest);
					MP3.pedro_dprintf(-1, "Closed");
					can_close_z = false;
					
				}
				else
				{
					MP3.pedro_dprintf(-1, "Already closed");
				}
			}
		}
		
	}
}
