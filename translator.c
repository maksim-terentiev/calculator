#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    int b, c, blch = 0, soprazenye = 0;
    while (((c = getchar()) != '=') && (c != '\n') && (c != EOF))
    {
        if (c == ' ') {soprazenye = 0;}
        else if ((c != '+') && (c != '-') && (c != '*') && (c != '/') && (c != '(') && (c != ')'))
        {
            if ((blch) && (!soprazenye))
                fprintf (stderr, "An error message\n");
            else if (soprazenye == 1)
                printf("%c", c);
            else
            {
                printf(" %c", c);
                blch = 1;
                soprazenye = 1;
            }
        }
        else if (c == '(')
        {
            put_stack(c);
            blch = 0;
            soprazenye = 0;
        }
        else if (c == ')')
        {
            if (!blch)
            {
                fprintf (stderr, "An error message\n");
                break;
            }
            while((c = pop_stack()) != '(')
            printf(" %c", c);
            soprazenye = 0;
        }
        else if ((c == '-') && (!blch))
        {
            put_stack('~');
            soprazenye = 0;
        }
        else if ((c == '-') || (c == '+'))
        {
            blch = 0;
            while(!(is_stack_empty()) && ((b = pop_stack()) != '('))
                printf(" %c", b);
            if (b == '(') put_stack('(');
                put_stack(c);
            soprazenye = 0;
        }
        else if ((c == '*') || (c == '/'))
        {
            if (!is_stack_empty())
            {
                while(!is_stack_empty())
                {
                    b = pop_stack();
                    if ((b == '+') || (b == '-') || (b == '('))
                    {
                        put_stack(b);
                        put_stack(c);
                        soprazenye = 0;
                        blch = 0;
                        break;
                    }
                    else
                    {
                        printf(" %c", b);
                    }
                }
                if (is_stack_empty())
                {
                    put_stack(c);
                    soprazenye = 0;
                    blch = 0;
                }
            }
            else
            {
                put_stack(c);
                soprazenye = 0;
                blch = 0;
            }
        }
    }
    while(!is_stack_empty())
    {
        if (!blch)
        {
            fprintf (stderr, "An error message\n");
            break;
        }
        c = pop_stack();
        printf(" %c", c);
    }
}
