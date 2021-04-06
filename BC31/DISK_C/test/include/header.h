#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "./include/mouse.h"
#include "./include/draw.h"
#include "./include/hzk.h"
#include "./include/login.h"
#include "./include/database.h"
#include "./include/lgfunc.h"
#include "./include/keyboard.h"
#include "./include/initmenu.h"
#include "./include/register.h"
#include "./include/forget.h"
#include "./include/admin.h"
#include "./include/adminmenu.h"
#include "./include/adminfunc.h"
#include "./include/building.h"
#include "./include/drawuser.h"
#include "./include/useroption.h"
#include "./include/input.h"

#ifdef _MSC_VER
#pragma warning(disable:4996)
#define NORM_WIDTH 3
#else
#include <dos.h>
#include <bios.h>
#include <conio.h>
#endif
#define SHOW_CONSOLE

#endif
