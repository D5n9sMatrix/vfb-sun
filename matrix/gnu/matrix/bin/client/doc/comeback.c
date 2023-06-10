typedef   signed char       int8;
typedef unsigned char      uint8;
typedef   signed short      int16;
typedef unsigned short     uint16;
typedef   signed int        int32;
typedef unsigned int       uint32;
typedef   signed long long  int64;
typedef unsigned long long uint64;
typedef struct { char *data; int64 len; int64 size; } FBSTRING;
typedef int8 boolean;
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $7FBARRAYI8FBSTRINGE {
	FBSTRING* DATA;
	FBSTRING* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYI8FBSTRINGE ) == 240 );
struct $7FBARRAYIKvE {
	void* DATA;
	void* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYIKvE ) == 240 );
struct $7FBARRAYIvE {
	void* DATA;
	void* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYIvE ) == 240 );
#define fb_D2I( value ) ((int32)__builtin_nearbyint( value ))
int32 fb_ArrayRedimEx( struct $7FBARRAYIvE*, uint64, int32, int32, uint64, ... );
int32 fb_ArrayRedimPresvEx( struct $7FBARRAYIvE*, uint64, int32, int32, uint64, ... );
int64 fb_ArrayLBound( struct $7FBARRAYIKvE*, int64 );
int64 fb_ArrayUBound( struct $7FBARRAYIKvE*, int64 );
int32 fb_Locate( int32, int32, int32, int32, int32 );
void fb_Cls( int32 );
FBSTRING* fb_Inkey( void );
int32 fb_FileOpen( FBSTRING*, uint32, uint32, uint32, int32, int32 );
int32 fb_FileClose( int32 );
int32 fb_FileLineInput( int32, void*, int64, int32 );
int32 fb_ConsoleInput( FBSTRING*, int32, int32 );
int32 fb_InputString( void*, int64, int32 );
int32 fb_FileFree( void );
int32 fb_FileEof( int32 );
int32 fb_FileKill( FBSTRING* );
int32 fb_GfxScreen( int32, int32, int32, int32, int32 );
void fb_PrintVoid( int32, int32 );
void fb_PrintString( int32, FBSTRING*, int32 );
FBSTRING* fb_StrInit( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
int32 fb_StrCompare( void*, int64, void*, int64 );
FBSTRING* fb_StrAllocTempResult( FBSTRING* );
FBSTRING* fb_StrAllocTempDescZEx( uint8*, int64 );
int64 fb_StrLen( void*, int64 );
int64 fb_StrInstr( int64, FBSTRING*, FBSTRING* );
void fb_End( int32 );
void fb_Sleep( int32 );
int32 fb_SleepEx( int32, int32 );
static void fb_ctor__comeback( void ) __attribute__(( constructor ));
FBSTRING* GETKEYS( FBSTRING* );
void CP( int64, FBSTRING* );
void SAPPEND( struct $7FBARRAYI8FBSTRINGE*, FBSTRING* );
void ADD_AFFIRMATION( void );
void SHOW_AFFIRMATIONS( void );
void MAIN( void );
static int64 I$ = 0ll;
static FBSTRING ANSWER$;
static FBSTRING TMP$;
struct $8FBARRAY1I8FBSTRINGE {
	FBSTRING* DATA;
	FBSTRING* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1I8FBSTRINGE ) == 72 );
static struct $8FBARRAY1I8FBSTRINGE BUFFER$ = { (FBSTRING*)0ull, (FBSTRING*)0ull, 0ll, 24ll, 1ll, 17ll, {  } };

FBSTRING* GETKEYS( FBSTRING* KEYSTOCATCH$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$2:;
	FBSTRING K$1;
	__builtin_memset( &K$1, 0, 24ll );
	label$4:;
	{
		FBSTRING* vr$2 = fb_Inkey(  );
		fb_StrAssign( (void*)&K$1, -1ll, (void*)vr$2, -1ll, 0 );
		fb_SleepEx( 1, 1 );
	}
	label$6:;
	int64 vr$5 = fb_StrInstr( 1ll, KEYSTOCATCH$1, (FBSTRING*)&K$1 );
	if( vr$5 == 0ll ) goto label$4;
	label$5:;
	label$7:;
	FBSTRING* vr$6 = fb_Inkey(  );
	int64 vr$7 = fb_StrLen( (void*)vr$6, -1ll );
	if( vr$7 <= 0ll ) goto label$8;
	{
		fb_SleepEx( 1, 1 );
	}
	goto label$7;
	label$8:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&K$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&K$1 );
	goto label$3;
	fb_StrDelete( (FBSTRING*)&K$1 );
	label$3:;
	FBSTRING* vr$13 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$13;
}

void CP( int64 ROW$1, FBSTRING* S$1 )
{
	label$9:;
	int64 vr$0 = fb_StrLen( (void*)S$1, -1ll );
	fb_Locate( (int32)ROW$1, fb_D2I( (double)(-vr$0 + 100ll) / 0x1.p+1 ), -1, 0, 0 );
	fb_PrintString( 0, (FBSTRING*)S$1, 1 );
	label$10:;
}

