#include <ncurses.h>

void drow_place();
void translate_color();

int main( int argc, char* argv[] ){

     initscr();
     cbreak();
     noecho();
     keypad(stdscr, TRUE);
     curs_set(FALSE);
     nodelay(stdscr, TRUE);

     timeout(0);

     start_color();

     init_pair(1, COLOR_WHITE, COLOR_WHITE );
     init_pair(2, COLOR_GREEN, COLOR_GREEN ); 
     init_pair(3, COLOR_RED, COLOR_RED );
     init_pair(4, COLOR_BLUE, COLOR_BLUE );
     init_pair(5, COLOR_YELLOW, COLOR_YELLOW );
     init_pair(6, COLOR_BLACK, COLOR_BLACK );
     init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA );
     init_pair(8, COLOR_CYAN, COLOR_CYAN );
     init_pair(9, COLOR_BLACK, COLOR_WHITE );



      drow_place();
  
    attron( COLOR_PAIR(2) );
    mvprintw( 6, 127,"        ");
    for( int a = 7; a < 10; a++ ){
     mvprintw( a, 127," ");
     mvprintw( a, 134," ");
    }
    mvprintw( 10, 127,"        ");


    mvprintw( 36, 153,"        ");
    for( int a = 37; a < 40; a++ ){
     mvprintw( a, 153," ");
     mvprintw( a, 160," ");
    }
    mvprintw( 40, 153,"        ");

    attroff( COLOR_PAIR(2) );


    //decode file
    if( argc == 2 && argv[1] != NULL ){

    FILE *fil;
    fil = fopen( argv[1], "r" );

    char cht;
    for( int x = 1; x < 37; x++ ){
     for( int y = 2; y < 116; y++ ){
      cht = fgetc(fil);
      if( cht != EOF ){
       mvprintw( x, y,"%c",cht);
      }
     }
    }
    fclose(fil);

    }

    int x = 17;
    int y = 60;
    attron( COLOR_PAIR(3) );
    mvprintw( x, y,"3");
    attroff( COLOR_PAIR(3) );
    char next_sym = 'h';


    while(1){
      int input = getch();
   
    
       translate_color();
      

      switch( input ){
       case '1':{
         attron( COLOR_PAIR(1) );
         for( int a = 1; a < 37; a = a + 5 ){
          mvprintw( a, 127,"        ");
          mvprintw( a+4, 127,"        ");
         }
         for( int a = 2; a < 40; a++ ){
          mvprintw( a, 127," ");
          mvprintw( a, 134," ");
         }
         attroff( COLOR_PAIR(1) );


         attron( COLOR_PAIR(2) );
         mvprintw( 1, 127,"        ");
         for( int a = 2; a < 5; a++ ){
          mvprintw( a, 127," ");
          mvprintw( a, 134," ");
         }
         mvprintw( 5, 127,"        ");
         attroff( COLOR_PAIR(2) );


         attron( COLOR_PAIR(2) );
         mvprintw( x, y,"2");
         attroff( COLOR_PAIR(2) );
        break; 
       } 

      case '2':{   
        attron( COLOR_PAIR(1) );
        for( int a = 1; a < 37; a = a + 5 ){
         mvprintw( a, 127,"        ");
         mvprintw( a+4, 127,"        ");
        }
        for( int a = 2; a < 40; a++ ){
         mvprintw( a, 127," ");
         mvprintw( a, 134," ");
        }
        attroff( COLOR_PAIR(1) );


        attron( COLOR_PAIR(2) );
        mvprintw( 6, 127,"        ");
        for( int a = 7; a < 10; a++ ){
         mvprintw( a, 127," ");
         mvprintw( a, 134," ");
        }
        mvprintw( 10, 127,"        ");
        attroff( COLOR_PAIR(2) );


        attron( COLOR_PAIR(3) );
        mvprintw( x, y,"3");
        attroff( COLOR_PAIR(3) );
       break; 
      }

      case '3':{
        attron( COLOR_PAIR(1) );
        for( int a = 1; a < 37; a = a + 5 ){
         mvprintw( a, 127,"        ");
         mvprintw( a+4, 127,"        ");
        }
        for( int a = 2; a < 40; a++ ){
         mvprintw( a, 127," ");
         mvprintw( a, 134," ");
        }
        attroff( COLOR_PAIR(1) );


        attron( COLOR_PAIR(2) );
        mvprintw( 11, 127,"        ");
        for( int a = 12; a < 15; a++ ){
         mvprintw( a, 127," ");
         mvprintw( a, 134," ");
        }
        mvprintw( 15, 127,"        ");
        attroff( COLOR_PAIR(2) );


        attron( COLOR_PAIR(4) );
        mvprintw( x, y,"4");
        attroff( COLOR_PAIR(4) );
       break; 
      }

     case '4':{
       attron( COLOR_PAIR(1) );
       for( int a = 1; a < 37; a = a + 5 ){
        mvprintw( a, 127,"        ");
        mvprintw( a+4, 127,"        ");
       }
       for( int a = 2; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       attroff( COLOR_PAIR(1) );
  

       attron( COLOR_PAIR(2) );
       mvprintw( 16, 127,"        ");
       for( int a = 16; a < 20; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       mvprintw( 20, 127,"        ");
       attroff( COLOR_PAIR(2) );


       attron( COLOR_PAIR(5) );
       mvprintw( x, y,"5");
       attroff( COLOR_PAIR(5) );
      break;
     }

     case '5':{
       attron( COLOR_PAIR(1) );
       for( int a = 1; a < 37; a = a + 5 ){
        mvprintw( a, 127,"        ");
        mvprintw( a+4, 127,"        ");
       }
       for( int a = 2; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       attroff( COLOR_PAIR(1) );
 

       attron( COLOR_PAIR(2) );
       mvprintw( 21, 127,"        ");
       for( int a = 22; a < 25; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       mvprintw( 25, 127,"        ");
       attroff( COLOR_PAIR(2) );


       attron( COLOR_PAIR(6) );
       mvprintw( x, y,"6");
       attroff( COLOR_PAIR(6) );
      break;
     }

     case '6':{
       attron( COLOR_PAIR(1) );
       for( int a = 1; a < 37; a = a + 5 ){
        mvprintw( a, 127,"        ");
        mvprintw( a+4, 127,"        ");
       }
       for( int a = 2; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       attroff( COLOR_PAIR(1) );


       attron( COLOR_PAIR(2) );
       mvprintw( 26, 127,"        ");
       for( int a = 27; a < 30; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       mvprintw( 30, 127,"        ");
       attroff( COLOR_PAIR(2) ); 


       attron( COLOR_PAIR(7) );
       mvprintw( x, y,"7");
       attroff( COLOR_PAIR(7) );
      break;
     }

     case '7':{
       attron( COLOR_PAIR(1) );
       for( int a = 1; a < 37; a = a + 5 ){
        mvprintw( a, 127,"        ");
        mvprintw( a+4, 127,"        ");
       }
       for( int a = 2; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       attroff( COLOR_PAIR(1) );
       

       attron( COLOR_PAIR(2) );
       mvprintw( 31, 127,"        ");
       for( int a = 32; a < 35; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       mvprintw( 35, 127,"        ");
       attroff( COLOR_PAIR(2) );


       attron( COLOR_PAIR(8) );
       mvprintw( x, y,"8");
       attroff( COLOR_PAIR(8) );
      break;
     }

     case '8':{
       attron( COLOR_PAIR(1) );
       for( int a = 1; a < 37; a = a + 5 ){
        mvprintw( a, 127,"        ");
        mvprintw( a+4, 127,"        ");
       }
       for( int a = 2; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       attroff( COLOR_PAIR(1) );


       attron( COLOR_PAIR(2) );
       mvprintw( 36, 127,"        ");
       for( int a = 37; a < 40; a++ ){
        mvprintw( a, 127," ");
        mvprintw( a, 134," ");
       }
       mvprintw( 40, 127,"        ");
       attroff( COLOR_PAIR(2) );

       
      attron( COLOR_PAIR(9) );
      mvprintw( x, y," ");
      attroff( COLOR_PAIR(9) );

      break;
     }

     case 'g': case 'G':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


      attron( COLOR_PAIR(2) );
      mvprintw( 1, 153,"        ");
      for( int a = 2; a < 5; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      mvprintw( 5, 153,"        ");
      attroff( COLOR_PAIR(2) );

      
      for( int x = 1; x < 37; x++ ){
       for( int y = 2; y < 116; y++ ){
         char sym = mvinch( x, y ) & A_CHARTEXT;
           if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
             mvprintw( x, y,"g");
           }
       }
      }

      next_sym = 'g';

      break;
     }

     case 'r': case 'R':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


      attron( COLOR_PAIR(2) );
      mvprintw( 6, 153,"        ");
      for( int a = 7; a < 10; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      mvprintw( 10, 153,"        ");
      attroff( COLOR_PAIR(2) );

  
      for( int x = 1; x < 37; x++ ){
       for( int y = 2; y < 116; y++ ){
         char sym = mvinch( x, y ) & A_CHARTEXT;
           if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
              mvprintw( x, y,"r");
           }
       }
      }
    
      next_sym = 'r';

      break;
     }

     case 'b': case 'B':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


       attron( COLOR_PAIR(2) );
       mvprintw( 11, 153,"        ");
       for( int a = 12; a < 15; a++ ){
        mvprintw( a, 153," ");
        mvprintw( a, 160," ");
       }
       mvprintw( 15, 153,"        ");
       attroff( COLOR_PAIR(2) );


       for( int x = 1; x < 37; x++ ){
        for( int y = 2; y < 116; y++ ){
          char sym = mvinch( x, y ) & A_CHARTEXT;
            if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
               mvprintw( x, y,"b");
            }
        }
       }

       next_sym = 'b';
   
      break;
     }

     case 'y': case 'Y':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


      attron( COLOR_PAIR(2) );
      mvprintw( 16, 153,"        ");
      for( int a = 17; a < 20; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      mvprintw( 20, 153,"        ");
      attroff( COLOR_PAIR(2) );


      for( int x = 1; x < 37; x++ ){
       for( int y = 2; y < 116; y++ ){
         char sym = mvinch( x, y ) & A_CHARTEXT;
           if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
              mvprintw( x, y,"y");
           }
       }
      }

      next_sym = 'y';

      break;
     }

     case 'l': case 'L':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


      attron( COLOR_PAIR(2) );
      mvprintw( 21, 153,"        ");
      for( int a = 22; a < 25; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      mvprintw( 25, 153,"        ");
      attroff( COLOR_PAIR(2) );


      for( int x = 1; x < 37; x++ ){
       for( int y = 2; y < 116; y++ ){
         char sym = mvinch( x, y ) & A_CHARTEXT;
           if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
              mvprintw( x, y,"l");
           }
       }
      }

      next_sym = 'l';
   
      break;
     }

     case 'm': case 'M':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );

       
      attron( COLOR_PAIR(2) );
      mvprintw( 26, 153,"        ");
      for( int a = 27; a < 30; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      mvprintw( 30, 153,"        ");
      attroff( COLOR_PAIR(2) );


      for( int x = 1; x < 37; x++ ){
       for( int y = 2; y < 116; y++ ){
         char sym = mvinch( x, y ) & A_CHARTEXT;
           if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
              mvprintw( x, y,"m");
         }
       }
      }

      next_sym = 'm';

      break;
     }

     case 'c': case 'C':{
      attron( COLOR_PAIR(1) );
      for( int a = 1; a < 37; a = a + 5 ){
       mvprintw( a, 153,"        ");
       mvprintw( a+4, 153,"        ");
      }
      for( int a = 2; a < 40; a++ ){
       mvprintw( a, 153," ");
       mvprintw( a, 160," ");
      }
      attroff( COLOR_PAIR(1) );


     attron( COLOR_PAIR(2) );
     mvprintw( 31, 153,"        ");
     for( int a = 32; a < 35; a++ ){
      mvprintw( a, 153," ");
      mvprintw( a, 160," ");
     }
     mvprintw( 35, 153,"        ");
     attroff( COLOR_PAIR(2) );


     for( int x = 1; x < 37; x++ ){
      for( int y = 2; y < 116; y++ ){
        char sym = mvinch( x, y ) & A_CHARTEXT;
          if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
           mvprintw( x, y,"c");
          }
      }
     }

     next_sym = 'c';

     break;
    }

    case 'h': case 'H':{
     attron( COLOR_PAIR(1) );
     for( int a = 1; a < 37; a = a + 5 ){
      mvprintw( a, 153,"        ");
      mvprintw( a+4, 153,"        ");
     }
     for( int a = 2; a < 40; a++ ){
      mvprintw( a, 153," ");
      mvprintw( a, 160," ");
     }
     attroff( COLOR_PAIR(1) );
     
     
     attron( COLOR_PAIR(2) );
     mvprintw( 36, 153,"        ");
     for( int a = 37; a < 40; a++ ){
      mvprintw( a, 153," ");
      mvprintw( a, 160," ");
     }
     mvprintw( 40, 153,"        ");
     attroff( COLOR_PAIR(2) );


     for( int x = 1; x < 37; x++ ){
      for( int y = 2; y < 116; y++ ){
        char sym = mvinch( x, y ) & A_CHARTEXT;
          if( sym == 'g' || sym == 'r' || sym == 'b' || sym == 'y' || sym == 'l' || sym == 'm' || sym == 'c' || sym == 'h' ){
             mvprintw( x, y,"h");
          }
      }
     }

     next_sym = 'h';
 
     break;
    }
     
     case 'w':  case 'W':{
       if( x-1 == 0 ){
        break;
       }

      char sym_col = mvinch(x, y) & A_CHARTEXT;
      mvprintw( x, y,"%c", next_sym );
      next_sym = mvinch( x-1, y) & A_CHARTEXT;
       
       mvprintw( x-1, y,"%c", sym_col );
       x--;
      
      break;
     }

     case 'S': case 's':{
       if( x+1 == 37 ){
        break;
       }

      char sym_col = mvinch(x, y) & A_CHARTEXT;
      mvprintw( x, y,"%c", next_sym );
      next_sym = mvinch( x+1, y) & A_CHARTEXT;

        mvprintw( x+1, y,"%c", sym_col );
        x++;
   
      break;
     } 

     case 'a': case 'A':{
       if( y-1 == 1 ){
        break;
       }

      char sym_col = mvinch(x, y) & A_CHARTEXT;
      mvprintw( x, y,"%c", next_sym );
      next_sym = mvinch( x, y-1) & A_CHARTEXT;

       mvprintw( x, y-1,"%c", sym_col );
       y--;

      break; 
     }

     case 'd': case 'D':{
       if( y+1 == 116 ){
        break;
       }
       
      char sym_col = mvinch(x,y) & A_CHARTEXT;
      mvprintw( x, y,"%c", next_sym );
      next_sym = mvinch( x, y+1) & A_CHARTEXT;
       
        mvprintw( x, y+1,"%c", sym_col );
        y++;
 
      break;
     }

     case ' ':{
       next_sym = mvinch( x, y ) & A_CHARTEXT;
      break;
     }

     case 'z': case 'Z':{
       char p;
       char p1;

        attron( COLOR_PAIR(7) );
        mvprintw( 40, 45,"                                          ");
        mvprintw( 42, 45,"                                          ");
        mvprintw( 41, 45,"  ");
        mvprintw( 41, 85,"  ");
        attroff( COLOR_PAIR(7) );
     
       
       if( argc == 2 && argv[1] != NULL ){

       attron( COLOR_PAIR(9) );
       mvprintw( 41, 47,"DO YOU WANT TO SAVE THIS PICTURE?(y/n)");
       attroff( COLOR_PAIR(9) );
        
        do{
        p = getch();
        if( p == 'y' || p == 'Y' ){
         FILE *fp;
         fp = fopen( argv[1], "w" );

         for( int x = 1; x < 37; x++ ){
          for( int y = 2; y < 116; y++ ){
           char sym = mvinch( x, y ) &A_CHARTEXT;
           fprintf(fp, "%c", sym );
          }
         }
 
         fclose(fp);
        }
       }while( p != 'y' && p != 'Y' && p != 'n' && p != 'N' );
      
       }

       attron( COLOR_PAIR(9) );
       mvprintw( 41, 47,"      DO YOU WANT TO LEAVE?(y/n)      ");
       attroff( COLOR_PAIR(9) );
      
      do{
       p1 = getch();
       if( p1 == 'y' || p1 == 'Y' ){
        endwin();
        return 0;
       } 
      }while( p1 != 'y' && p1 != 'Y' && p1 != 'n' && p1 != 'N' );
    

      attron( COLOR_PAIR(1) );
      mvprintw( 40, 45,"                                            ");
      mvprintw( 42, 45,"                                            ");
      mvprintw( 41, 45,"  ");
      mvprintw( 41, 85,"  ");
      mvprintw( 41, 47,"                                       ");
      attroff( COLOR_PAIR(1) );


      break;
     }
   


     } //switch

    } //while1






 
   endwin();
 return 0;
}

