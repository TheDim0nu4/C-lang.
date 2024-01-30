#define _POSIX_C_SOURCE 200201L
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

void drow_map_1();
void drow_map_2();

int main(){

   
   int map_number;

   do{
   printf("Please select which map you want to play on 1 or 2: ");
   scanf("%d", &map_number );
   }while( map_number != 1 && map_number != 2 );



   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   curs_set(FALSE);
   nodelay(stdscr, TRUE);
   
   //game
   int p;

 do{

   int x;     //starting position х for player 1
   int y;     //starting position у for player 1

   int x_2;   //starting position х for player 2
   int y_2;   //starting position у for player 2


   start_color();

   init_pair(1, COLOR_BLUE, COLOR_WHITE );
   init_pair(2, COLOR_GREEN, COLOR_GREEN );
   init_pair(3, COLOR_BLACK, COLOR_BLUE ); 

   init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
   init_pair(5, COLOR_WHITE, COLOR_WHITE );

   init_pair(6, COLOR_RED, COLOR_WHITE );
   init_pair(7, COLOR_BLUE, COLOR_BLUE );
   init_pair(8, COLOR_RED, COLOR_RED );
   init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA );
   init_pair(10, COLOR_BLACK, COLOR_WHITE );

  
   if( map_number == 1 ){
    drow_map_1();
    x = 22;
    y = 5;
    x_2 = 2;
    y_2 = 88;
   }
   else{
    drow_map_2();
    x = 12;
    y = 5;
    x_2 = 12;
    y_2 = 87;
   }
   
   attron( COLOR_PAIR(6) );
   mvprintw( x, y,"@>");
   attroff( COLOR_PAIR(6) );

   attron( COLOR_PAIR(1) );
   mvprintw( x_2, y_2,"<@");
   attroff( COLOR_PAIR(1) );

    ///variables
    
     int points_1 = 0;
     int points_2 = 0;
     int shels_wals_1 = 20;
     int shels_wals_2 = 20;
     int wals_1 = 20;
     int wals_2 = 20;

     int hp_2_1 = 10;
     int hp_2_2 = 10;

     int hp_1_1 = 10;
     int hp_1_2 = 10;

   while(1){

      for( int r = 0; r < 25; r++ ){
       attron( COLOR_PAIR(5) );
       mvprintw( r, 96,"                                 \n");
       attroff( COLOR_PAIR(5) );
      }

      attron( COLOR_PAIR(9) );
      mvprintw( 24 ,94,"                                     \n");
      for( int w = 0; w < 24; w++ ){
       mvprintw( w, 94,"  ");
       mvprintw( w, 129,"  ");
      }
      mvprintw( 0, 94,"                                     \n");
      attroff( COLOR_PAIR(9) );

      attron( COLOR_PAIR(10) );
      mvprintw( 2, 109,"Players");
      mvprintw( 6, 109,"Points");
      mvprintw( 9, 101,"Shels against the wals");
      mvprintw( 12, 110,"Wals" );
      attroff( COLOR_PAIR(10) );

      attron( COLOR_PAIR(6) );
      mvprintw( 4, 96,"  Player 1");
      mvprintw( 5, 99,"  @>");
      mvprintw( 7, 100," %d", points_1 );
      mvprintw( 10, 100,"  %d", shels_wals_1);
      mvprintw( 13, 100,"  %d", wals_1 );
      attroff( COLOR_PAIR(6) );


      attron( COLOR_PAIR(1) );
      mvprintw( 4, 116,"  Player 2");
      mvprintw( 5, 119,"  <@");
      mvprintw( 7, 120,"  %d", points_2 );
      mvprintw( 10, 120,"%d", shels_wals_2);
      mvprintw( 13, 120,"%d", wals_2 );
      attroff( COLOR_PAIR(1) );

     
      if( points_1 == 25 ){
       attron( COLOR_PAIR(10) );
       mvprintw( 12, 43,"PLAYER 1 WON!!!");
       attroff( COLOR_PAIR(10) );
       refresh();
       break;
      }else if( points_2 == 25 ){
       attron( COLOR_PAIR(10) );
       mvprintw( 12, 43,"PLAYER 2 WON!!!");
       attroff( COLOR_PAIR(10) );
       refresh();
       break;
      }

     char symbol = ' ';
   
     int input = getch();

     switch( input ){
       case 'w': case 'W':{ 
 
        symbol = mvinch(x-1, y) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!'  ){
         break;
        }

        symbol = mvinch(x-1, y+1) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!' ){
          break;
        }

        attron( COLOR_PAIR(5) );
        mvprintw( x, y,"  ");
        attroff( COLOR_PAIR(5) );

        x--;
        attron( COLOR_PAIR(6) );
        mvprintw( x, y,"@>");
        attroff( COLOR_PAIR(6) );
        refresh();
        break;
       }
       case 's': case 'S':{

        symbol = mvinch(x+1, y+1) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!' ){
          break;
        }

        symbol = mvinch(x+1, y) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!' ){
          break;
        }

        attron( COLOR_PAIR(5) );
        mvprintw( x, y,"  ");
        attroff( COLOR_PAIR(5) );

        x++;
        attron( COLOR_PAIR(6) );
        mvprintw( x, y,"@>");
        attroff( COLOR_PAIR(6) );
        refresh();
        break;
       }
       case 'a': case 'A':{

        symbol = mvinch(x, y-1) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!' ){
          break;
        }

        attron( COLOR_PAIR(5) );
        mvprintw( x, y,"  ");
        attroff( COLOR_PAIR(5) );

        y--;
        attron( COLOR_PAIR(6) );
        mvprintw( x, y,"@>");
        attroff( COLOR_PAIR(6) );
        refresh();
        break;
       }
       case 'd': case 'D':{

        symbol = mvinch(x, y+2) & A_CHARTEXT;
        if( symbol == '#' || symbol == '!' || symbol == ')' || symbol == '$' || symbol == '*' || symbol == '(' ){
          break;
        }

        attron( COLOR_PAIR(5) );
        mvprintw( x, y,"  ");
        attroff( COLOR_PAIR(5) );

        y++;
        attron( COLOR_PAIR(6) );
        mvprintw( x, y,"@>");
        attroff( COLOR_PAIR(6) );
        refresh();
        break;
       }
       case ' ':{ 

          char sym = ' ';
       
         struct timespec ts = {
          .tv_sec = 0,                    
          ts.tv_nsec = 0.1 * 10000000L
         };
 

         sym = mvinch( x, y+2) &A_CHARTEXT;
         if( sym == '#' || sym == '!' || sym == ')' || sym == '(' ){
          break;
         }
         if( sym == '$' ){
          if( hp_2_1 == 0 ){
           attron( COLOR_PAIR(5) );
           mvprintw( x, y+2," ");
           attroff( COLOR_PAIR(5) );
           break;
          }
          hp_2_1--;
          points_1++;
          break;
         }else if( sym == '*' ){
           if( hp_2_2 == 0 ){
            attron( COLOR_PAIR(5) );
            mvprintw( x, y+2," ");
            attroff( COLOR_PAIR(5) );
            break;
           }
          hp_2_2--;
          points_1++;
          break;
         }
         sym = ' ';

      
         for( int z = y+2; z < 100; z++ ){

           sym = mvinch( x, z+1) &A_CHARTEXT;
           if( sym == '#' || sym == '!' || sym == ')' || sym == '(' ){
            break;
           }
           if( sym == '<' ){
            points_1++;
            break;
           }
           if( sym == '$' ){
            if( hp_2_1 == 0 ){
             attron( COLOR_PAIR(5) );
             mvprintw( x, z+1," ");
             attroff( COLOR_PAIR(5) );
             break;
            }
            hp_2_1--;
            points_1++;
            break;
           }
           if( sym == '*' ){
            if( hp_2_2 == 0 ){
            attron( COLOR_PAIR(5) );
            mvprintw( x, z+1," ");
            attroff( COLOR_PAIR(5) );           
             break;
            }
            hp_2_2--;
            points_1++;
            break;
           }


           attron( COLOR_PAIR(6) );
           mvprintw( x, z,"0");
           attroff( COLOR_PAIR(6) );
           refresh();
           nanosleep(&ts, NULL);

           attron( COLOR_PAIR(5) );
           mvprintw( x, z," ");
           attroff( COLOR_PAIR(5) );
         }
         
        break;
       }
       case 'e': case 'E':{

        if( shels_wals_1 == 0 ){
         break;
        }
        shels_wals_1--;

        char sym = ' ';
        sym = mvinch( x, y+2) &A_CHARTEXT;

        struct timespec ts = {
         .tv_sec = 0,
         ts.tv_nsec = 0.1 * 100000000L
        };
      

        for( int z = y+2; z < 100; z++ ){
         if( z == y + 2 && ( sym == ')' || sym == '$' || sym == '*' || sym == '(' || sym == '!' ) ){
          ;
         } 
         else{
           attron( COLOR_PAIR(5) );
           mvprintw( x, z," ");
           attroff( COLOR_PAIR(5) );           
         }

          sym = mvinch( x, z+1) &A_CHARTEXT;
          if( sym == '!' || sym == '#' || sym == ')' || sym == '$' || sym == '*' || sym == '(' || sym == '<' ){
            attron( COLOR_PAIR(5) );
          
           char t = ' ';
           t = mvinch( x, z-1) &A_CHARTEXT;
           if( t == '#'){
            mvprintw( x, z-1," ");
           }
           t = ' ';

           t = mvinch( x, z+1) &A_CHARTEXT;
           if( t == '#' ){
            mvprintw( x, z+1," ");
           }
           t= ' ';

           t = mvinch( x-1, z) &A_CHARTEXT;
           if( t == '#' ){
            mvprintw( x-1, z," ");
           }
           t= ' ';

           t = mvinch( x+1, z) &A_CHARTEXT;
           if( t == '#' ){
            mvprintw( x+1, z," ");
           }

           attroff( COLOR_PAIR(5) );
           refresh();
           break;
          }
 

         attron( COLOR_PAIR(6) );
         mvprintw( x, z+1, "@");
         attroff( COLOR_PAIR(6) );
         refresh();
         nanosleep(&ts, NULL);
        }
 
        break;
       }
       case 'Q': case 'q':{

         if( wals_1 == 0 ){
           break;
         }
         wals_1--;
  
         char symbol= ' ';
         symbol = mvinch(x, y+2) & A_CHARTEXT;
         if( symbol != ' '){
          break;
         }

         attron( COLOR_PAIR(9) );
         mvprintw( x, y+2,"#");
         attroff( COLOR_PAIR(9) );

        break;
       }

      
      
       case KEY_UP:{

         symbol = mvinch(x_2-1, y_2) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' ){
           break;
         } 

         symbol = mvinch(x_2-1, y_2+1) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' ){
           break;
         }

         attron( COLOR_PAIR(5) );
         mvprintw( x_2, y_2,"  ");
         attroff( COLOR_PAIR(5) );

         x_2--;
         attron( COLOR_PAIR(1) );
         mvprintw( x_2, y_2,"<@");
         attroff( COLOR_PAIR(1) );
         refresh();
         break;
       }
       case KEY_DOWN:{

         symbol = mvinch(x_2+1, y_2) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' ){
           break;
         }

         symbol = mvinch(x_2+1, y_2+1) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' ){
           break;
         }

         attron( COLOR_PAIR(5) );
         mvprintw( x_2, y_2,"  ");
         attroff( COLOR_PAIR(5) );

         x_2++;
         attron( COLOR_PAIR(1) );
         mvprintw( x_2, y_2,"<@");
         attroff( COLOR_PAIR(1) );
         refresh();
         break;
       }
       case KEY_LEFT:{

         symbol = mvinch(x_2, y_2-1) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' || symbol == ')' || symbol == '$' || symbol == '*' || symbol == '(' ){
           break;
         }

         attron( COLOR_PAIR(5) );
         mvprintw( x_2, y_2,"  ");
         attroff( COLOR_PAIR(5) );

         y_2--;
         attron( COLOR_PAIR(1) );
         mvprintw( x_2, y_2,"<@");
         attroff( COLOR_PAIR(1) );
         refresh();
         break;
       }
       case KEY_RIGHT:{

         symbol = mvinch(x_2, y_2+2) & A_CHARTEXT;
         if( symbol == '#' || symbol == '!' ){
           break;
         }

         attron( COLOR_PAIR(5) );
         mvprintw( x_2, y_2,"  ");
         attroff( COLOR_PAIR(5) );

         y_2++;
         attron( COLOR_PAIR(1) );
         mvprintw( x_2, y_2,"<@");
         attroff( COLOR_PAIR(1) );
         refresh();
         break;
       }
       
       case '=': case '+':{

        char sym = ' ';

        struct timespec ts = {
         .tv_sec = 0,                   
         ts.tv_nsec = 0.1 * 10000000L        
        };

        sym = mvinch( x_2, y_2-1) &A_CHARTEXT;
        if ( sym == '#' || sym == '!' || sym == '$' || sym == '*' ){
          break;
        }
        if( sym == ')' ){
         if( hp_1_1 == 0 ){
          attron( COLOR_PAIR(5) );
          mvprintw( x_2, y_2-1," ");
          attroff( COLOR_PAIR(5) );
          break;
         } 
         hp_1_1--;
         points_2++;
         break;
        }else if( sym == '(' ){
         if( hp_1_2 == 0 ){
          attron( COLOR_PAIR(5) );
          mvprintw( x_2, y_2-1," ");
          attroff( COLOR_PAIR(5) );

          break;
         }
         hp_1_2--;
         points_2++;
         break;
        } 
        sym = ' ';


        for( int z = y_2-1; z > -1; z-- ){
         attron( COLOR_PAIR(5) );
         mvprintw( x_2, z," ");
         attroff( COLOR_PAIR(5) );

         sym = mvinch( x_2, z-1) &A_CHARTEXT;
         if( sym == '#' || sym == '!' || sym == '$' || sym == '*' ){
          break;
         }
         if( sym == '>' ){
          points_2++;
          break;
         }
         if( sym == ')' ){
          if( hp_1_1 == 0 ){
           attron( COLOR_PAIR(5) );
           mvprintw( x_2, z-1," ");
           attroff( COLOR_PAIR(5) );
           break;
          }
          hp_1_1--;
          points_2++;
          break;
         }
         if( sym == '(' ){
          if( hp_1_2 == 0 ){
           attron( COLOR_PAIR(5) );
           mvprintw( x_2, z-1," ");
           attroff( COLOR_PAIR(5) );           
           break;
          }
          hp_1_2--;
          points_2++;
          break;
         }

         attron( COLOR_PAIR(1) );
         mvprintw( x_2, z,"0");
         attroff( COLOR_PAIR(1) );
         refresh();
         nanosleep(&ts, NULL);

         attron( COLOR_PAIR(5) );
         mvprintw( x_2, z," ");
         attroff( COLOR_PAIR(5) );
        }

        break;
       }
      
       case '{': case '[' :{

        if( shels_wals_2 == 0 ){
          break;
        }
        shels_wals_2--;

        char sym = ' ';
        sym = mvinch( x_2, y_2-1) &A_CHARTEXT;

        struct timespec ts = {
         .tv_sec = 0,
         ts.tv_nsec = 0.1 * 100000000L
        };


        for( int z = y_2-1; z > -1; z-- ){
      
         if( z == y_2-1 && ( sym == ')' || sym == '$' || sym == '*' || sym == '(' || sym == '!' ) ){
          ;
         }
         else{
          attron( COLOR_PAIR(5) );
          mvprintw( x_2, z," ");
          attroff( COLOR_PAIR(5) );
         }
         
         sym = mvinch( x_2, z-1) &A_CHARTEXT;
         if( sym == '!' || sym == '#' || sym == '$' || sym == ')' || sym == '*' || sym == '(' || sym == '>'){
          attron( COLOR_PAIR(5) );

          char t = ' ';
          t = mvinch( x_2, z-1) &A_CHARTEXT;
          if( t == '#' ){
           mvprintw( x_2, z-1," ");
          }
          t= ' ';

          t = mvinch( x_2, z+1) &A_CHARTEXT;
          if( t == '#' ){
           mvprintw( x_2, z+1," ");
          }
          t= ' '; 

          t = mvinch( x_2-1, z) &A_CHARTEXT;
          if( t == '#' ){
           mvprintw( x_2-1, z," ");
          }
          t= ' ';

          t = mvinch( x_2+1, z) &A_CHARTEXT;
          if( t == '#' ){
           mvprintw( x_2+1, z," ");
          }
          t= ' ';
          
          attroff( COLOR_PAIR(5) );
          refresh();
          break;
         }

         attron( COLOR_PAIR(1) );
         mvprintw( x_2, z-1, "@");
         attroff( COLOR_PAIR(1) );
         refresh();
         nanosleep(&ts, NULL);
        }
   
        break;
       }
       case '-': case '_':{

         if( wals_2 == 0 ){
          break;
         }
         wals_2--;
   
         char symbol = ' ';
         symbol = mvinch(x_2, y_2-1) & A_CHARTEXT;

         if( symbol != ' '){
          break;
         }
     
         attron( COLOR_PAIR(9) );
         mvprintw( x_2, y_2-1,"#");
         attroff( COLOR_PAIR(9) );
  
        break;
       }


     }
    
     
   }

   while( p != 'y' || p != 'n' || p != 'Y' || p != 'N'  ){
    attron( COLOR_PAIR(10) );
    mvprintw( 13, 39,"Want to play again? y/n");
    attroff( COLOR_PAIR(10) );
    p = getch();
    if( p == 'y' || p == 'n' || p == 'Y' || p == 'N'  ){
     break;
    } 
   }
 
  }while( p == 'y' || p == 'Y' );
 
  endwin();
 return 0;
} 

