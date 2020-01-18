/*
** EPITECH PROJECT, 2020
** cpp_rush01
** File description:
** ex01
*/

#include "object.h"
#include "player.h"
#include "point.h"
#include "raise.h"

Object  *va_new(const Class *class, va_list* ap)
{
    Object *new;

    if (!class)
        raise("No class given");
    if (!class->__size__)
        raise("given class has no size given");
    if (!(new = malloc(class->__size__)))
        raise("malloc failed");
    if (!(memcpy(new, class, sizeof(Class))))
        raise("Memcpy failed");
    if (((Class *)new)->__ctor__ != NULL)
        (((Class *)new)->__ctor__(new, ap));
    return (new);
}

Object *new(const Class *class, ...)
{
    Object *new;
    va_list ap;

    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);
    return (new);
}

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__ != NULL)
        (((Class *)ptr)->__dtor__(ptr));
    free (ptr);
}