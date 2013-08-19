//
//  ascii.c
//  
//
//  Created by Ryan Strug on 6/18/13.
//
//

#include <stdio.h>

void amusement();
void print_char_list();
void print_help();
void print_html();
void print_list();
void print_string();

int main(int argc, char **argv)
{
    if (argc == 2 && **argv == '-') {
        switch (**++argv) {
            case 'a': amusement(); break;
            case 'c': print_char_list(); break;
            case 'l': print_list(); break;
            case 's': print_string(); break;
            case 'w': print_html(); break;
            default: print_help(); break;
        }
    } else
       print_help();
    
    return 0;
}

void amusement()
{
    for (int c=0x1f;c<042;printf("%c",(int)(++c*c*3.5-c*221.5+3606)))
        ;
    printf("\n");
}

void print_char_list()
{
    for (int c = 0x1f; c < 0x7e; printf("%c\n", ++c))
        ;
}

void print_help()
{
    printf("ASCII Character List Help\n"
           "-a\tAmusement.\n"
           "-c\tPrints just the characters in list format.\n"
           "-h\tPrints help documentation.\n"
           "-l\tPrints in list format.\n"
           "-s\tPrints a string of the characters.\n"
           "-w\tPrints in html format.\n"
           "\n");
}

void print_html()
{
    printf("<table>\n"
           "    <thead>\n"
           "        <th>Oct</th>\n"
           "        <th>Hex</th>\n"
           "        <th>Dec</th>\n"
           "        <th>Glyph</th>\n"
           "    </thead>\n"
           "    <tbody>\n"
           );
    
    for (char c = 32; c < 127; c++)
        printf("        <tr>\n"
               "            <td>0%o</td>\n"
               "            <td>0x%x</td>\n"
               "            <td>%d</td>\n"
               "            <td>%c</td>\n"
               "        </tr>\n",
               c, c, c, c);
    
    printf("    </tbody>\n"
           "</table>\n"
           );
}

void print_list()
{
    printf("ASCII Character List\nOct\tHex\tDec\tGlyph\n");
    
    for (char c = 0x1f; c < 0x7f; c++)
        printf("0%o\t0x%x\t%d\t%c\n", c, c, c, c);
}

void print_string()
{
    for (int c = 0x1f; c < 0x7e; printf("%c", ++c))
        ;
}
