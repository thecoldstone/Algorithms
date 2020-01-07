#include "stack.h"

int STACK_SIZE = MAX_STACK;

void stackInit ( tStack* s ) {
/*   ---------
** Provede inicializaci zásobníku - nastaví vrchol zásobníku.
** Hodnoty ve statickém poli neupravujte - po inicializaci zásobníku
** jsou nedefinované.
**
** V případě, že funkce dostane jako parametr s == NULL,
** volejte funkci stackError(SERR_INIT). U ostatních funkcí pro zjednodušení
** předpokládejte, že tato situace nenastane.
*/
    if (s == NULL) {
        return;
    }

    s->top = -1;
}

int stackEmpty ( const tStack* s ) {
/*  ----------
** Vrací nenulovou hodnotu, pokud je zásobník prázdný, jinak vrací hodnotu 0.
** Funkci implementujte jako jediný příkaz. Vyvarujte se zejména konstrukce
** typu "if ( true ) b=true else b=false".
*/
    return s->top == -1;
}

int stackFull ( const tStack* s ) {
/*  ---------
** Vrací nenulovou hodnotu, je-li zásobník plný, jinak vrací hodnotu 0.
** Dejte si zde pozor na častou programátorskou chybu "o jedničku"
** a dobře se zamyslete, kdy je zásobník plný, jestliže může obsahovat
** nejvýše STACK_SIZE prkvů a první prvek je vložen na pozici 0.
**
** Funkci implementujte jako jediný příkaz.
*/
    //printf("%d %d", s->top+1, STACK_SIZE);
    return s->top+1 == STACK_SIZE;
}

int stackTop ( const tStack* s) {
/*   --------
** Vrací znak z vrcholu zásobníku prostřednictvím parametru c.
** Tato operace ale prvek z vrcholu zásobníku neodstraňuje.
** Volání operace Top při prázdném zásobníku je nekorektní
** a ošetřete ho voláním funkce stackError(SERR_TOP).
**
** Pro ověření, zda je zásobník prázdný, použijte dříve definovanou
** funkci stackEmpty.
*/

    if(stackEmpty(s)) {
        return -1;
    }

    return s->arr[s->top];
}


void stackPop ( tStack* s ) {
/*   --------
** Odstraní prvek z vrcholu zásobníku. Pro ověření, zda je zásobník prázdný,
** použijte dříve definovanou funkci stackEmpty.
**
** Vyvolání operace Pop při prázdném zásobníku je sice podezřelé a může
** signalizovat chybu v algoritmu, ve kterém je zásobník použit, ale funkci
** pro ošetření chyby zde nevolejte (můžeme zásobník ponechat prázdný).
** Spíše než volání chyby by se zde hodilo vypsat varování, což však pro
** jednoduchost neděláme.
**
*/
    if(stackEmpty(s)) {
        return;
    }

    s->arr[s->top--] = 0;
}


void stackPush ( tStack* s, char c ) {
/*   ---------
** Vloží znak na vrchol zásobníku. Pokus o vložení prvku do plného zásobníku
** je nekorektní a ošetřete ho voláním procedury stackError(SERR_PUSH).
**
** Pro ověření, zda je zásobník plný, použijte dříve definovanou
** funkci stackFull.
*/
    if(stackFull(s)) {
        return;
    }

    s->arr[++s->top] = c;
}
