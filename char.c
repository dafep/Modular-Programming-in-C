/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char    letter;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->letter = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    /* Fill this function for exercice 02 */
    (void) this;
}

static char *Char_str(CharClass *this)
{
    char *res = malloc(sizeof(char) * 11);

    snprintf(res, 11, "<Char (%c)>", this->letter);
    return (res);
}

static Object *Char_addition(CharClass *p1, CharClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Addition not possible, empty Char");
    new_ob = new(Char, p1->letter + p2->letter);
    return (new_ob);
}

static Object *Char_substraction(CharClass *p1, CharClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Substraction not possible, empty Char");
    new_ob = new(Char, p1->letter - p2->letter);
    return (new_ob);
}

static Object *Char_multiplication(CharClass *p1, CharClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Multiplication not possible, empty Char");
    new_ob = new(Char, p1->letter * p2->letter);
    return (new_ob);
}

static Object *Char_division(CharClass *p1, CharClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Division not possible, empty Char");
    new_ob = new(Char, p1->letter / p2->letter);
    return (new_ob);
}

static bool Char_equal(CharClass *p1, CharClass *p2)
{
    if (!p1 || !p2)
        raise("Comparison not possible, empty Char");
    if (p1->letter == p2->letter)
        return (true);
    return (false);
}

static bool Char_lower(CharClass *p1, CharClass *p2)
{
    if (!p1 || !p2)
        raise("Comparison not possible, empty Char");
    if (p1->letter < p2->letter)
        return (true);
    return (false);
}

static bool Char_greater(CharClass *p1, CharClass *p2)
{
    if (!p1 || !p2)
        raise("Comparison not possible, empty Char");
    if (p1->letter > p2->letter)
        return (true);
    return (false);
}
// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Char_addition,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_substraction,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_multiplication,
        .__div__ = (binary_operator_t)&Char_division,
        .__eq__ = (binary_comparator_t)&Char_equal,
        .__gt__ = (binary_comparator_t)&Char_greater,
        .__lt__ = (binary_comparator_t)&Char_lower
    },
    .letter = 0
};

const Class   *Char = (const Class *)&_description;
