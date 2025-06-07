#	This file is a setting file for the database used for program.

#SECTION - General settings
#	Hash size:	1 means hash result are on a range from 0 to file_len.
#				1.3 means are on range from 0 to (file_len * 1.3).

DEFAULT_FLAGS->=nn=,
HASH_SIZE->1.3
QUIET->n

#SECTION - Files flags and enums
#	OPTIONAL: Choose the enum names of your files, 
#	and the flags of the lines you need to save.
#	⚠️Remember to run update.sh before modify this file!⚠️
#	PATTERN: 	filename->[yy=,
#	___________________________________________________________
#  |FLAG:			[	 |||y/n		|||y/n	  |||=	  |||,	   |
#  |___________________________________________________________|
#  |DESCRIPTION:	field|||multiple|||split  |||key/ |||values|
#  |				sep	 |||lines?	|||values?|||value|||sep   |
#  |				     |||		|||       |||sep  |||	   |
#  |___________________________________________________________|

# -- FLAGS -- #
data/pokedex/pokedex.txt->=nn=,
hash_data/pokedex/pokedex.txt->=nn=,
hash_hash_data/pokedex/pokedex.txt->=nn=,
hash_program/Libft/.vscode/settings.json->=nn=,
program/Libft/.vscode/settings.json->=nn=,
# -- ENUM -- #
data/pokedex/pokedex.txt->POKEDEX_POKEDEX
hash_data/pokedex/pokedex.txt->HASH_DATA_POKEDEX_POKEDEX
hash_hash_data/pokedex/pokedex.txt->HASH_HASH_DATA_POKEDEX_POKEDEX
hash_program/Libft/.vscode/settings.json->HASH_PROGRAM_LIBFT__VSCODE_SETTINGS
program/Libft/.vscode/settings.json->PROGRAM_LIBFT__VSCODE_SETTINGS
