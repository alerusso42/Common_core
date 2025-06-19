#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
	struct UserData *udata;
	struct WorkoutPlan *wplan;
	int days;

	udata = get_user_data(username);
	wplan = build_base_plan(udata);
	refine_plan(wplan, udata);
	days = determine_duration(wplan);
	assign_daily_exercises(wplan, days);
	assign_daily_tips(wplan, days);
	free_user_data(udata);
	return (wplan);
}

// Returns a new UserData (mocked). Returns NULL on failure.
struct UserData *get_user_data(char *username);
// Build a base WorkoutPlan from raw user data. Returns NULL on failure.
struct WorkoutPlan *build_base_plan(struct UserData *data);
// Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
struct WorkoutPlan *refine_plan(struct WorkoutPlan *plan, struct UserData *data);
// Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
int determine_duration(struct WorkoutPlan *plan);
// Assign daily exercises for the next day into the plan.
void assign_daily_exercises(struct WorkoutPlan *plan, int day);
// Assign daily tips for the next day into the plan.
void assign_daily_tips(struct WorkoutPlan *plan, int day);
// Free functions for cleanup.
void free_user_data(struct UserData *data);
void free_workout_plan(struct WorkoutPlan *plan);
