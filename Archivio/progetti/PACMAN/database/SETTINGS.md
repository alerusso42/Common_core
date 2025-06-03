#	This file is a setting file for the database used for program.

#SECTION - General settings
#	Hash size:	1 means hash result are on a range from 0 to file_len.
#				1.3 means are on range from 0 to (file_len * 1.3).

DEFAULT_FLAGS->=nn=,
HASH_SIZE->1.3
QUIET->n

#SECTION - Files flags
#	Choose the ending character of the line you need to save.
#	Remember to run update.sh before modify this file
#	PATTERN: 	filename->DEFAULT_LIMITER
#				userdata->$

# -- FLAGS -- #
data/pokedex/pokedex.txt->]yy=,
