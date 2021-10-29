extern unsigned __int64 __stdcall Int64ShllMod32 (unsigned __int64 Value,
						  unsigned long ShiftCount);
extern __int64 __stdcall Int64ShraMod32 (__int64 Value,
					 unsigned long ShiftCount);
extern unsigned __int64 __stdcall Int64ShrlMod32 (unsigned __int64 Value,
						  unsigned long ShiftCount);
extern void *__cdecl GetFiberData (void);
extern void *__cdecl GetCurrentFiber (void);
extern void __cdecl dprintf (const char *format, ...);
extern void __cdecl dprintf2 (const char *format, ...);
