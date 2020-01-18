/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    /* Fill this function for exercice 02 */
    (void) this;
}

static char *Point_str(PointClass *this)
{
    int length = snprintf( NULL, 0, "%d", this->x);
    int lengthtwo = snprintf( NULL, 0, "%d", this->y);
    int len = length + lengthtwo +  12 + 1;
    char *res = malloc(sizeof(char) *len);

    snprintf(res, len, "<Point (%i, %i)>", this->x, this->y);
    return (res);
}

static Object *Point_addition(PointClass *p1, PointClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Addition not possible, empty point");
    new_ob = new(Point, p1->x + p2->x, p1->y + p2->y);
    return (new_ob);
}

static Object *Point_substraction(PointClass *p1, PointClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Substraction not possible, empty point");
    new_ob = new(Point, p1->x - p2->x, p1->y - p2->y);
    return (new_ob);
}
// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_addition,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_substraction,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