void drow_map_1(){

  move( 0, 0 );
  for( int i = 0; i < 24; i++){
   attron( COLOR_PAIR(5) );
   printw("                                                                                            \n");
   attroff( COLOR_PAIR(5) );
  }


  attron( COLOR_PAIR(4) );
  mvprintw( 0, 0,"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  mvprintw( 24, 0,"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"); 
  for( int a = 0; a < 24; a++ ){
   mvprintw( a, 0,"!!");
   mvprintw( a, 92,"!!");
  }
  
  mvprintw( 22, 9,"###");
  mvprintw( 23, 9,"###" );
  mvprintw( 21, 9,"###" );
  mvprintw( 20, 9,"###" );

  mvprintw( 10, 2,"#########" );
  mvprintw( 9, 2,"#########" );
  mvprintw( 8, 2,"#########" );
  mvprintw( 7, 2,"#########" );

  mvprintw( 1, 19,"####" );
  mvprintw( 2, 19,"####" );
  mvprintw( 3, 19,"####" );
  mvprintw( 4, 19,"####" );

  mvprintw( 9, 25,"#########" );
  mvprintw( 10, 25,"#########" );
  mvprintw( 11, 25,"#########" );
  mvprintw( 12, 25,"#########" );

  mvprintw( 16, 50,"########" );
  mvprintw( 17, 50,"########" );
  mvprintw( 18, 50,"########" );
  mvprintw( 19, 50,"########" );

  mvprintw( 1, 83,"###" );
  mvprintw( 2, 83,"###" );
  mvprintw( 3, 83,"###" );
  mvprintw( 4, 83,"###" );

  attroff( COLOR_PAIR(4) );

  
  attron( COLOR_PAIR(2) );

  mvprintw( 19, 25,"#####");
  mvprintw( 20, 25,"##");
  mvprintw( 20, 28,"##");
  mvprintw( 21, 25,"#####");

  mvprintw( 6, 35,"#####");
  mvprintw( 5, 35,"##");
  mvprintw( 5, 38,"##");
  mvprintw( 4, 35,"#####");

  mvprintw( 9, 65,"#####");
  mvprintw( 8, 65,"##");
  mvprintw( 8, 68,"##");
  mvprintw( 7, 65,"#####");

  mvprintw( 20, 70,"#####");
  mvprintw( 21, 70,"##");
  mvprintw( 21, 73,"##");
  mvprintw( 22, 70,"#####");

  attroff( COLOR_PAIR(2) );

  attron( COLOR_PAIR(7) );
  mvprintw( 21, 72,"*");
  mvprintw( 8, 67,"$");
  attroff( COLOR_PAIR(7) );

  attron( COLOR_PAIR(8) );
  mvprintw( 20, 27,"(");
  mvprintw( 5, 37,")");
  attroff( COLOR_PAIR(8) );

}


void drow_map_2(){

  move( 0, 0 );
    for( int i = 0; i < 24; i++){
       attron( COLOR_PAIR(5) );
        printw("                                                                                            \n");
        attroff( COLOR_PAIR(5) );
    }


      attron( COLOR_PAIR(4) );
      mvprintw( 0, 0,"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      mvprintw( 24, 0,"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      for( int a = 0; a < 24; a++ ){
         mvprintw( a, 0,"!!");
         mvprintw( a, 92,"!!");
      }

      mvprintw( 11, 10,"##");
      mvprintw( 12, 10,"##");
      mvprintw( 10, 10,"##");
      mvprintw( 13, 10,"##");
      mvprintw( 14, 10,"##");

      mvprintw( 10, 82,"##");
      mvprintw( 11, 82,"##");
      mvprintw( 12, 82,"##");
      mvprintw( 13, 82,"##");
      mvprintw( 14, 82,"##");

      mvprintw( 10, 46,"#######");
      mvprintw( 11, 46,"#######");
      mvprintw( 12, 46,"#######");
      mvprintw( 13, 46,"#######");
      mvprintw( 14, 46,"#######");

      mvprintw( 4, 46,"#######");
      mvprintw( 5, 46,"#######");
      mvprintw( 6, 46,"#######");

      mvprintw( 18, 46,"#######");
      mvprintw( 19, 46,"#######");
      mvprintw( 20, 46,"#######");
     
      attroff( COLOR_PAIR(4) );

      attron( COLOR_PAIR(2) );
    
      mvprintw( 6, 25,"#####");
      mvprintw( 7, 25,"##");
      mvprintw( 7, 28,"##");
      mvprintw( 8, 25,"#####");

      mvprintw( 16, 25,"#####");
      mvprintw( 17, 25,"##");
      mvprintw( 17, 28,"##");
      mvprintw( 18, 25,"#####");

      mvprintw( 6, 69,"#####");
      mvprintw( 7, 69,"##");
      mvprintw( 7, 72,"##");
      mvprintw( 8, 69,"#####");

      mvprintw( 16, 69,"#####");
      mvprintw( 17, 69,"##");
      mvprintw( 17, 72,"##");
      mvprintw( 18, 69,"#####");

      attroff( COLOR_PAIR(2) );

      attron( COLOR_PAIR(8) );
      mvprintw( 7, 27,")");
      mvprintw( 17, 27,"(");
      attroff( COLOR_PAIR(8) );

      attron( COLOR_PAIR(7) );
      mvprintw( 7, 71,"*");
      mvprintw( 17, 71,"$");
      attroff( COLOR_PAIR(7) );
     

}

