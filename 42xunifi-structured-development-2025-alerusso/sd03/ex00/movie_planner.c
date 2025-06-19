#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *pref;
	struct MovieList *mlist;
	struct Plan *plan;

	pref = get_user_preferences();
	mlist = find_movies(pref);
	plan = build_plan(mlist);
	free(pref);
	free(mlist);
	return (plan);
}

struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);
