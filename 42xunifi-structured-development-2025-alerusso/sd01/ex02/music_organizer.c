#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	struct MusicLibrary *lib;
	char **mlist;
	int i;

	lib = create_music_library();
	mlist = scan_directory(directory_path);
	if (!mlist)
	  return (NULL);
	i = 0;
	while (mlist[i])
	{
		 update_music_library(lib, process_music_file(directory_path, mfile[i]));
		 ++i;
	}
	  return (lib);
}

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_fprocess_music_fileile(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);