void SAPPEND( struct $7FBARRAYI8FBSTRINGE* ARR$1, FBSTRING* TEMP$1 )
{
	label$11:;
	int64 vr$0 = fb_ArrayUBound( (struct $7FBARRAYIKvE*)ARR$1, 1ll );
	fb_StrAssign( (void*)((vr$0 * 24ll) + *(int64*)ARR$1), -1ll, (void*)TEMP$1, -1ll, 0 );
	int64 vr$5 = fb_ArrayUBound( (struct $7FBARRAYIKvE*)ARR$1, 1ll );
	int64 vr$7 = fb_ArrayLBound( (struct $7FBARRAYIKvE*)ARR$1, 1ll );
	fb_ArrayRedimPresvEx( (struct $7FBARRAYIvE*)ARR$1, 24ull, -1, -1, 1ull, vr$7, vr$5 + 1ll );
	label$12:;
}

void ADD_AFFIRMATION( void )
{
	int32 TMP$4$1;
	label$13:;
	int32 H$1;
	int32 vr$0 = fb_FileFree(  );
	H$1 = vr$0;
	fb_Cls( -65536 );
	FBSTRING* vr$1 = fb_StrAllocTempDescZEx( (uint8*)"PLEASE ENTER SOMETHING POSITIVE ABOUT YOURSELF: ", 48ll );
	fb_ConsoleInput( (FBSTRING*)vr$1, 0, -1 );
	fb_InputString( (void*)&ANSWER$, -1ll, 0 );
	FBSTRING* vr$2 = fb_StrAllocTempDescZEx( (uint8*)"affirmations.txt", 16ll );
	fb_FileOpen( (FBSTRING*)vr$2, 4u, 0u, 0u, H$1, 0 );
	TMP$4$1 = H$1;
	fb_PrintString( TMP$4$1, (FBSTRING*)&ANSWER$, 1 );
	fb_FileClose( H$1 );
	fb_PrintVoid( 0, 1 );
	FBSTRING* vr$3 = fb_StrAllocTempDescZEx( (uint8*)"PRESS ANY KEY...", 16ll );
	fb_PrintString( 0, (FBSTRING*)vr$3, 1 );
	fb_Sleep( -1 );
	label$14:;
}

void SHOW_AFFIRMATIONS( void )
{
	label$15:;
	int32 H$1;
	int32 vr$0 = fb_FileFree(  );
	H$1 = vr$0;
	fb_Cls( -65536 );
	FBSTRING* vr$1 = fb_StrAllocTempDescZEx( (uint8*)"affirmations.txt", 16ll );
	fb_FileOpen( (FBSTRING*)vr$1, 2u, 0u, 0u, H$1, 0 );
	label$17:;
	int32 vr$2 = fb_FileEof( H$1 );
	if( ~(int64)vr$2 == 0ll ) goto label$18;
	{
		fb_FileLineInput( H$1, (void*)&TMP$, -1ll, 0 );
		SAPPEND( (struct $7FBARRAYI8FBSTRINGE*)&BUFFER$, &TMP$ );
	}
	goto label$17;
	label$18:;
	fb_FileClose( H$1 );
	FBSTRING* vr$5 = fb_StrAllocTempDescZEx( (uint8*)"YOUR AFFIRMATIONS ARE:", 22ll );
	fb_PrintString( 0, (FBSTRING*)vr$5, 1 );
	label$19:;
	{
		fb_PrintString( 0, (FBSTRING*)((I$ * 24ll) + *(int64*)&BUFFER$), 1 );
		I$ = I$ + 1ll;
		if( (I$ % 5ll) != 0ll ) goto label$23;
		{
			fb_Sleep( -1 );
		}
		label$23:;
		label$22:;
	}
	label$21:;
	int64 vr$11 = fb_ArrayUBound( (struct $7FBARRAYIKvE*)&BUFFER$, 1ll );
	if( I$ != vr$11 ) goto label$19;
	label$20:;
	fb_PrintVoid( 0, 1 );
	FBSTRING* vr$12 = fb_StrAllocTempDescZEx( (uint8*)"PRESS ANY KEY...", 16ll );
	fb_PrintString( 0, (FBSTRING*)vr$12, 1 );
	fb_Sleep( -1 );
	label$16:;
}

