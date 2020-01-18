/*
** EPITECH PROJECT, 2020
** cpp_rush01
** File description:
** ex01
*/

#include "object.h"
#include "player.h"
#include "int.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    /* Fill this function for exercice 02 */
    (void) this;
}

static char *Int_str(IntClass *this)
{
    int length = snprintf( NULL, 0, "%d", this->x);
    int len = length + 10 + 1;
    char *res = malloc(sizeof(char) *len);

    snprintf(res, len, "<Int (%i)>", this->x);
    return (res);
}

static Object *Int_addition(IntClass *p1, IntClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Addition not possible, empty Int");
    new_ob = new(Int, p1->x + p2->x);
    return (new_ob);
}

static Object *Int_multiplication(IntClass *p1, IntClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Multiplication not possible, empty Int");
    new_ob = new(Int, p1->x * p2->x);
    return (new_ob);
}

static Object *Int_division(IntClass *p1, IntClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Division not possible, empty Int");
    new_ob = new(Int, p1->x / p2->x);
    return (new_ob);
}

static bool Int_equal(IntClass *p1, IntClass *p2)
{
    if (!p1 || !p2)
        raise("Comparision not possible, empty Int");
    if (p1 == p2)
        return (true);
    return (false);
}

static bool Int_lower(IntClass *p1, IntClass *p2)
{
    if (!p1 || !p2)
        raise("Comparision not possible, empty Int");
    if (p1 < p2)
        return (true);
    return (false);
}

static bool Int_greater(IntClass *p1, IntClass *p2)
{
    if (!p1 || !p2)
        raise("Comparision not possible, empty Int");
    if (p1 > p2)
        return (true);
    return (false);
}

static Object *Int_substraction(IntClass *p1, IntClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Substraction not possible, empty Int");
    new_ob = new(Int, p1->x - p2->x);
    return (new_ob);
}
// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_addition,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_substraction,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_multiplication,
        .__div__ = (binary_operator_t)&Int_division,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_greater,
        .__lt__ = (binary_comparator_t)&Int_lower
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;