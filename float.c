/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** float
*/

#include "float.h"
#include "new.h"
#include "player.h"
#include "object.h"
#include "raise.h"
#include <stdarg.h>
#include <stdlib.h>

typedef struct
{
  Class base;
  float value;
  char *str;
} FloatClass;

static void Float_ctor(FloatClass *obj, va_list *list)
{
    ((FloatClass *)obj)->value = (float)va_arg(*list, double);
}

static void Float_dtor(FloatClass *obj)
{
    if (!obj && ((FloatClass *)obj)->str != NULL)
        free(((FloatClass *)obj)->str);
}

static char *Float_toString(FloatClass *obj)
{
    FloatClass *obj2;

    if (obj == NULL)
        return (NULL);
    obj2 = ((FloatClass *)obj);
    if (!obj2->str)
        free(obj2->str);
    asprintf(&obj2->str, "<%s (%f)>", obj2->base.__name__, obj2->value);
    return (obj2->str);
}

static Object *Float_add(FloatClass *obj, FloatClass *obj2)
{
    Object *obj2 = new(Float, obj->value + obj2->value);
	return (obj2);
}

static Object *Float_sub(FloatClass *obj, FloatClass *obj2)
{
    Object *obj2 = new(Float, obj->value - obj2->value);
	return (obj2);
}

static Object *Float_mul(FloatClass *obj, FloatClass *obj2)
{
    Object *obj2 = new(Float, obj->value * obj2->value);
	return (obj2);
}

static Object *Float_div(FloatClass *obj, FloatClass *obj2)
{
    Object *obj2 = new(Float, obj->value / obj2->value);
	return (obj2);
}

static bool Float_eq(FloatClass *obj, FloatClass *obj2)
{
	return (obj->value == obj2->value);
}

static bool Float_gt(FloatClass *obj, FloatClass *obj2)
{
	return (obj->value > obj2->value);
}

static bool Float_lt(FloatClass *obj, FloatClass *obj2)
{
	return (obj->value < obj2->value);
}

static FloatClass _description = {
  {
    sizeof(FloatClass),
    "Float",
    &Float_ctor,
    &Float_dtor,
    &Float_toString,
    &Float_add,
    &Float_sub,
    &Float_mul,
    &Float_div,
    &Float_eq,
    &Float_gt,
    &Float_lt,
  },
  0, NULL
};

Class *Float = (Class *) &_description;