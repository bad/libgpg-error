/* gpg-error.h - Public interface to libgpg-error.
   Copyright (C) 2003 g10 Code GmbH

   This file is part of libgpg-error.
 
   libgpg-error is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.
 
   libgpg-error is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
 
   You should have received a copy of the GNU Lesser General Public
   License along with libgpg-error; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  */

#ifndef GPG_ERROR_H
#define GPG_ERROR_H	1

#ifdef __GNUC__
#define GPG_ERR_INLINE __inline__
#elif __STDC_VERSION__ >= 199901L
#define GPG_ERR_INLINE inline
#else
#define GPG_ERR_INLINE
#endif

/* The GnuPG project consists of many components.  Error codes are
   exchanged between all components.  The common error codes and their
   user-presentable descriptions are kept into a shared library to
   allow adding new error codes and components without recompiling any
   of the other components.  The interface will not change in a
   backward incompatible way.

   An error code together with an error source build up an error
   value.  As the error value is been passed from one component to
   another, it preserver the information about the source and nature
   of the error.

   A component of the GnuPG project can define the following macro to
   tune the behaviour of the library:

   GPG_ERR_SOURCE_DEFAULT: Define to an error source of type
   gpg_err_source_t to make that source the default for gpg_error().
   Otherwise GPG_ERR_SOURCE_UNKNOWN is used as default.  */


/* The error source type gpg_err_source_t.

   Where as the Poo out of a welle small
   Taketh his firste springing and his sours.
					--Chaucer.  */

/* Only use free slots, never change or reorder the existing
   entries.  */
typedef enum
  {
    GPG_ERR_SOURCE_UNKNOWN = 0,
    GPG_ERR_SOURCE_GCRYPT = 1,
    GPG_ERR_SOURCE_GPG = 2,
    GPG_ERR_SOURCE_GPGSM = 3,
    GPG_ERR_SOURCE_GPGAGENT = 4,
    GPG_ERR_SOURCE_PINENTRY = 5,
    GPG_ERR_SOURCE_SCD = 6,
    GPG_ERR_SOURCE_GPGME = 7,
    GPG_ERR_SOURCE_KEYBOX = 8,

    /* 9 to 31 are free to be used.  */

    /* Free for use by non-GnuPG components.  */
    GPG_ERR_SOURCE_USER_1 = 32,
    GPG_ERR_SOURCE_USER_2 = 33,
    GPG_ERR_SOURCE_USER_3 = 34,
    GPG_ERR_SOURCE_USER_4 = 35,

    /* 36 to 255 are free to be used.  */

    /* This is one more than the largest allowed entry.  */
    GPG_ERR_SOURCE_DIM = 256
  } gpg_err_source_t;


/* The error code type gpg_err_code_t.  */

/* Only use free slots, never change or reorder the existing
   entries.  */