void drow_place(){


   for( int a = 0; a < 45; a++ ){
    attron( COLOR_PAIR(1) ); 
    mvprintw( a, 0, "                                                                                                                                                                         ");
    attroff( COLOR_PAIR(1) );
   }

   for( int x = 1; x < 37; x++ ){
    for( int y = 2; y < 116; y++ ){
     mvprintw( x, y,"h" );
    }
   }
  
   attron( COLOR_PAIR(7) );
   mvprintw( 0,0,"######################################################################################################################");
   for( int a = 1; a < 37; a++ ){
    mvprintw( a, 0,"##");
    mvprintw( a, 116,"##");
   }
   mvprintw( 37, 0,"######################################################################################################################");
   attroff( COLOR_PAIR(7) );

 
   attron( COLOR_PAIR(7) );
   mvprintw( 45, 0,"                                                                                                                                                                           ");
   for( int a = 0; a < 45; a++ ){
    mvprintw( a, 143,"  ");
    mvprintw( a, 169,"  ");
   }
   for( int a = 38; a < 46; a++ ){
    mvprintw( a, 116,"  ");
   }

   mvprintw( 43, 126,"          ");
   mvprintw( 44, 126," ");
   mvprintw( 44, 135," ");

   mvprintw( 43, 151,"             ");
   mvprintw( 44, 151," ");
   mvprintw( 44, 163," ");
   mvprintw( 0, 118,"                                                   ");
   for( int a = 38; a < 46; a++ ){
     mvprintw( a, 0,"  "); 
   }  
   attroff( COLOR_PAIR(7) );
   
   
  attron( COLOR_PAIR(2) );
  mvprintw( 2, 128,"      " );
  mvprintw( 3, 128,"      " );
  mvprintw( 4, 128,"      " );

  mvprintw( 2, 154,"      ");
  mvprintw( 3, 154,"      ");
  mvprintw( 4, 154,"      ");
  attroff( COLOR_PAIR(2) );

  attron( COLOR_PAIR(3) );
  mvprintw( 7, 128,"      " );
  mvprintw( 8, 128,"      " );
  mvprintw( 9, 128,"      " );

  mvprintw( 7, 154,"      ");
  mvprintw( 8, 154,"      ");
  mvprintw( 9, 154,"      ");
  attroff( COLOR_PAIR(3) );

  attron( COLOR_PAIR(4) );
  mvprintw( 12, 128,"      " );
  mvprintw( 13, 128,"      " );
  mvprintw( 14, 128,"      " );

  mvprintw( 12, 154,"      ");
  mvprintw( 13, 154,"      ");
  mvprintw( 14, 154,"      ");
  attroff( COLOR_PAIR(4) );

  attron( COLOR_PAIR(5) );
  mvprintw( 17, 128,"      " );
  mvprintw( 18, 128,"      " );
  mvprintw( 19, 128,"      " );

  mvprintw( 17, 154,"      ");
  mvprintw( 18, 154,"      ");
  mvprintw( 19, 154,"      ");
  attroff( COLOR_PAIR(5) );

  attron( COLOR_PAIR(6) );
  mvprintw( 22, 128,"      " );
  mvprintw( 23, 128,"      " );
  mvprintw( 24, 128,"      " );

  mvprintw( 22, 154,"      ");
  mvprintw( 23, 154,"      ");
  mvprintw( 24, 154,"      ");
  attroff( COLOR_PAIR(6) );

  attron( COLOR_PAIR(7) );
  mvprintw( 27, 128,"      " );
  mvprintw( 28, 128,"      " );
  mvprintw( 29, 128,"      " );

  mvprintw( 27, 154,"      ");
  mvprintw( 28, 154,"      ");
  mvprintw( 29, 154,"      ");
  attroff( COLOR_PAIR(7) );

  attron( COLOR_PAIR(8) );
  mvprintw( 32, 128,"      " );
  mvprintw( 33, 128,"      " );
  mvprintw( 34, 128,"      " );

  mvprintw( 32, 154,"      ");
  mvprintw( 33, 154,"      ");
  mvprintw( 34, 154,"      ");
  attroff( COLOR_PAIR(8) );

  attron( COLOR_PAIR(9) );
  mvprintw( 39, 128,"Eraser" );
  attroff( COLOR_PAIR(9) );
  attron( COLOR_PAIR(4) );
  mvprintw( 38, 130,"  ");
  attroff( COLOR_PAIR(4) );
  attron( COLOR_PAIR(3) );
  mvprintw( 37, 130,"  ");
  attroff( COLOR_PAIR(3) );


  attron( COLOR_PAIR(9) );
  mvprintw( 38, 154,"WHITE");
  mvprintw( 39, 154,"Back");
  attroff( COLOR_PAIR(9) );


  attron( COLOR_PAIR(9) );
  mvprintw( 3, 137,"1" );
  mvprintw( 8, 137,"2" );
  mvprintw( 13, 137,"3" );
  mvprintw( 18, 137,"4" );
  mvprintw( 23, 137,"5" );
  mvprintw( 28, 137,"6" );
  mvprintw( 33, 137,"7" );
  mvprintw( 38, 137,"8" );
  mvprintw( 44, 128,"COLORS" );


  mvprintw( 3, 163,"g");
  mvprintw( 8, 163,"r");
  mvprintw( 13, 163,"b");
  mvprintw( 18, 163,"y");
  mvprintw( 23, 163,"l");
  mvprintw( 28, 163,"m");
  mvprintw( 33, 163,"c");
  mvprintw( 38, 163,"h");
  mvprintw( 44, 152,"BACKGROUNDS");
  attroff( COLOR_PAIR(9) );

 refresh(); 
}

