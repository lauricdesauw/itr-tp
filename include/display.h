int println(char* str)
{
  static int c = 0;

  if (c == 0)
    {display_clear();}
    
  display_goto_xy(0,c);
  display_sting(str[c]); 
  c++;

  if( c == 8)
    {c = 0;}

  return c; 
}


int nb_digit(int i)
{
  
  return 4;
}

void print(char** str, int nb, int* to_print)
{
  int c = 0, column = 0, int_count = 0, tmp = 0, line = 0;
  char curr_str[17];
  curr_str[16] = '\0';
  for(int i=0; i < nb; i++)
    {
      while(str[i][c] != '\0')
	{
	  
	  if(str[i][c] == '%')
	    {
	      
	      tmp = nb_digit(to_print[int_count]);
	      if (column + tmp > 15)
		{
		  
		  line = println(curr_str);
		  column = tmp;
		  line++; 
		}
	      else
		{
		  column += tmp;
		}
	      display_goto_xy(line, column);
	      display_int(to_print[int_count], tmp); 
	    }
	  else
	    {
	      curr_str[c] = str[i][c]; 
	    }


	  c++;
	  column++; 
	  if (column ==16)
	    {
	      line = println(curr_str);
	      column = 0;
	      line++; 
	    }

	  
	}
    }
}





