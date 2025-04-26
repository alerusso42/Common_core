#include "executor.h"

void	goto_valid_block(t_exec *exec, t_token **token)
{
	while ((exec->prior_layer <= (*token)->prior && \
	(*token)->type != AND && (*token)->type != OR) || \
	(((*token)->type == AND && *exec->exit_status != 0) || \
	((*token)->type == OR && *exec->exit_status == 0)))
	{
		++(*token);
	}
}