void MAIN( void )
{
	label$24:;
	label$26:;
	{
		FBSTRING TMP$8$2;
		FBSTRING TMP$10$2;
		FBSTRING TMP$12$2;
		FBSTRING TMP$14$2;
		FBSTRING TMP$16$2;
		FBSTRING TMP$20$2;
		FBSTRING K$2;
		__builtin_memset( &K$2, 0, 24ll );
		fb_Cls( -65536 );
		__builtin_memset( &TMP$8$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$8$2, -1ll, (void*)"POSITIVE AFFIRMATION PROGRAM", 29ll, 0 );
		CP( 1ll, &TMP$8$2 );
		fb_StrDelete( (FBSTRING*)&TMP$8$2 );
		__builtin_memset( &TMP$10$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$10$2, -1ll, (void*)"PRESS KEY 1 TO MAKE AN AFFIRMATION", 35ll, 0 );
		CP( 3ll, &TMP$10$2 );
		fb_StrDelete( (FBSTRING*)&TMP$10$2 );
		__builtin_memset( &TMP$12$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$12$2, -1ll, (void*)"PRESS KEY 2 TO VIEW YOUR AFFIRMATIONS", 38ll, 0 );
		CP( 5ll, &TMP$12$2 );
		fb_StrDelete( (FBSTRING*)&TMP$12$2 );
		__builtin_memset( &TMP$14$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$14$2, -1ll, (void*)"PRESS KEY 3 TO DELETE DATABASE AND START FRESH", 47ll, 0 );
		CP( 7ll, &TMP$14$2 );
		fb_StrDelete( (FBSTRING*)&TMP$14$2 );
		__builtin_memset( &TMP$16$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$16$2, -1ll, (void*)"PRESS ESC KEY TO EXIT PROGRAM", 30ll, 0 );
		CP( 9ll, &TMP$16$2 );
		fb_StrDelete( (FBSTRING*)&TMP$16$2 );
		__builtin_memset( &TMP$20$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$20$2, -1ll, (void*)"123\x1B", 5ll, 0 );
		FBSTRING* vr$24 = GETKEYS( (FBSTRING*)&TMP$20$2 );
		fb_StrAssign( (void*)&K$2, -1ll, (void*)vr$24, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$20$2 );
		int32 vr$28 = fb_StrCompare( (void*)&K$2, -1ll, (void*)"\x1B", 2ll );
		if( (int64)vr$28 != 0ll ) goto label$30;
		{
			fb_End( 0 );
		}
		goto label$29;
		label$30:;
		int32 vr$31 = fb_StrCompare( (void*)&K$2, -1ll, (void*)"1", 2ll );
		if( (int64)vr$31 != 0ll ) goto label$31;
		{
			ADD_AFFIRMATION(  );
		}
		goto label$29;
		label$31:;
		int32 vr$34 = fb_StrCompare( (void*)&K$2, -1ll, (void*)"2", 2ll );
		if( (int64)vr$34 != 0ll ) goto label$32;
		{
			SHOW_AFFIRMATIONS(  );
		}
		goto label$29;
		label$32:;
		int32 vr$37 = fb_StrCompare( (void*)&K$2, -1ll, (void*)"3", 2ll );
		if( (int64)vr$37 != 0ll ) goto label$33;
		{
			int64 RESULT$3;
			FBSTRING* vr$39 = fb_StrAllocTempDescZEx( (uint8*)"affirmations.txt", 16ll );
			int32 vr$40 = fb_FileKill( (FBSTRING*)vr$39 );
			RESULT$3 = (int64)vr$40;
			if( RESULT$3 == 0ll ) goto label$35;
			{
				fb_Cls( -65536 );
				FBSTRING* vr$42 = fb_StrAllocTempDescZEx( (uint8*)"ERROR TRYING TO DELETE FILE affirmations.txt MAYBE THE FILE DOESN'T EXITS? PLEASE MAKE AN AFFIRMATION FIRST :)", 110ll );
				fb_PrintString( 0, (FBSTRING*)vr$42, 1 );
				fb_Sleep( -1 );
			}
			goto label$34;
			label$35:;
			{
				fb_Cls( -65536 );
				int32 H$4;
				int32 vr$43 = fb_FileFree(  );
				H$4 = vr$43;
				FBSTRING* vr$44 = fb_StrAllocTempDescZEx( (uint8*)"affirmations.txt", 16ll );
				fb_FileOpen( (FBSTRING*)vr$44, 4u, 0u, 0u, H$4, 0 );
				fb_FileClose( H$4 );
				FBSTRING* vr$45 = fb_StrAllocTempDescZEx( (uint8*)"TEXT FILE BEEN ERASED", 21ll );
				fb_PrintString( 0, (FBSTRING*)vr$45, 1 );
				fb_Sleep( -1 );
			}
			label$34:;
		}
		label$33:;
		label$29:;
		fb_StrDelete( (FBSTRING*)&K$2 );
	}
	label$28:;
	goto label$26;
	label$27:;
	label$25:;
}

__attribute__(( constructor )) static void fb_ctor__comeback( void )
{
	label$0:;
	fb_GfxScreen( 19, 8, 0, 0, 0 );
	fb_ArrayRedimEx( (struct $7FBARRAYIvE*)&BUFFER$, 24ull, -1, -1, 1ull, 0ll, 0ll );
	MAIN(  );
	label$1:;
}

static const char __attribute__((used, section(".fbctinf"))) __fbctinf[] = "-l\0fb\0-gfx";