typedef enum
  {
    GPG_ERR_NO_ERROR = 0,		/* An error that is not an error.  */
    GPG_ERR_GENERAL = 1,
    GPG_ERR_UNKNOWN_PACKET = 2,
    GPG_ERR_UNKNOWN_VERSION = 3,	/* Unknown version (in packet).  */
    GPG_ERR_PUBKEY_ALGO	= 4,		/* Invalid public key algorithm.  */
    GPG_ERR_DIGEST_ALGO = 5,		/* Invalid digest algorithm.  */
    GPG_ERR_BAD_PUBKEY = 6,		/* Bad public key.  */
    GPG_ERR_BAD_SECKEY = 7,		/* Bad secret key.  */
    GPG_ERR_BAD_SIGNATURE = 8,		/* Bad signature.  */
    GPG_ERR_NO_PUBKEY = 9,		/* Public key not found.  */
    GPG_ERR_CHECKSUM = 10,		/* Checksum error.  */
    GPG_ERR_BAD_PASSPHRASE = 11,	/* Bad passphrase.  */
    GPG_ERR_CIPHER_ALGO = 12,		/* Invalid cipher algorithm.  */
    GPG_ERR_KEYRING_OPEN = 13,
    GPG_ERR_INV_PACKET = 14,
    GPG_ERR_INV_ARMOR = 15,
    GPG_ERR_NO_USER_ID = 16,
    GPG_ERR_NO_SECKEY = 17,		/* Secret key not available.  */
    GPG_ERR_WRONG_SECKEY = 18,		/* Wrong secret key used.  */
    GPG_ERR_BAD_KEY = 19,		/* Bad (session) key.  */
    GPG_ERR_COMPR_ALGO = 20,		/* Unknown compress algorithm.  */
    GPG_ERR_NO_PRIME = 21,	        /* Number is not prime.  */

    /* Codes 22 to 29 are free to be used.  */

    GPG_ERR_BAD_MPI = 30,		/* Problem with an MPI's value.  */
    GPG_ERR_INV_PASSPHRASE = 31,	/* Invalid passphrase.  */
    GPG_ERR_SIG_CLASS = 32,
    GPG_ERR_RESOURCE_LIMIT = 33,
    GPG_ERR_INV_KEYRING = 34,
    GPG_ERR_TRUSTDB = 35,		/* A problem with the trustdb.  */
    GPG_ERR_BAD_CERT = 36,		/* Bad certificate.  */
    GPG_ERR_INV_USER_ID = 37,
    GPG_ERR_UNEXPECTED = 38,
    GPG_ERR_TIME_CONFLICT = 39,
    GPG_ERR_KEYSERVER = 40,
    GPG_ERR_WRONG_PUBKEY_ALGO = 41,	/* Wrong public key algorithm.  */
    GPG_ERR_TRIBUTE_TO_D_A = 42,
    GPG_ERR_WEAK_KEY = 43,		/* Weak encryption key.  */
    GPG_ERR_INV_KEYLEN = 44,		/* Invalid length of a key.  */
    GPG_ERR_INV_ARG = 45,		/* Invalid argument.  */
    GPG_ERR_BAD_URI = 46,		/* Syntax error in URI.  */
    GPG_ERR_INV_URI = 47,		/* Unsupported scheme and similar.  */
    GPG_ERR_NETWORK = 48,		/* General network error.  */
    GPG_ERR_UNKNOWN_HOST = 49,
    GPG_ERR_SELFTEST_FAILED = 50,
    GPG_ERR_NOT_ENCRYPTED = 51,
    GPG_ERR_NOT_PROCESSED = 52,
    GPG_ERR_UNUSABLE_PUBKEY = 53,
    GPG_ERR_UNUSABLE_SECKEY = 54,
    GPG_ERR_INV_VALUE = 55,
    GPG_ERR_BAD_CERT_CHAIN = 56,
    GPG_ERR_MISSING_CERT = 57,
    GPG_ERR_NO_DATA = 58,
    GPG_ERR_BUG = 59,
    GPG_ERR_NOT_SUPPORTED = 60,
    GPG_ERR_INV_OP = 61,		/* Invalid operation code.  */
    GPG_ERR_TIMEOUT = 62,               /* Something timed out. */
    GPG_ERR_INTERNAL = 63,		/* Internal error.  */
    GPG_ERR_EOF_GCRYPT = 64,		/* Compatibility for gcrypt.  */
    GPG_ERR_INV_OBJ = 65,		/* An object is not valid.  */
    GPG_ERR_TOO_SHORT = 66,		/* Provided object is too short.  */
    GPG_ERR_TOO_LARGE = 67,		/* Provided object is too large.  */
    GPG_ERR_NO_OBJ = 68,		/* Missing item in an object.  */
    GPG_ERR_NOT_IMPLEMENTED = 69,	/* Not implemented.  */
    GPG_ERR_CONFLICT = 70,		/* Conflicting use.  */
    GPG_ERR_INV_CIPHER_MODE = 71,	/* Invalid cipher mode.  */ 
    GPG_ERR_INV_FLAG = 72,		/* Invalid flag.  */
    GPG_ERR_INV_HANDLE = 73,            /* Invalid handle.  */

    /* Code 74 is free to be used.  */

    GPG_ERR_INCOMPLETE_LINE = 75,
    GPG_ERR_INV_RESPONSE = 76,
    GPG_ERR_NO_AGENT = 77,
    GPG_ERR_AGENT = 78,
    GPG_ERR_INV_DATA = 79,
    GPG_ERR_ASSUAN_SERVER_FAULT = 80,
    GPG_ERR_ASSUAN = 81,		/* Catch all assuan error.  */
    GPG_ERR_INV_SESSION_KEY = 82,
    GPG_ERR_INV_SEXP = 83,
    GPG_ERR_UNSUPPORTED_ALGORITHM = 84,
    GPG_ERR_NO_PIN_ENTRY = 85,
    GPG_ERR_PIN_ENTRY = 86,
    GPG_ERR_BAD_PIN = 87,
    GPG_ERR_INV_NAME = 88,
    GPG_ERR_BAD_DATA = 89,
    GPG_ERR_INV_PARAMETER = 90,

    GPG_ERR_WRONG_CARD = 91, 
    
    GPG_ERR_NO_DIRMNGR = 92,
    GPG_ERR_DIRMNGR = 93,
    GPG_ERR_CERT_REVOKED = 94,
    GPG_ERR_NO_CRL_KNOWN = 95,
    GPG_ERR_CRL_TOO_OLD = 96,
    GPG_ERR_LINE_TOO_LONG = 97,
    GPG_ERR_NOT_TRUSTED = 98,
    GPG_ERR_CANCELED = 99,
    GPG_ERR_BAD_CA_CERT = 100,
    GPG_ERR_CERT_EXPIRED = 101,		/* Key signature expired.  */
    GPG_ERR_CERT_TOO_YOUNG = 102,
    GPG_ERR_UNSUPPORTED_CERT = 103,
    GPG_ERR_UNKNOWN_SEXP = 104,
    GPG_ERR_UNSUPPORTED_PROTECTION = 105,
    GPG_ERR_CORRUPTED_PROTECTION = 106,
    GPG_ERR_AMBIGUOUS_NAME = 107,
    GPG_ERR_CARD = 108,
    GPG_ERR_CARD_RESET = 109,
    GPG_ERR_CARD_REMOVED = 110,
    GPG_ERR_INV_CARD = 111,
    GPG_ERR_CARD_NOT_PRESENT = 112,
    GPG_ERR_NO_PKCS15_APP = 113,
    GPG_ERR_NOT_CONFIRMED = 114,
    GPG_ERR_CONFIGURATION = 115,
    GPG_ERR_NO_POLICY_MATCH = 116,
    GPG_ERR_INV_INDEX = 117,
    GPG_ERR_INV_ID = 118,
    GPG_ERR_NO_SCDAEMON = 119,
    GPG_ERR_SCDAEMON = 120,
    GPG_ERR_UNSUPPORTED_PROTOCOL = 121,
    GPG_ERR_BAD_PIN_METHOD = 122,
    GPG_ERR_CARD_NOT_INITIALIZED = 123,
    GPG_ERR_UNSUPPORTED_OPERATION = 124,
    GPG_ERR_WRONG_KEY_USAGE = 125,
    GPG_ERR_NOTHING_FOUND = 126,        /* Operation failed due to an
                                           unsuccessful find operation.  */
    GPG_ERR_WRONG_BLOB_TYPE = 127,      /* Keybox BLOB of wrong type.  */
    GPG_ERR_MISSING_VALUE = 128,        /* A required value is missing.  */

    GPG_ERR_HARDWARE = 129,             /* e.g. EEPROM error of a smartcard. */
    GPG_ERR_PIN_BLOCKED = 130,
    GPG_ERR_USE_CONDITIONS = 131,       /* e.g. used with smartcards. */
    /* 132 to 149 are free to be used.   */

    GPG_ERR_INV_ENGINE = 150,
    GPG_ERR_PUBKEY_NOT_TRUSTED = 151,
    GPG_ERR_DECRYPT_FAILED = 152,
    GPG_ERR_KEY_EXPIRED = 153,
    GPG_ERR_SIG_EXPIRED = 154,		/* Data signature expired.  */

    /* 155 to 200 are free to be used.  */

    /* Error codes pertaining to S-expressions.  */
    GPG_ERR_SEXP_INV_LEN_SPEC = 201,
    GPG_ERR_SEXP_STRING_TOO_LONG = 202,
    GPG_ERR_SEXP_UNMATCHED_PAREN = 203, 
    GPG_ERR_SEXP_NOT_CANONICAL = 204, 
    GPG_ERR_SEXP_BAD_CHARACTER = 205, 
    GPG_ERR_SEXP_BAD_QUOTATION = 206,	/* Or invalid hex or octal value.  */
    GPG_ERR_SEXP_ZERO_PREFIX = 207,	/* First character of length is 0.  */
    GPG_ERR_SEXP_NESTED_DH = 208,	/* Nested display hints.  */
    GPG_ERR_SEXP_UNMATCHED_DH = 209,	/* Unmatched display hint.  */
    GPG_ERR_SEXP_UNEXPECTED_PUNC = 210,	/* Unexpected reserved punctuation. */
    GPG_ERR_SEXP_BAD_HEX_CHAR = 211,
    GPG_ERR_SEXP_ODD_HEX_NUMBERS = 212,
    GPG_ERR_SEXP_BAD_OCT_CHAR = 213,

    /* 213 to 1023 are free to be used.  */

    /* For free use by non-GnuPG components.  */
    GPG_ERR_USER_1 = 1024,
    GPG_ERR_USER_2 = 1025,
    GPG_ERR_USER_3 = 1026,
    GPG_ERR_USER_4 = 1027,
    GPG_ERR_USER_5 = 1028,
    GPG_ERR_USER_6 = 1029,
    GPG_ERR_USER_7 = 1030,
    GPG_ERR_USER_8 = 1031,
    GPG_ERR_USER_9 = 1032,
    GPG_ERR_USER_10 = 1033,
    GPG_ERR_USER_11 = 1034,
    GPG_ERR_USER_12 = 1035,
    GPG_ERR_USER_13 = 1036,
    GPG_ERR_USER_14 = 1037,
    GPG_ERR_USER_15 = 1038,
    GPG_ERR_USER_16 = 1039,

    /* 1040 to 16381 are free to be used.  */

    GPG_ERR_UNKNOWN_ERRNO = 16382,
    GPG_ERR_EOF = 16383,		/* This was once a -1.  Pity.  */

    /* 16384 - 32767 are reserved for future extensions.  */

    /* The following error codes are used to map system errors.  */
#define GPG_ERR_SYSTEM_ERROR	(1 << 15)
    GPG_ERR_E2BIG = GPG_ERR_SYSTEM_ERROR | 0,
    GPG_ERR_EACCES = GPG_ERR_SYSTEM_ERROR | 1,
    GPG_ERR_EADDRINUSE = GPG_ERR_SYSTEM_ERROR | 2,
    GPG_ERR_EADDRNOTAVAIL = GPG_ERR_SYSTEM_ERROR | 3,
    GPG_ERR_EADV = GPG_ERR_SYSTEM_ERROR | 4,
    GPG_ERR_EAFNOSUPPORT = GPG_ERR_SYSTEM_ERROR | 5,
    GPG_ERR_EAGAIN = GPG_ERR_SYSTEM_ERROR | 6,
    GPG_ERR_EALREADY = GPG_ERR_SYSTEM_ERROR | 7,
    GPG_ERR_EAUTH = GPG_ERR_SYSTEM_ERROR | 8,
    GPG_ERR_EBACKGROUND = GPG_ERR_SYSTEM_ERROR | 9,
    GPG_ERR_EBADE = GPG_ERR_SYSTEM_ERROR | 10,
    GPG_ERR_EBADF = GPG_ERR_SYSTEM_ERROR | 11,
    GPG_ERR_EBADFD = GPG_ERR_SYSTEM_ERROR | 12,
    GPG_ERR_EBADMSG = GPG_ERR_SYSTEM_ERROR | 13,
    GPG_ERR_EBADR = GPG_ERR_SYSTEM_ERROR | 14,
    GPG_ERR_EBADRPC = GPG_ERR_SYSTEM_ERROR | 15,
    GPG_ERR_EBADRQC = GPG_ERR_SYSTEM_ERROR | 16,
    GPG_ERR_EBADSLT = GPG_ERR_SYSTEM_ERROR | 17,
    GPG_ERR_EBFONT = GPG_ERR_SYSTEM_ERROR | 18,
    GPG_ERR_EBUSY = GPG_ERR_SYSTEM_ERROR | 19,
    GPG_ERR_ECANCELED = GPG_ERR_SYSTEM_ERROR | 20,
    GPG_ERR_ECHILD = GPG_ERR_SYSTEM_ERROR | 21,
    GPG_ERR_ECHRNG = GPG_ERR_SYSTEM_ERROR | 22,
    GPG_ERR_ECOMM = GPG_ERR_SYSTEM_ERROR | 23,
    GPG_ERR_ECONNABORTED = GPG_ERR_SYSTEM_ERROR | 24,
    GPG_ERR_ECONNREFUSED = GPG_ERR_SYSTEM_ERROR | 25,
    GPG_ERR_ECONNRESET = GPG_ERR_SYSTEM_ERROR | 26,
    GPG_ERR_ED = GPG_ERR_SYSTEM_ERROR | 27,
    GPG_ERR_EDEADLK = GPG_ERR_SYSTEM_ERROR | 28,
    GPG_ERR_EDEADLOCK = GPG_ERR_SYSTEM_ERROR | 29,
    GPG_ERR_EDESTADDRREQ = GPG_ERR_SYSTEM_ERROR | 30,
    GPG_ERR_EDIED = GPG_ERR_SYSTEM_ERROR | 31,
    GPG_ERR_EDOM = GPG_ERR_SYSTEM_ERROR | 32,
    GPG_ERR_EDOTDOT = GPG_ERR_SYSTEM_ERROR | 33,
    GPG_ERR_EDQUOT = GPG_ERR_SYSTEM_ERROR | 34,
    GPG_ERR_EEXIST = GPG_ERR_SYSTEM_ERROR | 35,
    GPG_ERR_EFAULT = GPG_ERR_SYSTEM_ERROR | 36,
    GPG_ERR_EFBIG = GPG_ERR_SYSTEM_ERROR | 37,
    GPG_ERR_EFTYPE = GPG_ERR_SYSTEM_ERROR | 38,
    GPG_ERR_EGRATUITOUS = GPG_ERR_SYSTEM_ERROR | 39,
    GPG_ERR_EGREGIOUS = GPG_ERR_SYSTEM_ERROR | 40,
    GPG_ERR_EHOSTDOWN = GPG_ERR_SYSTEM_ERROR | 41,
    GPG_ERR_EHOSTUNREACH = GPG_ERR_SYSTEM_ERROR | 42,
    GPG_ERR_EIDRM = GPG_ERR_SYSTEM_ERROR | 43,
    GPG_ERR_EIEIO = GPG_ERR_SYSTEM_ERROR | 44,
    GPG_ERR_EILSEQ = GPG_ERR_SYSTEM_ERROR | 45,
    GPG_ERR_EINPROGRESS = GPG_ERR_SYSTEM_ERROR | 46,
    GPG_ERR_EINTR = GPG_ERR_SYSTEM_ERROR | 47,
    GPG_ERR_EINVAL = GPG_ERR_SYSTEM_ERROR | 48,
    GPG_ERR_EIO = GPG_ERR_SYSTEM_ERROR | 49,
    GPG_ERR_EISCONN = GPG_ERR_SYSTEM_ERROR | 50,
    GPG_ERR_EISDIR = GPG_ERR_SYSTEM_ERROR | 51,
    GPG_ERR_EISNAM = GPG_ERR_SYSTEM_ERROR | 52,
    GPG_ERR_EL2HLT = GPG_ERR_SYSTEM_ERROR | 53,
    GPG_ERR_EL2NSYNC = GPG_ERR_SYSTEM_ERROR | 54,
    GPG_ERR_EL3HLT = GPG_ERR_SYSTEM_ERROR | 55,
    GPG_ERR_EL3RST = GPG_ERR_SYSTEM_ERROR | 56,
    GPG_ERR_ELIBACC = GPG_ERR_SYSTEM_ERROR | 57,
    GPG_ERR_ELIBBAD = GPG_ERR_SYSTEM_ERROR | 58,
    GPG_ERR_ELIBEXEC = GPG_ERR_SYSTEM_ERROR | 59,
    GPG_ERR_ELIBMAX = GPG_ERR_SYSTEM_ERROR | 60,
    GPG_ERR_ELIBSCN = GPG_ERR_SYSTEM_ERROR | 61,
    GPG_ERR_ELNRNG = GPG_ERR_SYSTEM_ERROR | 62,
    GPG_ERR_ELOOP = GPG_ERR_SYSTEM_ERROR | 63,
    GPG_ERR_EMEDIUMTYPE = GPG_ERR_SYSTEM_ERROR | 64,
    GPG_ERR_EMFILE = GPG_ERR_SYSTEM_ERROR | 65,
    GPG_ERR_EMLINK = GPG_ERR_SYSTEM_ERROR | 66,
    GPG_ERR_EMSGSIZE = GPG_ERR_SYSTEM_ERROR | 67,
    GPG_ERR_EMULTIHOP = GPG_ERR_SYSTEM_ERROR | 68,
    GPG_ERR_ENAMETOOLONG = GPG_ERR_SYSTEM_ERROR | 69,
    GPG_ERR_ENAVAIL = GPG_ERR_SYSTEM_ERROR | 70,
    GPG_ERR_ENEEDAUTH = GPG_ERR_SYSTEM_ERROR | 71,
    GPG_ERR_ENETDOWN = GPG_ERR_SYSTEM_ERROR | 72,
    GPG_ERR_ENETRESET = GPG_ERR_SYSTEM_ERROR | 73,
    GPG_ERR_ENETUNREACH = GPG_ERR_SYSTEM_ERROR | 74,
    GPG_ERR_ENFILE = GPG_ERR_SYSTEM_ERROR | 75,
    GPG_ERR_ENOANO = GPG_ERR_SYSTEM_ERROR | 76,
    GPG_ERR_ENOBUFS = GPG_ERR_SYSTEM_ERROR | 77,
    GPG_ERR_ENOCSI = GPG_ERR_SYSTEM_ERROR | 78,
    GPG_ERR_ENODATA = GPG_ERR_SYSTEM_ERROR | 79,
    GPG_ERR_ENODEV = GPG_ERR_SYSTEM_ERROR | 80,
    GPG_ERR_ENOENT = GPG_ERR_SYSTEM_ERROR | 81,
    GPG_ERR_ENOEXEC = GPG_ERR_SYSTEM_ERROR | 82,
    GPG_ERR_ENOLCK = GPG_ERR_SYSTEM_ERROR | 83,
    GPG_ERR_ENOLINK = GPG_ERR_SYSTEM_ERROR | 84,
    GPG_ERR_ENOMEDIUM = GPG_ERR_SYSTEM_ERROR | 85,
    GPG_ERR_ENOMEM = GPG_ERR_SYSTEM_ERROR | 86,
    GPG_ERR_ENOMSG = GPG_ERR_SYSTEM_ERROR | 87,
    GPG_ERR_ENONET = GPG_ERR_SYSTEM_ERROR | 88,
    GPG_ERR_ENOPKG = GPG_ERR_SYSTEM_ERROR | 89,
    GPG_ERR_ENOPROTOOPT = GPG_ERR_SYSTEM_ERROR | 90,
    GPG_ERR_ENOSPC = GPG_ERR_SYSTEM_ERROR | 91,
    GPG_ERR_ENOSR = GPG_ERR_SYSTEM_ERROR | 92,
    GPG_ERR_ENOSTR = GPG_ERR_SYSTEM_ERROR | 93,
    GPG_ERR_ENOSYS = GPG_ERR_SYSTEM_ERROR | 94,
    GPG_ERR_ENOTBLK = GPG_ERR_SYSTEM_ERROR | 95,
    GPG_ERR_ENOTCONN = GPG_ERR_SYSTEM_ERROR | 96,
    GPG_ERR_ENOTDIR = GPG_ERR_SYSTEM_ERROR | 97,
    GPG_ERR_ENOTEMPTY = GPG_ERR_SYSTEM_ERROR | 98,
    GPG_ERR_ENOTNAM = GPG_ERR_SYSTEM_ERROR | 99,
    GPG_ERR_ENOTSOCK = GPG_ERR_SYSTEM_ERROR | 100,
    GPG_ERR_ENOTSUP = GPG_ERR_SYSTEM_ERROR | 101,
    GPG_ERR_ENOTTY = GPG_ERR_SYSTEM_ERROR | 102,
    GPG_ERR_ENOTUNIQ = GPG_ERR_SYSTEM_ERROR | 103,
    GPG_ERR_ENXIO = GPG_ERR_SYSTEM_ERROR | 104,
    GPG_ERR_EOPNOTSUPP = GPG_ERR_SYSTEM_ERROR | 105,
    GPG_ERR_EOVERFLOW = GPG_ERR_SYSTEM_ERROR | 106,
    GPG_ERR_EPERM = GPG_ERR_SYSTEM_ERROR | 107,
    GPG_ERR_EPFNOSUPPORT = GPG_ERR_SYSTEM_ERROR | 108,
    GPG_ERR_EPIPE = GPG_ERR_SYSTEM_ERROR | 109,
    GPG_ERR_EPROCLIM = GPG_ERR_SYSTEM_ERROR | 110,
    GPG_ERR_EPROCUNAVAIL = GPG_ERR_SYSTEM_ERROR | 111,
    GPG_ERR_EPROGMISMATCH = GPG_ERR_SYSTEM_ERROR | 112,
    GPG_ERR_EPROGUNAVAIL = GPG_ERR_SYSTEM_ERROR | 113,
    GPG_ERR_EPROTO = GPG_ERR_SYSTEM_ERROR | 114,
    GPG_ERR_EPROTONOSUPPORT = GPG_ERR_SYSTEM_ERROR | 115,
    GPG_ERR_EPROTOTYPE = GPG_ERR_SYSTEM_ERROR | 116,
    GPG_ERR_ERANGE = GPG_ERR_SYSTEM_ERROR | 117,
    GPG_ERR_EREMCHG = GPG_ERR_SYSTEM_ERROR | 118,
    GPG_ERR_EREMOTE = GPG_ERR_SYSTEM_ERROR | 119,
    GPG_ERR_EREMOTEIO = GPG_ERR_SYSTEM_ERROR | 120,
    GPG_ERR_ERESTART = GPG_ERR_SYSTEM_ERROR | 121,
    GPG_ERR_EROFS = GPG_ERR_SYSTEM_ERROR | 122,
    GPG_ERR_ERPCMISMATCH = GPG_ERR_SYSTEM_ERROR | 123,
    GPG_ERR_ESHUTDOWN = GPG_ERR_SYSTEM_ERROR | 124,
    GPG_ERR_ESOCKTNOSUPPORT = GPG_ERR_SYSTEM_ERROR | 125,
    GPG_ERR_ESPIPE = GPG_ERR_SYSTEM_ERROR | 126,
    GPG_ERR_ESRCH = GPG_ERR_SYSTEM_ERROR | 127,
    GPG_ERR_ESRMNT = GPG_ERR_SYSTEM_ERROR | 128,
    GPG_ERR_ESTALE = GPG_ERR_SYSTEM_ERROR | 129,
    GPG_ERR_ESTRPIPE = GPG_ERR_SYSTEM_ERROR | 130,
    GPG_ERR_ETIME = GPG_ERR_SYSTEM_ERROR | 131,
    GPG_ERR_ETIMEDOUT = GPG_ERR_SYSTEM_ERROR | 132,
    GPG_ERR_ETOOMANYREFS = GPG_ERR_SYSTEM_ERROR | 133,
    GPG_ERR_ETXTBSY = GPG_ERR_SYSTEM_ERROR | 134,
    GPG_ERR_EUCLEAN = GPG_ERR_SYSTEM_ERROR | 135,
    GPG_ERR_EUNATCH = GPG_ERR_SYSTEM_ERROR | 136,
    GPG_ERR_EUSERS = GPG_ERR_SYSTEM_ERROR | 137,
    GPG_ERR_EWOULDBLOCK = GPG_ERR_SYSTEM_ERROR | 138,
    GPG_ERR_EXDEV = GPG_ERR_SYSTEM_ERROR | 139,
    GPG_ERR_EXFULL = GPG_ERR_SYSTEM_ERROR | 140,

    /* GPG_SYSTEM_ERROR | (141 to 32767) are free to be used for more
       system errors.  */

    /* This is one more than the largest allowed entry.  */
    GPG_ERR_CODE_DIM = 65536
  } gpg_err_code_t;


