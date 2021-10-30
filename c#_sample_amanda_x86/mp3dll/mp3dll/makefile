all:
	@C:\WINDOWS\Microsoft.NET\Framework\v3.5\Csc.exe /nologo /noconfig \
	/nowarn:1701,1702 /platform:x86 /define:NPRINTF2 \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Data.dll \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Deployment.dll \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.dll \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Drawing.dll \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Windows.Forms.dll \
	/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Xml.dll /filealign:512 \
	/nowin32manifest /optimize+ /out:bin\x86\Release\mp3dll.exe \
	/resource:obj\x86\Release\mp3dll.DebugInformation.resources \
	/resource:obj\x86\Release\mp3dll.equalizer.resources \
	/resource:obj\x86\Release\mp3dll.sample.resources \
	/resource:obj\x86\Release\mp3dll.normalize.resources \
	/resource:obj\x86\Release\mp3dll.Properties.Resources.resources \
	/resource:obj\x86\Release\mp3dll.spectrum.resources \
	/resource:obj\x86\Release\mp3dll.wave_effects.resources \
	/target:winexe /warnaserror- /win32icon:mp3.ico DebugInformation.cs \
	DebugInformation.Designer.cs equalizer.cs equalizer.Designer.cs sample.cs \
	sample.Designer.cs mp3class.cs normalize.cs normalize.Designer.cs Program.cs \
	Properties\AssemblyInfo.cs Properties\Resources.Designer.cs \
	Properties\Settings.Designer.cs spectrum.cs spectrum.Designer.cs \
	wave_effects.cs wave_effects.Designer.cs select_wav_mode.cs \
	select_wav_mode.Designer.cs \
	progressbar.cs progressbar.designer.cs
	
final:
	C:\WINDOWS\Microsoft.NET\Framework\v3.5\Csc.exe /noconfig /nowarn:1701,1702 /platform:x86 /doc:bin\x86\Release\mp3dll.XML /define:NPRINTF2 /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Data.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Deployment.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Drawing.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Windows.Forms.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Xml.dll /filealign:512 /nowin32manifest /optimize+ /out:bin\x86\Release\mp3dll.exe /resource:obj\x86\Release\mp3dll.DebugInformation.resources /resource:obj\x86\Release\mp3dll.equalizer.resources /resource:obj\x86\Release\mp3dll.sample.resources /resource:obj\x86\Release\mp3dll.normalize.resources /resource:obj\x86\Release\mp3dll.Properties.Resources.resources /resource:obj\x86\Release\mp3dll.spectrum.resources /resource:obj\x86\Release\mp3dll.wave_effects.resources /target:winexe /warnaserror- /win32icon:mp3.ico DebugInformation.cs DebugInformation.Designer.cs equalizer.cs equalizer.Designer.cs sample.cs sample.Designer.cs mp3class.cs normalize.cs normalize.Designer.cs Program.cs Properties\AssemblyInfo.cs Properties\Resources.Designer.cs Properties\Settings.Designer.cs spectrum.cs spectrum.Designer.cs wave_effects.cs wave_effects.Designer.cs select_wav_mode.cs select_wav_mode.Designer.cs
	@echo                              .
	@echo            Compilou Bucaneiro