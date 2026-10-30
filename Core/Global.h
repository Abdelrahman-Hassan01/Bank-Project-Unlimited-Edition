#pragma once
#include "../Models/clsUser.h"

clsUser CurrentUser = clsUser::Find("", "");
bool IsExitRequested = false;