/* The error value type gpg_error_t.  */

/* We would really like to use bit-fields in a struct, but using
   structs as return values can cause binary compatibility issues, in
   particular if you want to do it effeciently (also see
   -freg-struct-return option to GCC).  */
typedef unsigned int gpg_error_t;

/* We use the lowest 16 bits of gpg_error_t for error codes.  The 16th
   bit indicates system errors.  */
#define GPG_ERR_CODE_MASK	(GPG_ERR_CODE_DIM - 1)

/* Bits 17 to 24 are reserved.  */

/* We use the upper 8 bits of gpg_error_t for error sources.  */
#define GPG_ERR_SOURCE_MASK	(GPG_ERR_SOURCE_DIM - 1)
#define GPG_ERR_SOURCE_SHIFT	24


/* Constructor and accessor functions.  */

/* Construct an error value from an error code and source.  Within a
   subsystem, use gpg_error.  */
static GPG_ERR_INLINE gpg_error_t
gpg_err_make (gpg_err_source_t source, gpg_err_code_t code)
{
  return code == GPG_ERR_NO_ERROR ? GPG_ERR_NO_ERROR
    : (((source & GPG_ERR_SOURCE_MASK) << GPG_ERR_SOURCE_SHIFT)
       | (code & GPG_ERR_CODE_MASK));
}


