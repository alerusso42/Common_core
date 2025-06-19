#include "task_scheduler.h"

struct ScheduleResult	*schedule_result(struct tasklist *task)
{
	struct TaskProfile 		*profile;
	struct ScheduleResult	*result;
	int						core_id;
	int						task_id;

	profile = profile_tasks(task);
	free_priority_map(compute_priorities_mock(profile));
	core_id = get_available_core_count();
	task_id = select_best_task(profile);
	result = create_schedule_result(core_id);
	update_schedule_entry(result, core_id, task_id);
	free_task_profile(profile);
	return (result);
}

// Analyze task load and I/O behavior. Returns a new TaskProfile or NULL on failure.
struct TaskProfile *profile_tasks(struct TaskList *tasks);
// Compute a priority map from task profiling. Returns a new PriorityMap or NULL on failure.
struct PriorityMap *compute_priorities_mock(struct TaskProfile *profile);
// Return the number of available CPU cores.
int get_available_core_count(void);
// Select the best task to assign next based on the profile. Returns a task ID or -1 on failure.
int select_best_task(struct TaskProfile *profile);
// Create a ScheduleResult structure for the specified number of cores. Returns NULL on failure.
struct ScheduleResult *create_schedule_result(int core_count);
// Update the result schedule with a task assignment.
void update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);
// Free functions for cleanup
void free_task_profile(struct TaskProfile *profile);
void free_priority_map(struct PriorityMap *priorities);