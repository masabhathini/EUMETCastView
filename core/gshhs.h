/*	$Id: gshhs.h,v 1.33 2011/03/03 21:02:51 guru Exp $
 *
 * Include file defining structures used in gshhs.c
 *
 * Paul Wessel, SOEST
 *
 *	Copyright (c) 1996-2011 by P. Wessel and W. H. F. Smith
 *	See LICENSE.TXT file for copying and redistribution conditions.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; version 2 or any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	Contact info: www.soest.hawaii.edu/pwessel
 *
 *	14-SEP-2004.  PW: Version 1.3.  Header is now n * 8 bytes (n = 5)
 *			  For use with version 1.3 of GSHHS
 *	2-MAY-2006.  PW: Version 1.4.  Header is now 32 bytes (all int 4)
 *			  For use with version 1.4 of GSHHS
 *	31-MAR-2007.  PW: Version 1.5.  no format change
 *			  For use with version 1.5 of GSHHS
 *	28-AUG-2007.  PW: Version 1.6.  no format change
 *			  For use with version 1.6 of GSHHS which now has WDBII
 *			  borders and rivers.
 *	03-JUL-2008.  PW: Version 1.11. New -I<id> option to pull out a single pol
 *	27-MAY-2009.  PW: Version 1.12. Now includes container polygon ID in header,
 *			  an ancestor ID, and area of the reduced polygon. Works on
 *			  GSHHS 2.0 data.
 *			  Header is now 44 bytes (all 4-byte integers)
 *	24-MAY-2010.  PW: Data version is now 2.1.0. [no change to format]
 */

#ifndef _GSHHS
#define _GSHHS
#define _POSIX_SOURCE 1		/* GSHHS code is POSIX compliant */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#ifndef M_PI
#define M_PI          3.14159265358979323846
#endif

#ifndef SEEK_CUR	/* For really ancient systems */
#define SEEK_CUR 1
#endif

#define GSHHS_DATA_RELEASE	8	/* For v2.1.0 data set */
#define GSHHS_DATA_VERSION	"2.1.0"	/* For v2.1.0 data set */
#define GSHHS_PROG_VERSION	"1.12"

#define GSHHS_SCL	1.0e-6	/* Convert micro-degrees to degrees */

/* For byte swapping on little-endian systems (GSHHS is defined to be bigendian) */

#define swabi4(i4) (((i4) >> 24) + (((i4) >> 8) & 65280) + (((i4) & 65280) << 8) + (((i4) & 255) << 24))

struct GSHHS {	/* Global Self-consistent Hierarchical High-resolution Shorelines */
	int id;		/* Unique polygon id number, starting at 0 */
	int n;		/* Number of points in this polygon */
	int flag;	/* = level + version << 8 + greenwich << 16 + source << 24 + river << 25 */
	/* flag contains 5 items, as follows:
	 * low byte:	level = flag & 255: Values: 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake
	 * 2nd byte:	version = (flag >> 8) & 255: Values: Should be 7 for GSHHS release 7
	 * 3rd byte:	greenwich = (flag >> 16) & 1: Values: Greenwich is 1 if Greenwich is crossed
	 * 4th byte:	source = (flag >> 24) & 1: Values: 0 = CIA WDBII, 1 = WVS
	 * 4th byte:	river = (flag >> 25) & 1: Values: 0 = not set, 1 = river-lake and level = 2
	 */
	int west, east, south, north;	/* min/max extent in micro-degrees */
	int area;	/* Area of polygon in 1/10 km^2 */
	int area_full;	/* Area of original full-resolution polygon in 1/10 km^2 */
	int container;	/* Id of container polygon that encloses this polygon (-1 if none) */
	int ancestor;	/* Id of ancestor polygon in the full resolution set that was the source of this polygon (-1 if none) */
};

struct	POINT_GSHHS {	/* Each lon, lat pair is stored in micro-degrees in 4-byte integer format */
	int	x;
	int	y;
};
#endif	/* _GSHHS */
