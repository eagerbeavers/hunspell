/* Copyright 2002-2017 Németh László
 * Copyright 2002 Kevin B. Hendricks, Stratford, Ontario, Canada
 *
 * This file is part of Hunspell.
 *
 * Hunspell is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Hunspell is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Hunspell.  If not, see <http://www.gnu.org/licenses/>.
 */

/* unmunch header file */

#define MAX_LN_LEN 200
#define MAX_WD_LEN 200
#define MAX_PREFIXES 256
#define MAX_SUFFIXES 256
#define MAX_WORDS 500000

#define ROTATE_LEN 5

#define ROTATE(v, q) \
  (v) = ((v) << (q)) | (((v) >> (32 - q)) & ((1 << (q)) - 1));

#define SET_SIZE 256

#define XPRODUCT (1 << 0)

/* the affix table entry */

struct affent {
  char* appnd;
  char* strip;
  short appndl;
  short stripl;
  char achar;
  char xpflg;
  short numconds;
  char conds[SET_SIZE];
};

struct affixptr {
  struct affent* aep;
  int num;
};

/* the prefix and suffix table */
int numpfx; /* Number of prefixes in table */
int numsfx; /* Number of suffixes in table */

/* the prefix table */
struct affixptr ptable[MAX_PREFIXES];

/* the suffix table */
struct affixptr stable[MAX_SUFFIXES];

int fullstrip;

int numwords; /* number of words found */
struct dwords {
  char* word;
  int pallow;
};

struct dwords wlist[MAX_WORDS]; /* list words found */

/* the routines */

int parse_aff_file(FILE* afflst);

void encodeit(struct affent* ptr, char* cs);

int expand_rootword(const char*, int, const char*);

void pfx_add(const char* word, int len, struct affent* ep, int num);

void suf_add(const char* word, int len, struct affent* ep, int num);

char* mystrsep(char** stringp, const char delim);

char* mystrdup(const char* s);

void mychomp(char* s);
