/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    /* Fill this function for exercice 02 */
    (void) this;
}
static char *Vertex_str(VertexClass *this)
{
    int len1 = snprintf( NULL, 0, "%d", this->x);
    int len2 = snprintf( NULL, 0, "%d", this->y);
    int len3 = snprintf( NULL, 0, "%d", this->z);
    int len = len1 + len2 + len3 + 16;
    char *res = malloc(sizeof(char) *(len));

    snprintf(res, len, "<Vertex (%i, %i, %i)>", this->x, this->y, this->z);
    return (res);
}

static Object *Vertex_addition(VertexClass *p1, VertexClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Addition not possible, empty vertex");
    new_ob = new(Vertex, p1->x + p2->x, p1->y + p2->y, p1->z + p2->z);
    return (new_ob);
}

static Object *Vertex_substraction(VertexClass *p1, VertexClass *p2)
{
    Object *new_ob;
    if (!p1 || !p2)
        raise("Substraction not possible, empty vertex");
    new_ob = new(Vertex, p1->x - p2->x, p1->y - p2->y, p1->z - p2->z);
    return (new_ob);
}
// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_addition,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_substraction,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;
