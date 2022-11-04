/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OBERROR_OS_ERRNO_H
#define OBERROR_OS_ERRNO_H

// linux
#include <errno.h>

namespace oceanbase {
namespace common {

// The length of the second dimension, in order to solve the conflict of multiple identical error codes
constexpr int OS_MAX_SAME_ERROR_COUNT = 2;

constexpr int OS_MAX_ERROR_CODE = 135;
constexpr int OS_ENOENT = -2;
constexpr int OS_ESRCH = -3;
constexpr int OS_EINTR = -4;
constexpr int OS_EIO = -5;
constexpr int OS_ENXIO = -6;
constexpr int OS_E2BIG = -7;
constexpr int OS_ENOEXEC = -8;
constexpr int OS_EBADF = -9;
constexpr int OS_ECHILD = -10;
constexpr int OS_EAGAIN = -11;
constexpr int OS_ENOMEM = -12;
constexpr int OS_EACCES = -13;
constexpr int OS_EFAULT = -14;
constexpr int OS_ENOTBLK = -15;
constexpr int OS_EBUSY = -16;
constexpr int OS_EEXIST = -17;
constexpr int OS_EXDEV = -18;
constexpr int OS_ENODEV = -19;
constexpr int OS_ENOTDIR = -20;
constexpr int OS_EISDIR = -21;
constexpr int OS_EINVAL = -22;
constexpr int OS_ENFILE = -23;
constexpr int OS_EMFILE = -24;
constexpr int OS_ENOTTY = -25;
constexpr int OS_ETXTBSY = -26;
constexpr int OS_EFBIG = -27;
constexpr int OS_ENOSPC = -28;
constexpr int OS_ESPIPE = -29;
constexpr int OS_EROFS = -30;
constexpr int OS_EMLINK = -31;
constexpr int OS_EPIPE = -32;
constexpr int OS_EDOM = -33;
constexpr int OS_ERANGE = -34;
constexpr int OS_EDEADLK = -35;
constexpr int OS_ENAMETOOLONG = -36;
constexpr int OS_ENOLCK = -37;
constexpr int OS_ENOSYS = -38;
constexpr int OS_ENOTEMPTY = -39;
constexpr int OS_ELOOP = -40;
constexpr int OS_EWOULDBLOCK = -41;
constexpr int OS_ENOMSG = -42;
constexpr int OS_EIDRM = -43;
constexpr int OS_ECHRNG = -44;
constexpr int OS_EL2NSYNC = -45;
constexpr int OS_EL3HLT = -46;
constexpr int OS_EL3RST = -47;
constexpr int OS_ELNRNG = -48;
constexpr int OS_EUNATCH = -49;
constexpr int OS_ENOCSI = -50;
constexpr int OS_EL2HLT = -51;
constexpr int OS_EBADE = -52;
constexpr int OS_EBADR = -53;
constexpr int OS_EXFULL = -54;
constexpr int OS_ENOANO = -55;
constexpr int OS_EBADRQC = -56;
constexpr int OS_EBADSLT = -57;
constexpr int OS_EBFONT = -59;
constexpr int OS_ENOSTR = -60;
constexpr int OS_ENODATA = -61;
constexpr int OS_ETIME = -62;
constexpr int OS_ENOSR = -63;
constexpr int OS_ENONET = -64;
constexpr int OS_ENOPKG = -65;
constexpr int OS_EREMOTE = -66;
constexpr int OS_ENOLINK = -67;
constexpr int OS_EADV = -68;
constexpr int OS_ESRMNT = -69;
constexpr int OS_ECOMM = -70;
constexpr int OS_EPROTO = -71;
constexpr int OS_EMULTIHOP = -72;
constexpr int OS_EDOTDOT = -73;
constexpr int OS_EBADMSG = -74;
constexpr int OS_EOVERFLOW = -75;
constexpr int OS_ENOTUNIQ = -76;
constexpr int OS_EBADFD = -77;
constexpr int OS_EREMCHG = -78;
constexpr int OS_ELIBACC = -79;
constexpr int OS_ELIBBAD = -80;
constexpr int OS_ELIBSCN = -81;
constexpr int OS_ELIBMAX = -82;
constexpr int OS_ELIBEXEC = -83;
constexpr int OS_EILSEQ = -84;
constexpr int OS_ERESTART = -85;
constexpr int OS_ESTRPIPE = -86;
constexpr int OS_EUSERS = -87;
constexpr int OS_ENOTSOCK = -88;
constexpr int OS_EDESTADDRREQ = -89;
constexpr int OS_EMSGSIZE = -90;
constexpr int OS_EPROTOTYPE = -91;
constexpr int OS_ENOPROTOOPT = -92;
constexpr int OS_EPROTONOSUPPORT = -93;
constexpr int OS_ESOCKTNOSUPPORT = -94;
constexpr int OS_EOPNOTSUPP = -95;
constexpr int OS_EPFNOSUPPORT = -96;
constexpr int OS_EAFNOSUPPORT = -97;
constexpr int OS_EADDRINUSE = -98;
constexpr int OS_EADDRNOTAVAIL = -99;
constexpr int OS_ENETDOWN = -100;
constexpr int OS_ENETUNREACH = -101;
constexpr int OS_ENETRESET = -102;
constexpr int OS_ECONNABORTED = -103;
constexpr int OS_ECONNRESET = -104;
constexpr int OS_ENOBUFS = -105;
constexpr int OS_EISCONN = -106;
constexpr int OS_ENOTCONN = -107;
constexpr int OS_ESHUTDOWN = -108;
constexpr int OS_ETOOMANYREFS = -109;
constexpr int OS_ETIMEDOUT = -110;
constexpr int OS_ECONNREFUSED = -111;
constexpr int OS_EHOSTDOWN = -112;
constexpr int OS_EHOSTUNREACH = -113;
constexpr int OS_EALREADY = -114;
constexpr int OS_EINPROGRESS = -115;
constexpr int OS_ESTALE = -116;
constexpr int OS_EUCLEAN = -117;
constexpr int OS_ENOTNAM = -118;
constexpr int OS_ENAVAIL = -119;
constexpr int OS_EISNAM = -120;
constexpr int OS_EREMOTEIO = -121;
constexpr int OS_EDQUOT = -122;
constexpr int OS_ENOMEDIUM = -123;
constexpr int OS_EMEDIUMTYPE = -124;
constexpr int OS_ECANCELED = -125;
constexpr int OS_ENOKEY = -126;
constexpr int OS_EKEYEXPIRED = -127;
constexpr int OS_EKEYREVOKED = -128;
constexpr int OS_EKEYREJECTED = -129;
constexpr int OS_EOWNERDEAD = -130;
constexpr int OS_ENOTRECOVERABLE = -131;
constexpr int OS_ERFKILL = -132;
constexpr int OS_EHWPOISON = -133;

const char* str_os_error_name(const int err);
const char* str_os_error_msg(const int err);
int os_errno(const int err);
}  // end namespace common
}  // end namespace oceanbase

#endif /* OBERROR_OS_ERRNO_H */