/* The user should define GPG_ERR_SOURCE_DEFAULT before including this
   file to specify a default source for gpg_error.  */
#ifndef GPG_ERR_SOURCE_DEFAULT
#define GPG_ERR_SOURCE_DEFAULT	GPG_ERR_SOURCE_UNKNOWN
#endif

static GPG_ERR_INLINE gpg_error_t
gpg_error (gpg_err_code_t code)
{
  return gpg_err_make (GPG_ERR_SOURCE_DEFAULT, code);
}


/* Retrieve the error code from an error value.  */
static GPG_ERR_INLINE gpg_err_code_t
gpg_err_code (gpg_error_t err)
{
  return (gpg_err_code_t) (err & GPG_ERR_CODE_MASK);
}


/* Retrieve the error source from an error value.  */
static GPG_ERR_INLINE gpg_err_source_t
gpg_err_source (gpg_error_t err)
{
  return (gpg_err_source_t) ((err >> GPG_ERR_SOURCE_SHIFT)
			     & GPG_ERR_SOURCE_MASK);
}


/* String functions.  */

/* Return a pointer to a string containing a description of the error
   code in the error value ERR.  */
const char *gpg_strerror (gpg_error_t err);

/* Return a pointer to a string containing a description of the error
   source in the error value ERR.  */
const char *gpg_strsource (gpg_error_t err);


/* Mapping of system errors (errno).  */

/* Retrieve the error code for the system error ERR.  This returns
   GPG_ERR_UNKNOWN_ERRNO if the system error is not mapped (report
   this).  */
gpg_err_code_t gpg_err_code_from_errno (int err);


/* Retrieve the system error for the error code CODE.  This returns 0
   if CODE is not a system error code.  */
int gpg_err_code_to_errno (gpg_err_code_t code);


/* Self-documenting convenience functions.  */

static GPG_ERR_INLINE gpg_error_t
gpg_err_make_from_errno (gpg_err_source_t source, int err)
{
  return gpg_err_make (source, gpg_err_code_from_errno (err));
}


static GPG_ERR_INLINE gpg_error_t
gpg_error_from_errno (int err)
{
  return gpg_error (gpg_err_code_from_errno (err));
}

#endif	/* GPG_ERROR_H */