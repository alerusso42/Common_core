#include "executor.h"

void	next_token(t_token **token)
{
	if ((*token)->content)
		++(*token);
}

void	skip_deeper_layers(t_token **token, int curr_layer)
{
	while ((*token)->content && (*token)->prior > curr_layer)
		++(*token);
}
