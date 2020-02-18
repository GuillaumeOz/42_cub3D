#include "cub3d.h"

int handle_key(int key, void *param)
{
	(void)param;
	if (key == ESC_KEY)
		close_application();
	return (0);
}
