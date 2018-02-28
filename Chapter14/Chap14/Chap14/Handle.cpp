#include "stdafx.h"

#include "Handle.h"
#include "Core.h"

//Compare two Handle<Core> by their names
bool compare_core_handles(const Handle<Core>& a, const Handle<Core>& b)
{
	return a->get_name() < b->get_name();
}