void translate_color(){

   for( int x = 1; x < 37; x++ ){
     for( int y = 2; y < 116; y++ ){
       char sym = mvinch( x, y) & A_CHARTEXT;
       
        switch( sym ){
         case '2':{
          attron( COLOR_PAIR(2) );
           mvprintw( x, y,"2");
          attroff( COLOR_PAIR(2) );
          break;
         }

         case 'g':{
           attron( COLOR_PAIR(2) );
            mvprintw( x, y,"g");
           attroff( COLOR_PAIR(2) );
          break;
         }

         case '3':{
          attron( COLOR_PAIR(3) );
           mvprintw( x, y,"3");
          attroff( COLOR_PAIR(3) );
          break;
         }

         case 'r':{
          attron( COLOR_PAIR(3) );
           mvprintw( x, y,"r");
          attroff( COLOR_PAIR(3) );
          break;
         }

         case '4':{
          attron( COLOR_PAIR(4) );
           mvprintw( x, y,"4");
          attroff( COLOR_PAIR(4) );
          break;
         }

         case 'b':{
          attron( COLOR_PAIR(4) );
           mvprintw( x, y,"b");
          attroff( COLOR_PAIR(4) );
          break;
         }

         case '5':{
          attron( COLOR_PAIR(5) );
           mvprintw( x, y,"5");
          attroff( COLOR_PAIR(5) );
          break;
         }

         case 'y':{
          attron( COLOR_PAIR(5) );
           mvprintw( x, y,"y");
          attroff( COLOR_PAIR(5) );
          break;
         }

         case '6':{
          attron( COLOR_PAIR(6) );
           mvprintw( x, y,"6");
          attroff( COLOR_PAIR(6) );
          break;
         }

         case 'l':{
          attron( COLOR_PAIR(6) );
           mvprintw( x, y,"l");
          attroff( COLOR_PAIR(6) );
          break;
         }

         case '7':{
          attron( COLOR_PAIR(7) );
           mvprintw( x, y,"7");
          attroff( COLOR_PAIR(7) );
          break;
         }

         case 'm':{
          attron( COLOR_PAIR(7) );
           mvprintw( x, y,"m");
          attroff( COLOR_PAIR(7) );
          break;
         }

         case '8':{
          attron( COLOR_PAIR(8) );
           mvprintw( x, y,"8");
          attroff( COLOR_PAIR(8) );
          break;
         }

         case 'c':{
          attron( COLOR_PAIR(8) );
           mvprintw( x, y,"c");
          attroff( COLOR_PAIR(8) );
          break;
         }

         case ' ':{
          attron( COLOR_PAIR(1) );
           mvprintw( x, y," ");
          attroff( COLOR_PAIR(1) );
          break;
         }
         case 'h':{
           attron( COLOR_PAIR(1) );
            mvprintw( x, y,"h");
           attroff( COLOR_PAIR(1) );
          break;
         }
        }

     }
   }
 


 refresh();
}

