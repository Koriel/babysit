/*
 * MIT/X Consortium License
 *
 * © 2011 Connor Lane Smith <cls@lubutu.com>
 * © 2011 Kamil Cholewiński <harry666t@gmail.com>
 * © 2011 sin <sin@2f30.org>
 * © 2011 Rob Pilling <robpilling@gmail.com>
 * © 2011 Hiltjo Posthuma <hiltjo@codemadness.org>
 * © 2011 pancake <pancake@youterm.com>
 * © 2011 Random832 <random832@fastmail.us>
 * © 2012 William Haddon <william@haddonthethird.net>
 * © 2012 Kurt H. Maier <khm@intma.in>
 * © 2012 Christoph Lohmann <20h@r-36.net>
 * © 2012 David Galos <galosd83@students.rowan.edu>
 * © 2012 Robert Ransom <rransom.8774@gmail.com>
 * © 2013 Jakob Kramer <jakob.kramer@gmx.de>
 * © 2013 Anselm R Garbe <anselm@garbe.us>
 * © 2013 Truls Becken <truls.becken@gmail.com>
 * © 2013 dsp <dsp@2f30.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "estrtol.h"

long
estrtol(const char *s, int base)
{
	char *end;
	long n;

	errno = 0;
	n = strtol(s, &end, base);
	if(*end != '\0') {
		if(base == 0)
			fprintf(stderr, "%s: not an integer\n", s);
		else
			fprintf(stderr, "%s: not a base %d integer\n", s, base);
		exit(1);
	}
	if(errno != 0) {
		fprintf(stderr, "%s:", s);
		exit(1);
	}

	return n;
}

