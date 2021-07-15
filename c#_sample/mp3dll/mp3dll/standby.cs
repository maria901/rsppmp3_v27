
/*
    <C# Sample Project for rsppmp3>
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
 */

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
