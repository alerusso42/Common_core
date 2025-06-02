# NOTE – Usage, Credits, Details

# SECTION - What This Database Does
This database lets you quickly find and retrieve data from a set of text given by user. It uses a hash-based lookup so that, given a key (e.g., "DATA1"), you immediately get the associated value (e.g., "apple").

Example file format (key–value pairs):
DATA1=apple
DATA2=red
DATA3=tasty,good
...
If you call daft_get("DATA1") you get back "apple".

Internally, you can choose how values are split or stored (see Settings).

# SECTION - How to Add or Remove Files

1) Go into the data/ directory (where your files reside).

2) Add or remove files anywhere under data/.
Files can be nested in subfolders.
Ignored file types: .sh, .c, .h, .o, Makefile, or .md.

3) From the project root, run:
chmod +x update.sh
./update.sh
This scans data/ and updates SETTINGS.md.

4) Open SETTINGS.md and adjust any per‐file or global flags.

5) Run:
./update.sh
again so the script rebuilds hashes with your new settings.

# SECTION - How to Format Your Data Files

Each data file’s format is flexible. 
You declare per-file rules in SETTINGS.md (delimiter, output style, etc.).
This is how they seem like:
data/file->=ny,

Example. File is:
# ------------------------------------- # 
	[BULBASAUR]							|
	Id=0								|
	Name=Bulbasaur						|
	Types=GRASS,POISON					|
	BaseStats=45,49,49,45,65,65			|
	...									|
	[IVYSAUR]							|
	Id=1								|
	Name=Ivysaur						|
	Types=GRASS,POISON					|
	BaseStats=60,62,63,60,80,80			|
	Specialkey=specialvalue				|
	...									|
# ------------------------------------- #

Files flags in SETTINGS shows:
data/pokedex/pokedex.txt->]yy=,

Characters after -> have this meaning:
1)	(]):	The character that is in lines to save.
	You can search "BULBASAUR" or "IVYSAUR" using daft_get(str);

2)	(y):	if set to y (yes), returns data as a matrix of string.
	If you call daft_get("BULBASAUR"), you get the matrix [ "0", "Bulbasaur", "GRASS,POISON", "45,49,49,45,65,65" ]
	(n):	if set to n (no), returns data as a string.
	If you call daft_get("Specialkey"), you get the string "specialvalue";

3)	(y):	if set to y (yes), separates data in every line in a matrix.
	If you call daft_get("BULBASAUR"), you get the 3D matrix:
	["0"], 
	["Bulbasaur"], 
	["GRASS","POISON"], 
	["45","49","49","45","65","65"]
	(n):	if set to n (no), returns data as a single string.
	If you call daft_get("BULBASAUR"), you get the matrix [ "0", "Bulbasaur", "GRASS,POISON", "45,49,49,45,65,65" ]

4)	(=):	the delimitator of content and values.
			In the above example: Name=Ivysaur

5)	(,):	the delimitator of strings in lines.
			In the above example: Types=GRASS,POISON

All flags are optional.
Default flags are set in SETTINGS.md.

CREATOR & LICENSE
Database tool by Alessandro Russo (GitHub: alerusso42).
Feel free to use, modify, and redistribute. Please credit the author when sharing or publishing.

REVIEW – Technical Overview