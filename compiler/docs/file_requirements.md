---------------------------------------------------------------
               FILE REQUIREMENTS for ASM Corewar
---------------------------------------------------------------

         - Your file need a ' .s ' extension to work.
         - Do not exceed a size of CHAMP_MAX_SIZE
         - Please refer to the below operations

           REGISTER = 1   DIRECT = 2   INDIRECT = 3
       __________________________________________________
      |     | NB   |                |       |     |  NB  |
      |NAME |PARAM |TYPE PARAM      |ENCODE |INDEX|CYCLES|
       --------------------------------------------------
   1   live     1          {2}         No      No    10
   2   ld       2       {2|3, 1}       Yes     No    5
   3   st       2       {1, 1|3}       Yes     No    5
   4   add      3       {1, 1, 1}      Yes     No    10
   5   sub      3       {1, 1 ,1}      Yes     No    10
   6   and      3  {1|2|3, 1|2|3, 1}   Yes     No    6
   7   or       3  {1|2|3, 1|2|3, 1}   Yes     No    6
   8   xor      3  {1|2|3, 1|2|3, 1}   Yes     No    6
   9   zjmp     1          {2}         No      Yes   20
   10  ldi      3  {1|2|3, 1|2|3, 1}   Yes     Yes   25
   11  sti      3   {1, 1|2|3, 1|2}    Yes     Yes   25
   12  fork     1          {2}         No      Yes   800
   13  lld      2        {2|3, 1}      Yes     No    10
   14  lldi     3   {1|2|3, 1|2, 1}    Yes     Yes   50
   15  lfork    1         {2}          No      Yes   1000
   16  aff      1         {1}          Yes     No    2
