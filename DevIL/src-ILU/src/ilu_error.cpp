//-----------------------------------------------------------------------------
//
// ImageLib Utility Sources
// Simplified English-only error system
//
//-----------------------------------------------------------------------------

#include "ilu_internal.h"
#include "ilu_error/ilu_err-english.h"

ILconst_string *iluErrors = iluErrorStringsEnglish;
ILconst_string *iluLibErrors = iluLibErrorStringsEnglish;
ILconst_string *iluMiscErrors = iluMiscErrorStringsEnglish;

ILconst_string ILAPIENTRY iluErrorString(ILenum Error)
{
	if (Error == IL_NO_ERROR) {
		return iluMiscErrors[0];
	}

	if (Error == IL_UNKNOWN_ERROR) {
		return iluMiscErrors[1];
	}

	if (Error >= IL_INVALID_ENUM && Error <= IL_FILE_READ_ERROR) {
		return (ILstring)iluErrors[Error - IL_INVALID_ENUM];
	}

	if (Error >= IL_LIB_GIF_ERROR && Error <= IL_LIB_EXR_ERROR) {
		return (ILstring)iluLibErrors[Error - IL_LIB_GIF_ERROR];
	}

	return iluMiscErrors[0];
}

ILboolean ILAPIENTRY iluSetLanguage(ILenum Language)
{
	// English only
	iluErrors = iluErrorStringsEnglish;
	iluLibErrors = iluLibErrorStringsEnglish;
	iluMiscErrors = iluMiscErrorStringsEnglish;

	return IL_TRUE;
}